module;

#include <cstdint>
#include <memory>

export module dgengine.parser.condition;

import dgengine.actions.action;
import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	std::shared_ptr<Action> getIfCondition(uint16_t conditionHash16,
		Game& game, const rapidjson::Value& elem);

	std::shared_ptr<Action> getInListCondition(Game& game, const rapidjson::Value& elem);

	std::shared_ptr<Action> getMultiIfCondition(Game& game, const rapidjson::Value& elem);

	std::shared_ptr<Action> getSwitchCondition(Game& game, const rapidjson::Value& elem);
}
