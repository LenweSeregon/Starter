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
    
    
    void updatePosition() override;
    void updateSize() override;
    
public:
    
    InputCheck(sf::Vector2f position, sf::Vector2f size, bool valueBox);
    ~InputCheck();
    
    void processEvent(sf::Event& event) override;
    void onMouseMove(sf::Event& event) override;
    void onMousePressed(sf::Event& event) override;
    void onMouseReleased(sf::Event& event) override;
    
    void setPosition(sf::Vector2f position) override;
    void setPosition(int x, int y) override;
    void setSize(sf::Vector2f size) override;
    void setSize(int x, int y) override;
    
    bool getEtat()const;
    
    void draw(sf::RenderWindow& renderer);
};

#endif /* defined(__MapEditor__InputCheck__) */
