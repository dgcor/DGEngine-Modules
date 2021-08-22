export module dgengine.actions.inputtext;

import dgengine.actions.action;
import dgengine.game;
import dgengine.inputtext;
import stl;

export class ActInputTextClick : public Action
{
private:
	std::string id;

public:
	ActInputTextClick(const std::string_view id_) : id(id_) {}

	bool execute(Game& game) override
	{
		auto text = game.Resources().getDrawable<InputText>(id);
		if (text != nullptr)
		{
			text->click(game);
		}
		return true;
	}
};
