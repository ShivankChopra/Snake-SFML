#include<MainGame.h>

MainGame::MainGame() : m_state(State::Intro),
                       m_window("Snake", sf::Vector2u(800, 600))
{


}

MainGame::~MainGame()
{

}

void MainGame::Run()
{   
    while (!m_window.isDone()) {
        BaseState* currentState = GetCurrentState();
        currentState->HandleInput(m_window, m_loadNextState, m_loadPreviousState);
        //const auto& currentState = m_state == State::Intro ? &m_mainMenu : &m_game;

        if (!UpdateState())
        {   
            currentState->Update();
            currentState->Render(m_window);
            currentState->RestartClock();
        }
    }
}

BaseState* MainGame::GetCurrentState()
{
    BaseState* currentState = nullptr;

    if (m_state == State::Intro)
    {
        //auto tempPtr = &m_mainMenu;
        currentState = &m_mainMenu;
    } 
    else if (m_state == State::Gameplay)
    {
        //auto tempPtr = &m_game;
        currentState = &m_game;
    }

    return currentState;
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

    return l_changeState;
}

