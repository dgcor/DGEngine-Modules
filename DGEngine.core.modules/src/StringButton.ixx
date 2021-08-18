module;

#include <string_view>

export module dgengine.stringbutton;

import dgengine.bindabletext;
import dgengine.button;
import sfml;

export class StringButton : public Button, public BindableText
{
public:
	using BindableText::BindableText;

	std::shared_ptr<Action> getAction(uint16_t nameHash16) const noexcept override;
	bool setAction(uint16_t nameHash16, const std::shared_ptr<Action>& action) noexcept override;

	void setColor(const sf::Color& color_) override { Text::setColor(color_); }

	void update(Game& game) override;

	bool getProperty(const std::string_view prop, Variable& var) const override;
};
