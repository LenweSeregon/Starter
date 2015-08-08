#ifndef __MapEditor__Screen__
#define __MapEditor__Screen__

//Include SFML
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Time.hpp>

//Include Perso
#include "NoCopyable.h"


/**
 * Abstract class for every screen in the application
 */
class Screen : public NoCopyableButMovable
{
    
protected:
    
    bool m_isActive;
    
public:
    
    Screen();
    Screen(Screen&&) = default;
    virtual ~Screen();
    
    virtual void draw(sf::RenderWindow& renderer) = 0;
    virtual void processEvent(sf::Event& event) = 0;
    virtual void update(sf::Time& delta) = 0;
    
    virtual void gainFocus();
    virtual void looseFocus();
};

#endif /* defined(__MapEditor__Screen__) */
