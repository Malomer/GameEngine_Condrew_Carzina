#pragma once

#include "StringUtils.h"
#include "GameObject.h"
#include <memory>
#include "Imports.h"

class Component {

protected:
	StrongGameObjectPtr m_pOwner;

public:
	virtual ~Component(void) { m_pOwner.reset(); }

	virtual bool VInit() = 0;
	virtual void VUpdate(int deltaMs) { }
	virtual void VOnChanged(void) { }

	virtual ComponentId VGetId(void) const { return GetIdFromName(VGetName()); }
	virtual const char *VGetName() const = 0;
	static ComponentId GetIdFromName(const char* componentStr) {
		void* rawId = HashedString::hash_name(componentStr);
		return reinterpret_cast<ComponentId>(rawId);
	}

private:
	void SetOwner(StrongGameObjectPtr pOwner) { m_pOwner = pOwner; }

};
