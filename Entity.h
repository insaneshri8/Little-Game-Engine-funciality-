#pragma once

#include"HitboxComponent.h"
#include"MovementComponent.h" 
#include"AnimationComponent.h"
class Entity
{
private:
	void InitVariables();

protected:
	
	sf::Sprite sprite;
	
	float m_speed;
	HitboxComponent* hitboxComponent;
	MovementComponent* movementComponent;
	AnimationComponent* animationComponent;

public:
	Entity();
	virtual ~Entity();

	// component method
	void setTexture(sf::Texture& texture);
	void CreateHitboxComponent(sf::Sprite& sprite , float offset_x, float offset_y, float width, float height);
	void CreateMovementComponent(const float maxVelocity, const float acceleration, const float deacceleration);
	void CreateAnimationComponent(sf::Texture& texture_sheet);
	//functions
	virtual void setPosition(const float x, const float y);
	virtual void Move( const float dir_x, const float dir_y, const float& dt);
	virtual void update(const float& dt);
	virtual void render(sf::RenderTarget& target);
};

