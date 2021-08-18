module;

#include <memory>

export module dgengine.actions.loadingscreen;

import dgengine.actions.action;
import dgengine.game;
import dgengine.utils.utils;

export class ActLoadingScreenSetProgress : public Action
{
private:
	int progress;

public:
	ActLoadingScreenSetProgress(int progress_) noexcept : progress(progress_) {}

	bool execute(Game& game) override
	{
		auto loadingScreen = game.getLoadingScreen();
		if (loadingScreen != nullptr)
		{
			loadingScreen->setProgress(progress);
			game.drawLoadingScreen();
			if (loadingScreen->isComplete())
			{
				game.Events().addBack(loadingScreen->getAction(str2int16("complete")));
			}
		}
		return true;
	}
};

export class ActLoadingScreenClear : public Action
{
public:
	bool execute(Game& game) noexcept override
	{
		game.setLoadingScreen(nullptr);
		return true;
	}
};
