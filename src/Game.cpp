#include "Game.h"
#include<iostream>

/////////////////////////////////////////////////////////////////////////////////////////////
Game::Game() : m_window("Snake", sf::Vector2u(800, 600)),
               m_world(sf::Vector2u(800,600)),
               m_snake(m_world.getBlockSize())
{ }

/////////////////////////////////////////////////////////////////////////////////////////////
Game::~Game(){}

/////////////////////////////////////////////////////////////////////////////////////////////
void Game::handleInput(){
    sf::Event event;
    while(m_window.getRenderWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            m_window.done();
        }
        else if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::F){
                m_window.toggleFullscreen();
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.getDirection() != Direction::Down){
               m_snake.setDirection(Direction::Up);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.getDirection() != Direction::Up){
               m_snake.setDirection(Direction::Down);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.getDirection() != Direction::Right){
               m_snake.setDirection(Direction::Left);
            }
            else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.getDirection() != Direction::Left){
               m_snake.setDirection(Direction::Right);
            }
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
void Game::update(){
    float timestep = 1.0f / m_snake.getSpeed();
    if(m_elapsed.asSeconds() >= timestep){
        m_snake.tick();
        m_world.update(m_snake);
        std::cout<<"Score :  "<<m_snake.getScore()<<std::endl<<std::endl;
        std::cout<<"Lives :  "<<m_snake.getLives()<<std::endl<<std::endl<<std::endl;
        m_elapsed = sf::seconds(m_elapsed.asSeconds() - timestep);
        if(m_snake.hasLost()){
               m_snake.reset();
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////
void Game::render(){
     m_window.beginDraw();
     // Render here.
     m_world.render(*m_window.getRenderWindow());
     m_snake.render(*m_window.getRenderWindow());
     m_window.endDraw();
}

//////////////////////////////////////////////////////////////////////////////////////////////
Window* Game::getWindow(){
    return &m_window;
}

//////////////////////////////////////////////////////////////////////////////////////////////
sf::Time Game::getElapsedTime(){ return m_elapsed; }

//////////////////////////////////////////////////////////////////////////////////////////////
void Game::restartClock(){ m_elapsed += m_clock.restart(); }
