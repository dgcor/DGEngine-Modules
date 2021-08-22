export module dgengine.parser.button;

import dgengine.button;
import dgengine.game;
import dgengine.json.parser;
import stl;

export namespace Parser
{
	std::shared_ptr<Button> parseBitmapButton(Game& game, const rapidjson::Value& elem);

	std::shared_ptr<Button> parseStringButton(Game& game, const rapidjson::Value& elem);

	std::shared_ptr<Button> parseButtonObj(Game& game, const rapidjson::Value& elem);

	typedef decltype(&parseButtonObj) parseButtonObjFuncPtr;

	void parseButton(Game& game, const rapidjson::Value& elem,
		const parseButtonObjFuncPtr parseButtonObjFunc);

	void parseButton(Game& game, const rapidjson::Value& elem);
}
