#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>


class Character
{
    private:

    int Id;

    public:
 	// Tablica przechowujaca wszystkie obiekty dzieziczące po klasie character
    static std::vector <Character> charactersTab;
    // Konstruktor
    Character();
    // Destruktor
    virtual ~Character();
    // Metoda odpowiadająca za ruch jednostek
	virtual void Move();
	// Metoda odpowiadająca za kolizję z innymi obiektami klasy character
	virtual void DetectColision();
	// Metoda wykrywająca skrzyżowania
	virtual void DetectIntersection();

};

#endif // CHARACTER_H
