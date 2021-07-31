#pragma once
#include<iostream>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<stack>
#include<map>

#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<fstream>
#include<sstream>

class MovementComponent
{
private:
	sf::Sprite& sprite;

	float  acceleration;
	float  deacceleration;
	float maxVelocity;


	sf::Vector2f velocity;


public:
	MovementComponent(sf::Sprite& sprite ,float maxVelocity, float acceleration, float deacceleration);
	virtual ~MovementComponent();

	const sf::Vector2f& getVelocity() const;

	const bool Idle() const;
	void move(const float dir_x, const  float dir_y, const float& dt);
	void update(const float& dt);
};

