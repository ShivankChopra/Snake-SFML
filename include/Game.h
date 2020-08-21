#ifndef GAME_H
#define GAME_H

#include<window.h>
#include<Snake.h>
#include<World.h>
#include<statsPanel.h>
#include<BaseState.h>
   
class Game : public BaseState
{
  public:
      Game();
      ~Game();
      void HandleInput(Window& renderWindow, bool &loadNextState, bool &loadPreviousState) ;
      void Update() ;
      void Render(Window& renderWindow) ;
      void RestartClock();
      sf::Time getElapsedTime();
      

  private:
      sf::Clock m_clock;
      sf::Time m_elapsed;
      Snake m_snake;
      StatsPanel m_statsPanel;
      World m_world;

};

#endif // GAME_H
