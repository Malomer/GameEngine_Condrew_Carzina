#include "GameObjectManager.h"

int GameObjectManager::nextObjectID = 0;

void GameObjectManager::InitGameObjects() {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Init();
	}
}

void GameObjectManager::Close() {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Destroy();
	}
}

void GameObjectManager::Update(float msec) {
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Update(msec);
	}
}

void GameObjectManager::Render() {
	/*
	for (std::map<int, GameObject*>::iterator i = m_Objects.begin(); i != m_Objects.end(); ++i) {
		(i->second)->Update(msec);
	}*/
}

GameObject* GameObjectManager::CreateObject(std::string name) {
	GameObject* newObj = new GameObject(nextObjectID++, name);
	m_Objects[GetNextId()] = newObj;

	return newObj;
}
