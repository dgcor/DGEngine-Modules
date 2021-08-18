export module dgengine.actions.action;

export class Game;

export class Action
{
public:
	virtual ~Action() = default;
	virtual bool execute(Game& game) = 0;
};
