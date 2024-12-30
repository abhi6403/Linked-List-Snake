#include"UI/LinkedListUI/LinkedListUIController.h"
#include "Main/GameService.h"
#include "Graphics/GraphicService.h"
#include "Sound/SoundService.h"
#include "Event/EventService.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/ImageView.h"
#include "Global/Config.h"

namespace UI
{
	using namespace UIElement;
	using namespace Global;
	using namespace Event;
	using namespace Sound;
	using namespace Main;
	using namespace Level;

	namespace LinkedListUI
	{
		LinkedListUIController::LinkedListUIController()
		{
			createButtons();
			createImage();
		}

		LinkedListUIController::~LinkedListUIController()
		{
			destroy();
		}

		void LinkedListUIController::initialize()
		{
			initializeBackgroundImage();
			initializeButtons();
			registerButtonCallback();
		}

		void LinkedListUIController::update()
		{
			background_image->update();
			single_linked_button->update();
			double_linked_button->update();
			menu_button->update();
		}

		void LinkedListUIController::render()
		{
			background_image->render();
			single_linked_button->render();
			double_linked_button->render();
			menu_button->render();
		}

		void LinkedListUIController::show()
		{
			background_image->show();
			single_linked_button->show();
			double_linked_button->show();
			menu_button->show();
		}

		void LinkedListUIController::createImage()
		{
			background_image = new ImageView();
		}

		void LinkedListUIController::createButtons()
		{
			single_linked_button = new ButtonView();
			double_linked_button = new ButtonView();
			menu_button = new ButtonView();
		}

		void LinkedListUIController::initializeBackgroundImage()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

			background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
			background_image->setImageAlpha(background_alpha);
		}

		void LinkedListUIController::initializeButtons()
		{
			float x_position = calculateLeftOffsetForButton();

			single_linked_button->initialize("Level One Button", Config::single_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x_position, single_linked_button_y_position));
			double_linked_button->initialize("Level Two Button", Config::double_linked_list_button_texture_path, button_width, button_height, sf::Vector2f(x_position, double_linked_button_y_position));
			menu_button->initialize("Menu Button", Config::menu_button_texture_path, button_width, button_height, sf::Vector2f(x_position, menu_button_y_position));
		}

		void LinkedListUIController::registerButtonCallback()
		{
			single_linked_button->registerCallbackFuntion(std::bind(&LinkedListUIController::singleLinkedButtonCallback, this));
			double_linked_button->registerCallbackFuntion(std::bind(&LinkedListUIController::doubleLinkedButtonCallback, this));
			menu_button->registerCallbackFuntion(std::bind(&LinkedListUIController::menuButtonCallback, this));
		}
		
		float LinkedListUIController::calculateLeftOffsetForButton()
		{
			sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();
			return (static_cast<float>(game_window->getSize().x) / 2) - button_width / 2;
		}

		void LinkedListUIController::singleLinkedButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getLevelService()->createLevel(LinkedListType::SINGLE_LINKED_LIST);
		}

		void LinkedListUIController::doubleLinkedButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::GAMEPLAY);
			ServiceLocator::getInstance()->getLevelService()->createLevel(LinkedListType::DOUBLE_LINKED_LIST);
		}

		void LinkedListUIController::menuButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(SoundType::BUTTON_CLICK);
			GameService::setGameState(GameState::MAIN_MENU);
		}

		void LinkedListUIController::destroy()
		{
			delete(background_image);
			delete(single_linked_button);
			delete(double_linked_button);
			delete(menu_button);
		}
	}
}