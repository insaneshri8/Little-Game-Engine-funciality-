#include "State.h"

State::State(sf::RenderWindow* window , std::map<std::string, int>* supportedkeys ,
	       std::stack<State*>* states)
{
	this->m_Window = window; 
	this->supportedkeys = supportedkeys;
	this->states = states;
	this->quit = false;
}

State::~State()
{

}

const bool& State::getQuit() const
{
	return this->quit;
}



void State::endstate()
{
	this->quit = true;
}

void State::updatemousePosition()
{
	this->mouse_PosScreen = sf::Mouse::getPosition();
	this->mouse_PosWindow = sf::Mouse::getPosition(*this->m_Window);
	this->mouse_PosView = this->m_Window->mapPixelToCoords
	                      (sf::Mouse::getPosition(*this->m_Window));
}
