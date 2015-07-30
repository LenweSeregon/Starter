#ifndef __MapEditor__Application__
#define __MapEditor__Application__

//Include SFML
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>

//Include PERSO
#include "View.h"

class Application
{
    
private:
    
    sf::Vector2f        m_sizeWindow;
    sf::RenderWindow    m_window;
    View                m_view;
    
    void processEvent(sf::Event& event);
    void update(sf::Time& delta);
    void draw();
    
public:
    
    Application();
    ~Application();
    void run();
    
    //Entity semantic respect
    Application(const Application& app) = delete;
    Application& operator=(const Application &) = delete;
    bool operator==(Application const&) = delete;
    bool operator!=(Application const&) = delete;
};


#endif /* defined(__MapEditor__Application__) */
