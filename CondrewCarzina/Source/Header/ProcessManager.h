#pragma once

#include <list>
#include "Process.h"

class ProcessManager {

	typedef std::list<StrongProcessPtr> ProcessList;

	ProcessList m_processList;

public:
	~ProcessManager(void);

	unsigned int UpdateProcesses(unsigned long deltaMs);
	WeakProcessPtr AttachProcess(StrongProcessPtr pProcess);
	void AbortAllProcesses(bool immediate);

	unsigned int GetProcessCount(void) const { return m_processList.size(); }

private:
	void ClearAllProcesses(void);
};