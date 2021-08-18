module;

#include <cstdint>
#include <string>
#include <variant>

export module dgengine.variable;

export typedef std::variant<std::string, int64_t, double, bool> Variable;

export namespace VarUtils
{
	bool toBool(const Variable& var) noexcept;
	double toDouble(const Variable& var) noexcept;
	int64_t toInt64(const Variable& var) noexcept;
	std::string toString(const Variable& var);
}
