#include "Input.h"

#include <iostream>

Input::Input():
m_mouseHover(false),
m_mouseClicked(false),
m_position(sf::Vector2f(0,0)),
m_size(sf::Vector2f(0,0))
{
    
}

Input::Input(sf::Vector2f position, sf::Vector2f size):
m_mouseHover(false),
m_mouseClicked(false),
m_position(position),
m_size(size)
{

}


Input::~Input()
{
    
}

sf::Vector2f Input::getPosition()const
{
    return m_position;
}

sf::Vector2f Input::getSize()const
{
    return m_size;
}

void Input::setPosition(sf::Vector2f position)
{
    m_position = position;
}

void Input::setPosition(int x, int y)
{
    
    m_position.x = x;
    m_position.y = y;
}

void Input::setSize(sf::Vector2f size)
{
    m_size = size;
}

void Input::setSize(int x, int y)
{
    m_size.x = x;
    m_size.y = y;
}