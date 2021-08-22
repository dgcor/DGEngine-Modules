export module dgengine.parser.utils;

import dgengine.json.parser;
import dgengine.parser.properties;
export import dgengine.parser.utils.idx;
export import dgengine.parser.utils.key;
export import dgengine.parser.utils.val;
import stl;

export namespace Parser
{
	ReplaceVars getReplaceVars(const std::string_view str, ReplaceVars val = ReplaceVars::None);

	bool getIdFromFile(const std::string_view file, std::string& id);

	bool isValidArray(const rapidjson::Value& elem, const std::string_view key);

	bool isValidId(const std::string_view id) noexcept;

	bool isValidString(const rapidjson::Value& elem);

	bool isValidString(const rapidjson::Value& elem, const std::string_view key);
}
