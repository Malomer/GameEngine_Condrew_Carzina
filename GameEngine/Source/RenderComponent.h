#pragma once

#include "Component.h"
#include "SFML/Graphics.hpp"

class RenderComponent : public Component {

public:

	sf::Transform transform;
	virtual const char *VGetName() const { return "Render"; }

	RenderComponent() {
		transform = m_pOwner->transform.transform;
	}

	virtual void VUpdate(int deltaMs) {
	

	}
};
