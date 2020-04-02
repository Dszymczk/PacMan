#ifndef AVATAR_H
#define AVATAR_H
#include <vector>
#include "Character.h"
#include <string>
#include <SFML/Graphics.hpp>


class Avatar : public Character
{
    static const int window_height = 600;
    static const int window_width = 800;
    // zmienna opisuj¹ca stan avatara. Normalny, lub ulepszony po zdobyciu powerupu
	std::string state;
	// zmienna klasy Player opisuj¹ca do którego gracza nale¿y avatar
	//Player player;
	// Zmienna przechowuj¹ca liczbê punktów gracza
	int points_number;
	// Zmienna przechowuj¹ca informacjê o kierunku poruszania siê obiektu
	char direction;
	// Zmienna przechowuj¹ca informacjê o prêdkoœci obiektu
	int velocity;
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
	void object_colision();
	// Metoda obs³uguj¹ca natrafienie na punkt
	void Score(int points_number);
	// Metoda obs³uguj¹ca natrafienie na powerup
	void Powerup();
	// Metoda odpowiadaj¹ca za ruch jednostek
	void Move();
	// Method checking if avatar isn't outside game window
	//
	// returns 0 if avatar position is correct and return 1 if avatar position is outside window
	bool Avatar_position_exceeds_window();
	// Metoda obs³uguj¹ca zmianê kierunku ruchu
	void Change_direction(char new_direction);
	// Metoda obslugujaca spotkanie z duchem - przegrana gracza, lub zdobycie dodatkowych punktów, zale¿nie od stanu
	void Ghost_colision();
	// Metoda obs³uguj¹ca spotkanie z innym graczem - zmiana kierunku ruchu
	void Avatar_colision();
	// Metoda wykrywaj¹ca skrzy¿owania
	void Detect_intersection();
	// Metoda zwracajaca pozycje
	sf::Vector2f Get_position();

	// Method seeting Avatar::position parameter to x, y and alsa chnging position of sprite in window coordinates
	//
	// Parameters
	// x - first coordinate in cartesian coordinate system
	// y - second coordinate in cartesian coordinate system
	void Set_position(float x, float y);
	// Draw avatar in sf::Window window
	void Draw(sf::RenderWindow &appWindow);


};

#endif // AVATAR_H
