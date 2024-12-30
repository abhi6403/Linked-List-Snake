#include"Player/SnakeController.h"
#include"Global/ServiceLocator.h"
#include"Level/LevelService.h"
#include"Event/EventService.h"
#include"Element/ElementService.h"
#include"LinkedList/LinkedList.h"
#include"LinkedList/SingleLinkedList/SingleLinkedList.h"
#include"Food/FoodService.h"
#include"Food/FoodType.h"

namespace Player
{
	using namespace LinkedList;
	using namespace Global;
	using namespace Level;
	using namespace Event;
	using namespace Sound;
	using namespace Food;
	using namespace Element;

	SnakeController::SnakeController()
	{
		single_linked_list = nullptr;
		createLinkedList();
	}

	SnakeController::~SnakeController()
	{
		destroy();
	}

	void SnakeController::initialize()
	{
		float width = ServiceLocator::getInstance()->getLevelService()->getCellWidth();
		float height = ServiceLocator::getInstance()->getLevelService()->getCellHeight();

		single_linked_list->initialize(width, height, default_position, default_direction);
	}

	void SnakeController::update()
	{
		switch (current_snake_state)
		{
		case SnakeState::ALIVE:
			processPlayerInput();
			delayedUpdate();
			break;

		case SnakeState::DEAD:
			handleRestart();
			break;
		}
	}

	void SnakeController::render()
	{
		single_linked_list->render();
	}

	void SnakeController::processPlayerInput()
	{
		if (current_input_state == InputState::PROCESSING)
		{
			return;
		}

		EventService* event_service = ServiceLocator::getInstance()->getEventService();

		if (event_service->pressedUpArrowKey() && current_snake_direction != Direction::DOWN)
		{
			current_snake_direction = Direction::UP;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedDownArrowKey() && current_snake_direction != Direction::UP)
		{
			current_snake_direction = Direction::DOWN;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedLeftArrowKey() && current_snake_direction != Direction::RIGHT)
		{
			current_snake_direction = Direction::LEFT;
			current_input_state = InputState::PROCESSING;
		}
		else if (event_service->pressedRightArrowKey() && current_snake_direction != Direction::LEFT)
		{
			current_snake_direction = Direction::RIGHT;
			current_input_state = InputState::PROCESSING;
		}
	}

	void SnakeController::createLinkedList()
	{
		single_linked_list = new SingleLinkedList();
	}

	void SnakeController::spawnSnake()
	{
		for (int i = 0; i < initial_snake_length; i++) 
		{
			single_linked_list->insertNodeAtTail();    
		}
	}

	void SnakeController::updateSnakeDirection()
	{
		single_linked_list->updateNodeDirection(current_snake_direction);
	}

	void SnakeController::moveSnake()
	{
		single_linked_list->updateNodePosition();
	}

	void SnakeController::delayedUpdate()
	{
		elapsed_duration += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (elapsed_duration >= movement_frame_duration)
		{
			elapsed_duration = 0.f;
			updateSnakeDirection();
			processSnakeCollision();
			if (current_snake_state == SnakeState::ALIVE)
			{
				moveSnake();
			}
			current_input_state = InputState::WAITING;
		}
	}

	void SnakeController::processSnakeCollision()
	{
		processBodyCollision();
		processElementscollision();
		processFoodCollision();
	}

	void SnakeController::processBodyCollision()
	{
		if (single_linked_list->processNodeCollision())
		{
			current_snake_state = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}

	void SnakeController::processElementscollision()
	{
		ElementService* element_service = ServiceLocator::getInstance()->getElementService();

		if (element_service->processElementsCollision(single_linked_list->getHeadNode()))
		{
			current_snake_state = SnakeState::DEAD;
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::DEATH);
		}
	}

	void SnakeController::processFoodCollision()
	{
		FoodService* food_service = ServiceLocator::getInstance()->getFoodService();
		FoodType food_type;

		if (food_service->processFoodCollision(single_linked_list->getHeadNode(), food_type))
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::PICKUP);

			player_score++;
			food_service->destroyFood();
			OnFoodCollected(food_type);
		}
	}



	void SnakeController::handleRestart()
	{
		restart_counter += ServiceLocator::getInstance()->getTimeService()->getDeltaTime();

		if (restart_counter >= restart_duration)
		{
			respawnSnake();
		}
	}

	void SnakeController::reset()
	{
		current_snake_state = SnakeState::ALIVE;
		current_snake_direction = default_direction;
		elapsed_duration = 0.f;
		restart_counter = 0.f;
		player_score = 0;
		current_input_state = InputState::WAITING;
	}

	int SnakeController::getPlayerScore()
	{
		return player_score;
	}

	void SnakeController::respawnSnake()
	{
		single_linked_list->removeAllNodes();
		reset();
		spawnSnake();
	}

	void SnakeController::setSnakeState(SnakeState state)
	{
		current_snake_state = state;
	}

	SnakeState SnakeController::getSnakeState()
	{
		return current_snake_state;
	}

	std::vector<sf::Vector2i> SnakeController::getCurrentSnakePositionList()
	{
		return single_linked_list->getNodesPositionList();
	}

	void SnakeController::OnFoodCollected(FoodType food_type)
	{
		switch (food_type)
		{
		case FoodType::PIZZA:
			//Insert At Tail
			single_linked_list->insertNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_TAIL;
			break;

		case FoodType::BURGER:
			//Insert At Head
			single_linked_list->insertNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_HEAD;
			break;

		case FoodType::CHEESE:
			//Insert in Middle
			single_linked_list->insertNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::INSERT_AT_MID;
			break;

		case FoodType::APPLE:
			//Delete at Head
			single_linked_list->removeNodeAtHead();
			time_complexity = TimeComplexity::ONE;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_HEAD;
			break;

		case FoodType::MANGO:
			//Delete at Middle
			single_linked_list->removeNodeAtMiddle();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_MID;
			break;

		case FoodType::ORANGE:
			//Delete at Tail
			single_linked_list->removeNodeAtTail();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REMOVE_AT_TAIL;
			break;

		case FoodType::POISION:
			//Delete half the snake
			single_linked_list->removeHalfNodes();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REVERSE_LIST;
			break;

		case FoodType::ALCOHOL:
			//Reverse the snake
			current_snake_direction = single_linked_list->reverse();
			time_complexity = TimeComplexity::N;
			last_linked_list_operation = LinkedListOperations::REVERSE_LIST;
			break;
		}
	}
	
	TimeComplexity SnakeController::getTimeComplexity()
	{
		return time_complexity;
	}

	LinkedListOperations SnakeController::getLastOperation()
	{
		return last_linked_list_operation;
	}

	void SnakeController::destroy()
	{
		delete(single_linked_list);
	}
}