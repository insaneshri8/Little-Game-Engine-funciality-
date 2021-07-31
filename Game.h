#pragma once

#include"MainMenuState.h"

class Game
{
private:
	sf::RenderWindow* m_Window;
	std::vector<sf::VideoMode> videoModes;
	sf::ContextSettings window_settings;
	bool fullscreen;


	sf::Event event;

	sf::Clock dt_Clock;
	float dt;
  
	/*  we can not create object of abstract class 
	 only we create pointer and reference of that class */

	std::stack<State*> states; 
	std::map<std::string, int> supportedkeys;

	/* private function that access only private memeber of class */
	
	void InitVariables();
	void InitWindow();
	void InitKeys();
	void InitStates();
	

public:

	//   constructor //

	Game();
	virtual ~Game();

	//normal
	void QuitApp();


	// functions

	//update
	void UpdateDeltaTime();
	void UpdateSFMLEvents();
	void Update();

	//render
	void Render();

	//main
	void IsRunning();
};

