#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TMP.h"
#include "Character.h"
#include "Avatar.h"





int main()
{
    if ( 's' )
        std::cout << " Przeszlo";
    sf::RenderWindow applicationWindow( sf::VideoMode( 800, 600, 32 ), "Kurs SFML 2.0 - http://cpp0x.pl" );
    applicationWindow.setFramerateLimit(60);
    sf::Event zdarzenie;
    Avatar avatar1;
    avatar1.Move();
    while( applicationWindow.isOpen() )
    {
        avatar1.Move();
        while( applicationWindow.pollEvent( zdarzenie ) )
        {
            if( zdarzenie.type == sf::Event::Closed )
                 applicationWindow.close();
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 applicationWindow.close();
        }
        applicationWindow.clear( sf::Color::Black );
        avatar1.Draw(applicationWindow);


        applicationWindow.display();
    }

    //TMP_func();
    return 0;
}
