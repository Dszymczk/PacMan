#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>


class Character
{
    private:

    int Id;

    public:
 	// Tablica przechowujaca wszystkie obiekty dziezicz�ce po klasie character
    static std::vector <Character> charactersTab;;
    // Konstruktor
    Character();
    // Destruktor
    virtual ~Character();
    // Metoda odpowiadaj�ca za ruch jednostek
	virtual void Move();
	// Metoda odpowiadaj�ca za kolizj� z innymi obiektami klasy character
	virtual void DetectColision();
	// Metoda wykrywaj�ca skrzy�owania
	virtual void DetectIntersection();

};

#endif // CHARACTER_H
