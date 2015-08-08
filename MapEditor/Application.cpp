#include "Application.h"
#include "ScreenManager.h"
#include "MainMenu.h"
#include "SettingsMenu.h"

#include <iostream>

Application::Application():
m_sizeWindow(1200,700),
m_window(sf::VideoMode(m_sizeWindow.x, m_sizeWindow.y), "Map Editor V.0"),
m_view(m_sizeWindow, m_window.getDefaultView())
{
    m_window.setKeyRepeatEnabled(false);
    m_window.setFramerateLimit(60);
    m_window.setView(m_view.getView());
    
    ScreenManager::addScreen(std::make_shared<MainMenu>(m_sizeWindow), "MainMenu");
    ScreenManager::addScreen(std::make_shared<SettingsMenu>(m_sizeWindow), "SettingsMenu");
    
    ScreenManager::gotoScreen("SettingsMenu");
}

Application::~Application()
{
    
}

void Application::run()
{
    sf::Clock clock;
    
    while(m_window.isOpen())
    {
        sf::Event event;
        sf::Time deltaTime = clock.restart();
        
        while(m_window.pollEvent(event))
        {
            processEvent(event);
            ScreenManager::getCurrentScreen()->processEvent(event);
        }
        
        //std::cout<<ScreenManager::getCurrentNameScreen()<<std::endl;
        
        if(ScreenManager::getCurrentNameScreen() == "Close")
        {
            m_window.close();
        }
        
        update(deltaTime);
        draw();
    }
}

void Application::processEvent(sf::Event &event)
{
    if(event.type == sf::Event::Closed)
    {
        m_window.close();
    }
    if(event.type == sf::Event::MouseButtonPressed)
    {
        sf::Vector2i posMouse = sf::Mouse::getPosition(m_window);
        sf::Vector2f worldPos = m_window.mapPixelToCoords(posMouse);
        
        event.mouseButton.x = worldPos.x;
        event.mouseButton.y = worldPos.y;
        
    }
    if(event.type == sf::Event::MouseMoved)
    {
        sf::Vector2i posMouse = sf::Mouse::getPosition(m_window);
        sf::Vector2f worldPos = m_window.mapPixelToCoords(posMouse);
        
        event.mouseMove.x = worldPos.x;
        event.mouseMove.y = worldPos.y;
    }
}

void Application::update(sf::Time &delta)
{
    ScreenManager::getCurrentScreen()->update(delta);
}

void Application::draw()
{
    m_window.clear();
    ScreenManager::getCurrentScreen()->draw(m_window);
    m_window.display();
}