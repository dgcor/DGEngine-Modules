module;

#include <memory>
#include <string_view>

export module dgengine.actions.sound;

import dgengine.actions.action;
import dgengine.fileutils;
import dgengine.game;
import dgengine.parser.sound;
import dgengine.parser.utils;
import dgengine.variable;
import sfml;

export class ActSoundLoadPlay : public Action
{
private:
	std::string file;
	std::string id;
	Variable volume;
	sf::Time seek;
	bool unique;

public:
	ActSoundLoadPlay(const std::string_view file_, const Variable& volume_,
		sf::Time seek_, bool unique_) : file(file_), volume(volume_),
		seek(seek_), unique(unique_)
	{
		Parser::getIdFromFile(file_, id);
	}

	bool execute(Game& game) override
	{
		auto sndBuffer = game.Resources().getSoundBuffer(id);

		if (sndBuffer == nullptr && id.empty() == false)
		{
			sndBuffer = Parser::parseSoundObj(game, id, file, {});
		}
		if (sndBuffer != nullptr)
		{
			sf::Sound sound(*sndBuffer);
			auto vol = game.getVarOrProp<int64_t, unsigned>(volume, game.SoundVolume());
			if (vol > 0)
			{
				if (vol > 100)
				{
					vol = 100;
				}
				sound.setVolume((float)vol);
				game.Resources().addPlayingSound(sound, unique, seek);
			}
		}
		return true;
	}
};

export class ActSoundPlay : public Action
{
private:
	std::string id;
	Variable volume;
	sf::Time seek;
	bool unique;

public:
	ActSoundPlay(const std::string_view id_, const Variable& volume_,
		sf::Time seek_, bool unique_) : id(id_), volume(volume_),
		seek(seek_), unique(unique_) {}

	bool execute(Game& game) override
	{
		auto sndBuffer = game.Resources().getSoundBuffer(id);
		if (sndBuffer != nullptr)
		{
			sf::Sound sound(*sndBuffer);
			auto vol = game.getVarOrProp<int64_t, unsigned>(volume, game.SoundVolume());
			if (vol > 0)
			{
				if (vol > 100)
				{
					vol = 100;
				}
				sound.setVolume((float)vol);
				game.Resources().addPlayingSound(sound, unique, seek);
			}
		}
		return true;
	}
};
