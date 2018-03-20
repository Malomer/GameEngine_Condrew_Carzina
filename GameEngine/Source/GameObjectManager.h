#pragma once

#include <map>
#include "GameObject.h"

class GameObjectManager {

	friend class GameObject;
public:
	GameObject* CreateObject();

	void Update(float msec);
	GameObjectId GetNextId() { return nextObjectID++; }

private:
	std::map<int, GameObject*> m_Objects;
	static int nextObjectID;
};
