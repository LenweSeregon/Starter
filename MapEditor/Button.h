//
//  Button.h
//  MapEditor
//
//  Created by Nicolas Serf on 14/07/2015.
//  Copyright (c) 2015 Nicolas Serf. All rights reserved.
//
#ifndef __MapEditor__Button__
#define __MapEditor__Button__

//Include SFML
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

class Button
{
    
private:
    
    sf::RectangleShape  m_defaultShape;
    sf::RectangleShape  m_hoverShape;
    sf::Text            m_text;
    
    sf::Vector2f        m_position;
    sf::Vector2f        m_size;
    std::string         m_action;
    
    
    bool                m_mouseHover;
    bool                m_mouseClicked;
    
    
    //Function
    void updatePositionText();
    
public:
    
    Button(sf::Vector2f position, sf::Vector2f size, int sizeFont, std::string actionOnClick = "");
    ~Button();
    
    void draw(sf::RenderWindow& renderer);
    
    sf::Vector2f getPosition()const;
    sf::Vector2f getSize()const;
    
    void setText(sf::String string);
    void setPosition(sf::Vector2f pos);
    
    //event
    void onMouseMove(sf::Event& event);
    void onMousePressed(sf::Event& event);
    void onMouseReleased(sf::Event& event);
    
    //Entity semantic respect
    Button(const Button& app) = delete;
    Button& operator=(const Button &) = delete;
    bool operator==(Button const&) = delete;
    bool operator!=(Button const&) = delete;
};

#endif /* defined(__MapEditor__Button__) */