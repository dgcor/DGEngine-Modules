module dgengine.parser.variable;

import dgengine.parser.utils;
import dgengine.variable;

namespace Parser
{
	using namespace rapidjson;

	void parseVariable(Game& game, const Value& elem)
	{
		for (auto it = elem.MemberBegin(); it != elem.MemberEnd(); ++it)
		{
			auto key = it->name.GetStringStr();
			if (isValidId(key) == true)
			{
				Variable var;
				if (getVariableVal(it->value, var) == true)
				{
					game.setVariable(key, var);
				}
			}
		}
	}
}
