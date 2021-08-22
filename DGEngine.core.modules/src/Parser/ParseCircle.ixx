export module dgengine.parser.circle;

import dgengine.circle;
import dgengine.game;
import dgengine.json.parser;
import stl;

export namespace Parser
{
	std::shared_ptr<Circle> getCircleObj(Game& game, const rapidjson::Value& elem);

	typedef decltype(&getCircleObj) getCircleObjFuncPtr;

	void parseCircle(Game& game, const rapidjson::Value& elem,
		const getCircleObjFuncPtr getCircleObjFunc);

	void parseCircle(Game& game, const rapidjson::Value& elem);
}
