#pragma once
#include"UI/UIElement/ImageView.h"
#include"Food/FoodType.h"
#include<SFML/Graphics.hpp>

namespace Food
{
	class FoodItem
	{
	private:
		UI::UIElement::ImageView* food_image;

		sf::Vector2i grid_position;

		float cell_width;
		float cell_height;

		FoodType food_type;

		void initializeFoodImage();
		sf::Vector2f getFoodImagePosition();
		sf::String getFoodTexturePath();

	public:
		static const int number_of_foods = 8;

		FoodItem();
		~FoodItem();

		void initialize(sf::Vector2i grid_pos, float width, float height, FoodType type);
		void update();
		void render();

		sf::Vector2i getFoodPosition();
		FoodType getFoodType();

	};
}