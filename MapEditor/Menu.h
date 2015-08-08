#ifndef __MapEditor__Menu__
#define __MapEditor__Menu__

//Include STD
#include <vector>

//Include SFML
#include <SFML/System/Vector2.hpp>
#include <SFML/System/String.hpp>

//Include PERSO
#include "Screen.h"
#include "Button.h"
#include "NoCopyable.h"


/**
 * Abstract class for every menu in the application
 */
class Menu : public Screen, private NoCopyable
{
    
protected:
    
    sf::Vector2f        m_windowSize;
    std::vector<Button> m_menuElement;
    sf::Text            m_title;
    
public:
    
    Menu(const sf::Vector2f& windowSize);
    virtual ~Menu() = 0;
    
    void centerEveryElement();
    
    void mouseMove(sf::Event& event);
    void mousePressed(sf::Event& event);
    void mouseReleased(sf::Event& event);
    
    //Herited from screen
    virtual void draw(sf::RenderWindow& renderer);
    virtual void processEvent(sf::Event& event);
    virtual void update(sf::Time& delta);
    
};

#endif /* defined(__MapEditor__Menu__) */
