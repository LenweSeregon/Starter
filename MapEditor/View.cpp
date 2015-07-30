#include "View.h"

View::View(sf::Vector2f windowSize, sf::View defaultView):
m_defaultView(defaultView)
{
    m_view.setCenter(windowSize.x / 2, windowSize.y / 2);
    m_view.setSize(windowSize);
}

const sf::View& View::getView()const
{
    return m_view;
}

void View::reinitDefaultView()
{
    m_view = m_defaultView;
}

View::~View()
{

}