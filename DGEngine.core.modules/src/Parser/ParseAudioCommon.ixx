module;

#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

export module dgengine.parser.audiocommon;

import dgengine.game;
import dgengine.json.parser;
import dgengine.sfml.musicloops;
import sfml;

export namespace Parser
{
	sf::Music::TimeSpan parseAudioTimeSpan(const rapidjson::Value& elem);

	void parseAudioLoopName(const rapidjson::Value& elem,
		std::unordered_map<std::string, sf::Music::TimeSpan>& loopNames);

	void parseAudioLoopNamesVal(const rapidjson::Value& elem, const char* key,
		std::unordered_map<std::string, sf::Music::TimeSpan>& loopNames);

	void parseAudioLoopPoint(const rapidjson::Value& elem,
		std::vector<sf::Music::TimeSpan>& loopPoints);

	void parseAudioLoopPointsVal(const rapidjson::Value& elem,
		const char* key, sf::MusicLoops& music);

	void updateAudioLoopString(const std::string_view str,
		const std::unordered_map<std::string, sf::Music::TimeSpan>& loopNames,
		sf::MusicLoops& music);
}
