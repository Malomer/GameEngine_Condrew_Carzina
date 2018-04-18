#pragma once

#include "Component.h"
#include "SFML/Graphics.hpp"
#include "Matrices.h"

class TransformComponent  {//: public Component

public:
	
	Matrix4 transformMatrix;

	//virtual const char *VGetName() const { return "Transform"; }
};
