export module dgengine.actions.fade;

import dgengine.actions.action;
import dgengine.fadeinout;
import dgengine.game;
import sfml;
import stl;

export class ActGameFade : public Action
{
private:
	sf::Color color;
	bool isFadeOut;
	bool enableInput;
	uint8_t fadeOffset;
	sf::Time refresh;
	std::shared_ptr<Action> action;

public:
	ActGameFade(const sf::Color& color_, bool isFadeOut_, bool enableInput_,
		uint8_t fadeOffset_, sf::Time refresh_) noexcept : color(color_),
		isFadeOut(isFadeOut_), enableInput(enableInput_), fadeOffset(fadeOffset_),
		refresh(refresh_), action(nullptr) {}

	void setAction(const std::shared_ptr<Action>& action_) noexcept { action = action_; }

	bool execute(Game& game) override
	{
		game.FadeObj().Reset(
			color,
			isFadeOut,
			enableInput,
			fadeOffset,
			refresh,
			action);
		return true;
	}
};
