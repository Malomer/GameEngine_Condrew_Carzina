
#include "GameObject.h"
#include "Component.h"

GameObject::GameObject(unsigned int id) {
	id = id;
	type = "Unknown";
}

GameObject::~GameObject(void) {
	std::cout << "Destroyed GameObject " << id << std::endl;
}

bool GameObject::Init() {
	for (Components::iterator it = components.begin(); it != components.end(); ++it) {
		it->second->VPostInit();
	}
	return true;
}

void GameObject::Destroy(void) {
	components.clear();
}

void GameObject::Update(int deltaMs) {
	for (Components::iterator it = components.begin(); it != components.end(); ++it) {
		it->second->VUpdate(deltaMs);
	}
}

void GameObject::AddComponent(StrongActorComponentPtr pComponent) {
	std::pair<Component::iterator, bool> success = components.insert(std::make_pair(pComponent->VGetName(), pComponent));
}

void GameObject::AddChild(GameObject* child) {
	children.push_back(child);
	child->parent = this;
}
