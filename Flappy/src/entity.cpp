#include "entity.h"

Entity::Entity(glm::vec3 color, glm::vec2 position, glm::vec2 size)
    :m_Position(position), m_Size(size), lil::Quad(color, position, size){


}

Entity::~Entity(){}

