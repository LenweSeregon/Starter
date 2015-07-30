#include "SettingsMenu.h"

SettingsMenu::SettingsMenu(sf::Vector2f windowSize):
Menu(windowSize)
{
    m_title.setString("Settings");
    m_title.setPosition(300, 10);
    
    m_menuElement.emplace_back(sf::Vector2f(300,100), sf::Vector2f(200,50), 30, "Foo1");
    m_menuElement[0].setText(L"Foo1");
    
    m_menuElement.emplace_back(sf::Vector2f(300,200), sf::Vector2f(200,50), 30, "Foo2");
    m_menuElement[1].setText(L"Foo2");
    
    m_menuElement.emplace_back(sf::Vector2f(300,300), sf::Vector2f(200,50), 30, "MainMenu");
    m_menuElement[2].setText(L"Back menu");
    
    Menu::centerEveryElement();
}

SettingsMenu::~SettingsMenu()
{
    
}