#include "Menu.h"
#include "Ressource.h"

Menu::Menu(const sf::Vector2f& windowSize):
Screen(),
m_windowSize(windowSize),
m_title("", Ressource::getFont("sansation.ttf"), 60)
{
    
}

Menu::~Menu()
{
    
}

void Menu::centerEveryElement()
{
    //Positionning title
    int savePositionY = m_title.getPosition().y;
    m_title.setPosition(0,0);
    m_title.setOrigin(0,0);
    
    m_title.setOrigin(m_title.getGlobalBounds().left + m_title.getGlobalBounds().width / 2,
                      m_title.getGlobalBounds().top + m_title.getGlobalBounds().height / 2);
    
    m_title.setPosition(m_windowSize.x/2, savePositionY+ (m_title.getGlobalBounds().height/2));
    
    //Positionning buttons
    for(size_t i = 0; i < m_menuElement.size(); i++)
    {
        int savePositionButtonY = m_menuElement[i].getPosition().y;
        m_menuElement[i].setPosition(sf::Vector2f((m_windowSize.x - m_menuElement[i].getSize().x) / 2,
                                                    savePositionButtonY));
    }
}

void Menu::mouseMove(sf::Event& event)
{
    for(size_t i = 0; i < m_menuElement.size(); i++)
    {
        m_menuElement[i].onMouseMove(event);
    }
}

void Menu::mousePressed(sf::Event& event)
{
    for(size_t i = 0; i < m_menuElement.size(); i++)
    {
        m_menuElement[i].onMousePressed(event);
    }
}

void Menu::mouseReleased(sf::Event& event)
{
    for(size_t i = 0; i < m_menuElement.size(); i++)
    {
        m_menuElement[i].onMouseReleased(event);
    }
}

void Menu::draw(sf::RenderWindow& renderer)
{
    if(m_isActive)
    {
        for(size_t i = 0; i < m_menuElement.size(); i++)
        {
            m_menuElement[i].draw(renderer);
        }
        renderer.draw(m_title);
    }
}

void Menu::processEvent(sf::Event& event)
{
    if(m_isActive)
    {
        switch(event.type)
        {
            case(sf::Event::MouseMoved):
            {
                mouseMove(event);
                break;
            }
            case(sf::Event::MouseButtonPressed):
            {
                mousePressed(event);
                break;
            }
            case(sf::Event::MouseButtonReleased):
            {
                mouseReleased(event);
                break;
            }
            default:
            {
                break;
            }
        }
    }
}

void Menu::update(sf::Time& delta)
{
    if(m_isActive)
    {
        
    }
}