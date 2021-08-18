export module dgengine.parser.palette;

import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	bool parsePaletteFromId(Game& game, const rapidjson::Value& elem);

	void parsePalette(Game& game, const rapidjson::Value& elem);
}
