#pragma once
#include "State.h"


/* if we cant define that function in this child class 
then this is not pure class */

class GameState : public State
{
private:
	Player* player;

	//function
	void InitKeyBinds() override;
	void InitTexture();
	void InitPlayer();

public:
	GameState(sf::RenderWindow* window , std::map<std::string, int>* supportedkeys , std::stack<State*>* states);
	virtual ~GameState();

	// pure virtual function define here in child class
	void updateInput(const float& dt) override; 

	void update(const float& dt) override;
	void render(sf::RenderTarget* target = NULL) override;

};

