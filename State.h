#pragma once

#include"Player.h"


// abstract class //

class State
{

protected:
	/* a stack full of states pointers not a copy of states */
	std::stack<State*>* states;
	/* GameState class can access these protected members*/
	sf::RenderWindow* m_Window;

	//keys
	std::map<std::string, int>* supportedkeys;
	std::map<std::string, int> keybinds;

	//mouse position
	sf::Vector2i mouse_PosScreen;
	sf::Vector2i mouse_PosWindow;
	sf::Vector2f mouse_PosView;


	bool quit = false;
	std::map<std::string , sf::Texture> m_Texture;

	//functions
	virtual void InitKeyBinds() = 0;

public:
	State(sf::RenderWindow* window , std::map<std::string , int>* supportedkeys , 
		std::stack<State*>* states);
	virtual ~State();

	const bool& getQuit() const;


	void endstate();
	virtual void updatemousePosition();
	virtual void updateInput(const float& dt) = 0;
	/* define in child class in future */
	virtual void update(const float&  dt) = 0;
	virtual void render(sf::RenderTarget* target = NULL) = 0;
};

