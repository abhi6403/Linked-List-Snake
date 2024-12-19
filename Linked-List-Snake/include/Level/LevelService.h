#pragma once
#include"Level/LevelController.h"

namespace Level
{
	class LevelService
	{
	private:
		LevelController* level_controller;
		LevelNumber current_level;

		void createLevelController();
		void destroy();

	public:
		LevelService();
		~LevelService();

		void initialize();
		void update();
		void render();

		void createLevel(LevelNumber level_to_load);
	};
}