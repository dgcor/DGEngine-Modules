export module dgengine.parser.font;

import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	bool parseFontFromId(Game& game, const rapidjson::Value& elem);

	bool cloneFont(Game& game, const rapidjson::Value& elem);

	bool parseBitmapFont(Game& game, const rapidjson::Value& elem);

	bool parseFreeTypeFont(Game& game, const rapidjson::Value& elem);

	void parseFont(Game& game, const rapidjson::Value& elem);
}
