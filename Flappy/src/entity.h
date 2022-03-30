#pragma once 

#include <Little.h>

#include <glm/glm.hpp>

class Entity : public lil::Quad {
public:
    Entity(glm::vec3 color = {1.0f, 1.0f, 1.0f}, glm::vec2 position = {1.0f, 1.0f}, glm::vec2 size = {1.0f, 1.0f});
    ~Entity();


private:
    glm::vec2 m_Position;
    glm::vec2 m_Size;

};

class Wall : public Entity{
public:
    Wall(glm::vec2 position, glm::vec2 size);
    ~Wall();

};

class Player : public Entity{
public:
    Player(glm::vec2 size, glm::vec2 position);
    ~Player();

    void Death();

    bool IsAllive();

private:
    bool m_Allive = true;
};