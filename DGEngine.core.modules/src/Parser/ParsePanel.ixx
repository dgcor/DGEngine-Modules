export module dgengine.parser.panel;

import dgengine.game;
import dgengine.json.parser;
import dgengine.panel;
import stl;

export namespace Parser
{
	std::shared_ptr<Panel> getPanelObj(Game& game, const rapidjson::Value& elem);

	typedef decltype(&getPanelObj) getPanelObjFuncPtr;

	void parsePanel(Game& game, const rapidjson::Value& elem,
		const getPanelObjFuncPtr getPanelObjFunc);

	void parsePanel(Game& game, const rapidjson::Value& elem);
}
