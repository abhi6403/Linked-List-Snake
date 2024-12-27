#pragma once
#include"UI/UIElement/ImageView.h"
#include"Player/Direction.h"

namespace Player
{
	class BodyPart
	{
	protected:
		UI::UIElement::ImageView* bodypart_image;

		sf::Vector2i grid_position;
		Direction direction;

		float bodypart_width;
		float bodypart_height;

		sf::Vector2f getBodyPartScreenPosition();
		sf::Vector2i getNextPositionUp();
		sf::Vector2i getNextPositionDown();
		sf::Vector2i getNextPositionLeft();
		sf::Vector2i getNextPositionRight();
		

		float getRotationAngle();
		
		void initializeBodyPartImage();
		void createBodyPartImage();
		void destroy();

	public:
		BodyPart();
		~BodyPart();

		void initialize(float width, float height, sf::Vector2i pos, Direction dir);
		void updatePosition();
		void render();

		sf::Vector2i getNextPosition();
		sf::Vector2i getPrevPosition();

		void setDirection(Direction direction);
		Direction getDirection();

		void setPosition(sf::Vector2i position);
		sf::Vector2i getPosition();
	};
}