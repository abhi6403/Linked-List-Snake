#pragma once
#include"Player/Direction.h"
#include<SFML/System/Vector2.hpp>
#include"LinkedList/LinkedList.h"
#include"Level/LevelConfig.h"
#include"Food/FoodType.h"

namespace Player
{
	using namespace LinkedListLib;
	using namespace Food;

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

	enum class TimeComplexity
	{
		NONE,
		ONE,
		N,
	};

	enum class LinkedListOperations
	{
		NONE,
		INSERT_AT_HEAD,
		INSERT_AT_TAIL,
		INSERT_AT_MID,
		REMOVE_AT_HEAD,
		REMOVE_AT_TAIL,
		REMOVE_AT_MID,
		DELETE_HALF_LIST,
		REVERSE_LIST,
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
		int player_score;
		
		Direction current_snake_direction;
		SnakeState current_snake_state;
		InputState current_input_state;
		LinkedList* linked_list;
		TimeComplexity time_complexity;
		LinkedListOperations last_linked_list_operation;


		
		void initializeLinkedList();
		void processPlayerInput();
		void updateSnakeDirection();
		void moveSnake();
		void processSnakeCollision();
		void processBodyCollision();
		void processElementscollision();
		void processFoodCollision();
		void OnFoodCollected(FoodType food_type);
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

		void createLinkedList(Level::LinkedListType level_type);

		void spawnSnake();

		void setSnakeState(SnakeState state);
		SnakeState getSnakeState();

		std::vector<sf::Vector2i> getCurrentSnakePositionList();

		int getPlayerScore();

		TimeComplexity getTimeComplexity();
		LinkedListOperations getLastOperation();

		bool isSnakeDead();

	};
}