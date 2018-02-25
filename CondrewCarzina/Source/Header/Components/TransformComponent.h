#include "Component.h"
#include "Matrices.h"

class TransformComponent : public Component {

public:

	Matrix4 transform;

	Matrix4 GetTransform(void) const { return transform; }
	void SetTransform(const Matrix4& newTransform) { transform = newTransform; }
};