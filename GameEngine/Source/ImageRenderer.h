#pragma once

#include "Component.h"
#include <SFML\Graphics.hpp>

class ImageRenderer : public Component {

public:

	sf::Sprite image;

	virtual const char *VGetName() const { return "ImageRenderer"; }

	ImageRenderer(sf::Sprite image) {
		this->image = image;
	}

	virtual void Draw();
	void VUpdate(int deltaMs);
};
