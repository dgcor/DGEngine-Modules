export module dgengine.parser.mountfile;

import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	void parseMountFile(const Game& game, const rapidjson::Value& elem);
}
