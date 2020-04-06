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

void Intersections::Map1()
{
    this->AddIntersection( 50, 250, 0, 1,1,0 );   //1
    this->AddIntersection( 250, 250,  1,0,0,1);//2
    this->AddIntersection(250, 50 , 0,1,1,0);//3
    this->AddIntersection( 450, 50 , 0,1,0,1);//4
    this->AddIntersection( 450, 250, 1,1,1,0);//5
    this->AddIntersection( 650, 250, 0,1,0,1);//6
    this->AddIntersection( 650, 450, 1,0,0,1);//7
    this->AddIntersection( 450, 450, 1,1,1,0);//8
    this->AddIntersection(450, 650, 1, 0, 0, 1);
    this->AddIntersection( 250, 450, 0,1,0,1);//9
    this->AddIntersection( 250, 650, 1,0,1,0);//10
    this->AddIntersection( 50, 450, 1,0,1,0);//11
    //this->AddIntersection( , , , , , , );//12
    //this->AddIntersection( , , , , , , );//13
    //this->AddIntersection( , , , , , , );//14
    //this->AddIntersection( , , , , , , );//15
}
