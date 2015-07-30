#ifndef __MapEditor__MainMenu__
#define __MapEditor__MainMenu__

//Include PERSO
#include "Menu.h"
#include "InputCheck.h"
#include "InputRange.h"
#include "InputText.h"

//Include SFML
#include <SFML/System/Vector2.hpp>

class MainMenu : public Menu
{
    
private:
    
    InputText  m_inputText;
    InputRange m_rangeBox;
    
public:
    
    MainMenu(sf::Vector2f windowSize);
    ~MainMenu();
    
    virtual void processEvent(sf::Event& event);
    virtual void draw(sf::RenderWindow& renderer);
    
};

#endif /* defined(__MapEditor__MainMenu__) */
