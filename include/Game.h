#ifndef GAME_H
#define GAME_H

#include<window.h>
#include<Snake.h>
#include<World.h>

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
      World m_world;

};

#endif // GAME_H
