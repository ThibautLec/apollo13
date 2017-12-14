#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

class LogInPage
{
public:
	LogInPage(float width, float height);
	~LogInPage();

	void draw(RenderWindow &window);


private:
	Font font;
	Text name, password;
	RectangleShape rectName, rectPassword;
};

