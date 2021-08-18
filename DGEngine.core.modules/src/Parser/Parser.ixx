module;

#include <string_view>

export module dgengine.parser.parser;

import dgengine.game;

export namespace Parser
{
	void parseGame(Game& game, const std::string_view filePath, const std::string_view fileName);
}
