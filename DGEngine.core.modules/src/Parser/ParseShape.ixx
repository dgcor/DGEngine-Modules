module;

#include <memory>

export module dgengine.parser.shape;

import dgengine.game;
import dgengine.json.parser;
import dgengine.shape;

export namespace Parser
{
	std::shared_ptr<Shape> getShapeObj(Game& game, const rapidjson::Value& elem);

	typedef decltype(&getShapeObj) getShapeObjFuncPtr;

	void parseShape(Game& game, const rapidjson::Value& elem,
		const getShapeObjFuncPtr getShapeObjFunc);

	void parseShape(Game& game, const rapidjson::Value& elem);
}
