module dgengine.parser.predicate;

import dgengine.hooks;
import dgengine.predicates.io;
import dgengine.parser.utils;
import dgengine.utils.utils;

namespace Parser
{
	using namespace rapidjson;
	using namespace std::literals;

	std::shared_ptr<Predicate> getPredicateObj(Game& game, const Value& elem)
	{
		if (isValidString(elem, "name") == false)
		{
			return nullptr;
		}
		auto nameHash = str2int16(elem["name"sv].GetStringView());
		switch (nameHash)
		{
		case str2int16("file.exists"):
		{
			return std::make_shared<PredFileExists>(getStringKey(elem, "file"));
		}
		case str2int16("gamefile.exists"):
		{
			return std::make_shared<PredGamefileExists>(getStringKey(elem, "file"));
		}
		default:
		{
			if (Hooks::GetPredicateObj != nullptr)
			{
				return Hooks::GetPredicateObj(game, nameHash, elem);
			}
			else
			{
				return nullptr;
			}
		}
		}
	}
}
