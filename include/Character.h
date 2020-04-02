#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>


class Character
{
    private:

    int Id;

    public:
 	// Tablica przechowujaca wszystkie obiekty dzieziczące po klasie character
    static std::vector <Character> characters_tab;;
    // Konstruktor
    Character();
    // Destruktor
    virtual ~Character();
    // Metoda odpowiadająca za ruch jednostek
	virtual void Move();
	// Metoda odpowiadająca za kolizję z innymi obiektami klasy character
	virtual void Detect_colision();
	// Metoda wykrywająca skrzyżowania
	virtual void Detect_intersection();

};

#endif // CHARACTER_H
