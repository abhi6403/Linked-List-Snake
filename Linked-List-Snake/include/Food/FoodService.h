#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>
#include <random>

namespace Food
{
	enum class FoodType;
	class FoodItem;

	class FoodService
	{
	private:

		FoodItem* current_food_item;

		float cell_width;
		float cell_height;

		FoodItem* createFood(sf::Vector2i position, FoodType type);
		void spawnFood();

		
		void destroyFood();
		void reset();

	public:
		FoodService();
		~FoodService();

		void initialize();
		void update();
		void render();

		void startFoodSpawning();
	};
}