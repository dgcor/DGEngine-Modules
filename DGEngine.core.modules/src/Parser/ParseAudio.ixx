module;

#include <memory>
#include <string_view>

export module dgengine.parser.audio;

import dgengine.audiosource;
import dgengine.game;
import dgengine.json.parser;
import dgengine.sfml.music2;

export namespace Parser
{
	bool openMusicFromBuffer(Game& game, std::shared_ptr<sf::Music2>& music,
		sf::SoundBuffer& buffer, const std::string& id, const std::string_view resource);

	bool openMusicFromFile(Game& game, std::shared_ptr<sf::Music2> music,
		sf::InputStream& stream, const AudioSource audioSource,
		const std::string& id, const std::string_view resource);

	sf::Music2* parseAudioObjFromFile(Game& game, const rapidjson::Value& elem,
		const std::string& id, const std::string& file);

	sf::Music2* parseAudioObjFromSource(Game& game,
		const rapidjson::Value& elem, const std::string& id);

	sf::Music2* parseAudioObj(Game& game, const rapidjson::Value& elem);

	bool parseAudioFromId(Game& game, const rapidjson::Value& elem);

	typedef decltype(&parseAudioObj) parseAudioObjFuncPtr;

	void parseAudio(Game& game, const rapidjson::Value& elem,
		const parseAudioObjFuncPtr parseAudioObjFunc);

	void parseAudio(Game& game, const rapidjson::Value& elem);
}
