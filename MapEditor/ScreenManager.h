#ifndef __MapEditor__ScreenManager__
#define __MapEditor__ScreenManager__

//Include STD
#include <map>

//Include SFML
#include "Screen.h"

class ScreenManager
{
    
private:
    
    static std::map<std::string, std::shared_ptr<Screen>>   m_screens;
    static std::shared_ptr<Screen>                          m_currentScreen;
    static std::string                                      m_currentScreenName;
    
public:
    
    static void addScreen(const std::shared_ptr<Screen>& screen, std::string screenName);
    static void gotoScreen(std::string screenName);
    
    static const std::string getCurrentNameScreen();
    static const std::shared_ptr<Screen>& getCurrentScreen();
};

#endif /* defined(__MapEditor__ScreenManager__) */
