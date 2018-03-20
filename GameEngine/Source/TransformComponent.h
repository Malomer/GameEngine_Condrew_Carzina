#pragma once

#include "Component.h"
#include "SFML/Graphics.hpp"

class TransformComponent : public Component {

public:
	sf::Transform transform;

	virtual const char *VGetName() const { return "Transform"; }

	TransformComponent(void) { 
		transform = sf::Transform::Identity;
	}
};
