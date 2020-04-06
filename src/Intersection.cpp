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
    int dimension = 30;
    sf::CircleShape shape(dimension, 4);
    shape.setFillColor(sf::Color(100, 250, 50));
    shape.setPosition(Intersection::position.x, Intersection::position.y);
    appWindow.draw(shape);
    if(!Intersection::nOK == 1)
    {
        sf::CircleShape shapeN(dimension/3, 4);
        shapeN.setFillColor(sf::Color(250, 0, 0));
        shapeN.setPosition(Intersection::position.x + int(dimension / 2 * 1.42), Intersection::position.y-dimension/3);
        appWindow.draw(shapeN);
    }
    if(!Intersection::sOK == 1)
    {
        sf::CircleShape shapeN(dimension/3, 4);
        shapeN.setFillColor(sf::Color(250, 0, 0));
        shapeN.setPosition(Intersection::position.x + int(dimension / 2 * 1.42), Intersection::position.y+dimension*1.41+dimension/4);
        appWindow.draw(shapeN);
    }
    if(! Intersection::wOK == 1)
    {
        sf::CircleShape shapeN(dimension/3, 4);
        shapeN.setFillColor(sf::Color(250, 0, 0));
        shapeN.setPosition(Intersection::position.x - dimension/3, Intersection::position.y + dimension*1.41/2);
        appWindow.draw(shapeN);
    }
    if(!Intersection::eOK == 1)
    {
        sf::CircleShape shapeN(dimension/3, 4);
        shapeN.setFillColor(sf::Color(250, 0, 0));
        shapeN.setPosition(Intersection::position.x +1.41* dimension + dimension/3, Intersection::position.y  + dimension*1.41/2);
        appWindow.draw(shapeN);
    }
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
