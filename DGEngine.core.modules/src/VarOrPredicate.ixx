export module dgengine.varorpredicate;

import dgengine.predicates.predicate;
import dgengine.variable;
import stl;

export
{
	typedef std::variant<Variable, std::shared_ptr<Predicate>> VarOrPredicate;

	constexpr bool holdsVariable(const VarOrPredicate& var) noexcept
	{
		return std::holds_alternative<Variable>(var);
	}

	constexpr bool holdsPredicate(const VarOrPredicate& var) noexcept
	{
		return std::holds_alternative<std::shared_ptr<Predicate>>(var);
	}
}
