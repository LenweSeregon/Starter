#include <iostream>

#include "InputCheck.h"

InputCheck::InputCheck(sf::Vector2f position, sf::Vector2f size, bool valueBox):
Input(position, size),
m_isCheck(valueBox)
{
    updateSize();
    updatePosition();
    m_checkBox.setFillColor(sf::Color::Black);
    m_checkBox.setOutlineColor(sf::Color::White);
    m_checkBox.setOutlineThickness(2.0f);
}

InputCheck::~InputCheck()
{
    
}

void InputCheck::updatePosition()
{
    m_checkBox.setPosition(m_position);
    
    m_rectangleChecker.setPosition(0,0);
    m_rectangleChecker.setOrigin(0,0);
    
    m_rectangleChecker.setOrigin(m_rectangleChecker.getSize().x/2, m_rectangleChecker.getSize().y/2);
    m_rectangleChecker.setPosition(m_checkBox.getPosition().x + m_checkBox.getSize().x / 2,
                                   m_checkBox.getPosition().y + m_checkBox.getSize().y / 2);
}

void InputCheck::updateSize()
{
    m_checkBox.setSize(m_size);
    m_rectangleChecker.setSize(sf::Vector2f(m_size.x/2, m_size.y/2));
}

void InputCheck::processEvent(sf::Event& event)
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

void InputCheck::setPosition(sf::Vector2f position)
{
    Input::setPosition(position);
    updatePosition();
}

void InputCheck::setPosition(int x, int y)
{
    Input::setPosition(x,y);
    updatePosition();
}
void InputCheck::setSize(sf::Vector2f size)
{
    Input::setSize(size);
    updateSize();
}

void InputCheck::setSize(int x, int y)
{
    Input::setSize(x,y);
    updateSize();
}

void InputCheck::onMouseMove(sf::Event& event)
{
    m_mouseHover = m_checkBox.getGlobalBounds().contains(event.mouseMove.x , event.mouseMove.y);
}

void InputCheck::onMousePressed(sf::Event& event)
{
    m_mouseHover = m_checkBox.getGlobalBounds().contains(event.mouseButton.x , event.mouseButton.y);
    m_mouseClicked = m_mouseHover;
}

void InputCheck::onMouseReleased(sf::Event& event)
{
    if(m_mouseHover && m_mouseClicked)
    {
        m_isCheck = !m_isCheck;
    }
    m_mouseClicked = false;
}

bool InputCheck::getEtat()const
{
    return m_isCheck;
}

void InputCheck::draw(sf::RenderWindow &renderer)
{
    renderer.draw(m_checkBox);
    if(m_isCheck)
    {
        renderer.draw(m_rectangleChecker);
    }
}