#include <iostream>
#include "Sheep.h"

Sheep::Sheep()
{
	// initialise animations
	for (int i = 0; i < 4; i++)
		m_walkDown.addFrame({ { 64 * i, 0 }, { 64, 64 } });
	m_walkDown.setLooping(true);
	m_walkDown.setFrameSpeed(0.25f);

	for (int i = 0; i < 4; i++)
		m_walkUp.addFrame({ { (64 * (i + 4)), 0 }, { 64, 64 } });
	m_walkUp.setLooping(true);
	m_walkUp.setFrameSpeed(0.25f);

	for (int i = 0; i < 4; i++)
		m_walkUpRight.addFrame({ { 64 * i, 64 }, { 64, 64 } });
	m_walkUpRight.setLooping(true);
	m_walkUpRight.setFrameSpeed(0.25f);

	for (int i = 0; i < 4; i++)
		m_walkRight.addFrame({ { (64 * (i + 4)), 64 }, { 64, 64 } });
	m_walkRight.setLooping(true);
	m_walkRight.setFrameSpeed(0.25f);

	for (int i = 0; i < 4; i++)
		m_walkDownRight.addFrame({ { 64 * i, 128 }, { 64, 64 } });
	m_walkDownRight.setLooping(true);
	m_walkDownRight.setFrameSpeed(0.25f);

	// the next 4 animations go clockwise from Up through Right to Down.

	m_currentAnimation = &m_walkDown;
	setTextureRect(m_currentAnimation->getCurrentFrame());

	sf::FloatRect collider({ 4,4 }, { 56,56 });
	setCollisionBox(collider);
}

Sheep::~Sheep()
{
}

void Sheep::handleInput(float dt)
{
	sf::Vector2f inputDir = { 0,0 };

	if (m_input->isKeyDown(sf::Keyboard::Scancode::S)) inputDir.y = 1;
	else if (m_input->isKeyDown(sf::Keyboard::Scancode::W)) inputDir.y = -1;

	if (m_input->isKeyDown(sf::Keyboard::Scancode::D)) inputDir.x = 1;
	else if (m_input->isKeyDown(sf::Keyboard::Scancode::A)) inputDir.x = -1;

	m_acceleration = ACCELERATION * inputDir;


}


void Sheep::update(float dt)
{
	if (m_worldSize.x - getPosition().x < 0 || m_worldSize.x - getPosition().x > m_worldSize.x ||
		m_worldSize.y - getPosition().y < 0 || m_worldSize.y - getPosition().y > m_worldSize.y) {
		std::cout << "sheep bounces!" << std::endl;
		checkWallAndBounce();
		}

	m_velocity += m_acceleration * dt;
	m_velocity *= DRAG_FACTOR;

	move(m_velocity);
}

void Sheep::checkWallAndBounce() {

	m_velocity *= -COEFF_OF_RESTITUTION;

}

void Sheep::collisionResponse(GameObject& collider) {
	collider.setVelocity(getVelocity() * -1.f * COEFF_OF_RESTITUTION);
}