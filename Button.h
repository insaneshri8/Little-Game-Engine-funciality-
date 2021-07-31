#pragma once
#include<iostream>
#include<sstream>
#include<cstdlib>

#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>

enum button_states{BTN_IDLE = 0 , BTN_HOVER , BTN_ACTIVE};

class Button
{
private:
	short unsigned buttonState;

	sf::RectangleShape m_shape;
	sf::Font* m_font;
	sf::Text m_text;

	sf::Color textIdleColor;
	sf::Color textHoverColor;
	sf::Color textActiveColor;

	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color activeColor;

public:
	 Button(float x, float y, float width, float height,
		sf::Font* font, std::string text, unsigned character_size,
		sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
		sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor);

	~Button();

	//Accessors

	const bool isPressed() const;


	//functions
	void update(const sf::Vector2f mousePos);
	void render(sf::RenderTarget& target);
};

