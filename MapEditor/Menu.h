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


/**
 * Abstract class for every menu in the application
 */
class Menu : public Screen
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
    
    //Entity semantic respect
    Menu(const Menu& app) = delete;
    Menu& operator=(const Menu &) = delete;
    bool operator==(Menu const&) = delete;
    bool operator!=(Menu const&) = delete;
    
};

#endif /* defined(__MapEditor__Menu__) */
