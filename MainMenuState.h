#pragma once

#include"GameState.h"
#include"Button.h"
#include"EditorState.h"

class MainMenuState : public State
{
private:
	//variables
	sf::Texture bgTexture;
	sf::RectangleShape background;
    
	//font
	sf::Font font;

	std::map<std::string, Button*> buttons;

	//function
	void InitVariables();
	void InitBackground();
	void InitFont();
	void InitKeyBinds() override;
	void InitButtons();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys
	              ,std::stack<State*>* states);
	virtual ~MainMenuState();


	// pure virtual function define here in child class
	void updateInput(const float& dt) override;
	void updateBUttons();
	void update(const float& dt) override;
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL) override;
};

