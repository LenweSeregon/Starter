#ifndef __MapEditor__Input__
#define __MapEditor__Input__

//Include SFMl
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Input
{
    
protected:
    
    bool            m_mouseHover;
    bool            m_mouseClicked;
    
public:
    
    Input();
    virtual ~Input();
    
    virtual void processEvent(sf::Event& event) = 0;
    virtual void onMouseMove(sf::Event& event) = 0;
    virtual void onMousePressed(sf::Event& event) = 0;
    virtual void onMouseReleased(sf::Event& event) = 0;
    
    virtual void draw(sf::RenderWindow& renderer) = 0;
    
    //Entity semantic respect
    Input(const Input& app) = delete;
    Input& operator=(const Input &) = delete;
    bool operator==(Input const&) = delete;
    bool operator!=(Input const&) = delete;
    
};

#endif /* defined(__MapEditor__Input__) */
