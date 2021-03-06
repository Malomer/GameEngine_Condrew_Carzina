#pragma once

#include <assert.h>
#include <iostream>
#include <memory>

class Process;

typedef std::shared_ptr<Process> StrongProcessPtr;
typedef std::weak_ptr<Process> WeakProcessPtr;

class Process {

	friend class ProcessManager;

public:
	enum State {
		// Processes that are neither dead nor alive
		UNINITIALIZED = 0,  // created but not running
		REMOVED,  // removed from the process list but not destroyed; this can happen when a process that is already running is parented to another process

				  // Living processes
				  RUNNING,  // initialized and running
				  PAUSED,  // initialized but paused

						   // Dead processes
						   SUCCEEDED,  // completed successfully
						   FAILED,  // failed to complete
						   ABORTED,  // aborted; may not have started
	};

private:
	State m_state;
	StrongProcessPtr m_pChild;

public:
	Process(void);
	virtual ~Process(void);

protected:
	virtual void VOnInit(void) { m_state = RUNNING; }  // called during the first update; responsible for setting the initial state (typically RUNNING)
	virtual void VOnUpdate(unsigned long deltaMs) = 0;  // called every frame
	virtual void VOnSuccess(void) { }  // called if the process succeeds
	virtual void VOnFail(void) { }  // called if the process fails
	virtual void VOnAbort(void) { }  // called if the process is aborted

public:
	inline void Succeed(void);
	inline void Fail(void);

	inline void Pause(void);
	inline void UnPause(void);

	State GetState(void) const { return m_state; }
	bool IsAlive(void) const { return (m_state == RUNNING || m_state == PAUSED); }
	bool IsDead(void) const { return (m_state == SUCCEEDED || m_state == FAILED || m_state == ABORTED); }
	bool IsRemoved(void) const { return (m_state == REMOVED); }
	bool IsPaused(void) const { return m_state == PAUSED; }

	inline void AttachChild(StrongProcessPtr pChild);
	StrongProcessPtr RemoveChild(void);
	StrongProcessPtr PeekChild(void) { return m_pChild; }

private:
	void SetState(State newState) { m_state = newState; }
};

inline void Process::Succeed(void) {
	assert(m_state == RUNNING || m_state == PAUSED);
	m_state = SUCCEEDED;
}

inline void Process::Fail(void) {
	assert(m_state == RUNNING || m_state == PAUSED);
	m_state = FAILED;
}

inline void Process::AttachChild(StrongProcessPtr pChild) {
	if (m_pChild)
		m_pChild->AttachChild(pChild);
	else
		m_pChild = pChild;
}

inline void Process::Pause(void) {
	if (m_state == RUNNING)
		m_state = PAUSED;
	else
		std::cout << "Attempting  to pause a process that isn't running" << std::endl;
}

inline void Process::UnPause(void) {
	if (m_state == PAUSED)
		m_state = RUNNING;
	else
		std::cout << "Attempting to unpause a process that isn't paused" << std::endl;
}
