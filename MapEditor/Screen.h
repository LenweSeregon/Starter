#ifndef __MapEditor__Screen__
#define __MapEditor__Screen__

//Include SFML
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>


/**
 * Abstract class for every screen in the application
 */
class Screen
{
    
protected:
    
    bool m_isActive;
    
public:
    
    Screen();
    virtual ~Screen();
    
    virtual void draw(sf::RenderWindow& renderer) = 0;
    virtual void processEvent(sf::Event& event) = 0;
    virtual void update(sf::Time& delta) = 0;
    
    virtual void gainFocus();
    virtual void looseFocus();
    
    //Entity semantic respect
    Screen(const Screen& app) = delete;
    Screen& operator=(const Screen &) = delete;
    bool operator==(Screen const&) = delete;
    bool operator!=(Screen const&) = delete;
};

#endif /* defined(__MapEditor__Screen__) */
