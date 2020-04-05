#ifndef INTERSECTION_H
#define INTERSECTION_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


class Intersection
{
    static const int height = 20;
    static const int width = 20;
    sf::Vector2f position;
    bool nOK;
    bool sOK;
    bool eOK;
    bool wOK;
    public:
        Intersection(int x, int y, bool nOK, bool sOK, bool eOK, bool wOK);
        virtual ~Intersection();

        void DrawIntersection(sf::RenderWindow &appWindow);

        // Method that returns intersection position
        sf::Vector2f GetPosition();

        // Method that checks if given direction is available on particular intersection
        bool CheckDirection(char direction);
    protected:

    private:

};

#endif // INTERSECTION_H
