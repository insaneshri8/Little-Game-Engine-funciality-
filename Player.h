#pragma once
#include "Entity.h"
class Player : public Entity
{
private:
	/* variables */


	/* Initializer functions */

	void InitVariables();
	void InitComponets();
public:
	Player(float x, float y, sf::Texture& texture_sheet);
	virtual ~Player();


	void update(const float& dt);

};

