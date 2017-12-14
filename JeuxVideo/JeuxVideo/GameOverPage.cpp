#include "stdafx.h"
#include "GameOverPage.h"


GameOverPage::GameOverPage(float w, float h)
{
	if (!font.loadFromFile("arial.ttf")) {
		//error
	}

	textMenu[0].setFont(font);
	textMenu[0].setFillColor(Color::Red);
	textMenu[0].setString("Home");
	textMenu[0].setCharacterSize(40);
	textMenu[0].setPosition(Vector2f(w / 4, h / (MAX_NUMBER_OF_ITEMS + 1) * 0.5));
	textMenu[1].setFont(font);
	textMenu[1].setFillColor(Color::White);
	textMenu[1].setString("Restart");
	textMenu[1].setCharacterSize(40);
	textMenu[1].setPosition(Vector2f(w / 4, h / (MAX_NUMBER_OF_ITEMS + 1) * 1));
	textMenu[2].setFont(font);
	textMenu[2].setFillColor(Color::White);
	textMenu[2].setString("Save score");
	textMenu[2].setCharacterSize(40);
	textMenu[2].setPosition(Vector2f(w / 4, h / (MAX_NUMBER_OF_ITEMS + 1) * 1.5));

	selectedItemIndex = 0;
	//BOUTON HOME
	if (!btnHome.loadFromFile("home.png"))
	{
		//Error
	}
	imageHome.setTexture(btnHome);
	imageHome.setPosition(Vector2f(w / 6, h / 8));

	//BOUTON RESTART
	if (!btnRestart.loadFromFile("restart4.png"))
	{
		//Error
	}
	imageRestart.setTexture(btnRestart);
	imageRestart.setPosition(Vector2f(w / 1.2, h / 8));
	

	background;
	if (!background.loadFromFile("explosion-in-space.jpg"))
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




	
	text.setFont(font); 
	
	text.setString("You're such a loser !");
	text.setCharacterSize(40); 
	text.setFillColor(Color::Red);
	text.setStyle(sf::Text::Bold);
	text.setPosition(Vector2f(w / 3, h / 1.2));
	


}


GameOverPage::~GameOverPage()
{
}

void GameOverPage::draw(RenderWindow &window)
{
	window.draw(imagebackground);
	window.draw(imageHome);
	window.draw(imageRestart);
	window.draw(text);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		//window.draw(textMenu[i]);
	}
}

void GameOverPage::moveUp()
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

void GameOverPage::moveDown()
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
FloatRect GameOverPage::getPositionBtnHome() {
	return imageHome.getGlobalBounds();
}