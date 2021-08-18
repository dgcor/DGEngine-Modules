module;

#include <memory>

export module dgengine.parser.inputtext;

import dgengine.game;
import dgengine.inputtext;
import dgengine.json.parser;

export namespace Parser
{
	std::shared_ptr<InputText> getInputTextObj(Game& game, const rapidjson::Value& elem);

	typedef decltype(&getInputTextObj) getInputTextObjFuncPtr;

	void parseInputText(Game& game, const rapidjson::Value& elem,
		const getInputTextObjFuncPtr getInputTextObjFunc);

	void parseInputText(Game& game, const rapidjson::Value& elem);
}
