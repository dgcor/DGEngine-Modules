export module dgengine.actions.button;

import dgengine.actions.action;
import dgengine.button;
import dgengine.game;
import stl;

export class ActButtonClick : public Action
{
private:
	std::string id;
	bool playSound;

public:
	ActButtonClick(const std::string_view id_, bool playSound_)
		: id(id_), playSound(playSound_) {}

	bool execute(Game& game) override
	{
		auto button = game.Resources().getDrawable<Button>(id);
		if (button != nullptr)
		{
			button->click(game, playSound);
		}
		return true;
	}
};

export class ActButtonEnable : public Action
{
private:
	std::string id;
	bool enable;

public:
	ActButtonEnable(const std::string_view id_, bool enable_)
		: id(id_), enable(enable_) {}

	bool execute(Game& game) noexcept override
	{
		auto button = game.Resources().getDrawable<Button>(id);
		if (button != nullptr)
		{
			button->enable(enable);
		}
		return true;
	}
};

export class ActButtonRightClick : public Action
{
private:
	std::string id;
	bool playSound;

public:
	ActButtonRightClick(const std::string_view id_, bool playSound_)
		: id(id_), playSound(playSound_) {}

	bool execute(Game& game) override
	{
		auto button = game.Resources().getDrawable<Button>(id);
		if (button != nullptr)
		{
			button->rightClick(game, playSound);
		}
		return true;
	}
};

export class ActButtonSetColor : public Action
{
private:
	std::string id;
	sf::Color color;

public:
	ActButtonSetColor(const std::string_view id_, const sf::Color& color_)
		: id(id_), color(color_) {}

	bool execute(Game& game) override
	{
		auto button = game.Resources().getDrawable<Button>(id);
		if (button != nullptr)
		{
			button->setColor(color);
		}
		return true;
	}
};
