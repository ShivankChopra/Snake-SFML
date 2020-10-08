#include "window.h"


Window::Window(){ setup("window", sf::Vector2u(640,480)); }


Window::Window(const std::string& l_title, const sf::Vector2u& l_size){
    setup(l_title, l_size);
}


Window::~Window(){ destroy();}


void Window::setup(const std::string& l_title,const sf::Vector2u& l_size){
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    create();
}


void Window::create(){
    auto style = (m_isFullscreen ? sf::Style::Fullscreen  :  sf::Style::Default);
    m_window.create({ m_windowSize.x, m_windowSize.y, 32 } , m_windowTitle, style);
}


void Window::destroy(){
    m_window.close();
}


void Window::toggleFullscreen(){
    m_isFullscreen = !m_isFullscreen;
    /* we need to destroy and re-create
       for toggleFullscreen to take effect
    */
    destroy();
    create();
}


void Window::beginDraw(){ m_window.clear(sf::Color::Black); }


void Window::endDraw(){ m_window.display(); }


bool Window::isDone(){ return m_isDone; }


void Window::done(){m_isDone = true;}


bool Window::isFullScreen(){ return m_isFullscreen; }


sf::Vector2u Window::getWindowSize(){ return m_windowSize; }


void Window::draw(sf::Drawable& l_drawable){
     m_window.draw(l_drawable);
}

/////////////////////////////////////////////////////////////////////////////////////
sf::RenderWindow* Window::getRenderWindow(){
     return &m_window;
}
