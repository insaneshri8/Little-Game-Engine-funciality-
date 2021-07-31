#include "EditorState.h"

#include "MainMenuState.h"

// INIT functions
void EditorState::InitVariables()
{

}

void EditorState::InitBackground()
{
	

}

void EditorState::InitFont()
{
	if (!this->font.loadFromFile("Font/static/Dosis-Light.ttf"))
	{
		throw(" Failed to load Font in EditorState "); // throw an expections
	}
}

void EditorState::InitKeyBinds()
{
	std::ifstream ifs("config/EditorState.ini");
	if (ifs.is_open())
	{
		std::string key = "";
		std::string key2 = "";
		while (ifs >> key >> key2)
		{
			this->keybinds[key] = this->supportedkeys->at(key2);
		}
	}
	ifs.close();


}

void EditorState::InitButtons()
{

}
EditorState::EditorState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* states)
	: State(window, supportedkeys, states)
{
	this->InitVariables();
	this->InitBackground();
	this->InitFont();
	InitKeyBinds();
	InitButtons();

}

EditorState::~EditorState()
{
	for (auto it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}

void EditorState::updateInput(const float& dt)
{

	// update input
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		this->endstate();
	}

}

void EditorState::updateBUttons()

{
	/* update all the buttons in the state and handles their functionality*/
	for (auto& it : this->buttons)
	{
		it.second->update(this->mouse_PosView);
	}



}


void EditorState::update(const float& dt)
{
	this->updatemousePosition();
	this->updateInput(dt);
	this->updateBUttons();




	/*system("cls");
	std::cout << this->mouse_PosView.x << " " << this->mouse_PosView.y << std::endl;*/
	//this->gamestate_btn->update(mouse_PosView);
}

void EditorState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void EditorState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->m_Window; //if nothing bound to target we bind to window

	
	//this->gamestate_btn->render(target);
	this->renderButtons(*target);

	// debug 250 500
	//sf::Text mouseText;
	//mouseText.setPosition(this->mouse_PosView.x, this->mouse_PosView.y - 40);
	//mouseText.setFont(font);
	//mouseText.setCharacterSize(12);
	//std::stringstream ss;
	//ss << mouse_PosView.x << " " << mouse_PosView.y;
	//mouseText.setString(ss.str());

	//target->draw(mouseText);
}
