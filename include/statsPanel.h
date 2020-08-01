#ifndef STATSPANEL_H
#define STATSPANEL_H

#include<SFML/Graphics.hpp>
#include<sstream>

class StatsPanel
{
public:
	StatsPanel();
	void setScore(int l_score);
	int getScore();
	void setLevels(int l_levels);
	int getLevels();
	void setLives(int l_lives);
	int getLives();
	void render(sf::RenderWindow& l_window);


private:
	int m_score;
	int m_lives;
	int m_levels;

	sf::Font m_font;
	sf::Text _getSfTextFromNum(const char* heading,  int num,  sf::Vector2f position);
};
#endif