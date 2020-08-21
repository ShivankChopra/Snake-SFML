#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include<BaseState.h>
#include"window.h"
#include"Game.h"
#include<World.h>

class MainMenu : public BaseState
{
    public:
        MainMenu();
        ~MainMenu();

        void HandleInput(Window& renderWindow, bool &loadNextState, bool &loadPreviousState);
        void Update();
        void Render(Window& renderWindow);

    private:
        sf::Font m_font;
        sf::Text m_gameTitle;
        sf::Text m_playButton;
        sf::Text m_exitButton;
  
        bool m_isPlayButtonSelected;
        bool m_isPlayButtonPressed;

        bool m_isExitButtonSelected;
        bool m_isExitButtonPressed;
};
