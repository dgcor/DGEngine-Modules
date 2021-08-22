export module dgengine.parser.scrollable;

import dgengine.game;
import dgengine.json.parser;
import dgengine.scrollable;
import stl;

export namespace Parser
{
	std::shared_ptr<Scrollable> getScrollableObj(Game& game, const rapidjson::Value& elem,
		std::shared_ptr<UIObject>& uiObj);

	typedef decltype(&getScrollableObj) getScrollableObjFuncPtr;

	void parseScrollable(Game& game, const rapidjson::Value& elem,
		const getScrollableObjFuncPtr getScrollableObjFunc);

	void parseScrollable(Game& game, const rapidjson::Value& elem);
}
