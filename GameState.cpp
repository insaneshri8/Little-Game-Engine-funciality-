#include "GameState.h"

void GameState::InitKeyBinds()
{
	std::ifstream ifs("config/GameState_keybinds.ini");
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

void GameState::InitTexture()
{
	// texture initilize of player class 
	if (!this->m_Texture["PLAYER_SHEET"].loadFromFile(
		"Resources/Images/sprites/player/Idle.png"))
	{
		throw "ERROR::FAILED TO LOAD TEXTURE OF PLAYER CLASS IN GAME_STATE";
	}

}

void GameState::InitPlayer()
{
	// Player initilize
	this->player = new Player(0, 0, this->m_Texture["PLAYER_SHEET"]);
}

GameState::GameState(sf::RenderWindow* window, std::map<std::string, int>* supportedkeys , std::stack<State*>* states)
	: State(window, supportedkeys , states)
{
	InitKeyBinds();
	InitTexture();
	InitPlayer();
}

GameState::~GameState()
{
	delete this->player;
}

void GameState::updateInput(const float & dt)
{


	// update input

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
		this->player->Move( -1.f, 0.f , dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
		this->player->Move( 1.f, 0.f , dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
		this->player->Move( 0.f, -1.f , dt);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
		this->player->Move( 0.f, 1.f , dt);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		this->endstate();
}



void GameState::update(const float& dt)
{
	this->updatemousePosition();
	this->updateInput(dt);
	this->player->update(dt);
}

void GameState::render(sf::RenderTarget* target)
{
	if (!target)
		target = this->m_Window; //if nothing bound to target we bind to window

	this->player->render(*target);
}
