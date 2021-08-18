module;

#include <memory>
#include <unordered_map>
#include <variant>

export module dgengine.audiosource;

import dgengine.sfml.physfsstream;
import sfml;

export struct SoundBufferLoops
{
	sf::SoundBuffer soundBuffer;
	std::unordered_map<std::string, sf::Music::TimeSpan> loops;
};

export struct SoundFileLoops
{
	sf::PhysFSStream file;
	std::unordered_map<std::string, sf::Music::TimeSpan> loops;

	SoundFileLoops(const std::string& fileName) : file(fileName) {}
	SoundFileLoops(const char* fileName) : file(fileName) {}
};

export typedef std::variant<
	std::shared_ptr<sf::SoundBuffer>,
	std::shared_ptr<sf::InputStream>,
	std::shared_ptr<SoundBufferLoops>,
	std::shared_ptr<SoundFileLoops>>
	AudioSource;
