#pragma once
#include"Level//LevelService.h"
#include "Level/LevelController.h"

namespace Level
{
	struct LevelData
	{
		LevelData(LevelNumber ind)
		{
			level_index = ind;
		}

		LevelNumber level_index;
	};

}