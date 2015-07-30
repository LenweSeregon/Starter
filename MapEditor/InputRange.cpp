#include "InputRange.h"
#include <iostream>


InputRange::InputRange(sf::Vector2f position, sf::Vector2f size, int currentVal):
Input(),
m_position(position),
m_size(size),
m_minValue(0),
m_maxValue(100),
m_reductionCoefficient(m_size.x/m_maxValue)
{
    if(currentVal < 0)
        m_value = 0;
    else if(currentVal > 100)
        m_value = 100;
    else
        m_value = currentVal;
    
    m_cursor.setFillColor(sf::Color::White);
    m_cursor.setOutlineThickness(2.0f);
    m_cursor.setSize(sf::Vector2f(10,m_size.y + 20));
    
    m_boundRectangle.setOutlineThickness(2.0f);
    m_boundRectangle.setOutlineColor(sf::Color::White);
    m_boundRectangle.setFillColor(sf::Color::Black);
    m_boundRectangle.setPosition(m_position);
    m_boundRectangle.setSize(m_size);
    
    m_volumeRectangle.setOutlineThickness(2.0f);
    m_volumeRectangle.setOutlineColor(sf::Color::White);
    m_volumeRectangle.setFillColor(sf::Color::Yellow);
    m_volumeRectangle.setPosition(m_position);
    m_volumeRectangle.setSize(sf::Vector2f((m_boundRectangle.getGlobalBounds().width*currentVal)/100,m_size.y));
    
    setCursorPosition();
    
}

InputRange::~InputRange()
{
    
}

void InputRange::draw(sf::RenderWindow& renderer)
{
    renderer.draw(m_boundRectangle);
    renderer.draw(m_volumeRectangle);
    renderer.draw(m_cursor);
}

void InputRange::setCursorPosition()
{
    m_cursor.setPosition(0,0);
    m_cursor.setOrigin(0,0);
    m_cursor.setOrigin(m_cursor.getSize().x / 2, m_cursor.getSize().y / 2);
    
    m_cursor.setPosition(m_volumeRectangle.getPosition().x + m_volumeRectangle.getGlobalBounds().width,
                         m_volumeRectangle.getPosition().y+m_volumeRectangle.getGlobalBounds().height/2);
}

void InputRange::update()
{
    int widthTotal = m_boundRectangle.getGlobalBounds().width;
    int widthVolume = m_volumeRectangle.getGlobalBounds().width;
    int m_value = (widthVolume/m_reductionCoefficient) - (widthTotal/m_reductionCoefficient) + 100;
    setCursorPosition();
}

void InputRange::processEvent(sf::Event& event)
{
    switch(event.type)
    {
        case(sf::Event::MouseMoved):
        {
            onMouseMove(event);
            break;
        }
        case(sf::Event::MouseButtonPressed):
        {
            onMousePressed(event);
            break;
        }
        case(sf::Event::MouseButtonReleased):
        {
            onMouseReleased(event);
            break;
        }
        default:
        {
            break;
        }
    }
}

void InputRange::onMouseMove(sf::Event& event)
{
    m_mouseHover = m_boundRectangle.getGlobalBounds().contains(event.mouseMove.x , event.mouseMove.y);
}

void InputRange::onMousePressed(sf::Event& event)
{
    m_mouseHover = m_boundRectangle.getGlobalBounds().contains(event.mouseButton.x , event.mouseButton.y);
    m_mouseClicked = m_mouseHover;
}

void InputRange::onMouseReleased(sf::Event& event)
{
    if(m_mouseHover && m_mouseClicked)
    {
        m_volumeRectangle.setSize(sf::Vector2f(event.mouseButton.x - m_boundRectangle.getPosition().x,
                                               m_size.y));
        
        update();
    }
    m_mouseClicked = false;
}

int InputRange::getValue()const
{
    return m_value;
}