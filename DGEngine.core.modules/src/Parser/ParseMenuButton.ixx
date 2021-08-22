export module dgengine.parser.menubutton;

import dgengine.anchor;
import dgengine.alignment;
import dgengine.font;
import dgengine.game;
import dgengine.json.parser;
import dgengine.menu;
import sfml;
import stl;

export namespace Parser
{
	void parseMenuButton(
		Game& game,
		const rapidjson::Value& val,
		::Menu& menu,
		Anchor anchor,
		const sf::Color& color,
		HorizontalAlign horizAlign,
		int horizSpaceOffset,
		int vertSpaceOffset,
		const Font& font,
		unsigned fontSize,
		const sf::SoundBuffer* sound,
		const sf::SoundBuffer* focusSound,
		bool clickUp,
		bool hasFocus,
		bool focusOnClick,
		bool relativePos,
		const sf::Vector2f& origPos,
		const std::string_view resource);
}
