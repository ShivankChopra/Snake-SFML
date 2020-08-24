#include<MainGame.h>
#include<iostream>

MainGame::MainGame() : m_state(State::Intro),
                       m_window("Snake", sf::Vector2u(800, 600)),
                       m_snake(10)
{


}

MainGame::~MainGame()
{

}

BaseState* MainGame::GetCurrentState()
{
    BaseState* currentState = nullptr;

    if (m_state == State::Intro)
    {
        currentState = &m_mainMenu;
    }
    else if (m_state == State::Gameplay)
    {
        currentState = &m_game;
       
    }

    return currentState;
}


void MainGame::Run()
{   
    while (!m_window.isDone()){      

            BaseState* currentState = GetCurrentState();

            currentState->HandleInput(m_window, m_loadNextState, m_loadPreviousState);

            if (!UpdateState())
            {
                currentState->Update();
                currentState->Render(m_window);
                currentState->RestartClock();
            }
    }
}

void MainGame::_Reset()
{
    m_snake.hasLost();
    m_snake.reset();
}

bool MainGame::UpdateState()
{
    bool l_changeState = false;


    if (m_loadNextState)
    {
        if (m_state == State::Intro)
        {
            m_state = State::Gameplay;
            l_changeState = true;
        }
    }
    else if (m_loadPreviousState)
    {

        if (m_state == State::Gameplay)
        {
            m_state = State::Intro;
            l_changeState = true;
            
        }
    }

    m_loadNextState = false;
    m_loadPreviousState = false;

    _Reset();

    return l_changeState;
}

