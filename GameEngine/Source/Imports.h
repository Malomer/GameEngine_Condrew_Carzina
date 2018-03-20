#pragma once

#include <memory>

class GameObject;
class Component;

typedef unsigned int GameObjectId;
typedef unsigned int ComponentId;

typedef std::shared_ptr<GameObject> StrongGameObjectPtr;
typedef std::weak_ptr<GameObject> WeakGameObjectPtr;
typedef std::shared_ptr<Component> StrongComponentPtr;
typedef std::weak_ptr<Component> WeakComponentPtr;
