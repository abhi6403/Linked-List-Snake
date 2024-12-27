#pragma once
#include"Player/Direction.h"
#include<SFML/System/Vector2.hpp>
#include"LinkedList/SingleLinkedList.h"

namespace Player
{
	using namespace LinkedList;

	enum class SnakeState
	{
		ALIVE,
		DEAD,
	};

	enum class InputState
	{
		WAITING,
		PROCESSING,
	};

	class SnakeController
	{
	private:
		const int initial_snake_length = 10;
		const float movement_frame_duration = 0.1f;
		const float restart_duration = 2.f;
		float restart_counter;
		const sf::Vector2i default_position = sf::Vector2i(25, 13);
		const Direction default_direction = Direction::RIGHT;

		float elapsed_duration;
		
		Direction current_snake_direction;
		SnakeState current_snake_state;
		InputState current_input_state;
		SingleLinkedList* single_linked_list;

		void createLinkedList();
		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void processBodyCollision();
		void processElementscollision();
		void processFoodCollision();
		void handleRestart();
		void reset();
		void respawnSnake();
		void delayedUpdate();
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

		std::vector<sf::Vector2i> getCurrentSnakePositionList();
	};
}