

#ifndef MAINGAME_H
#define MAINGAME_H

#include<Game.h>
#include<Window.h>
#include<MainMenu.h>
#include<BaseState.h>


enum class State{ Intro, Gameplay };

class MainGame : public BaseState
{
	public:
		MainGame();
		~MainGame();

		void Run();

	private:
		MainMenu m_mainMenu ;
		Game m_game;
		State m_state;
		Window m_window;
		bool m_loadNextState = false;
		bool m_loadPreviousState = false;

		// private helpers
		BaseState* GetCurrentState();
		bool UpdateState();
};

#endif