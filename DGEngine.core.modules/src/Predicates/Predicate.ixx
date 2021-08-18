export module dgengine.predicates.predicate;

import dgengine.variable;

export class Game;

export class Predicate
{
public:
	virtual ~Predicate() = default;
	virtual Variable getResult(const Game& game) const = 0;
};
