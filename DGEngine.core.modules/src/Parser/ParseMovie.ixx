export module dgengine.parser.movie;

import dgengine.game;
import dgengine.json.parser;
import dgengine.movie;
import stl;

export namespace Parser
{
	std::shared_ptr<Movie> getMovieObj(Game& game, const rapidjson::Value& elem,
		const std::string_view file);

	typedef decltype(&getMovieObj) getMovieObjFuncPtr;

	void parseMovie(Game& game, const rapidjson::Value& elem,
		const getMovieObjFuncPtr getMovieObjFunc);

	void parseMovie(Game& game, const rapidjson::Value& elem);
}
