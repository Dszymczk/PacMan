#ifndef CHARACTER_H
#define CHARACTER_H
#include <vector>


class Character
{
    private:

    int Id;

    public:
 	// Tablica przechowujaca wszystkie obiekty dziezicz¹ce po klasie character
    static std::vector <Character> characters_tab;;
    // Konstruktor
    Character();
    // Destruktor
    virtual ~Character();
    // Metoda odpowiadaj¹ca za ruch jednostek
	virtual void Move();
	// Metoda odpowiadaj¹ca za kolizjê z innymi obiektami klasy character
	virtual void Detect_colision();
	// Metoda wykrywaj¹ca skrzy¿owania
	virtual void Detect_intersection();

};

#endif // CHARACTER_H
