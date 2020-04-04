#include "Avatar.h"
//Below directives are already used in headers file
//#include <SFML/Window.hpp>
//#include <SFML/Graphics.hpp>
//#include <iostream>

Avatar::Avatar()
{
    Avatar::direction = 'e';
    Avatar::velocity = 1;
    if (!Avatar::texture.loadFromFile("Circle.png"))
        std::cout<<"Cannot load file \"" <<"jakis plik" <<"to Avatar";
        // Trzeba wstawic do klasy zmienna string z nazwa pliku do wczytania
    sf::Sprite sprite;
    Avatar::sprite.setTexture(texture);
    Avatar::SetPosition(1, 1);
    std::cout<<"Avatar object constructed";
}

Avatar::~Avatar()
{
    //dtor
}


// Metoda obs³uguj¹ca kolizje z innymi obiektami dziedzicz¹cymi po klasie character
void Avatar::Colision()
{

}

// Metoda obsluguj¹ca natrafienie na obiekt klasy Object - punkt lub powerup
void Avatar::ObjectColision()
{

}

// Metoda obs³uguj¹ca natrafienie na punkt
void Avatar::Score(int pointsNumber)
{

}

// Metoda obs³uguj¹ca natrafienie na powerup
void Avatar::Powerup()
{

}

// Metoda odpowiadaj¹ca za ruch jednostek
void Avatar::Move()
{
    float x = Avatar::position.x;
    float y = Avatar::position.y;
    // If avatar exceeds window change direction to oposite
    if( Avatar::AvatarPositionExceedsWindow())
    {
        std::cout<<"Avatar position exceeds window range!\n";
        switch(Avatar::direction)
        {
        case 'n':
            //Avatar::direction = 's';
            this->ChangeDirection('s');
            break;
        case 's':
            //Avatar::direction = 'n';
            this->ChangeDirection('n');
            break;
        case 'w':
            //Avatar::direction = 'e';
            this->ChangeDirection('e');
            break;
        case 'e':
            //Avatar::direction = 'w';
            this->ChangeDirection('w');
            break;
        }
    }
    switch(Avatar::direction)
    {
    case 'n':
        y -= Avatar::velocity;
        break;
    case 's':
        y += Avatar::velocity;
        break;
    case 'w':
        x -= Avatar::velocity;
        break;
    case 'e':
        x += Avatar::velocity;
        break;
    }
    this ->SetPosition(x, y);

}

bool Avatar::AvatarPositionExceedsWindow()
{
    float x = Avatar::position.x;
    float y = Avatar::position.y;
    if( x <= 0 || x >= Avatar::WindowWidth
       || y <= 0 || y >= Avatar::windowHeight)
       {
           //std::cout<<"x: " <<x << "y: " <<y <<std::endl;
        return 1;
       }
    else
        return 0;
}

// Metoda obs³uguj¹ca zmianê kierunku ruchu
void Avatar::ChangeDirection(char new_direction)
{
    if( new_direction == 's'
       || new_direction == 'n'
       || new_direction == 'e'
       || new_direction == 'w')
       std::cout<<"Old direction"<<Avatar::direction<<std::endl;
        Avatar::direction = new_direction;
        std::cout<<"Old direction"<<Avatar::direction<<std::endl;
}

void Avatar::GhostColision()
{

}

void Avatar::AvatarColision()
{

}

void Avatar::DetectIntersection()
{

}

sf::Vector2f Avatar::GetPosition()
{

}

void Avatar::SetPosition(float x, float y)
{
    Avatar::position.x = x;
    Avatar::position.y = y;
    Avatar::sprite.setPosition(Avatar::position);
}

void Avatar::Draw(sf::RenderWindow &appWindow)
{
    appWindow.draw(Avatar::sprite);
}
