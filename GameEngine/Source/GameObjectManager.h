#pragma once

#include <map>
#include "GameObject.h"

class GameObjectManager {

	friend class GameObject;
public:
	GameObject* CreateObject(std::string name = "Unknown");
	void InitGameObjects();

	void Update(float msec);
	void Close();
	void Render();
	GameObjectId GetNextId() { return nextObjectID++; }

private:
	std::map<int, GameObject*> m_Objects;
	static int nextObjectID;
};
