#pragma once

#include "Imports.h"
#include "Component.h"
#include "TransformComponent.h"
#include "Matrices.h"
#include <string>
#include <map>
#include <iostream>

typedef std::string GameObjectType;
typedef std::map<ComponentId, StrongComponentPtr> Components;

class GameObject {
	
public:
	TransformComponent transform;
	Matrix4 worldTransform;

private:
	GameObjectId m_id;
	
	GameObjectType m_type;
	GameObject *parent;
	
public:
	explicit GameObject(GameObjectId id);
	explicit GameObject(GameObjectId id, std::string name);
	~GameObject(void);

	Components m_components;

	bool Init();
	void Destroy(void);
	void Update(int deltaMs);
	void VRender() { }

	GameObjectId GetId(void) const { return m_id; }
	GameObjectType GetType(void) const { return m_type; }

	template <class ComponentType>
	std::weak_ptr<ComponentType> GetComponent(ComponentId id) {
		ActorComponents::iterator findIt = m_components.find(id);
		if (findIt != m_components.end()) {
			StrongActorComponentPtr pBase(findIt->second);
			shared_ptr<ComponentType> pSub(static_pointer_cast<ComponentType>(pBase));
			weak_ptr<ComponentType> pWeakSub(pSub);
			return pWeakSub;
		} else {
			return weak_ptr<ComponentType>();
		}
	}

	template <class ComponentType>
	std::weak_ptr<ComponentType> GetComponent(const char *name) {
		ComponentId id = Component::GetIdFromName(name);
		Components::iterator findIt = m_components.find(id);
		if (findIt != m_components.end()) {
			StrongComponentPtr pBase(findIt->second);
			std::shared_ptr<ComponentType> pSub(std::static_pointer_cast<ComponentType>(pBase));
			std::weak_ptr<ComponentType> pWeakSub(pSub);
			return pWeakSub;
		} else {
			return std::weak_ptr<ComponentType>();
		}
	}

	template <class ComponentType>
	std::shared_ptr<ComponentType> GetComponent2(const char *name) {
		ComponentId id = Component::GetIdFromName(name);
		Components::iterator findIt = m_components.find(id);
		if (findIt != m_components.end()) {
			StrongComponentPtr pBase(findIt->second);
			std::shared_ptr<ComponentType> pSub(std::static_pointer_cast<ComponentType>(pBase));
			//std::weak_ptr<ComponentType> pWeakSub(pSub);
			return pSub;
		}
		else {
			return std::shared_ptr<ComponentType>();
		}
	}

	void SetParent(GameObject *parent) { this->parent = parent; }
	GameObject* GetParent() { return parent; }

	const Components* GetComponents() { return &m_components; }

	void AddComponent(StrongComponentPtr pComponent);
};
