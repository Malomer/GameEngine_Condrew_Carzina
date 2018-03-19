#pragma once

#include <stdio.h>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>

#include "Component.h"

class GameObject {

public:
	GameObject(int uniqueID) : m_UniqueID(uniqueID), m_Parent(NULL) {
	}

	int GetObjectID() const { return m_UniqueID; }

	void AddComponent(Component* component);

	void SetParent(GameObject& parent) { m_Parent = &parent; }
	void AddChild(GameObject* child);

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);

public: // Members
	//Transform transform;    //local transform

protected: // Members
	int m_UniqueID;

	GameObject* m_Parent;
	std::vector<GameObject*> m_Children;

	//glm::mat4 worldTransform;
	std::vector<Component*> m_Components;
};