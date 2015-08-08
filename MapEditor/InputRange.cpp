#include "InputRange.h"
#include <iostream>


InputRange::InputRange(sf::Vector2f position, sf::Vector2f size, int currentVal):
Input(position, size),
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
    
    m_boundRectangle.setPosition(m_position);
    m_boundRectangle.setSize(m_size);
    m_boundRectangle.setOutlineThickness(2.0f);
    m_boundRectangle.setOutlineColor(sf::Color::White);
    m_boundRectangle.setFillColor(sf::Color::Black);

    m_volumeRectangle.setPosition(m_position);
    m_volumeRectangle.setSize(sf::Vector2f(m_value*m_reductionCoefficient,m_size.y));
    m_volumeRectangle.setOutlineThickness(2.0f);
    m_volumeRectangle.setOutlineColor(sf::Color::White);
    m_volumeRectangle.setFillColor(sf::Color::Yellow);
    
    m_cursor.setSize(sf::Vector2f(10,m_size.y + 20));
    setCursorPosition();
    
    update();
}

InputRange::~InputRange()
{
    
}

void InputRange::setCursorPosition()
{
    m_cursor.setSize(sf::Vector2f(10,m_size.y + 20));
    
    m_cursor.setPosition(0,0);
    m_cursor.setOrigin(0,0);
    m_cursor.setOrigin(m_cursor.getSize().x / 2, m_cursor.getSize().y / 2);
    
    m_cursor.setPosition(m_volumeRectangle.getPosition().x + m_volumeRectangle.getGlobalBounds().width,
                         m_volumeRectangle.getPosition().y+m_volumeRectangle.getGlobalBounds().height/2);
}

void InputRange::updateGraphic()
{
    //std::cout<<"Value update graphic: "<<m_value<<std::endl;
    /*m_boundRectangle.setPosition(m_position);
    m_boundRectangle.setSize(m_size);
    
    m_volumeRectangle.setPosition(m_position);
    
    m_cursor.setSize(sf::Vector2f(10,m_size.y + 20));
    setCursorPosition();*/
}

void InputRange::updatePosition()
{
    m_boundRectangle.setPosition(m_position);
    m_volumeRectangle.setPosition(m_position);
    setCursorPosition();
}

void InputRange::updateSize()
{
    std::cout<<"Updating"<<std::endl;
    m_reductionCoefficient = m_size.x / m_maxValue;
    m_boundRectangle.setSize(m_size);
    m_volumeRectangle.setSize(sf::Vector2f(m_value*m_reductionCoefficient,m_size.y));
    setCursorPosition();
}

void InputRange::update()
{
    m_value = m_volumeRectangle.getSize().x / m_reductionCoefficient;
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

void InputRange::setPosition(sf::Vector2f position)
{
    Input::setPosition(position);
    updatePosition();
}

void InputRange::setPosition(int x, int y)
{
    Input::setPosition(x,y);
    update();
    updateGraphic();
}

void InputRange::setSize(sf::Vector2f size)
{
    Input::setSize(size);
    updateSize();
}

void InputRange::setSize(int x, int y)
{
    Input::setSize(x,y);
    update();
    updateGraphic();
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

void InputRange::draw(sf::RenderWindow& renderer)
{
    renderer.draw(m_boundRectangle);
    renderer.draw(m_volumeRectangle);
    renderer.draw(m_cursor);
}

unsigned int InputRange::getValue()const
{
    return m_value;
}