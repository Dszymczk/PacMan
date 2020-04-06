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
    // zmienna opisuj¹ca stan avatara. Normalny, lub ulepszony po zdobyciu powerupu
	std::string state;
	// zmienna klasy Player opisuj¹ca do którego gracza nale¿y avatar
	//Player player;
	// Zmienna przechowuj¹ca liczbê punktów gracza
	int pointsNumber;
	// Zmienna przechowuj¹ca informacjê o kierunku poruszania siê obiektu
	char direction;
	// Parameter storing information about next direction
	char directionBuffer;
	// Zmienna przechowuj¹ca informacjê o prêdkoœci obiektu
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
    // Tablica przechowuj¹ca wszystkie obiekty klasy Avatar
	static std::vector <Avatar> avatars_tab;
    Avatar();
    virtual ~Avatar();
	// Metoda obs³uguj¹ca kolizje z innymi obiektami dziedzicz¹cymi po klasie character
	void Colision();
	// Metoda obsluguj¹ca natrafienie na obiekt klasy Object - punkt lub powerup
	void ObjectColision();
	// Metoda obs³uguj¹ca natrafienie na punkt
	void Score(int pointsNumber);
	// Metoda obs³uguj¹ca natrafienie na powerup
	void Powerup();
	// Metoda odpowiadaj¹ca za ruch jednostek
	void Move();
	// Method checking if avatar isn't outside game window
	//
	// returns 0 if avatar position is correct and return 1 if avatar position is outside window
	bool AvatarPositionExceedsWindow();

	// Metoda obs³uguj¹ca zmianê kierunku ruchu
	void ChangeDirection(char new_direction);

	//
	void ChangeDirectionBuffer(char new_direction);

	// Metoda obslugujaca spotkanie z duchem - przegrana gracza, lub zdobycie dodatkowych punktów, zale¿nie od stanu
	void GhostColision();

	// Metoda obs³uguj¹ca spotkanie z innym graczem - zmiana kierunku ruchu
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
