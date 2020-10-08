#ifndef WORLD_H
#define WORLD_H

#include<SFML/Graphics.hpp>
#include<Snake.h>
#include<window.h>
#include<statsPanel.h>
using BlockContainer = std::vector<sf::RectangleShape> ;

class World{
  public:
      World(sf::Vector2u l_windSize );
     ~World();
     int getBlockSize();
     void respawnApple();
     void update(Snake& l_player);
     void render(sf::RenderWindow& l_window);
   

  private:

     sf::Vector2u m_windowSize;
     sf::Vector2i m_item;// track apple coordinate
     sf::Vector2f m_pos;
     const int m_blockSize = 10;
     sf::CircleShape m_appleShape;
     sf::RectangleShape m_bounds[4];
     sf::RectangleShape m_rocks[4];
     BlockContainer m_blocks;
  
  

};

#endif // WORLD_H
