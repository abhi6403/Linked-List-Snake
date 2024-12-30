#pragma once
#include<SFML/Graphics.hpp>
#include"UI/Interface/IUIController.h"
#include "UI/UIElement/ButtonView.h"
#include "UI/UIElement/ImageView.h"


namespace UI
{
	namespace LinkedListUI
    {
        class LinkedListUIController : public Interface::IUIController
        {
        private:
            const float button_width = 400.f;
			const float button_height = 140.f;

			const float single_linked_button_y_position = 500.f;
			const float double_linked_button_y_position = 700.f;
			const float menu_button_y_position = 900.f;

			const float background_alpha = 85.f;

			UI::UIElement::ImageView* background_image;

			UI::UIElement::ButtonView* single_linked_button;
			UI::UIElement::ButtonView* double_linked_button;
			UI::UIElement::ButtonView* menu_button;

			void createImage();
			void createButtons();
			void initializeBackgroundImage();
			void initializeButtons();

			float calculateLeftOffsetForButton();
			float calculateRightOffsetForButton();

			void singleLinkedButtonCallback();
			void doubleLinkedButtonCallback();
			void menuButtonCallback();
			void registerButtonCallback();

			void destroy();

		public:
			LinkedListUIController();
			~LinkedListUIController();

			void initialize();
			void update();
			void render();
			void show();
        };

    }
}