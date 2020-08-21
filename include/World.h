#ifndef WORLD_H
#define WORLD_H

#include<SFML/Graphics.hpp>
#include<Snake.h>
#include<window.h>
#include<statsPanel.h>

class World{
  public:
      World(sf::Vector2u l_windSize );
     ~World();
     int getBlockSize();
     void respawnApple();
     void update(Snake& l_player);
     void render(sf::RenderWindow& l_window);
     Window* getWindow();
     //void RestartClock();
     //sf::Time getElapsedTime();
     //void handleInput();

  private:

     sf::Vector2u m_windowSize;
     sf::Vector2i m_item;// track apple coordinate
     const int m_blockSize = 10;
     sf::CircleShape m_appleShape;
     sf::RectangleShape m_bounds[4];
     sf::RectangleShape m_statsBounds[4];
    // Window m_window;
    // sf::Clock m_clock;
    // sf::Time m_elapsed;
    // Snake m_snake;
    // StatsPanel m_statsPanel;
     

};

#endif // WORLD_H
