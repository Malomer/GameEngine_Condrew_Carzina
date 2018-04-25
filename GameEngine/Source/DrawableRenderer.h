#pragma once

#include "Component.h"
#include "SFML/Graphics.hpp"

class DrawableRenderer : public Component, public sf::Drawable, public sf::Transformable {

public:
	sf::CircleShape circle;
	sf::Drawable *target;

	virtual const char *VGetName() const { return "DrawableRenderer"; }

	DrawableRenderer();

	virtual void Draw();
	void VUpdate(int deltaMs);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{

	}

	//  virtual shared_ptr<SceneNode> VCreateSceneNode(void) = 0; 
	//virtual shared_ptr<SceneNode> VGetSceneNode(void) = 0;
};
