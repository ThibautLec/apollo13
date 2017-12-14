#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;

#define MAX_NUMBER_OF_ITEMS 3

class GameOverPage
{
public:

	GameOverPage(float width, float height);
	~GameOverPage();

	int getPressedItem() { return selectedItemIndex; }

	void draw(RenderWindow &window);
	void moveUp();
	void moveDown();
	FloatRect getPositionBtnHome();

private:

	int selectedItemIndex;
	Font font;
	Text textMenu[MAX_NUMBER_OF_ITEMS];
	Texture btnHome, btnRestart, background;
	Sprite imageHome, imageRestart, imagebackground;
	Text text;
	
};
