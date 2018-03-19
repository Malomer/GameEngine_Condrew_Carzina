#pragma once

#include <memory>
#include "GameObject.h"
#include "Component.h"

class GameObject;
class Component;

typedef unsigned int ComponentId;

typedef std::shared_ptr<Component> StrongActorPtr;
typedef std::weak_ptr<Component> WeakActorPtr;
typedef std::shared_ptr<GameObject> StrongActorComponentPtr;
typedef std::weak_ptr<GameObject> WeakActorComponentPtr;
