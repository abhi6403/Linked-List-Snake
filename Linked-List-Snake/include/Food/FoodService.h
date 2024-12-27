#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <random>
#include"LinkedList/Node.h"

namespace Food
{
	enum class FoodType;
	class FoodItem;

	enum FoodSpawningStatus
	{
		ACTIVE,
		IN_ACTIVE,
	};

	class FoodService
	{
	private:

		FoodItem* current_food_item;
		FoodSpawningStatus current_spawning_status;

		const float spawn_duration = 4.f;
		float elapsed_duration;
		float cell_width;
		float cell_height;

		std::default_random_engine random_engine;
		std::random_device random_device;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();
		void updateElapsedDuration();
		void handleFoodSpawning();

		FoodType getRandomFoodType();

		sf::Vector2i getRandomPosition();
		sf::Vector2i getValidSpawnPosition();

		bool isValidPosition(std::vector<sf::Vector2i> position_data, sf::Vector2i food_position);
		
		void reset();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
		void stopFoodSpawning();
		void destroyFood();

		bool processFoodCollision(LinkedList::Node* head_node, FoodType& out_food_type);
		
	};
}