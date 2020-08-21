#include "World.h"
#include<iostream>

World::World(sf::Vector2u l_windSize) 
                                       
{
    //m_blockSize = 16;
    m_windowSize = l_windSize;
    respawnApple();
    m_appleShape.setFillColor(sf::Color::Red);
    m_appleShape.setRadius(m_blockSize / 2);
    for(int i = 0; i < 4; ++i){
         m_statsBounds[i].setFillColor(sf::Color(150, 0, 0));
         m_bounds[i].setFillColor(sf::Color(150,0,0));
         if(!((i + 1) % 2)){
             m_statsBounds[i].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
             m_bounds[i].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
         }
         else {
             m_statsBounds[i].setSize(sf::Vector2f(m_blockSize, m_windowSize.y));
             m_bounds[i].setSize(sf::Vector2f(m_blockSize,m_windowSize.y));
         }

         if(i < 2){
             m_statsBounds[i].setPosition(0, 0);
             m_bounds[i].setPosition(0,40);
         }
         else {
             m_statsBounds[i].setOrigin(m_bounds[i].getSize());
             m_bounds[i].setOrigin(m_bounds[i].getSize());
             m_statsBounds[i].setPosition(sf::Vector2f(m_windowSize));
             m_bounds[i].setPosition(sf::Vector2f(m_windowSize));
         }
    }// for
}


World::~World(){}


void World::respawnApple(){
    int maxX = (m_windowSize.x / m_blockSize) - 2;
    int maxY = (m_windowSize.y / (m_blockSize + 15)) - 2;
    m_item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 3);
    m_appleShape.setPosition(m_item.x * m_blockSize, m_item.y * m_blockSize);
}


void World::update(Snake& l_player) {

    if (l_player.getPosition() == m_item) {
        l_player.extend();
        l_player.increaseScore();
        respawnApple();
    }

    int gridSize_x = m_windowSize.x / m_blockSize;
    int gridSize_y = m_windowSize.y / m_blockSize;
    if (l_player.getPosition().x <= 0 ||
        l_player.getPosition().y <= 4 ||
        l_player.getPosition().x >= (gridSize_x - 1) ||
        l_player.getPosition().y >= (gridSize_y - 1)
        ) {

        l_player.lose();
    }
}



void World::render(sf::RenderWindow& l_window) {


    for (int i = 0; i < 4; ++i) {
        l_window.draw(m_statsBounds[i]);
        l_window.draw(m_bounds[i]);
    }
    l_window.draw(m_appleShape);
}

//sf::Time World::getElapsedTime() { return m_elapsed; }*/

//void World::RestartClock() { m_elapsed += m_clock.restart(); }



int World::getBlockSize(){ return 10;}
