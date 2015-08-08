#include <iostream>

#include "Button.h"
#include "Ressource.h"
#include "ScreenManager.h"

Button::Button(sf::Vector2f position, sf::Vector2f size, int sizeFont, std::string actionOnClick):
NoCopyableButMovable(),
m_position(position),
m_size(size),
m_action(actionOnClick)
{
    m_defaultShape.setPosition(position);
    m_defaultShape.setSize(size);
    m_defaultShape.setOutlineColor(sf::Color::White);
    m_defaultShape.setOutlineThickness(2.0f);
    m_defaultShape.setFillColor(sf::Color::Black);
    
    m_hoverShape.setPosition(position);
    m_hoverShape.setSize(size);
    m_hoverShape.setOutlineColor(sf::Color::White);
    m_hoverShape.setOutlineThickness(2.0f);
    m_hoverShape.setFillColor(sf::Color::Red);
    
    m_text.setCharacterSize(sizeFont);
    m_text.setFont(Ressource::getFont("sansation.ttf"));
    m_text.setString("-");
}

Button::~Button()
{
    
}

void Button::updatePositionText()
{
    m_text.setOrigin(0,0);
    m_text.setPosition(0,0);
    
    m_text.setOrigin(m_text.getGlobalBounds().left + m_text.getGlobalBounds().width / 2,
                     m_text.getGlobalBounds().top + m_text.getGlobalBounds().height / 2);
    
    m_text.setPosition(m_position.x + m_size.x / 2,
                       m_position.y + m_size.y / 2);
}

void Button::setText(sf::String string)
{
    m_text.setString(string);
    updatePositionText();
    
}

sf::Vector2f Button::getPosition()const
{
    return m_position;
}

sf::Vector2f Button::getSize()const
{
    return m_size;
}

void Button::setPosition(sf::Vector2f pos)
{
    m_position = pos;
    m_defaultShape.setPosition(pos);
    m_hoverShape.setPosition(pos);
    updatePositionText();
}

void Button::draw(sf::RenderWindow &renderer)
{
    if(m_mouseHover)
    {
        renderer.draw(m_hoverShape);
    }
    else
    {
        renderer.draw(m_defaultShape);
    }
    
    renderer.draw(m_text);
}

void Button::onMouseMove(sf::Event& event)
{
    m_mouseHover = m_defaultShape.getGlobalBounds().contains(event.mouseMove.x , event.mouseMove.y);
}

void Button::onMousePressed(sf::Event& event)
{
    m_mouseHover = m_defaultShape.getGlobalBounds().contains(event.mouseButton.x , event.mouseButton.y);
    m_mouseClicked = m_mouseHover;
}

void Button::onMouseReleased(sf::Event& event)
{    
    if(m_mouseHover && m_mouseClicked)
    {
        ScreenManager::gotoScreen(m_action);
    }
    m_mouseClicked = false;
}