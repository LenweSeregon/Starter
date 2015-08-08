#ifndef __MapEditor__InputCheck__
#define __MapEditor__InputCheck__

//Include SFML
#include <SFML/Graphics/RectangleShape.hpp>

//Include Personnel
#include "Input.h"

class InputCheck : public Input
{
    
private:
    
    sf::RectangleShape  m_checkBox;
    sf::RectangleShape  m_rectangleChecker;
    bool                m_isCheck;
    
    
    void updateGraphic();
    
public:
    
    InputCheck(sf::Vector2f position, sf::Vector2f size, bool valueBox);
    ~InputCheck();
    
    //Herited from Input
    virtual void processEvent(sf::Event& event);
    virtual void onMouseMove(sf::Event& event);
    virtual void onMousePressed(sf::Event& event);
    virtual void onMouseReleased(sf::Event& event);
    
    virtual void setPosition(sf::Vector2f position);
    virtual void setPosition(int x, int y);
    virtual void setSize(sf::Vector2f size);
    virtual void setSize(int x, int y);
    //
    
    bool getEtat()const;
    
    void draw(sf::RenderWindow& renderer);
};

#endif /* defined(__MapEditor__InputCheck__) */
