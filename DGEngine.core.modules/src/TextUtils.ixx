module;

#include <string_view>
#include <vector>

export module dgengine.textutils;

import dgengine.actions.action;
import dgengine.anchor;
import dgengine.queryable;
import sfml;

class Game;

export namespace TextUtils
{
	enum class TextOp : uint32_t
	{
		Set = 0,
		Replace = 1,
		Query = 2,
		FormatString = 3,
		ReplaceAll = 4,
		Trim = 8,
		RemoveEmptyLines = 16,
	};
}

using T = std::underlying_type_t<TextUtils::TextOp>;

export namespace TextUtils
{
	constexpr TextOp operator~ (TextOp a) noexcept { return (TextOp)~static_cast<T>(a); }
	constexpr TextOp operator| (TextOp a, TextOp b) noexcept { return (TextOp)(static_cast<T>(a) | static_cast<T>(b)); }
	constexpr TextOp operator& (TextOp a, TextOp b) noexcept { return (TextOp)(static_cast<T>(a) & static_cast<T>(b)); }
	constexpr TextOp operator^ (TextOp a, TextOp b) noexcept { return (TextOp)(static_cast<T>(a) ^ static_cast<T>(b)); }
	constexpr TextOp& operator|= (TextOp& a, TextOp b) noexcept { a = (TextOp)(static_cast<T>(a) | static_cast<T>(b)); return a; }
	constexpr TextOp& operator&= (TextOp& a, TextOp b) noexcept { a = (TextOp)(static_cast<T>(a) & static_cast<T>(b)); return a; }
	constexpr TextOp& operator^= (TextOp& a, TextOp b) noexcept { a = (TextOp)(static_cast<T>(a) ^ static_cast<T>(b)); return a; }

	bool getFormatString(const Game& game, const std::string_view format,
		const std::vector<std::string>& bindings, std::string& outStr);

	std::string getFormatString(const Game& game, const std::string_view format,
		const std::vector<std::string>& bindings);

	std::string getTextQueryable(const Game& game, const std::string_view format,
		const std::string_view query);

	std::string getText(const Game& game, TextOp textOp, const std::string_view textOrformat,
		const std::vector<std::string>& bindings);

	void appendText(const Game& game, TextOp textOp, std::string& str,
		const std::string_view textOrformat, const std::vector<std::string>& bindings);
}
