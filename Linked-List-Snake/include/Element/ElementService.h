#pragma once
#include<vector>
#include<SFML/System/Vector2.hpp>
#include"LinkedList/Node.h"

namespace Element
{
	class Obstacle;
	struct ElementData;
	enum class ElementType;

	class ElementService
	{
	private:
		std::vector<Obstacle*> obstacle_list;
		
		void spawnObstacles(sf::Vector2i position, float cell_width, float cell_height);
		

	public:
		ElementService();
		~ElementService();

		void initialize();
		void update();
		void render();

		const void spawnElements(std::vector<ElementData>& element_data_list, float cell_width, float cell_height);

		bool processElementsCollision(LinkedList::Node* head_node);

		std::vector<sf::Vector2i> getElementsPositionList();
	};

}