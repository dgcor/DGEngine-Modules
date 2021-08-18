export module dgengine.parser.filebytes;

import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	bool parseFileBytesFromId(Game& game, const rapidjson::Value& elem);

	void parseFileBytes(Game& game, const rapidjson::Value& elem);
}
