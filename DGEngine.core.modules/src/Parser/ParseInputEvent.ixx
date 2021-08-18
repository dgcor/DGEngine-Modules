export module dgengine.parser.inputevent;

import dgengine.game;
import dgengine.json.parser;
import sfml;

export namespace Parser
{
	sf::Event updateKeyEvent(sf::Event evt);

	void parseActionKey(Game& game, const rapidjson::Value& elem);

	void parseEventKey(Game& game, const rapidjson::Value& elem);

	void parseInputEvent(Game& game, const rapidjson::Value& elem);
}
