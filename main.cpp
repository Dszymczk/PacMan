#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "TMP.h"
#include "Character.h"
#include "Avatar.h"
#include "EventHandler.h"
#include "Intersections.h"


int main()
{
    // Setting application windwo
    sf::RenderWindow applicationWindow( sf::VideoMode( 800, 600, 32 ), "Kurs SFML 2.0 - http://cpp0x.pl" );
    applicationWindow.setFramerateLimit(200);

    //Setting avatar
    Avatar avatar1;

    //Intersection(int x, int y, bool nOK, bool sOK, bool eOK, bool wOK);
    // Setting Intersections
    Intersections intersectionsTab;
    intersectionsTab.AddIntersection(1, 100, 0, 0, 1, 0);
    intersectionsTab.AddIntersection(100, 1, 0, 1, 0, 1);
    intersectionsTab.AddIntersection(100, 100, 1, 0, 0, 1);




    // Setting event handler
    EventHandler event(applicationWindow, avatar1);

    // Main game loop
    while( applicationWindow.isOpen() )
    {
        event.HandleEvents();
        avatar1.IntersectionAction(intersectionsTab);
        avatar1.Move();


        applicationWindow.clear( sf::Color::Black );
        avatar1.Draw(applicationWindow);
        //intersection.DrawIntersection(applicationWindow);
        intersectionsTab.DrawAllIntersections(applicationWindow);


        applicationWindow.display();
    }

    return 0;
}
