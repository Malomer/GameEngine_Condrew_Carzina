#pragma once

#include "Component.h"
#include <SFML/Audio.hpp>

class AudioComponent : public Component {

public:

	virtual const char *VGetName() const { return "Audio"; }

	sf::Sound sound;
	sf::Music m;

	AudioComponent() {
	}
};
