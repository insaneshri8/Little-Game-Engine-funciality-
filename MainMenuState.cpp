#include "MainMenuState.h"

// INIT functions
void MainMenuState::InitVariables()
{

}

void MainMenuState::InitBackground()
{
	this->background.setSize(sf::Vector2f
	(
		static_cast<float>(this->m_Window->getSize().x),
		static_cast<float>(this->m_Window->getSize().y))
	);

	if (!bgTexture.loadFromFile("Resources/Images/BackGrounds/bg.png"))
	{
		throw "ERROR::FAILED_TO_LOAD BackGround IN MAIN_MENU_STATE ! ";
	}
	this->background.setTexture(&this->bgTexture);
}

void MainMenuState::InitFont()
{
	if (!this->font.loadFromFile("Font/static/Dosis-Light.ttf"))
	{
		throw(" Failed to load Font in MainMenuState "); // throw an expections
	}
}

void MainMenuState::InitKeyBinds()
{
	std::ifstream ifs("config/MainMenuState.ini");
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

void MainMenuState::InitButtons()
{
	 this->buttons["GAME_STATE"] =  new Button(
		250.f, 500.f, 150.f, 50.f,
		&this->font, " New Game ", 25, 
		sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250),sf::Color(20, 20, 20,50),
		sf::Color(70, 70, 70, 0 ), sf::Color(150, 150, 150, 0),sf::Color(20, 20, 20, 0));

	 this->buttons["SETTINGS"] = new Button(250, 600, 150, 50,
		 &this->font, "Settings", 25,
		 sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		 sf::Color(70, 70, 70, 0), sf::Color(150, 150, 150, 0),sf::Color(20, 20, 20, 0));

	 this->buttons["EDITOR_STATE"] = new Button(250, 700, 150, 50,
		 &this->font, "Editor", 25,
		 sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		 sf::Color(70, 70, 70,0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	 this->buttons["EXIT_STATE"] = new Button(250, 800, 150, 50,
		 &this->font, " Quit ", 25,
		 sf::Color(70, 70, 70, 200), sf::Color(250, 250, 250, 250), sf::Color(20, 20, 20, 50),
		 sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150,0),sf::Color(20, 20, 20, 0));
}

MainMenuState::MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys, std::stack<State*>* states)
	: State(window, supportedkeys, states)
{
	this->InitVariables();
	this->InitBackground();
	this->InitFont();
	InitKeyBinds();
	InitButtons();

}

MainMenuState::~MainMenuState()
{
	for (auto it = buttons.begin(); it != buttons.end(); ++it)
	{
		delete it->second;
	}
}

void MainMenuState::updateInput(const float& dt)
{

	// update input

	
}

void MainMenuState::updateBUttons()

{
	/* update all the buttons in the state and handles their functionality*/
	for (auto &it : this->buttons)
	{
		it.second->update(this->mouse_PosView);
	}

	if (this->buttons["GAME_STATE"]->isPressed())
	{
		/* pushing game state in stack states pointer - new window for playing */ 
		this->states->push(new GameState(this->m_Window, this->supportedkeys, this->states));
	}
	if (this->buttons["EDITOR_STATE"]->isPressed())
	{
		this->states->push(new EditorState(this->m_Window, this->supportedkeys, this->states));
	}

	if (this->buttons["EXIT_STATE"]->isPressed())
	{
		this->endstate();
	
	}

}


void MainMenuState::update(const float& dt)
{
	this->updatemousePosition();
	this->updateInput(dt);
	this->updateBUttons();




	/*system("cls");
	std::cout << this->mouse_PosView.x << " " << this->mouse_PosView.y << std::endl;*/
	//this->gamestate_btn->update(mouse_PosView);
}

void MainMenuState::renderButtons(sf::RenderTarget& target)
{
	for (auto& it : this->buttons)
	{
		it.second->render(target);
	}
}

void MainMenuState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->m_Window; //if nothing bound to target we bind to window

	target->draw(background);
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
