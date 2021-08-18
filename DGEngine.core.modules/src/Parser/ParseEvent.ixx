export module dgengine.parser.event;

import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	void parseEvent(Game& game, const rapidjson::Value& elem);
}
