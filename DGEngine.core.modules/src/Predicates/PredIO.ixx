export module dgengine.predicates.io;

import dgengine.fileutils;
import dgengine.game;
import dgengine.gameutils;
import dgengine.predicates.predicate;
import dgengine.variable;
import stl;

export class PredFileExists : public Predicate
{
private:
	std::string file;

public:
	PredFileExists(const std::string& file_) : file(file_) {}

	Variable getResult(const Game& game) const override
	{
		auto file2 = GameUtils::replaceStringWithVarOrProp(file, game);
		if (file2.empty() == false)
		{
			return { FileUtils::exists(file2.c_str()) };
		}
		return { false };
	}
};

export class PredGamefileExists : public Predicate
{
private:
	std::string file;

public:
	PredGamefileExists(const std::string& file_) : file(file_) {}

	Variable getResult(const Game& game) const override
	{
		auto file2 = GameUtils::replaceStringWithVarOrProp(game.getPath() + file, game);
		if (file2.empty() == false)
		{
			return { FileUtils::gamefileExists(file2.c_str()) };
		}
		return { false };
	}
};
