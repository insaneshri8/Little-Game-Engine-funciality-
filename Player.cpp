#include "Player.h"

void Player::InitVariables()
{

}

void Player::InitComponets()
{

}

Player::Player(float x ,float y ,sf::Texture& texture_sheet)
{
    InitVariables();
	

	this->setPosition(x, y);
	this->CreateHitboxComponent(this->sprite, -40.f,0.f,55 , 60);
	this->CreateMovementComponent(300.f, 15.f, 5.f);
	this->CreateAnimationComponent(texture_sheet);
	this->animationComponent->AddAnimation("IDLE_LEFT", 10.f, 0, 0, 3, 0,63, 60);
	

}

Player::~Player()
{
}

void Player::update(const float& dt)
{
	this->movementComponent->update(dt); 

		this->animationComponent->Play("IDLE_LEFT", dt);

		this->hitboxComponent->update();
}
