module;

#include <memory>

export module dgengine.parser.animation;

import dgengine.animation;
import dgengine.game;
import dgengine.json.parser;

export namespace Parser
{
	std::shared_ptr<Animation> getAnimationObj(Game& game, const rapidjson::Value& elem);

	typedef decltype(&getAnimationObj) getAnimationObjFuncPtr;

	void parseAnimation(Game& game, const rapidjson::Value& elem,
		const getAnimationObjFuncPtr getAnimationObjFunc);

	void parseAnimation(Game& game, const rapidjson::Value& elem);
}
