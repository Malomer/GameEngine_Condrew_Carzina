#include "GameObjectManager.h"

int GameObjectManager::nextObjectID = 0;

void GameObjectManager::Update(float msec) {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Update(msec);
	}
}

GameObject* GameObjectManager::CreateObject() {
	GameObject* newObj = new GameObject(nextObjectID++);
	m_Objects[GetNextId()] = newObj;

	return newObj;
}
