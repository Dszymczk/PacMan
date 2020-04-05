#include "EventHandler.h"



EventHandler::EventHandler(sf::RenderWindow &appWindow, Avatar &plAvatar)
{
    EventHandler::appWindow = &appWindow;
    EventHandler::plAvatar = &plAvatar;
}

EventHandler::~EventHandler()
{
    //dtor
}

void EventHandler::HandleEvents()
{
    //EventHandler::appWindow->display();
    while( this->IfEventOccurs() )
    {
        if( EventHandler::IfCloseWindow() )
            EventHandler::appWindow->close();
        if( char newDirection = EventHandler::IfChangeDirectionBuffer())
        {
            EventHandler::plAvatar->ChangeDirectionBuffer(newDirection);
        }
    }

}

bool EventHandler::IfEventOccurs()
{
    return EventHandler::appWindow->pollEvent( EventHandler::event );
}

bool EventHandler::IfCloseWindow()
{
    bool closeButtonClicked = EventHandler::event.type == sf::Event::Closed;
    bool escPressed = EventHandler::event.type == sf::Event::KeyPressed && EventHandler::event.key.code == sf::Keyboard::Escape;
    return closeButtonClicked || escPressed;
}

char EventHandler::IfChangeDirectionBuffer()
{
    bool upArrowPressed =  EventHandler::event.type == sf::Event::KeyPressed && EventHandler::event.key.code == sf::Keyboard::Up;
    bool downArrowPressed =  EventHandler::event.type == sf::Event::KeyPressed && EventHandler::event.key.code == sf::Keyboard::Down;
    bool rightArrowPressed =  EventHandler::event.type == sf::Event::KeyPressed && EventHandler::event.key.code == sf::Keyboard::Right;
    bool leftArrowPressed =  EventHandler::event.type == sf::Event::KeyPressed && EventHandler::event.key.code == sf::Keyboard::Left;

    if(upArrowPressed)
        return 'n';
    else if(downArrowPressed)
        return 's';
    else if(rightArrowPressed)
        return 'e';
    else if(leftArrowPressed)
        return 'w';
    else
        return false;
}
