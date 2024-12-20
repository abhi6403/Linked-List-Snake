#include"Player/BodyPart.h"
#include"UI/UIElement/ImageView.h"
#include"Global/Config.h"

namespace Player
{
	using namespace UI::UIElement;
	using namespace Global;

	BodyPart::BodyPart()
	{
		grid_position = sf::Vector2i(0, 0);
		createBodyPartImage();
	}

	BodyPart::~BodyPart()
	{
		destroy();
	}

	void BodyPart::initialize(float width, float height, sf::Vector2i pos, Direction dir)
	{
		bodypart_width = width;
		bodypart_height = height;
		grid_position = pos;
		direction = dir;

		initializeBodyPartImage();
	}

	void BodyPart::update()
	{

	}

	void BodyPart::render()
	{
		bodypart_image->render();
	}

	void BodyPart::createBodyPartImage()
	{
		bodypart_image = new ImageView();
	}

	void BodyPart::initializeBodyPartImage()
	{
		bodypart_image->initialize(Config::snake_body_texture_path, bodypart_width, bodypart_height, getBodyPartScreenPosition());
		bodypart_image->setOriginAtCentre();
	}
	void BodyPart::destroy()
	{
		delete(bodypart_image);
	}
}