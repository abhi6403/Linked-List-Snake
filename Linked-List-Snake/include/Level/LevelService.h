#pragma once
#include"Level/LevelController.h"
#include"Level/LevelNumber.h"

namespace Level
{
	class LevelController;

	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void createLevelController();
		void spawnLevelElements(LevelNumber level_to_load);
		void spawnPlayer();
		void spawnFood();
		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LevelNumber level_to_load);

		float getCellWidth();
		float getCellHeight();
	};
}