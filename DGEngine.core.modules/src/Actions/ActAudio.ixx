export module dgengine.actions.audio;

import dgengine.actions.action;
import dgengine.game;
import dgengine.sfml.musicloops;
import dgengine.variable;
import stl;

export class ActAudioDelete : public Action
{
private:
	std::string id;

public:
	ActAudioDelete(const std::string_view id_) : id(id_) {}

	bool execute(Game& game) override
	{
		game.Resources().deleteSong(id);
		return true;
	}
};

export class ActAudioPause : public Action
{
private:
	std::string id;

public:
	ActAudioPause(const std::string_view id_) : id(id_) {}

	bool execute(Game& game) override
	{
		auto song = game.Resources().getSong(id);
		if (song != nullptr)
		{
			song->pause();
		}
		return true;
	}
};

export class ActAudioPauseAll : public Action
{
public:
	bool execute(Game& game) override
	{
		game.Resources().pauseSongs();
		return true;
	}
};

export class ActAudioPlay : public Action
{
private:
	std::string id;
	Variable volume;
	bool clear;
	bool loop{ false };
	bool hasLoop{ false };

public:
	ActAudioPlay(const std::string_view id_, const Variable& volume_,
		bool clear_) : id(id_), volume(volume_), clear(clear_) {}

	void setLoop(bool loop_) noexcept
	{
		loop = loop_;
		hasLoop = true;
	}

	bool execute(Game& game) override
	{
		if (clear == true)
		{
			game.Resources().stopSongs();
		}
		auto song = game.Resources().getSong(id);
		if (song != nullptr)
		{
			if (hasLoop == true)
			{
				song->setLoop(loop);
				auto musicLoop = dynamic_cast<sf::MusicLoops*>(song.get());
				if (musicLoop != nullptr)
				{
					musicLoop->setLoop(loop);
					song->setLoop(true);
				}
			}
			auto vol = game.getVarOrProp<int64_t, unsigned>(volume, game.MusicVolume());
			song->setVolume((float)vol);

			if (song->getStatus() != sf::Music::Playing ||
				song->getPlayingOffset() == sf::microseconds(0) ||
				song->getPlayingOffset() >= song->getDuration())
			{
				song->stop();
				song->play();
			}
		}
		return true;
	}
};

export class ActAudioResumeAll : public Action
{
private:
	bool restart;

public:
	ActAudioResumeAll(bool restart_) noexcept : restart(restart_) {}

	bool execute(Game& game) override
	{
		game.Resources().playPaused(restart);
		return true;
	}
};

export class ActAudioSeek : public Action
{
private:
	std::string id;
	sf::Time time;

public:
	ActAudioSeek(const std::string_view id_, sf::Time time_) : id(id_), time(time_) {}

	bool execute(Game& game) override
	{
		auto song = game.Resources().getSong(id);
		if (song != nullptr)
		{
			song->setPlayingOffset(time);
		}
		return true;
	}
};

export class ActAudioSetVolume : public Action
{
private:
	std::string id;
	Variable volume;

public:
	ActAudioSetVolume(const std::string_view id_, const Variable& volume_)
		: id(id_), volume(volume_) {}

	bool execute(Game& game) override
	{
		auto song = game.Resources().getSong(id);
		if (song != nullptr)
		{
			auto vol = game.getVarOrProp<int64_t, unsigned>(volume, game.MusicVolume());
			if (vol > 100)
			{
				vol = 100;
			}
			song->setVolume((float)vol);
		}
		return true;
	}
};

export class ActAudioStop : public Action
{
private:
	std::string id;

public:
	ActAudioStop(const std::string_view id_) : id(id_) {}

	bool execute(Game& game) override
	{
		auto song = game.Resources().getSong(id);
		if (song != nullptr)
		{
			song->stop();
		}
		return true;
	}
};

export class ActAudioStopAll : public Action
{
public:
	bool execute(Game& game) override
	{
		game.Resources().stopSongs();
		return true;
	}
};
