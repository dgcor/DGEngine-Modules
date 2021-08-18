module;

#include <memory>

export module dgengine.parser.rectangle;

import dgengine.game;
import dgengine.json.parser;
import dgengine.rectangle;

export namespace Parser
{
	std::shared_ptr<Rectangle> getRectangleObj(Game& game, const rapidjson::Value& elem);

	typedef decltype(&getRectangleObj) getRectangleObjFuncPtr;

	void parseRectangle(Game& game, const rapidjson::Value& elem,
		const getRectangleObjFuncPtr getRectangleObjFunc);

	void parseRectangle(Game& game, const rapidjson::Value& elem);
}
