export module dgengine.font;

import dgengine.bitmapfont;
import dgengine.freetypefont;
import stl;

export
{
	typedef std::variant<
		std::nullptr_t,
		std::shared_ptr<BitmapFont>,
		std::shared_ptr<FreeTypeFont>>
		Font;

	constexpr bool holdsNullFont(const Font& var) noexcept
	{
		return std::holds_alternative<std::nullptr_t>(var);
	}

	constexpr bool holdsBitmapFont(const Font& var) noexcept
	{
		return std::holds_alternative<std::shared_ptr<BitmapFont>>(var);
	}

	constexpr bool holdsFreeTypeFont(const Font& var) noexcept
	{
		return std::holds_alternative<std::shared_ptr<FreeTypeFont>>(var);
	}
}
