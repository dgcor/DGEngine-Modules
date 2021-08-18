module;

#include <memory>
#include <string_view>

export module dgengine.actions.movie;

import dgengine.actions.action;
import dgengine.game;
import dgengine.movie;

export class ActMoviePause : public Action
{
private:
	std::string id;

public:
	ActMoviePause(const std::string_view id_) : id(id_) {}

	bool execute(Game& game) override
	{
		auto movie = game.Resources().getDrawable<Movie>(id);
		if (movie != nullptr)
		{
			movie->pause();
		}
		return true;
	}
};

export class ActMoviePlay : public Action
{
private:
	std::string id;

public:
	ActMoviePlay(const std::string_view id_) : id(id_) {}

	bool execute(Game& game) override
	{
		auto movie = game.Resources().getDrawable<Movie>(id);
		if (movie != nullptr)
		{
			movie->play();
		}
		return true;
	}
};
