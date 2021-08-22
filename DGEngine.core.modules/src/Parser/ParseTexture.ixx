export module dgengine.parser.texture;

import dgengine.game;
import dgengine.json.parser;
import sfml;
import stl;

export namespace Parser
{
	sf::Image parseTextureImg(Game& game, const rapidjson::Value& elem);

	bool parseTextureFromId(Game& game, const rapidjson::Value& elem);

	std::shared_ptr<sf::Texture> getTextureObj(Game& game, const rapidjson::Value& elem);

	typedef decltype(&getTextureObj) getTextureObjFuncPtr;

	void parseTexture(Game& game, const rapidjson::Value& elem,
		const getTextureObjFuncPtr getTextureObjFunc);

	void parseTexture(Game& game, const rapidjson::Value& elem);
}
