#pragma once

#include "DrawableRenderer.h"
#include <SFML\Graphics.hpp>

class TestRenderer : public DrawableRenderer {

public:

	sf::Shape *shape;

	virtual const char *VGetName() const { return "TestRenderer"; }

	TestRenderer(sf::Shape *shape);

private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		//sf::Vector2f pos = shape->getPosition();
		//printf("Drawing at %f, %f\n", pos.x, pos.y);
		/*
			const float *m = m_pOwner->worldTransform.get();
	std::shared_ptr<TestRenderer> testRenderer = MakeStrongPtr(m_pOwner->GetComponent<TestRenderer>("TestRenderer"));
	if (testRenderer) {
		testRenderer->shape->setPosition(m[3], m[7]);
	}
		*/
		const float *m = m_pOwner->worldTransform.get();
		shape->setPosition(m[3], m[7]);

		target.draw(*shape);
	}
	//virtual void draw(sf::RenderTarget& target, sf::RenderStates states);
};
