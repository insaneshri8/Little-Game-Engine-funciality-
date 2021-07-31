#include "Entity.h"

void Entity::InitVariables()
{
	this->hitboxComponent = NULL;
	this->movementComponent = NULL;
	this->animationComponent = NULL;
	m_speed = 150.f;
}

Entity::Entity()
{
	this->InitVariables();

}

Entity::~Entity()
{
	delete this->hitboxComponent;
	delete	this->movementComponent;
	delete this->animationComponent;

}

void Entity::setTexture(sf::Texture& texture)
{
	
	this->sprite.setTexture(texture);
	
}

void Entity::CreateHitboxComponent(sf::Sprite& sprite, float offset_x, float offset_y, float width, float height)
{
	this->hitboxComponent = new HitboxComponent(sprite, offset_x , offset_y, width , height);
}

void Entity::CreateMovementComponent(const float maxVelocity , const float acceleration , const float deacceleration)
{
	this->movementComponent = new MovementComponent(this->sprite , maxVelocity , acceleration , deacceleration);
}

void Entity::CreateAnimationComponent( sf::Texture& texture_sheet)
{
	this->animationComponent = new AnimationComponent(this->sprite, texture_sheet);
}

void Entity::setPosition(const float x, const float y)
{
	
	   this->sprite.setPosition(x, y);
}

void Entity::Move( const float dir_x, const float dir_y  , const float& dt )
{
	if (this->movementComponent)
	{
		this->movementComponent->move(dir_x, dir_y , dt); // set velocity
		
	}
}

void Entity::update(const float& dt)
{

}

void Entity::render(sf::RenderTarget& target)
{
	
	target.draw(sprite);

	if (this->hitboxComponent)
		this->hitboxComponent->render(target);
}
