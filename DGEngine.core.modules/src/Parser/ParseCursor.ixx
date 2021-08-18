export module dgengine.parser.cursor;

import dgengine.game;
import dgengine.json.parser;
import dgengine.parser.animation;

export namespace Parser
{
	void parseCursor(Game& game, const rapidjson::Value& elem,
		const getAnimationObjFuncPtr getAnimationObjFunc);

	void parseCursor(Game& game, const rapidjson::Value& elem);
}
