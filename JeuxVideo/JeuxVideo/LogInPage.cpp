#include "stdafx.h"
#include "LogInPage.h"


LogInPage::LogInPage(float w, float h)
{
	if (!font.loadFromFile("arial.ttf")) {
		//error
	}
	
	name.setFont(font);	
	name.setString("Name");
	name.setCharacterSize(25);
	name.setFillColor(sf::Color::Red);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	name.setPosition(Vector2f(w / 10, h  / 4));

	password.setFont(font);
	password.setString("Password");
	password.setCharacterSize(25);
	password.setFillColor(sf::Color::Red);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	password.setPosition(Vector2f(w / 10, h /2  ));
	

	rectName.setPosition(Vector2f(w / 3, h / 4));
	rectName.setSize(sf::Vector2f(250, 50));
	rectName.setFillColor(Color::Blue);
	rectPassword.setPosition(Vector2f(w / 3, h / 2));
	rectPassword.setSize(sf::Vector2f(250, 50));
	rectPassword.setFillColor(Color::Blue);
}


LogInPage::~LogInPage()
{
}

void LogInPage::draw(RenderWindow &window)
{
	
	window.draw(name);
	window.draw(password);
	window.draw(rectName);
	window.draw(rectPassword);
}
