#include "MovementComponent.h"

MovementComponent::MovementComponent(sf::Sprite& sprite, float maxVelocity
     , float acceleration , float deacceleration)
	: sprite(sprite), maxVelocity(maxVelocity) , acceleration(acceleration) , deacceleration(deacceleration)
{
	this->maxVelocity = maxVelocity;
}

MovementComponent::~MovementComponent()
{

}

const sf::Vector2f& MovementComponent::getVelocity() const
{
	return this->velocity;
}

const bool MovementComponent::Idle() const
{
	if (this->velocity.x == 0.f && this->velocity.y == 0.f)
		return true;

	return false;

}

void MovementComponent::move(const float dir_x, const float dir_y , const float& dt)
{
	/* Acceleraing the sprite until he reaches the max velocity */
	this->velocity.x += acceleration * dir_x;
	this->velocity.y += acceleration * dir_y;

	
}

void MovementComponent::update(const float& dt)
{
	/* deaccelerate the sprite and control the maximum velocity
	move the sprite
	*/
	if (this->velocity.x > 0.f) // check for positive x
	{
		// max velocity check
		if (this->velocity.x > this->maxVelocity)
			this->velocity.x = maxVelocity;

		//deacceleration x positive
		this->velocity.x -= deacceleration;
		if (this->velocity.x < 0.f)
			this->velocity.x = 0.f;

	}
	else if (this->velocity.x < 0.f) // negative x
	{
		// max velocity check
		if (this->velocity.x < -this->maxVelocity)
			this->velocity.x = -maxVelocity;

		//deaccleration
		this->velocity.x += deacceleration;
		if (this->velocity.x > 0.f)
			this->velocity.x = 0.f;
	}


	if (this->velocity.y > 0.f) // check for positive y
	{
		// max velocity check
		if (this->velocity.y > this->maxVelocity)
			this->velocity.y = maxVelocity;

		//deacceleration x positive
		this->velocity.y -= deacceleration;
		if (this->velocity.y < 0.f)
			this->velocity.y = 0.f;

	}
	else if (this->velocity.y < 0.f) // negative y
	{
		// max velocity check
		if (this->velocity.y < -this->maxVelocity)
			this->velocity.y = -maxVelocity;

		//deaccleration
		this->velocity.y += deacceleration;
		if (this->velocity.y > 0.f)
			this->velocity.y = 0.f;
	}


	this->sprite.move(this->velocity * dt); // use velcity
}
