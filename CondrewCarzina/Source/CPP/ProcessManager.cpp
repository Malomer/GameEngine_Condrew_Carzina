
#include "ProcessManager.h"

ProcessManager::~ProcessManager(void) {
	ClearAllProcesses();
}

unsigned int ProcessManager::UpdateProcesses(unsigned long deltaMs) {
	unsigned short int successCount = 0;
	unsigned short int failCount = 0;

	ProcessList::iterator it = m_processList.begin();
	while (it != m_processList.end()) {
		StrongProcessPtr pCurrProcess = (*it);

		ProcessList::iterator thisIt = it;
		++it;

		// process is uninitialized, so initialize it
		if (pCurrProcess->GetState() == Process::UNINITIALIZED)
			pCurrProcess->VOnInit();

		// give the process an update tick if it's running
		if (pCurrProcess->GetState() == Process::RUNNING)
			pCurrProcess->VOnUpdate(deltaMs);

		// check to see if the process is dead
		if (pCurrProcess->IsDead()) {
			switch (pCurrProcess->GetState()) {
			case Process::SUCCEEDED: {
				pCurrProcess->VOnSuccess();
				StrongProcessPtr pChild = pCurrProcess->RemoveChild();
				if (pChild)
					AttachProcess(pChild);
				else
					++successCount;  // only counts if the whole chain completed
				break;
			}

			case Process::FAILED: {
				pCurrProcess->VOnFail();
				++failCount;
				break;
			}

			case Process::ABORTED: {
				pCurrProcess->VOnAbort();
				++failCount;
				break;
			}
			}

			m_processList.erase(thisIt);
		}
	}
	return ((successCount << 16) | failCount);
}

WeakProcessPtr ProcessManager::AttachProcess(StrongProcessPtr pProcess) {
	m_processList.push_front(pProcess);
	return WeakProcessPtr(pProcess);
}

void ProcessManager::ClearAllProcesses(void) {
	m_processList.clear();
}

void ProcessManager::AbortAllProcesses(bool immediate) {
	ProcessList::iterator it = m_processList.begin();
	while (it != m_processList.end()) {
		ProcessList::iterator tempIt = it;
		++it;

		StrongProcessPtr pProcess = *tempIt;
		if (pProcess->IsAlive()) {
			pProcess->SetState(Process::ABORTED);
			if (immediate) {
				pProcess->VOnAbort();
				m_processList.erase(tempIt);
			}
		}
	}
}
