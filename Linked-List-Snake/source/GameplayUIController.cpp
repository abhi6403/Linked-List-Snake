#include "../header/GameplayUIController.h"
#include "../header/GameService.h"
#include "../header/GraphicService.h"
#include "../header/SoundService.h"
#include "../header/EventService.h"
#include "../header/TextView.h"
#include "../header/Config.h"

GameplayUIController::GameplayUIController()
{
    createTexts();
}

GameplayUIController::~GameplayUIController()
{
    destroy();
}

void GameplayUIController::initialize()
{
    initializeTexts();
}

void GameplayUIController::createTexts()
{
    level_number_text = new TextView();
    score_text = new TextView();
    time_complexity_text = new TextView();
}

void GameplayUIController::initializeTexts()
{
    initializeLevelNumberText();
    initializeScoreText();
    initializeTimeComplexityText();
}

void GameplayUIController::initializeLevelNumberText()
{
    level_number_text->initialize("Level : 1", sf::Vector2f(level_number_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
}

void GameplayUIController::initializeScoreText()
{
    score_text->initialize("Score : 0", sf::Vector2f(score_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
}

void GameplayUIController::initializeTimeComplexityText()
{
    time_complexity_text->initialize("Time Complexity : O(1)", sf::Vector2f(time_complexity_text_x_position, text_y_position), FontType::BUBBLE_BOBBLE, font_size, sf::Color::Black);
}

void GameplayUIController::update()
{
    level_number_text->update();
    score_text->update();
    time_complexity_text->update();
}

void GameplayUIController::render()
{
    level_number_text->render();
    score_text->render();
    time_complexity_text->render();
}

void GameplayUIController::show()
{
    level_number_text->show();
    score_text->show();
    time_complexity_text->show();
}

void GameplayUIController::destroy()
{
    delete (level_number_text);
    delete (score_text);
    delete (time_complexity_text);
}
