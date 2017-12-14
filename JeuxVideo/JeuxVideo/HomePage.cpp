#include "stdafx.h"
#include "HomePage.h"


HomePage::HomePage(float w, float h)
{
	if (!font.loadFromFile("arial.ttf")) {
		//error
	}

	textMenu[0].setFont(font);
	textMenu[0].setFillColor(Color::Red);
	textMenu[0].setString("Start");
	textMenu[0].setCharacterSize(40);
	textMenu[0].setPosition(Vector2f(w / 4, h / (MAX_NUMBER_OF_ITEMS + 1) * 0.5));
	textMenu[1].setFont(font);
	textMenu[1].setFillColor(Color::White);
	textMenu[1].setString("About");
	textMenu[1].setCharacterSize(40);
	textMenu[1].setPosition(Vector2f(w / 4, h / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	textMenu[2].setFont(font);
	textMenu[2].setFillColor(Color::White);
	textMenu[2].setString("Quit");
	textMenu[2].setCharacterSize(40);
	textMenu[2].setPosition(Vector2f(w / 4, h / (MAX_NUMBER_OF_ITEMS + 1) * 1.5));

	selectedItemIndex = 0;

	
	

	background;
	if (!background.loadFromFile("spaceBackGround.png"))
	{
		//error
	}
	imagebackground.setTexture(background);
	imagebackground.setPosition(0, 0);

	//pour mettre un image en plein ecran
	sf::Vector2f targetSize(w, h);
	imagebackground.setScale(
		targetSize.x / imagebackground.getLocalBounds().width,
		targetSize.y / imagebackground.getLocalBounds().height);
}


HomePage::~HomePage()
{
}

void HomePage::draw(RenderWindow &window)
{
	window.draw(imagebackground);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(textMenu[i]);
		
	}
	
}

void HomePage::moveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		textMenu[selectedItemIndex].setFillColor(Color::White);
		textMenu[selectedItemIndex].setCharacterSize(40);
		selectedItemIndex--;
		textMenu[selectedItemIndex].setFillColor(Color::Red);
		textMenu[selectedItemIndex].setCharacterSize(60);
	}
}

void HomePage::moveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		textMenu[selectedItemIndex].setFillColor(Color::White);
		textMenu[selectedItemIndex].setCharacterSize(40);
		selectedItemIndex++;
		textMenu[selectedItemIndex].setFillColor(Color::Red);
		textMenu[selectedItemIndex].setCharacterSize(60);
	}
}