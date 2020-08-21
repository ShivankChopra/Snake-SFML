#include "Game.h"


Game::Game() : m_world(sf::Vector2u (800, 600)),
               m_snake(m_world.getBlockSize())
{
    
};

Game::~Game() {};

void Game::HandleInput(Window& renderWindow, bool &loadNextState, bool &loadPreviousState) {
   sf::Event event;
    while(renderWindow.getRenderWindow()->pollEvent(event)){
        if(event.type == sf::Event::Closed){
            loadPreviousState = true;
        }
        else if(event.type == sf::Event::KeyPressed){
            if(event.key.code == sf::Keyboard::F){
               renderWindow.toggleFullscreen();
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


void Game::Update(){
    float timestep = 1.0f / m_snake.getSpeed();
    if(m_elapsed.asSeconds() >= timestep){
       m_snake.tick();
       m_world.update(m_snake);
       m_elapsed = sf::seconds(m_elapsed.asSeconds() - timestep);
       if(m_snake.hasLost()){
               m_snake.reset();
        }
    }
    m_statsPanel.setScore(m_snake.getScore());
    m_statsPanel.setLives(m_snake.getLives());

    m_world.update(m_snake);
}


void Game::Render(Window& renderWindow){
    renderWindow.beginDraw();
    // Render here.     
    m_snake.render(*renderWindow.getRenderWindow());
    m_world.render(*renderWindow.getRenderWindow());
    m_statsPanel.render(*renderWindow.getRenderWindow());
    renderWindow.endDraw();
}


sf::Time Game::getElapsedTime(){ return m_elapsed; }


void Game::RestartClock() { m_elapsed += m_clock.restart(); }
