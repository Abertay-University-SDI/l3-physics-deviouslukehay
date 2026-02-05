#pragma once

#include "Framework/BaseLevel.h"
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
#include "Pig.h"
#include "Sheep.h"

class Level : BaseLevel {
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level();

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	const float SHAKE_TIME = .3f;


	// Default variables for level class.
	bool m_gameOver;
	float m_shakeTimer;


	sf::Texture m_backgroundTexture;
	GameObject m_background;

	// Here are our nice animals
	sf::Texture m_pigTexture;
	sf::Texture m_sheepTexture;
	std::vector<Pig*> m_pigPointers;
	Sheep m_sheep;
};