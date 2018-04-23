#pragma once

#include "Component.h"
#include "Matrices.h"

class TransformComponent {

public:

	Matrix4 transformMatrix;

	//virtual const char *VGetName() const { return "Transform"; }
};
