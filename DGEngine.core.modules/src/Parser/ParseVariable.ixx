module;

#include <memory>

export module dgengine.parser.variable;

import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	void parseVariable(Game& game, const rapidjson::Value& elem);
}
