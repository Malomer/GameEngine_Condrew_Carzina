#pragma once

#include "StringUtils.h"
#include "GameObject.h"
#include "Imports.h"
#include <memory>

class Component {

protected:
	StrongGameObjectPtr m_pOwner;

public:
	virtual ~Component(void) { m_pOwner.reset(); }

	virtual void VInit() { };
	virtual void VUpdate(int deltaMs) { }
	virtual void VOnChanged(void) { }
	virtual void VOnDestroy() { }

	void SetOwner(StrongGameObjectPtr pOwner) { m_pOwner = pOwner; }
	virtual const char* VGetName() const = 0;
	virtual ComponentId VGetId(void) { return GetIdFromName(VGetName()); }

	static ComponentId GetIdFromName(const char* componentStr) {
		void* rawId = HashedString::hash_name(componentStr);
		return reinterpret_cast<ComponentId>(rawId);
	}
};
