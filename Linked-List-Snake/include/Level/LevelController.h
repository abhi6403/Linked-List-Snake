#pragma once

namespace Level
{
	enum class LevelNumber
	{
		ONE,
		TWO,
	};

	class LevelController
	{
	private:

	public:
		LevelController();
		~LevelController();

		void initialize();
		void update();
		void render();

	};
}