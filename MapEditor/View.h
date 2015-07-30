#ifndef __MapEditor__View__
#define __MapEditor__View__

#include <SFML/Graphics/View.hpp>
#include <SFML/System/Vector2.hpp>

class View
{
    
private:
    
    sf::View    m_view;
    sf::View    m_defaultView;
    
public:
    
    View(sf::Vector2f windowSize, sf::View defaultView);
    
    const sf::View& getView()const;
    
    void reinitDefaultView();
    
    //Entity semantic respect
    View(const View& app) = delete;
    View& operator=(const View &) = delete;
    bool operator==(View const&) = delete;
    bool operator!=(View const&) = delete;
    
    ~View();
};

#endif /* defined(__MapEditor__View__) */
