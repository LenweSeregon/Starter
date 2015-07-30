#ifndef __MapEditor__InputText__
#define __MapEditor__InputText__

#include "Input.h"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class InputText : public Input
{
    
private:
    
    sf::Vector2f        m_position;
    sf::Vector2f        m_size;
    sf::String          m_textValue;
    sf::Text            m_textGraphic;
    
    bool                m_isSelected;
    bool                m_displayCursor;
    sf::Clock           m_timeCursorDisplay;
    
    unsigned int        m_maximumCharacter;
    unsigned int        m_cursorPosition;
    
    sf::RectangleShape  m_textArea;
    sf::RectangleShape  m_cursor;
    
    void updateTextPosition();
    int detectCursorPosition(sf::Text textCopy, int xMouse);
    
    
public:
    
    InputText(sf::Vector2f position, sf::Vector2f size, sf::String textValue, unsigned int maxCharacter);
    ~InputText();
    
    void setMaximumCharacter(unsigned int max);
    void setCharacterSize(unsigned int size);
    
    sf::String getValue()const;
    
    virtual void onKeyPressed(sf::Event& event);
    virtual void onTextEntered(sf::Event& event);
    
    //Herited from Input
    virtual void processEvent(sf::Event& event);
    virtual void onMouseMove(sf::Event& event);
    virtual void onMousePressed(sf::Event& event);
    virtual void onMouseReleased(sf::Event& event);
    
    virtual void draw(sf::RenderWindow& renderer);
};

#endif /* defined(__MapEditor__InputText__) */
