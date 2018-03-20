#pragma once

#include "Imports.h"
#include "Component.h"
#include <string>
#include <map>
#include <iostream>

typedef std::string GameObjectType;

class GameObject {
	
public:

	typedef std::map<ComponentId, StrongComponentPtr> Components;

private:
	GameObjectId m_id;
	Components m_components;
	GameObjectType m_type;

public:
	explicit GameObject(GameObjectId id);
	~GameObject(void);

	bool Init();
	void Destroy(void);
	void Update(int deltaMs);

	GameObjectId GetId(void) const { return m_id; }
	GameObjectType GetType(void) const { return m_type; }

	template <class ComponentType>
	std::weak_ptr<ComponentType> GetComponent(ComponentId id) {
		ActorComponents::iterator findIt = m_components.find(id);
		if (findIt != m_components.end()) {
			StrongActorComponentPtr pBase(findIt->second);
			shared_ptr<ComponentType> pSub(static_pointer_cast<ComponentType>(pBase));  // cast to subclass version of the pointer
			weak_ptr<ComponentType> pWeakSub(pSub);  // convert strong pointer to weak pointer
			return pWeakSub;  // return the weak pointer
		} else {
			return weak_ptr<ComponentType>();
		}
	}

	template <class ComponentType>
	std::weak_ptr<ComponentType> GetComponent(const char *name) {
		ComponentId id = ActorComponent::GetIdFromName(name);
		ActorComponents::iterator findIt = m_components.find(id);
		if (findIt != m_components.end()) {
			StrongActorComponentPtr pBase(findIt->second);
			shared_ptr<ComponentType> pSub(static_pointer_cast<ComponentType>(pBase));  // cast to subclass version of the pointer
			weak_ptr<ComponentType> pWeakSub(pSub);  // convert strong pointer to weak pointer
			return pWeakSub;  // return the weak pointer
		} else {
			return weak_ptr<ComponentType>();
		}
	}

	const Components* GetComponents() { return &m_components; }

	void AddComponent(StrongComponentPtr pComponent);
};