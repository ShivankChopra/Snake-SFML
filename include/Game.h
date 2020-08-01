#ifndef GAME_H
#define GAME_H

#include<window.h>
#include<Snake.h>
#include<World.h>
#include<statsPanel.h>

class Game{
  public:
      Game();
      ~Game();
      void handleInput();
      void update();
      void render();
      Window *getWindow();
      void restartClock();
      sf::Time getElapsedTime();

  private:
      Window m_window;
      sf::Clock m_clock;
      sf::Time m_elapsed;
      Snake m_snake;
      StatsPanel m_statsPanel;
      World m_world;

};

#endif // GAME_H
