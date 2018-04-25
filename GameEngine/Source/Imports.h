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

template <class Type>
std::shared_ptr<Type> MakeStrongPtr(std::weak_ptr<Type> pWeakPtr) {
	if (!pWeakPtr.expired())
		return std::shared_ptr<Type>(pWeakPtr);
	else
		return std::shared_ptr<Type>();
};
