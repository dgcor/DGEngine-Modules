export module dgengine.hooks;

import dgengine.actions.action;
import dgengine.filebytes;
import dgengine.imagecontainers.imagecontainer;
import dgengine.json.parser;
import dgengine.parser.properties;
import dgengine.predicates.predicate;
import dgengine.queryable;
import dgengine.shadermanager;
import dgengine.variable;
import sfml;
import stl;

class Game;

export namespace Hooks
{
	typedef void(*InitializeShaderManagerFuncPtr)(ShaderManager& shaderManager);
	typedef bool(*ParseDocumentElemFuncPtr)(Game& game, uint16_t nameHash16, const rapidjson::Value& elem,
		ReplaceVars& replaceVars, rapidjson::MemoryPoolAllocator<rapidjson::CrtAllocator>& allocator);
	typedef std::shared_ptr<Action>(*ParseActionElemFuncPtr)(Game& game,
		uint16_t nameHash16, const rapidjson::Value& elem);
	typedef std::shared_ptr<Predicate>(*GetPredicateObjFuncPtr)(Game& game,
		uint16_t nameHash16, const rapidjson::Value& elem);
	typedef bool(*GetImageContainerObjFuncPtr)(std::shared_ptr<FileBytes>& fileBytes,
		const std::string_view fileName, const rapidjson::Value& elem,
		std::shared_ptr<ImageContainer>& imgContainer);
	typedef bool(*DecodeImageFuncPtr)(sf::InputStream& file, sf::Image& image);
	typedef bool(*ParseTextureImgFuncPtr)(Game& game, const rapidjson::Value& elem, sf::Image& img);
	typedef void(*RegisterArchiversFuncPtr)();

	extern InitializeShaderManagerFuncPtr InitializeShaderManager;
	extern ParseDocumentElemFuncPtr ParseDocumentElem;
	extern ParseActionElemFuncPtr ParseActionElem;
	extern GetPredicateObjFuncPtr GetPredicateObj;
	extern GetImageContainerObjFuncPtr GetImageContainerObj;
	extern DecodeImageFuncPtr DecodeImage;
	extern ParseTextureImgFuncPtr ParseTextureImg;
	extern RegisterArchiversFuncPtr RegisterArchivers;

	extern std::vector<std::string_view> ArchiveExtensions;
}
