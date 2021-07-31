#include "AnimationComponent.h"



AnimationComponent::AnimationComponent(sf::Sprite& sprite, sf::Texture& texture)
	 :m_sprite(sprite) ,m_texture(texture)
{

}

AnimationComponent::~AnimationComponent()
{
	for (auto& i : this->animations)
	{
		delete i.second;
	}
}

void AnimationComponent::AddAnimation(const std::string key , float ani_speed, int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height)
{
	this->animations[key] = new Animation(this->m_sprite, this->m_texture, ani_speed, start_frame_x, start_frame_y, frames_x, frames_y, width, height);
}



void AnimationComponent::Play(const std::string key , const float& dt)
{
	this->animations[key]->play(dt);
}

