#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class HomePage
{
public:

	HomePage(float width, float height);
	~HomePage();

	int getPressedItem() { return selectedItemIndex; }

	void draw(RenderWindow &window);
	void moveUp();
	void moveDown();

private:

	int selectedItemIndex;
	Font font;
	Text textMenu[MAX_NUMBER_OF_ITEMS];
	
	Texture background;
	Sprite imagebackground;
};
