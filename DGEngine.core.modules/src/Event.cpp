module dgengine.event;

import dgengine.game;
import sfml;

bool Event::execute(Game& game)
{
	if (action == nullptr)
	{
		return true;
	}
	if (elapsedTime.currentTime == sf::microseconds(0))
	{
		// prevents executing events created while loading big files immediately
		elapsedTime.currentTime = sf::microseconds(1);
		return false;
	}
	if (elapsedTime.timeout == sf::microseconds(0) ||
		elapsedTime.update(game.getElapsedTime()) == true)
	{
		auto ret = action->execute(game);
		if (ret == true || elapsedTime.timeout == sf::microseconds(0))
		{
			resetTime();
		}
		return ret;
	}
	return false;
}
