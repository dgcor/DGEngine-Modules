module;

#include <physfs.h>

module dgengine.sfml.physfsstream;

import dgengine.utils.utils;

sf::PhysFSStream::PhysFSStream(const std::string_view fileName)
{
	load(fileName);
}

sf::PhysFSStream::~PhysFSStream()
{
	if (file != nullptr)
	{
		PHYSFS_close(file);
	}
}

bool sf::PhysFSStream::load(const std::string_view fileName)
{
	if (file == nullptr)
	{
		file = PHYSFS_openRead(fileName.data());
	}
#ifdef DGENGINE_FALLBACK_TO_LOWERCASE
	if (file == nullptr)
	{
		auto lowerCaseFileName = Utils::toLower(fileName);
		file = PHYSFS_openRead(lowerCaseFileName.c_str());
	}
#endif
	return (file != nullptr);
}

sf::Int64 sf::PhysFSStream::read(void* data, sf::Int64 size) noexcept
{
	return PHYSFS_readBytes(file, data, (PHYSFS_uint64)size);
}

sf::Int64 sf::PhysFSStream::seek(sf::Int64 position) noexcept
{
	if (PHYSFS_seek(file, position) == 0)
	{
		return -1;
	}
	return position;
}

sf::Int64 sf::PhysFSStream::tell() noexcept
{
	return PHYSFS_tell(file);
}

sf::Int64 sf::PhysFSStream::getSize() noexcept
{
	return PHYSFS_fileLength(file);
}
