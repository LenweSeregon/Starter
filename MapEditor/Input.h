#ifndef __MapEditor__Input__
#define __MapEditor__Input__

//Include SFMl
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

//Include Perso
#include "NoCopyable.h"

class Input : private NoCopyable
{
    
protected:
    
    bool            m_mouseHover;
    bool            m_mouseClicked;
    
    sf::Vector2f    m_position;
    sf::Vector2f    m_size;
    
    virtual void updateGraphic() = 0;
    
public:
    
    Input();
    Input(sf::Vector2f position, sf::Vector2f size);
    virtual ~Input();
    
    sf::Vector2f getPosition()const;
    sf::Vector2f getSize()const;
    
    virtual void setPosition(sf::Vector2f position);
    virtual void setPosition(int x, int y);
    virtual void setSize(sf::Vector2f size);
    virtual void setSize(int x, int y);
    
    virtual void processEvent(sf::Event& event) = 0;
    virtual void onMouseMove(sf::Event& event) = 0;
    virtual void onMousePressed(sf::Event& event) = 0;
    virtual void onMouseReleased(sf::Event& event) = 0;
    
    virtual void draw(sf::RenderWindow& renderer) = 0;
    
};

#endif /* defined(__MapEditor__Input__) */
