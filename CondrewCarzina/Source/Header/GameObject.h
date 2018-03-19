#pragma once

#include <vector>
#include <map>
#include <string>
#include <memory>

#include "Matrices.h"

class GameObject {

public:
	typedef std::map<unsigned int, Component*> Components;

private:
	std::vector<GameObject*> children;
	unsigned int id;
	GameObject *parent;
	Components components;
	std::string type;

public:
	explicit GameObject(unsigned int id);
	~GameObject(void);

	bool Init();
	void Awake(void);
	void Destroy(void);
	void Update(int deltaMs);

	// accessors
	unsigned int GetId(void) const { return id; }
	std::string GetType(void) const { return type; }

	// template function for retrieving components
	template <class ComponentType>
	std::weak_ptr<ComponentType> GetComponent(GameObjectName id) {
		ActorComponents::iterator findIt = m_components.find(id);
		if (findIt != m_components.end()) {
			StrongActorComponentPtr pBase(findIt->second);
			std::shared_ptr<ComponentType> pSub(std::static_pointer_cast<ComponentType>(pBase));  // cast to subclass version of the pointer
			std::weak_ptr<ComponentType> pWeakSub(pSub);  // convert strong pointer to weak pointer
			return pWeakSub;  // return the weak pointer
		}
		else {
			return weak_ptr<ComponentType>();
		}
	}

	void AddComponent(StrongActorComponentPtr pComponent);
	const Components* GetComponents() { return &components; }

	void SetParent(GameObject& parent) { this->parent = &parent; }
	GameObject* GetParent() { return parent; }

	void AddChild(GameObject* child);
};

/*
public:
GameObject() { parent = NULL; }
~GameObject(void);

void SetTransform(const Matrix4 &matrix) {
transform = matrix;
}

Matrix4 GetTransform() {
return transform;
}

Matrix4 GetWorldTransform() {
return worldTransform;
}

void SetParent(GameObject& p) {
parent = &p;
}

void AddChild(GameObject* s);
void Update(float msec);

void Awake(void);
void Destroy(void);
virtual void Update(int deltaMs);

protected:
GameObject* parent;
Matrix4 worldTransform;
Matrix4 transform;
std::vector<GameObject*> children;
std::map<std::string, Component> actorComponents;
};
*/