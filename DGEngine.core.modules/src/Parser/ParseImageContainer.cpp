module;

#include <cassert>
#include <memory>
#include <string_view>

module dgengine.parser.imagecontainer;

import dgengine.filebytes;
import dgengine.fileutils;
import dgengine.hooks;
import dgengine.imagecontainers;
import dgengine.parser.utils;

namespace Parser
{
	using namespace rapidjson;
	using namespace std::literals;

	std::shared_ptr<ImageContainer> getImageContainerObj(Game& game, const Value& elem)
	{
		std::shared_ptr<FileBytes> fileBytes;
		std::string_view fileName;
		if (isValidString(elem, "fileBytes") == true)
		{
			fileBytes = game.Resources().getFileBytes(getStringViewVal(elem["fileBytes"sv]));
		}
		else if (isValidString(elem, "file") == true)
		{
			fileName = getStringViewVal(elem["file"sv]);
			fileBytes = std::make_shared<FileBytes>(FileUtils::readChar(fileName));
		}
		if (fileBytes == nullptr || fileBytes->empty() == true)
		{
			return nullptr;
		}

		std::shared_ptr<ImageContainer> imgContainer;

		if (Hooks::GetImageContainerObj == nullptr ||
			Hooks::GetImageContainerObj(fileBytes, fileName, elem, imgContainer) == false)
		{
			auto frames = getFramesKey(elem, "frames");
			auto directions = getUIntKey(elem, "directions");
			imgContainer = std::make_shared<SimpleImageContainer>(
				fileName, frames.first, frames.second, directions, false);
		}

		if (imgContainer->size() == 0)
		{
			return nullptr;
		}
		imgContainer->setBlendMode(getBlendModeKey(elem, "blendMode"));
		return imgContainer;
	}

	bool parseImageContainerFromId(Game& game, const Value& elem)
	{
		if (isValidString(elem, "fromId") == true)
		{
			if (isValidString(elem, "id") == true)
			{
				auto fromId = elem["fromId"sv].GetStringView();
				auto id = elem["id"sv].GetStringView();
				if (fromId != id && isValidId(id) == true)
				{
					auto obj = game.Resources().getImageContainer(fromId);
					if (obj != nullptr)
					{
						game.Resources().addImageContainer(id, obj, getStringViewKey(elem, "resource"));
					}
				}
			}
			return true;
		}
		return false;
	}

	void parseImageContainer(Game& game, const Value& elem,
		const getImageContainerObjFuncPtr getImageContainerObjFunc)
	{
		assert(getImageContainerObjFunc != nullptr);

		if (parseImageContainerFromId(game, elem) == true)
		{
			return;
		}
		std::string id;
		if (isValidString(elem, "id") == true)
		{
			id = elem["id"sv].GetStringView();
		}
		else
		{
			if (isValidString(elem, "file") == false)
			{
				return;
			}
			auto file = getStringViewVal(elem["file"sv]);
			if (getIdFromFile(file, id) == false)
			{
				return;
			}
		}
		if (isValidId(id) == false)
		{
			return;
		}
		if (game.Resources().hasImageContainer(id) == true)
		{
			return;
		}
		auto imageContainer = getImageContainerObjFunc(game, elem);
		if (imageContainer == nullptr)
		{
			return;
		}
		game.Resources().addImageContainer(id, imageContainer, getStringViewKey(elem, "resource"));
	}

	void parseImageContainer(Game& game, const Value& elem)
	{
		parseImageContainer(game, elem, getImageContainerObj);
	}
}
