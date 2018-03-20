
#include "GameObject.h"

GameObject::GameObject(GameObjectId id) {
	m_id = id;
	m_type = "Unknown";
}

GameObject::~GameObject(void) {
	std::cout << "Destoryed Game Object Id: " << m_id << std::endl;
}

void GameObject::Destroy(void) {
	m_components.clear();
}

void GameObject::Update(int deltaMs) {
	for (Components::iterator it = m_components.begin(); it != m_components.end(); ++it) {
		it->second->VUpdate(deltaMs);
	}
}

void GameObject::AddComponent(StrongComponentPtr pComponent) {
	std::pair<Components::iterator, bool> success = m_components.insert(std::make_pair(pComponent->VGetId(), pComponent));
	pComponent->SetOwner(StrongGameObjectPtr(this));
}
