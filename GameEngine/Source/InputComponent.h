#pragma once

#include "Component.h"
#include "SFML/Graphics.hpp"
#include "SFML\System\Vector2.hpp"

class InputComponent : public Component {

public:

	virtual const char *VGetName() const { return "Input"; }

};
