#include "InputText.h"
#include "Ressource.h"

#include <iostream>

InputText::InputText(sf::Vector2f position, sf::Vector2f size, sf::String textValue, unsigned int maxCharacter):
Input(position, size),
m_isSelected(false),
m_displayCursor(false),
m_textValue(textValue),
m_maximumCharacter(maxCharacter),
m_cursorPosition(m_textValue.getSize()),
m_characterSize(25),
m_marginValue(10)
{
    
    updateGraphic();
    
    m_textArea.setFillColor(sf::Color(133,133,133));
    m_textArea.setOutlineColor(sf::Color::White);
    m_textArea.setOutlineThickness(2.0f);
    
    m_textGraphic.setString(textValue);
    m_textGraphic.setColor(sf::Color::White);
    m_textGraphic.setFont(Ressource::getFont("sansation.ttf"));
    m_textGraphic.setCharacterSize(m_characterSize);
    
    updateTextPosition();
    
}

InputText::~InputText()
{
    
}

void InputText::updateGraphic()
{
    m_textArea.setPosition(m_position);
    m_textArea.setSize(m_size);
    m_textGraphic.setPosition(m_position);
}

void InputText::setPosition(sf::Vector2f position)
{
    Input::setPosition(position);
    updateGraphic();
    updateTextPosition();
}

void InputText::setPosition(int x, int y)
{
    Input::setPosition(x,y);
    updateGraphic();
    updateTextPosition();
}

void InputText::setSize(sf::Vector2f size)
{
    if(size.y > m_characterSize - m_marginValue)
    {
        Input::setSize(size);
        updateGraphic();
        updateTextPosition();
    }
}

void InputText::setSize(int x, int y)
{
    if(y > m_characterSize - m_marginValue)
    {
        Input::setSize(x,y);
        updateGraphic();
        updateTextPosition();
    }
}

sf::String InputText::getValue()const
{
    return m_textValue;
}

int InputText::detectCursorPosition(sf::Text textCopy, int xMouse)
{
    int iterator = textCopy.getString().getSize();
    
    while(textCopy.getString().getSize() != 0)
    {
        if(xMouse > textCopy.getPosition().x + textCopy.getGlobalBounds().width)
        {
            return iterator;
        }
        else
        {
            textCopy.setString(textCopy.getString().substring(0,textCopy.getString().getSize()-1));
            iterator--;
        }
    }
    return iterator;
}

void InputText::updateTextPosition()
{
    m_textGraphic.setPosition(0,0);
    m_textGraphic.setOrigin(0,0);
    
    m_textGraphic.setOrigin(0,m_textGraphic.getGlobalBounds().top + m_textGraphic.getGlobalBounds().height / 2);
    m_textGraphic.setPosition( m_position.x + 10, m_position.y + m_size.y / 2);
}

void InputText::setMaximumCharacter(unsigned int max)
{
    m_maximumCharacter = max;
}

void InputText::setCharacterSize(unsigned int size)
{
    if(size > m_textArea.getSize().y - m_marginValue)
    {
        m_characterSize = m_textArea.getSize().y - 10;
        m_textGraphic.setCharacterSize(m_characterSize);
    }
    else
    {
        m_characterSize = size;
        m_textGraphic.setCharacterSize(m_characterSize);
    }
    updateTextPosition();
}

void InputText::processEvent(sf::Event& event)
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
        case(sf::Event::KeyPressed):
        {
            onKeyPressed(event);
        }
        case(sf::Event::TextEntered):
        {
            onTextEntered(event);
        }
        default:
        {
            break;
        }
    }
}


void InputText::onKeyPressed(sf::Event& event)
{
    if(m_isSelected)
    {
        switch(event.key.code)
        {
            case(sf::Keyboard::Left):
            {
                if(m_cursorPosition > 0 && m_isSelected)
                    m_cursorPosition--;
                break;
            }
            case(sf::Keyboard::Right):
            {
                if(m_cursorPosition < m_textValue.getSize() && m_isSelected)
                    m_cursorPosition++;
                break;
            }
            case(sf::Keyboard::BackSpace):
            {
                if(m_cursorPosition != 0)
                {
                    m_textValue.erase(m_cursorPosition-1);
                    m_cursorPosition--;
                }
                
                m_textGraphic.setString(m_textValue);
            }
            default:
            {
                break;
            }
        }
    }
}

void InputText::onTextEntered(sf::Event& event)
{
    if(m_isSelected)
    {
        std::cout<<event.text.unicode<<std::endl;
        //Exclude 59 = Delete touch
        //Exclude 71 = left touch
        //Exclude 72 = right touch
        //Exclude 38 = left maj
        //Exclude 42 = right maj
        //Exclude 57 = spaceBar
        //Excluse all of this, because, they are double signification for sfml i guess
        
        if(event.text.unicode > 31 && event.text.unicode < 127 && event.text.unicode != 59 && event.text.unicode != 71 && event.text.unicode != 72 &&  event.text.unicode != 38 && event.text.unicode != 42 && event.text.unicode != 57 && m_textValue.getSize() < m_maximumCharacter)
        {
            if(m_cursorPosition != m_textValue.getSize())
            {
                //Look at documentation if no understand parameters
                m_textValue = m_textValue.substring(0,m_cursorPosition)+event.text.unicode+m_textValue.substring(m_cursorPosition);
            }
            else
            {
                m_textValue += event.text.unicode;
            }
            m_cursorPosition++;
        }
        m_textGraphic.setString(m_textValue);
    }
}

void InputText::onMouseMove(sf::Event& event)
{
    m_mouseHover = m_textArea.getGlobalBounds().contains(event.mouseMove.x , event.mouseMove.y);
}

void InputText::onMousePressed(sf::Event& event)
{
    m_mouseHover = m_textArea.getGlobalBounds().contains(event.mouseButton.x , event.mouseButton.y);
    m_mouseClicked = m_mouseHover;
}

void InputText::onMouseReleased(sf::Event& event)
{
    if(m_mouseHover && m_mouseClicked)
    {
        m_isSelected = true;
        m_displayCursor = true;
        m_textArea.setFillColor(sf::Color::Black);
        m_cursorPosition = detectCursorPosition(m_textGraphic, event.mouseButton.x);
    }
    else
    {
        m_isSelected = false;
        m_displayCursor = false;
        m_textArea.setFillColor(sf::Color(133,133,133)); //Grey
    }
}

void InputText::draw(sf::RenderWindow& renderer)
{
    renderer.draw(m_textArea);
    renderer.draw(m_textGraphic);
    if(m_displayCursor)
    {
        renderer.draw(m_cursor);
    }
}