#ifndef __MapEditor__InputRange__
#define __MapEditor__InputRange__

#include "Input.h"

#include <SFML/Graphics/RectangleShape.hpp>

class InputRange : public Input
{
    
private:

    int                 m_minValue;
    int                 m_maxValue;
    unsigned int                 m_value;
    
    sf::RectangleShape  m_cursor;
    sf::RectangleShape  m_boundRectangle;
    sf::RectangleShape  m_volumeRectangle;
    
    float               m_reductionCoefficient; //Used to back base 100
    
    void update();
    void updateSize() override;
    void updatePosition() override;
    void setCursorPosition();
    
public:
    
    InputRange(sf::Vector2f position, sf::Vector2f size, int currentVal);
    ~InputRange();
    
    void draw(sf::RenderWindow& renderer);
    
    void processEvent(sf::Event& event) override;
    void onMouseMove(sf::Event& event) override;
    void onMousePressed(sf::Event& event) override;
    void onMouseReleased(sf::Event& event) override;
    
    void setPosition(sf::Vector2f position) override;
    void setPosition(int x, int y) override;
    void setSize(sf::Vector2f size) override;
    void setSize(int x, int y) override;
    
    unsigned int getValue()const;
};

#endif /* defined(__MapEditor__InputRange__) */
