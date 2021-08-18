module;

#include <memory>

export module dgengine.parser.text;

import dgengine.bindabletext;
import dgengine.drawabletext;
import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	std::unique_ptr<DrawableText> getDrawableTextObj(Game& game, const rapidjson::Value& elem);

	std::unique_ptr<BindableText> getTextObj(Game& game, const rapidjson::Value& elem);

	void parseTextObj(Game& game, const rapidjson::Value& elem, BindableText& text);

	typedef decltype(&getTextObj) getTextObjFuncPtr;

	void parseText(Game& game, const rapidjson::Value& elem,
		const getTextObjFuncPtr getTextObjFunc);

	void parseText(Game& game, const rapidjson::Value& elem);
}
