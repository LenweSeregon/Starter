#include "ScreenManager.h"

std::map<std::string, std::shared_ptr<Screen>>  ScreenManager::m_screens;
std::shared_ptr<Screen>                         ScreenManager::m_currentScreen = nullptr;
std::string                                     ScreenManager::m_currentScreenName = "";

void ScreenManager::addScreen(const std::shared_ptr<Screen>& screen, std::string screenName)
{
    m_screens[screenName] = screen;
}

void ScreenManager::gotoScreen(std::string screenName)
{
    if(screenName == "Close")
    {
        m_currentScreenName = "Close";
    }
    else if(m_screens.find(screenName) != m_screens.end())
    {
        if(m_currentScreen!=nullptr)
        {
            m_currentScreen->looseFocus();
        }
        m_currentScreen = m_screens[screenName];
        m_currentScreenName = screenName;
        m_currentScreen->gainFocus();
    }
}

const std::shared_ptr<Screen>& ScreenManager::getCurrentScreen()
{
    return m_currentScreen;
}

const std::string ScreenManager::getCurrentNameScreen()
{
    return m_currentScreenName;
}