#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TMP.h"
#include "Character.h"
#include "Avatar.h"
#include "EventHandler.h"





int main()
{
    char tmp = false;
    if (tmp)
    {
        std::cout<<"cos tam"<<tmp<<std::endl<<std::endl;
    }
    int *wsk;
    int liczba = 1;
    wsk = &liczba;
    std::cout << *wsk;
    sf::RenderWindow applicationWindow( sf::VideoMode( 800, 600, 32 ), "Kurs SFML 2.0 - http://cpp0x.pl" );
    applicationWindow.setFramerateLimit(200);

    Avatar avatar1;
    EventHandler event(applicationWindow, avatar1);
    avatar1.Move();
    while( applicationWindow.isOpen() )
    {
        avatar1.Move();

        event.HandleEvents();
        applicationWindow.clear( sf::Color::Black );
        avatar1.Draw(applicationWindow);


        applicationWindow.display();
    }

    //TMP_func();
    return 0;
}
