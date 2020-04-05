#include "Intersections.h"

Intersections::Intersections()
{
    //ctor
}

Intersections::~Intersections()
{
    //dtor
}

void Intersections::AddIntersection(int newX, int newY, bool newNOK, bool newSOK, bool newEOK, bool newWOK )
{
    Intersection newIntersection = Intersection(newX, newY, newNOK, newSOK, newEOK, newWOK);
    tab.push_back(newIntersection);
}

int Intersections::GetTabSize()
{
    return Intersections::tab.size();
}

Intersection Intersections::GetIntersectionById(int id)
{
    return this->tab[id];
}

void Intersections::DrawAllIntersections(sf::RenderWindow &appWindow)
{
    int length = this->GetTabSize();
    for(int i = 0; i < length; i++)
    {
        Intersections::tab[i].DrawIntersection(appWindow);
    }

}
