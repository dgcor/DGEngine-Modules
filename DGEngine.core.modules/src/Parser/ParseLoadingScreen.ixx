export module dgengine.parser.loadingscreen;

import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	void parseLoadingScreen(Game& game, const rapidjson::Value& elem);
}
