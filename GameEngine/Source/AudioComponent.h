#pragma once

#include "Component.h"
#include <SFML\Audio.hpp>

class AudioComponent : public Component {

public:

	sf::SoundBuffer soundBuffer;
	sf::Sound sound;

	void SetSound();
};
