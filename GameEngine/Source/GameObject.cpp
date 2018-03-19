#include "GameObject.h"

void GameObject::Awake() {
	for (std::vector<Component*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Awake();
	}
}

void GameObject::Start() {
	for (std::vector<Component*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Start();
	}
}

void GameObject::Update(float msec) {
	if (m_Parent) { 
		worldTransform = m_Parent->worldTransform * transform.transformMatrix;
	}
	else { 
		worldTransform = glm::mat4(1.0f) * transform.transformMatrix;
	}

	for (std::vector<Component*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->Update();
	}
}

void GameObject::LateUpdate(float msec) {
	for (std::vector<Component*>::iterator i = m_Components.begin(); i != m_Components.end(); ++i) {
		(*i)->LateUpdate();
	}
}

void GameObject::AddComponent(Component* component) {
	m_Components.push_back(component);
}

void GameObject::AddChild(GameObject* child) {
	m_Children.push_back(child);
}
