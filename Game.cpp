#include "Game.h"

// private method

void Game::InitVariables()
{
	this->m_Window = NULL;
	this->fullscreen = false;
	this->dt = 0.f;
}


void Game::InitWindow()
{
	/* Creates a sfml window using options from window.ini file. */
	/* open file for read purpose only */

	std::ifstream in_file_stream("config/window.ini"); 
	this->videoModes = sf::VideoMode::getFullscreenModes();

	std::string title = "Non";
	sf::VideoMode window_bounds = sf::VideoMode::getDesktopMode();
	bool fullscreen = false;
	unsigned frametrate_limit = 60;
	bool vertical_sync = false; 
	unsigned antialising_level = 0;
	/* taking input from window ini file */
	if (in_file_stream.is_open())
	{
		std::getline(in_file_stream, title);
		in_file_stream >> window_bounds.width >> window_bounds.height;
		in_file_stream >> fullscreen;
		in_file_stream >> frametrate_limit;
		in_file_stream >> vertical_sync;
		in_file_stream >> antialising_level;
	}

	in_file_stream.close();

	this->fullscreen = fullscreen;
	window_settings.antialiasingLevel = antialising_level;

	if (this->fullscreen)
	{
		this->m_Window = new sf::RenderWindow(window_bounds, title, sf::Style::Fullscreen, window_settings);
	}
	else
	{
		this->m_Window = new sf::RenderWindow(window_bounds, title, sf::Style::Titlebar | sf::Style::Close , window_settings);
		
	}
	/* vertical sync will limit the number of frame displayed
	   to the refresh rate of the moniterr */
	this->m_Window->setFramerateLimit(frametrate_limit);
	this->m_Window->setVerticalSyncEnabled(vertical_sync);
}

void Game::InitKeys()
{
	std::ifstream ifs("config/supportedkey.ini");
	if(ifs.is_open())
	{
		std::string key = "";
		int key_value = 0;
		while (ifs >> key >> key_value)
		{
			this->supportedkeys[key] = key_value;
		}
	}
	ifs.close();



	//Debug
	for (auto i : this->supportedkeys)
		std::cout << i.first << " " << i.second << std::endl;

}


void Game::InitStates()
{
	 this->states.push(new MainMenuState(this->m_Window, &this->supportedkeys , &this->states));

	 /*this->states.push(new GameState(this->m_Window , &this->supportedkeys));*/
}


/* constructor 
   destructor */

Game::Game()
{
	/* when contructor call these things first 
	initilize then move to next  */
	InitVariables();
	InitWindow();
	InitKeys();
	InitStates();
}

Game::~Game()
{
	/* release the heap memory after program done his work */

	delete this->m_Window;
	
	/* remove all state from stack after game end */
	while (!this->states.empty())
	{
		delete this->states.top();
		this->states.pop();
	}
}

// Functions

void Game::QuitApp()
{
	std::cout << " Quit App " << std::endl;
}

void Game::IsRunning()
{
	while (m_Window->isOpen())
	{
		/* reset clock and update render and save in dt var then reset clock */
		this->UpdateDeltaTime();
		this->Update();
		this->Render();
	}
}

void Game::UpdateDeltaTime()
{
	/* time between to load one frame to another */
	dt = dt_Clock.restart().asSeconds();
	
}

void Game::UpdateSFMLEvents()
{
	/* pop the event on top of event queue */

	while (m_Window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			m_Window->close();

		if (event.type == sf::Keyboard::Escape)
			m_Window->close();
	}

}

void Game::Update()
{
	UpdateSFMLEvents();

	if (!this->states.empty())
	{
		this->states.top()->update(this->dt);

		if (this->states.top()->getQuit())  /* checking for quit */
		{
			this->states.top()->endstate();
			delete this->states.top();
			this->states.pop();
		}
	}
	else
	{
		this->QuitApp();
		this->m_Window->close();  // no more state left in queue 
	}
}

void Game::Render()
{
	/* clear window everyframe */
	m_Window->clear();


	/* Render item */  /* if stack is not empty we render top state */
	if (!this->states.empty())
		this->states.top()->render();

	/* display on screen what has rendered to the window so far
	(for each current frame)*/
	
	m_Window->display();
}
