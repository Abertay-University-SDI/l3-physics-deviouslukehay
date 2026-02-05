#pragma once
#include <iostream>
#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Sheep :
	public GameObject
{

public:
	Sheep();
	~Sheep();

	void handleInput(float dt) override;
	void update(float dt) override;
	void setWorldSize(sf::Vector2f worldSize) { m_worldSize = worldSize;  };
	void checkWallAndBounce();

private:
	const float ACCELERATION = 90.0f;   // rate of acceleration, suggested range 10-500
	const float DRAG_FACTOR = 0.9f;    // friction, suggest range 0.7-0.99
	const float COEFF_OF_RESTITUTION = .8f;
	sf::Vector2f m_acceleration;
	sf::Vector2f m_worldSize; 

	Animation m_walkDown;
	Animation m_walkUp;
	Animation m_walkUpRight;
	Animation m_walkRight;
	Animation m_walkDownRight;

	Animation* m_currentAnimation;
};

