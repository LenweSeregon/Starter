#include "Screen.h"


Screen::Screen():
m_isActive(false)
{
    
}

Screen::~Screen()
{
    
}

void Screen::gainFocus()
{
    m_isActive = true;
}

void Screen::looseFocus()
{
    m_isActive = false;
}