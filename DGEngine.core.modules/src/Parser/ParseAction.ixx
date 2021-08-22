export module dgengine.parser.action;

import dgengine.actions.action;
import dgengine.game;
import dgengine.json.parser;
import stl;

export namespace Parser
{
	std::shared_ptr<Action> getActionKey(Game& game, const rapidjson::Value& elem, const char* key);

	std::shared_ptr<Action> getActionVal(Game& game, const rapidjson::Value& elem);

	void parseActionAndExecute(Game& game, const rapidjson::Value& elem);
}
