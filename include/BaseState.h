
#ifndef BASESTATE_H
#define BASESTATE_H

#include<window.h>

class BaseState
{
    public:

        virtual void HandleInput(Window &renderWindow, bool &loadNextState, bool &loadPreviousState) {};
        virtual void Render(Window& renderWindow) {};
        virtual void RestartClock() {};
        virtual void GetElaspedTime() {};
        virtual void Update() {};
};

#endif