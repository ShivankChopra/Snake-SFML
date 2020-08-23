#include<MainGame.h>
#include<iostream>

MainGame::MainGame() : m_state(State::Intro),
                       m_window("Snake", sf::Vector2u(800, 600))
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

    if (l_changeState) {
        std::cout << "Changing state..... " << std::endl;
        std::cout << "Current state is : " << (m_state == State::Gameplay ? "Gameplay" : "Intro") << std::endl;
    }

    return l_changeState;
}

