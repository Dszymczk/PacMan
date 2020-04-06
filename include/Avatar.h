#ifndef AVATAR_H
#define AVATAR_H
#include <vector>
#include "Character.h"
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <Intersections.h>
#include <Intersection.h>


class Avatar : public Character
{
    static const int windowHeight = 800;
    static const int WindowWidth = 800;
    // zmienna opisuj�ca stan avatara. Normalny, lub ulepszony po zdobyciu powerupu
	std::string state;
	// zmienna klasy Player opisuj�ca do kt�rego gracza nale�y avatar
	//Player player;
	// Zmienna przechowuj�ca liczb� punkt�w gracza
	int pointsNumber;
	// Zmienna przechowuj�ca informacj� o kierunku poruszania si� obiektu
	char direction;
	// Parameter storing information about next direction
	char directionBuffer;
	// Zmienna przechowuj�ca informacj� o pr�dko�ci obiektu
	int velocity;
	bool stopped;
	// Zmienna przechowujaca informacje o pozycji na planszy
	sf::Vector2f position;
	// Obiekt przechowujacy teksture
	sf::Texture texture;
	public:
	//
	sf::Sprite sprite;

    public:
    // Tablica przechowuj�ca wszystkie obiekty klasy Avatar
	static std::vector <Avatar> avatars_tab;
    Avatar();
    virtual ~Avatar();
	// Metoda obs�uguj�ca kolizje z innymi obiektami dziedzicz�cymi po klasie character
	void Colision();
	// Metoda obsluguj�ca natrafienie na obiekt klasy Object - punkt lub powerup
	void ObjectColision();
	// Metoda obs�uguj�ca natrafienie na punkt
	void Score(int pointsNumber);
	// Metoda obs�uguj�ca natrafienie na powerup
	void Powerup();
	// Metoda odpowiadaj�ca za ruch jednostek
	void Move();
	// Method checking if avatar isn't outside game window
	//
	// returns 0 if avatar position is correct and return 1 if avatar position is outside window
	bool AvatarPositionExceedsWindow();

	// Metoda obs�uguj�ca zmian� kierunku ruchu
	void ChangeDirection(char new_direction);

	//
	void ChangeDirectionBuffer(char new_direction);

	// Metoda obslugujaca spotkanie z duchem - przegrana gracza, lub zdobycie dodatkowych punkt�w, zale�nie od stanu
	void GhostColision();

	// Metoda obs�uguj�ca spotkanie z innym graczem - zmiana kierunku ruchu
	void AvatarColision();

	// Method that detects if avatar comes across intersection and returns its number in tab
	// If interectin wasnt detected then returns -1
	int DetectIntersection(Intersections Tab);

	void IntersectionAction(Intersections intersectionsTab);

	// Metoda zwracajaca pozycje
	sf::Vector2f GetPosition();

	// Method seeting Avatar::position parameter to x, y and alsa chnging position of sprite in window coordinates
	//
	// Parameters
	// x - first coordinate in cartesian coordinate system
	// y - second coordinate in cartesian coordinate system
	void SetPosition(float x, float y);
	// Draw avatar in sf::Window window
	void Draw(sf::RenderWindow &appWindow);
	// Returns directionBuffer
	char GetDirectionBuffer();
	// Returns direction
	char GetDirection();
	//Reset directionBuffer
	void ResetDirectionBuffer();
	// Stops avatar
	void Stop();


};

#endif // AVATAR_H
