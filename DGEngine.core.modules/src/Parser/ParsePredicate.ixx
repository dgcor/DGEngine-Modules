module;

#include <memory>

export module dgengine.parser.predicate;

import dgengine.game;
import dgengine.json.parser;
import dgengine.predicates.predicate;

export namespace Parser
{
	std::shared_ptr<Predicate> getPredicateObj(Game& game, const rapidjson::Value& elem);
}
