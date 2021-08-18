module;

#include <memory>
#include <string>
#include <string_view>

export module dgengine.event;

import dgengine.actions.action;
import dgengine.utils.elapsedtime;

export class Event : public Action
{
private:
	std::string id;
	std::shared_ptr<Action> action;
	ElapsedTime elapsedTime;

public:
	explicit Event(const std::shared_ptr<Action>& action_,
		const sf::Time& timeout_ = sf::microseconds(0))
		: action(action_), elapsedTime(timeout_) {}

	const std::string& getId() const noexcept { return id; }
	void setId(const std::string_view id_) { id = id_; }

	void setAction(const std::shared_ptr<Action>& action_) noexcept { action = action_; }

	void resetTime() noexcept { elapsedTime.reset(); }

	bool execute(Game& game) override;
};
