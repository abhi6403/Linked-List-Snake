#pragma once
#include"UIView.h"

namespace UI
{
	namespace UIElement
	{
		class RectangleShapeView : public UIView
		{
		protected:
			sf::RectangleShape rectangle_shape;

		public:
			RectangleShapeView();
			~RectangleShapeView();

			void initialize(sf::Vector2f rectangle_size, sf::Vector2f rectangle_position, int outline_thickness = 0, sf::Color fill_color = sf::Color::Transparent, sf::Color outline_color = sf::Color::Transparent);
			void update();
			void render();

			void setSize(sf::Vector2f rectangle_size);
			void setPosition(sf::Vector2f rectangle_position);
			void setFillColor(sf::Color fill_color);
			void setOutlineColor(sf::Color outline_color);
			void setOutlineThickness(int outline_thickness);

		};
	}
}