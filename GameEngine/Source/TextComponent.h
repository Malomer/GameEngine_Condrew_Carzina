#pragma once

#include "Component.h"
#include <SFML/Graphics.hpp>

class TextComponent : public Component {

	virtual const char *VGetName() const { return "TextComponent"; }

public:

	sf::Font font;
	sf::Text text;
};
