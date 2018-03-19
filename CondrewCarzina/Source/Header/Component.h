#pragma once

#include "Imports.h"

class Component {

	typedef std::shared_ptr<Component> StrongActorPtr;

protected:
	StrongActorPtr pOwner;

public:
	virtual ~Component(void) { pOwner.reset(); }

	virtual bool VInit() { }
	virtual void VPostInit(void) { }
	virtual void VUpdate(int deltaMs) { }
	virtual void VOnChanged(void) { }

	virtual const char *VGetName() const = 0;

private:
	void SetOwner(StrongActorPtr owner) { pOwner = owner; }

};
/*

#include <list>

class Component {

public:
virtual void Awake(void) { }
virtual void Update(int deltaMs) { }

virtual const char GetName() const = 0;
};
*/