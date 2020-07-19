#ifndef WINDOW_H
#define WINDOW_H

#include<SFML/Graphics.hpp>
#include<string.h>

class Window{
  public:
      Window();
      Window(const std::string& l_title,const sf::Vector2u& l_size);
      ~Window();

      void beginDraw(); // clear the window
      void endDraw(); // display changes

      //void update();

      bool isDone();
      void done();// set m_done = true
      bool isFullScreen();
      sf::Vector2u getWindowSize();
      sf::RenderWindow* getRenderWindow();

      void toggleFullscreen();

      void draw(sf::Drawable& l_drawable);

  private:

      // helper methods
      void setup(const std::string& l_title,const sf::Vector2u& size);
      void destroy();
      void create();

      // member variables
      sf::RenderWindow m_window;
      sf::Vector2u m_windowSize;
      std::string m_windowTitle;
      bool m_isDone;
      bool m_isFullscreen;
};


#endif // WINDOW_H
