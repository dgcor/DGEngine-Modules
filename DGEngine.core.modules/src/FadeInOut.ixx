export module dgengine.fadeinout;

import dgengine.actions.action;
import dgengine.utils.elapsedtime;
import sfml;
import stl;

// fade out - hide
// fade in - show
export class FadeInOut
{
private:
	sf::Color color{ sf::StaticColor::Transparent() };
	bool isFadeOut{ false };
	bool enableInput{ false };
	uint8_t fadeOffset{ 0 };
	ElapsedTime elapsedTime;
	std::shared_ptr<Action> action;
	bool running{ false };
	bool updateEnableInput{ false };

	void UpdateFade() noexcept;
	bool HasFadeEnded() noexcept;

public:
	const sf::Color& getColor() const noexcept { return color; }

	void Reset(sf::Color color_, bool isFadeOut_, bool enableInput_, uint8_t fadeOffset_,
		const sf::Time& timeout_, const std::shared_ptr<Action>& action_);

	void update(Game& game) noexcept;
};
