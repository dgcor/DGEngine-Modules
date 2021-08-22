export module dgengine.parser.parser;

import dgengine.game;
import stl;

export namespace Parser
{
	void parseGame(Game& game, const std::string_view filePath, const std::string_view fileName);
}
