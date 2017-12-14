#include "stdafx.h"
#include "About.h"


About::About(float w, float h)
{
	if (!font.loadFromFile("arial.ttf")) {
		//error
	}
	sf::Color color(149, 6, 1);

	// choix de la police à utiliser
	text.setFont(font); // font est un sf::Font
	text2.setFont(font);
	text3.setFont(font);
	// choix de la chaîne de caractères à afficher
	text.setString("A propos de nom de votre programme");
	text2.setString("Jeu réalisé par Verfaillie Julie, Lecouvet Thibaut et Moussaoui Aymen, \nétudiants de la HELHa Campus Mons, \ndans le cadre du cours de Mr.V.Altares.");
	text3.setString("Ce jeu a été créé en hommage à l'équipage des missions lunaires Apollo. Merci");
	// choix de la taille des caractères
	text.setCharacterSize(30); // exprimée en pixels, pas en points !
	text2.setCharacterSize(20);						   // choix de la couleur du texte
	text3.setCharacterSize(20);
	text.setFillColor(color);
	text2.setFillColor(Color::Black);
	text3.setFillColor(color);
	// choix du style du texte
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setPosition(Vector2f(w / 15, h /4 ));
	text2.setPosition(Vector2f(w / 15, h / 3 ));
	text2.setStyle(Text::Bold);
	text3.setPosition(Vector2f(w / 15, h / 1.2));
	text3.setStyle(Text::Bold);

	
	if (!backgroundGame.loadFromFile("apolo13.jpg"))
	{
		//Error
	}
	imagebackground.setTexture(backgroundGame);
	imagebackground.setPosition(0, 0);
	//pour mettre un image en plein ecran
	sf::Vector2f targetSize(w, h);
	imagebackground.setScale(
		targetSize.x / imagebackground.getLocalBounds().width,
		targetSize.y / imagebackground.getLocalBounds().height);
}


About::~About()
{
}

void About::draw(RenderWindow &window)
{
	window.draw(imagebackground);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
}