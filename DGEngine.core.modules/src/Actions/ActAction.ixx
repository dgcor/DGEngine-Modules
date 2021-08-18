module;

#include <memory>
#include <string_view>

export module dgengine.actions.actions;

import dgengine.actions.action;
import dgengine.game;

export class ActActionSet : public Action
{
private:
	std::string key;
	std::shared_ptr<Action> action;

public:
	ActActionSet(const std::string_view key_, const std::shared_ptr<Action>& action_)
		: key(key_), action(action_) {}

	bool execute(Game& game) override
	{
		if (key.empty() == false)
		{
			game.Resources().setAction(key, action);
		}
		return true;
	}
};
