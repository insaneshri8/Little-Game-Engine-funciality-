#pragma once
#include "State.h"
#include"Button.h"
class EditorState :public State
{
private:
	//font
	sf::Font font;

	std::map<std::string, Button*> buttons;

	void InitVariables();
	void InitBackground() ;
	void InitFont();
	void InitKeyBinds() override;
	void InitButtons();

public:
	EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys
		, std::stack<State*>* states);
	virtual ~EditorState();


	void updateInput(const float& dt) override;
	void updateBUttons();
	void update(const float& dt) override;
	void renderButtons(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL) override;
};

