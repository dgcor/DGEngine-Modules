export module dgengine.parser.image;

import dgengine.game;
import dgengine.image;
import dgengine.json.parser;
import stl;

export namespace Parser
{
	std::shared_ptr<Image> getImageObj(Game& game, const rapidjson::Value& elem);

	typedef decltype(&getImageObj) getImageObjFuncPtr;

	void parseImage(Game& game, const rapidjson::Value& elem,
		const getImageObjFuncPtr getImageObjFunc);

	void parseImage(Game& game, const rapidjson::Value& elem);
}
