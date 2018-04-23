#pragma once

#include "Component.h"
#include <SFML\Graphics.hpp>

class ShapeRenderer : public Component {

public:

	sf::Shape *shape;

	virtual const char *VGetName() const { return "ShapeRenderer"; }

	ShapeRenderer(sf::Shape *shape);

	virtual void Draw();
	void VUpdate(int deltaMs);
};
