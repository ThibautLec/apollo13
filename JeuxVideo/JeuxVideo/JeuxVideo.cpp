// ProjSFML.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "AnimatedSprite.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "HomePage.h"
#include "GameOverPage.h"
#include "LogInPage.h"
#include "About.h"
#include "Collision.h"
#include <SFML/Audio.hpp>
using namespace sf;
using std::cout;
using std::endl;




int main()
{


	// setup window
	Vector2i screenDimensions(1000, 600);
	RenderWindow window(VideoMode(screenDimensions.x, screenDimensions.y), "Animations!");

	HomePage gopage(window.getSize().x, window.getSize().y);
	GameOverPage endpage(window.getSize().x, window.getSize().y);
	LogInPage logpage(window.getSize().x, window.getSize().y);
	About aboutpage(window.getSize().x, window.getSize().y);

	window.setFramerateLimit(60);

	int statut = 0;
	String m_saisie;
	sf::Clock time, time2;
	Text inputName;
	Font font;
	if (!font.loadFromFile("arial.ttf")) {
		//error
	}
	inputName.setFont(font);
	inputName.setPosition(Vector2f(window.getSize().x / 3, window.getSize().y / 4));


	// load texture (spritesheet)
	Texture texture;
	if (!texture.loadFromFile("rocket-flames-96.png"))
	{
		cout << "Failed to load player spritesheet!" << std::endl;
		return -1;
	}
	
	Texture background2;
	if (!background2.loadFromFile("explosion-in-space.jpg"))
	{
		cout << "Failed to load player spritesheet!" << std::endl;
		return -1;
	}
	Texture backgroundGame;
	if (!backgroundGame.loadFromFile("espace.jpg"))
	{
		cout << "Failed to load player spritesheet!" << std::endl;
		return -1;
	}
	// Chargement des images ( 3 au total )
	Texture home;

	if (!home.loadFromFile("home.gif"))
		return EXIT_FAILURE;
	// Creation des sprites ( 7 au total )
	Sprite menuStart, menuQuitter, btnHome;
	
	Sprite imagebackground2(background2);
	Sprite imagebackGame(backgroundGame);

	Texture test;
	if (!test.loadFromFile("quitter.png", sf::IntRect(10, 10, 50, 50)))
	{
		// erreur...
	}
	Sprite testSprite;
	testSprite.setTexture(test);
	testSprite.setPosition(200, 200);
	btnHome.setTexture(home);
	btnHome.setPosition(0, 0);

	
	


	// set up the animations for all four directions (set spritesheet and push frames)
	Animation walkingAnimationDown;
	walkingAnimationDown.setSpriteSheet(texture);
	walkingAnimationDown.addFrame(IntRect(1, 0, 97, 122));
	walkingAnimationDown.addFrame(IntRect(112, 0, 82, 122));
	walkingAnimationDown.addFrame(IntRect(196, 0, 88, 122));
	walkingAnimationDown.addFrame(IntRect(283, 0, 88, 122));

	Animation walkingAnimationLeft;
	walkingAnimationLeft.setSpriteSheet(texture);
	walkingAnimationLeft.addFrame(IntRect(1, 0, 97, 122));
	walkingAnimationLeft.addFrame(IntRect(112, 0, 82, 122));
	walkingAnimationLeft.addFrame(IntRect(196, 0, 88, 122));
	walkingAnimationLeft.addFrame(IntRect(283, 0, 88, 122));

	Animation walkingAnimationRight;
	walkingAnimationRight.setSpriteSheet(texture);
	walkingAnimationRight.addFrame(IntRect(1, 0, 97, 122));
	walkingAnimationRight.addFrame(IntRect(112, 0, 82, 122));
	walkingAnimationRight.addFrame(IntRect(196, 0, 88, 122));
	walkingAnimationRight.addFrame(IntRect(283, 0, 88, 122));

	Animation walkingAnimationUp;
	walkingAnimationUp.setSpriteSheet(texture);
	walkingAnimationUp.addFrame(IntRect(4, 154, 88, 153));
	walkingAnimationUp.addFrame(IntRect(109, 154, 88, 153));
	walkingAnimationUp.addFrame(IntRect(197, 154, 88, 153));
	walkingAnimationUp.addFrame(IntRect(282, 154, 88, 153));

	Animation* currentAnimation = &walkingAnimationDown;

	// set up AnimatedSprite
	AnimatedSprite animatedSprite(seconds(0.2), true, false);
	animatedSprite.setPosition(Vector2f(screenDimensions / 2));

	Clock frameClock;

	float speed = 80.f;
	bool noKeyWasPressed = true;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
			if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape)
				window.close();

			switch (event.type)
			{
			case Event::KeyReleased:
				switch (event.key.code)
				{
				case Keyboard::Up: gopage.moveUp(); break;

				case Keyboard::Down: gopage.moveDown(); break;

				case Keyboard::Return:
					
					switch (gopage.getPressedItem())
					{
					case 0: cout << "Okay let's start a new game !" << endl;
						statut = 1;
						break;
					case 1: cout << "Let's go to the home page nigga !" << endl; 
						statut = 3;
						break;
					case 2: cout << "Ya, good idea, save that !" << endl; 
						window.close();break;
					}
					break;
					
				}
				break;

			case Event::Closed: window.close(); break;
			}
		}


		Time frameTime = frameClock.restart();

		//Définis la "zone" du sprite

		FloatRect boundingBoxHome = endpage.getPositionBtnHome();


		//Convertis un Vector2i en Vector2f 
		Vector2i Mouseosition = Mouse::getPosition(window);
		Vector2f MousePosition = static_cast<Vector2f>(Mouseosition);


		// if a key was pressed set the correct animation and move correctly
		Vector2f movement(0.f, 0.f);
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			currentAnimation = &walkingAnimationUp;
			movement.y -= speed;
			noKeyWasPressed = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Down))
		{
			currentAnimation = &walkingAnimationDown;
			movement.y += speed;
			noKeyWasPressed = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			currentAnimation = &walkingAnimationLeft;
			movement.x -= speed;
			noKeyWasPressed = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			currentAnimation = &walkingAnimationRight;
			movement.x += speed;
			noKeyWasPressed = false;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::T))
		{
			testSprite.setPosition(100, 100);
		}
		if (Keyboard::isKeyPressed(Keyboard::G))
		{
			testSprite.setPosition(200, 200);
		}
		if (boundingBoxHome.contains(MousePosition) && Mouse::isButtonPressed(Mouse::Left)) { //si la sourie est dans la "zone"																						 
			cout << "HOMEEEEEEEEEEEEEE" << endl;
			statut = 0;
		}

		animatedSprite.play(*currentAnimation);
		animatedSprite.move(movement * frameTime.asSeconds());

		// if no key was pressed stop the animation
		if (noKeyWasPressed)
		{
			animatedSprite.stop();
		}
		noKeyWasPressed = true;
		
		if (Collision::PixelPerfectTest(testSprite, btnHome)) {
			cout << "Collision" << endl;
			statut = 2;
		}
		else {
			cout << "NO Collision" << endl;
		}
		
	

		// update AnimatedSprite
		animatedSprite.update(frameTime);
		if (statut == 0) {
			// gestion du menu démarer...
			window.clear();
			gopage.draw(window);
			window.display();
		}
		else if (statut == 1)
		{

			// gestion du jeu (déplacements, ...)
			window.clear();
			window.draw(imagebackGame);
			window.draw(animatedSprite);
			window.draw(btnHome);
			window.draw(testSprite);
			window.display();
		}
		else if (statut == 2) {
			// gestion des menus fin du jeu
			testSprite.setPosition(200, 200);
			window.clear();
		
			endpage.draw(window);
			window.display();
		}
		else if (statut == 3) {
			window.clear();
			aboutpage.draw(window);
			window.display();
			/*
			//SAISIE TEXT
			if (time.getElapsedTime().asMilliseconds() >= 150)
			{
				if (event.type == sf::Event::TextEntered)
				{
					if ((event.text.unicode > 30 && (event.text.unicode < 128 || event.text.unicode > 159)))
					{
						m_saisie += sf::String(event.text.unicode);
						inputName.setString(m_saisie);
					}
					sf::Time frameTime = time.restart();
				}
				if (Keyboard::isKeyPressed(Keyboard::BackSpace)) {
					//String s = m_saisie;
					int taille = m_saisie.getSize();
					if (taille > 0) {
						m_saisie.erase(taille - 1, 1);
						inputName.setString(m_saisie);
						cout << "DELETE + " << taille << endl;
					}
					

				}
				
			}
			
			
			window.clear();
			logpage.draw(window);
			window.draw(inputName);
			window.display();*/
		}




	}
	return EXIT_SUCCESS;
}

