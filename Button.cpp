#include "Button.h"

Button::Button(float x, float y, float width, float height,
	sf::Font* font, std::string text, unsigned character_size ,
	sf::Color text_idle_color , sf::Color text_hover_color  , sf::Color text_active_color,
	sf::Color idleColor, sf::Color hoverColor, sf::Color activeColor)
{
	//button
	this->buttonState = BTN_IDLE;

	// shape

	this->m_shape.setPosition(sf::Vector2f(x, y));
	this->m_shape.setSize(sf::Vector2f(width, height));
	this->m_shape.setFillColor(idleColor);

	// font
	this->m_font = font;
	this->m_text.setFont(*this->m_font);
	this->m_text.setString(text);
	this->m_text.setFillColor(text_idle_color);
	this->m_text.setScale(1.5f, 1.5f);
	this->m_text.setCharacterSize(character_size);
	/* text center */
	this->m_text.setPosition(
		this->m_shape.getPosition().x  + (m_shape.getGlobalBounds().width / 2.f) - this->m_text.getGlobalBounds().width / 2.f,
		this->m_shape.getPosition().y  + (m_shape.getGlobalBounds().height / 2.f) - this->m_text.getGlobalBounds().height / 2.f
		);

	this->textIdleColor = text_idle_color;
	this->textHoverColor = text_hover_color;
	this->textActiveColor = text_active_color;



	// color
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->activeColor = activeColor;

	this->m_shape.setFillColor(this->idleColor);

}


Button::~Button()
{
	/*delete this->m_font;*/
}

void Button::update(const sf::Vector2f mousePos)
{
	this->buttonState = BTN_IDLE;

	/* update the boolean for hover onPressed */
	if (m_shape.getGlobalBounds().contains(mousePos)) // hover conditions
	{
		this->buttonState = BTN_HOVER;

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			this->buttonState = BTN_ACTIVE;
		}
	}

	switch (this->buttonState)
	{
	case BTN_IDLE:
		this->m_shape.setFillColor(this->idleColor);
		this->m_text.setFillColor(textIdleColor);
		break;
	case BTN_HOVER:
		this->m_shape.setFillColor(this->hoverColor);
		this->m_text.setFillColor(textHoverColor);
		break;
	case BTN_ACTIVE:
		this->m_shape.setFillColor(this->activeColor);
		this->m_text.setFillColor(textActiveColor);
		break;

	default:
		this->m_shape.setFillColor(sf::Color::Red);
		this->m_text.setFillColor(sf::Color::Blue);
		break;
	}
}

const bool Button::isPressed() const
{
	/* checking button is pressed or not */
	if (this->buttonState == BTN_ACTIVE) 
	{
		return true;
	}
	return false;
}

void Button::render(sf::RenderTarget& target)
{
	target.draw(this->m_shape);
	target.draw(this->m_text);
}
