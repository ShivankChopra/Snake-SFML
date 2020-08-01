#include<statsPanel.h>
#include<iostream>


StatsPanel::StatsPanel() :m_score(0), m_lives(3), m_levels(1)
{
    m_font.loadFromFile("Pacifico-Regular.ttf");
}

int StatsPanel::getScore() { return m_score; };

int StatsPanel::getLives() { return m_lives; };

int StatsPanel::getLevels() { return m_levels; };

void StatsPanel::setScore(int l_score) { m_score = l_score; }

void StatsPanel::setLives(int l_lives) { m_lives = l_lives; }

void StatsPanel::setLevels(int l_levels) { m_levels = l_levels; }

sf::Text StatsPanel::_getSfTextFromNum(const char* heading,  int num, sf::Vector2f position)
{ 
    sf::Text text(heading + std::to_string(num), m_font, 20);
    text.setPosition(position);
    return text;
}

void StatsPanel::render(sf::RenderWindow& l_window)
{
    sf::Text scoreText = _getSfTextFromNum("Score : ", m_score, { 240, 10 });
    sf::Text livesText = _getSfTextFromNum("Lives : ", m_lives, { 130, 10 });
    sf::Text levelText = _getSfTextFromNum("Levels : ", m_levels, { 20, 10 });

    l_window.draw(levelText);
    l_window.draw(livesText);
    l_window.draw(scoreText);
 
}