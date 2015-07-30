#include "Application.h"
#include "ScreenManager.h"
#include "MainMenu.h"
#include "SettingsMenu.h"

Application::Application():
m_sizeWindow(800,600),
m_window(sf::VideoMode(m_sizeWindow.x, m_sizeWindow.y), "Map Editor V.0", sf::Style::Close),
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