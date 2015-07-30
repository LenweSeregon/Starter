#ifndef __MapEditor__Entity__
#define __MapEditor__Entity__

#include <SFML/System/Vector2.hpp>

//--------------------------------------------------------------------------------------------------------------------------------//
//----------------------------------------------------------------Entity----------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------//

class GameEntity
{
    
private:
    
    sf::Vector2f    m_position;
    sf::Vector2f    m_size;
    
    bool            m_isCollidable;
    
    
public:
    
    GameEntity();
    virtual ~GameEntity();
    
    //Entity semantic respect
    GameEntity(const GameEntity& app) = delete;
    GameEntity& operator=(const GameEntity &) = delete;
    bool operator==(GameEntity const&) = delete;
    bool operator!=(GameEntity const&) = delete;
};

//--------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------MovableEntity------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------//

class MovableEntity : public GameEntity
{
    
private:
    
public:
    
    
};

//--------------------------------------------------------------------------------------------------------------------------------//
//-------------------------------------------------------------StaticEntity-------------------------------------------------------//
//--------------------------------------------------------------------------------------------------------------------------------//

class StaticEntity : public GameEntity
{
    
private:
    
public:
    
};

#endif /* defined(__MapEditor__Entity__) */
