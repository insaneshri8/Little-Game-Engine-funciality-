#pragma once

#include<map>
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Network.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

class AnimationComponent
{
private:
	class Animation
	{
	public: 
		//variable
		sf::Texture& texturesheet;
		sf::Sprite& sprite;
	
		float animation_timer;
		float timer;
		int width;
		int height;
  		sf::IntRect Startrect;
		sf::IntRect Currnetrect;
		sf::IntRect Endrect;

		Animation(sf::Sprite& sprite ,sf::Texture& texturesheet , float ani_speed , int start_frame_x , int start_frame_y , int frames_x , int frames_y , int width , int height)
			:sprite(sprite),texturesheet(texturesheet) , animation_timer(ani_speed) , width(width) , height(height)
		{
			this->timer = 0.f;
			this->Startrect = sf::IntRect(start_frame_x * width, start_frame_y * height, width , height);
			this->Currnetrect = this->Startrect;
			this->Endrect = sf::IntRect(frames_x*width, frames_y*height, width, height);
			
			this->sprite.setTexture(this->texturesheet, true);

			this->sprite.setTextureRect(Startrect);
		}
		//functions
		void play(const float& dt)
		{
			//update timer
			this->timer += 100.f * dt;
			if (this->timer >= this->animation_timer)
			{
				//reset timer
				this->timer = 0.f;
				if (this->Currnetrect != this->Endrect)
				{
					this->Currnetrect.left += this->width;
				}
				else
				{
					this->Currnetrect.left = this->Startrect.left;  
				}
				this->sprite.setTextureRect(this->Currnetrect);
			}
		}
	     
		
		void reset()
		{
			this->timer = 0.f;
			this->Currnetrect = this->Startrect;
		}
	};


	sf::Sprite& m_sprite;
	sf::Texture& m_texture;
	std::map<std::string, Animation*> animations;
public:
	AnimationComponent(sf::Sprite& sprite , sf::Texture& texture);
	virtual ~AnimationComponent();
	
	//functions
	void AddAnimation(const std::string key ,  float ani_speed, int start_frame_x, int start_frame_y, int frames_x, int frames_y, int width, int height);


	void Play(const std::string key ,const float& dt);

};

