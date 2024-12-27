#pragma once
#include<SFML/System/Vector2.hpp>
#include"LinkedList/Node.h"

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Direction default_direction;

		Node* createNode();
	
		void destroy();

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Direction direction);
		void render();
		void insertNodeAtTail();
		void updateNodeDirection(Direction direction_to_set);
		void updateNodePosition();
		void removeNodeAtHead();
		void removeAllNodes();
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		std::vector<sf::Vector2i> getNodesPositionList();

		Node* getHeadNode();

		bool processNodeCollision();
		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);
	};
}