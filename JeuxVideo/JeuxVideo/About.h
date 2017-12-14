#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
class About
{
public:
	About(float width, float height);
	~About();
	void draw(RenderWindow &window);
private:
	Font font;
	Text text, text2, text3;
	Texture backgroundGame;
	Sprite imagebackground;
};

