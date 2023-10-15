#pragma once
#include <SFML/System/Vector2.hpp>

enum class ElementType;

struct ElementData
{
    ElementData(ElementType type, sf::Vector2i pos)
    {
        element_type = type;
        position = pos;
    }

    ElementType element_type;
    sf::Vector2i position;
};