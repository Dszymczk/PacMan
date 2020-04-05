#include "Intersection.h"

Intersection::Intersection(int x, int y, bool nOK, bool sOK, bool eOK, bool wOK)
{
    Intersection::position.x = x;
    Intersection::position.y = y;
    Intersection::nOK = nOK;
    Intersection::sOK = sOK;
    Intersection::eOK = eOK;
    Intersection::wOK = wOK;

}

Intersection::~Intersection()
{
    //dtor
}

void Intersection::DrawIntersection(sf::RenderWindow &appWindow)
{
    sf::CircleShape shape(30, 4);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(Intersection::position.x, Intersection::position.y);
    appWindow.draw(shape);
}

sf::Vector2f Intersection::GetPosition()
{
    return Intersection::position;
}

bool Intersection::CheckDirection(char direction)
{
    if ( direction == 'n' )
        return nOK;
    else if ( direction == 's' )
        return sOK;
    else if ( direction == 'e' )
        return eOK;
    else if ( direction == 'w' )
        return wOK;
    else
        return 0;

}
