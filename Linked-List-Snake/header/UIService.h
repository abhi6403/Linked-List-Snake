#pragma once

class IUIController;
class SplashScreenUIController;
class MainMenuUIController;
class LevelSelectionUIController;
class GameplayUIController;

class UIService
{
private:
	SplashScreenUIController* splash_screen_controller;
	MainMenuUIController* main_menu_controller;
	LevelSelectionUIController* level_selection_ui_controller;
	GameplayUIController* gameplay_ui_controller;

	void createControllers();
	void initializeControllers();
	IUIController* getCurrentUIController();
	void destroy();

public:
	UIService();
	~UIService();

	void initialize();
	void update();
	void render();
	void showScreen();
};