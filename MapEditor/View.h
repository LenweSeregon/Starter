#ifndef __MapEditor__View__
#define __MapEditor__View__

#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>

#include "NoCopyable.h"

class View : private NoCopyable
{
    
private:
    
    sf::View    m_view;
    sf::View    m_defaultView;
    
public:
    
    View(sf::Vector2f windowSize, sf::View defaultView);
    
    const sf::View& getView()const;
    
    void reinitDefaultView();
    
    ~View();
};

#endif /* defined(__MapEditor__View__) */
