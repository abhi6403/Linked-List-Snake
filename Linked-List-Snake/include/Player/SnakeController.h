#pragma once
#include"Player/Direction.h"
#include<SFML/System/Vector2.hpp>

namespace Player
{
	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;
		
		Direction current_snake_direction;
		SnakeState current_snake_state;

		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void handleRestart();
		void reset();
		void respawnSnake();
		void destroy();
		
	public:
		SnakeController();
		~SnakeController();

		void initialize();
		void update();
		void render();

		void spawnSnake();

		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();
	};
}