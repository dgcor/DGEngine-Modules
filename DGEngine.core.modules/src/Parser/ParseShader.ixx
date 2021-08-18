export module dgengine.parser.shader;

import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	void parseShader(Game& game, const rapidjson::Value& elem);
}
