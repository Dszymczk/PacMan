#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>


void TMP_func()
{
    sf::RenderWindow oknoAplikacji( sf::VideoMode( 800, 600, 32 ), "Kurs SFML 2.0 - http://cpp0x.pl" );
    oknoAplikacji.setFramerateLimit(60);
    sf::Vector2f pozycja(0, 0);
    char kierunek;
    kierunek = 'a';
    int v = 5;
    std::cout << "Hello";
    while( oknoAplikacji.isOpen() )
    {
        sf::Texture tekstura;
        tekstura.loadFromFile( "Circle.png" );
        sf::Event zdarzenie;

        sf::Sprite obrazek; //INFO: dopisane w tym rozdziale
        obrazek.setTexture( tekstura ); //INFO: dopisane w tym rozdziale
        obrazek.setPosition(pozycja);

        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {

            if( zdarzenie.type == sf::Event::Closed )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 obrazek.move(-1, 0);//oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
                 oknoAplikacji.close();

            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Left)
            {
                kierunek = 'l'; //obrazek.move(-1, 0);
            }
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Right)
            {
                kierunek = 'p';//obrazek.move(1, 0);
            }
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up)
            {
                kierunek = 'g';//obrazek.move(0, 1);
            }
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down)
            {
                kierunek = 'd';//obrazek.move(0, -1);
            }



        }


        if( kierunek == 'l')
            {
                obrazek.move(-v, 0);
            }
            if( kierunek == 'p')
            {
                obrazek.move(v, 0);
            }
            if( kierunek == 'd')
            {
                obrazek.move(0, v);
            }
            if( kierunek == 'g')
            {
                obrazek.move(0, -v);
            }
            pozycja = obrazek.getPosition();
        oknoAplikacji.clear( sf::Color::Black );

        oknoAplikacji.draw( obrazek); //INFO: dopisane w tym rozdziale
        oknoAplikacji.display();
    }
}
