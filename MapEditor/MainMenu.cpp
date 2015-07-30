#include "MainMenu.h"

MainMenu::MainMenu(sf::Vector2f windowSize):
Menu(windowSize),
//m_boxCheckSound(sf::Vector2f(300,400), sf::Vector2f(50,50), true),
m_inputText(sf::Vector2f(300,400), sf::Vector2f(300,50), "Bonjour", 25),
m_rangeBox(sf::Vector2f(200,500), sf::Vector2f(500,50), 20)
{
    m_title.setString("Main Menu");
    m_title.setPosition(300, 10);
    
    m_menuElement.emplace_back(sf::Vector2f(300,100), sf::Vector2f(260,50), 30, "MainMenu");
    m_menuElement[0].setText(L"Main Menu");
    
    m_menuElement.emplace_back(sf::Vector2f(300,200), sf::Vector2f(260,50), 30, "SettingsMenu");
    m_menuElement[1].setText(L"Settings Menu");
    
    m_menuElement.emplace_back(sf::Vector2f(300,300), sf::Vector2f(370,50), 30, "Close");
    m_menuElement[2].setText(L"Close");

    Menu::centerEveryElement();
}

MainMenu::~MainMenu()
{
    
}

void MainMenu::processEvent(sf::Event &event)
{
    if(m_isActive)
    {
        Menu::processEvent(event);
        //m_boxCheckSound.processEvent(event);
        m_inputText.processEvent(event);
        m_rangeBox.processEvent(event);
    }
}

void MainMenu::draw(sf::RenderWindow& renderer)
{
    if(m_isActive)
    {
        Menu::draw(renderer);
        //m_boxCheckSound.draw(renderer);
        m_inputText.draw(renderer);
        m_rangeBox.draw(renderer);
    }
}