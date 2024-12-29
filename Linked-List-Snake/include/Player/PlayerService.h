#pragma once
#include"Player/SnakeController.h"

namespace Player
{
	class PlayerService
	{
	private:
		SnakeController* snake_controller;
		
		void createController();

		void destroy();
	public:
		PlayerService();
		~PlayerService();

		void initialize();
		void update();
		void render();

		void spawnPlayer();
		int getPlayerScore();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();


		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}