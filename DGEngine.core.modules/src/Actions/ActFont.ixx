module;

#include <memory>
#include <string_view>
#include <variant>

export module dgengine.actions.font;

import dgengine.actions.action;
import dgengine.font;
import dgengine.game;
import sfml;

export class ActFontSetPaletteOrColor : public Action
{
private:
	std::string id;
	std::string idPalette;
	sf::Color color;

public:
	ActFontSetPaletteOrColor(const std::string_view id_,
		const std::string_view idPalette_, const sf::Color& color_)
		: id(id_), idPalette(idPalette_), color(color_) {}

	bool execute(Game& game) override
	{
		auto font = game.Resources().getFont(id);
		if (holdsBitmapFont(font) == true)
		{
			auto bitmapFont = std::get<std::shared_ptr<BitmapFont>>(font);
			if (bitmapFont->hasPalette() == true)
			{
				auto palette = game.Resources().getPalette(idPalette);
				if (palette != nullptr)
				{
					bitmapFont->setPalette(palette);
				}
			}
			else
			{
				bitmapFont->setColor(color);
			}
		}
		else if (holdsFreeTypeFont(font) == true)
		{
			auto freeTypeFont = std::get<std::shared_ptr<FreeTypeFont>>(font);
			freeTypeFont->setColor(color);
		}
		return true;
	}
};
