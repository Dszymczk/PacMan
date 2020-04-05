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

    //Intersection intersection(10, 100, 0, 1, 0, 0);
    //intersection.DrawIntersection(applicationWindow);


    // Setting event handler
    EventHandler event(applicationWindow, avatar1);

    // Main game loop
    while( applicationWindow.isOpen() )
    {
        event.HandleEvents();
        avatar1.IntersectionAction(intersectionsTab);
        /*
        if( avatar1.DetectIntersection(intersectionsTab) >= 0)
        {
            // Intersection detected
            std::cout<<"Intersection Detected. Checking!" <<std::endl;
            int intersectionId = avatar1.DetectIntersection(intersectionsTab);
            if( intersectionsTab.tab[intersectionId].CheckDirection(avatar1.GetDirectionBuffer()))
            {
                // If bufferDirection is ok then change direction
                std::cout<<"Change direction"<<std::endl;
                avatar1.ChangeDirection(avatar1.GetDirectionBuffer());
                avatar1.ResetDirectionBuffer();
            }else if ( intersectionsTab.tab[intersectionId].CheckDirection(avatar1.GetDirection()))
            {
                // If buffer direction is not ok, but current direction is ok
                std::cout<<"can go further" <<std::endl;

            }else
            {
                std::cout<<"stop avatar"<<std::endl;
                avatar1.Stop();
            }

        }*/
        avatar1.Move();


        applicationWindow.clear( sf::Color::Black );
        avatar1.Draw(applicationWindow);
        //intersection.DrawIntersection(applicationWindow);
        intersectionsTab.DrawAllIntersections(applicationWindow);


        applicationWindow.display();
    }

    return 0;
}
