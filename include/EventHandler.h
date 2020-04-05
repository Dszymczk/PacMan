#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <Avatar.h>


class EventHandler
{
        sf::Event event;
        sf::RenderWindow *appWindow;
        Avatar *plAvatar;

    public:
        // class constructor
        // Arguments:
        // sf::RenderWindow appWindow - main application window
        // Avatar plAvatar - avatar controlled by current user
        EventHandler(sf::RenderWindow &appWindow, Avatar &plAvatar);
        virtual ~EventHandler();


        // Method that checks input from user
        void HandleEvents();


    protected:

    private:

        //  Returns information if there is any input from user to handle
        //
        // Output:
        //True - There is
        //False - There is not
        bool IfEventOccurs();

        // Returns infrormation if Window should be closed
        //
        // Output:
        //True - There is
        //False - There is not
        bool IfCloseWindow();

        // Returns information if Avatar should change directionBuffer. If avatar should move return information about direction
        //
        // Output:
        //n, s, e, w - main directions
        //False - There is not
        char IfChangeDirectionBuffer();


};

#endif // EVENTHANDLER_H
