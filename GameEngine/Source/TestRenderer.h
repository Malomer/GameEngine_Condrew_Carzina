#pragma once

#include "DrawableRenderer.h"
#include <SFML\Graphics.hpp>

class TestRenderer : public DrawableRenderer {

public:

	sf::Shape *shape;

	virtual const char *VGetName() { return "TestRenderer"; }

	TestRenderer(sf::Shape *shape);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		target.draw(*shape);
	}
	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
};
