#pragma once
#include"Player/SnakeController.h"
#include"Level/LevelConfig.h"

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

		void spawnPlayer(Level::LinkedListType level_type);
		int getPlayerScore();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();


		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}