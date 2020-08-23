#include "MainMenu.h"


#include <SFML/Window/Event.hpp>

MainMenu::MainMenu()
    : m_isPlayButtonSelected(true),
      m_isPlayButtonPressed(false), m_isExitButtonSelected(false),
      m_isExitButtonPressed(false)
{
    m_font.loadFromFile("Pacifico-Regular.ttf");


    // Title
    m_gameTitle.setFont(m_font);
    m_gameTitle.setString("Snake Game");
    m_gameTitle.setOrigin(
        m_gameTitle.getLocalBounds().width / 2, 
        m_gameTitle.getLocalBounds().height / 2
    );
    m_gameTitle.setPosition(400, 150);

    // Play Button
    m_playButton.setFont(m_font);
    m_playButton.setString("Play");
    m_playButton.setOrigin(
        m_playButton.getLocalBounds().width / 2,
        m_playButton.getLocalBounds().height / 2
    );
    m_playButton.setPosition(400, 275);
    m_playButton.setCharacterSize(20);
    m_playButton.setFillColor(sf::Color::Yellow);

    // Exit Button
    m_exitButton.setFont(m_font);
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(
      m_exitButton.getLocalBounds().width / 2,
      m_exitButton.getLocalBounds().height / 2
    );
    m_exitButton.setPosition(400, 325);
    m_exitButton.setCharacterSize(20);
}

MainMenu::~MainMenu()
{
}

void MainMenu::HandleInput(Window& renderWindow, bool &loadNextState, bool &loadPreviousState)
{
    sf::Event event;
    while (renderWindow.getRenderWindow()->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            renderWindow.done();
        }
        else if (event.type == sf::Event::KeyPressed)
        {
          
            switch (event.key.code)
            {
                case sf::Keyboard::Up:
                {
                    if (!m_isPlayButtonSelected)
                    {
                        m_isPlayButtonSelected = true;
                        m_isExitButtonSelected = false;

                        m_playButton.setFillColor(sf::Color::Yellow);
                        m_exitButton.setFillColor(sf::Color::White);
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if (!m_isExitButtonSelected)
                    {
                        m_isPlayButtonSelected = false;
                        m_isExitButtonSelected = true;

                        m_exitButton.setFillColor(sf::Color::Yellow);
                        m_playButton.setFillColor(sf::Color::White);
                    }
                    break;
                }
                case sf::Keyboard::Enter:
                {
                    m_isPlayButtonPressed = false;
                    m_isExitButtonPressed = false;

                    if (m_isPlayButtonSelected)
                    {
                        m_isPlayButtonPressed = true;
                    }
                    else
                    {
                        m_isExitButtonPressed = true;
                    }

                    if (m_isPlayButtonPressed == true)
                    {
                        loadNextState = true;
                    }

                    break;
                }
                default:
                    break;
            }
        }
    }
   
}

void MainMenu::Update()
{

}

void MainMenu::Render(Window& renderWindow)
{
    
    renderWindow.beginDraw();
    renderWindow.draw(m_gameTitle);
    renderWindow.draw(m_playButton);
    renderWindow.draw(m_exitButton);
    renderWindow.endDraw();
}