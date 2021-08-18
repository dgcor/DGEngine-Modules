module;

#include <physfs.h>
#include <string_view>

export module dgengine.sfml.physfsstream;

import sfml;

export namespace sf
{
	class PhysFSStream : public sf::InputStream, public sf::NonCopyable
	{
	protected:
		PHYSFS_File* file{ nullptr };

	public:
		PhysFSStream() {}
		PhysFSStream(const std::string_view fileName);
		~PhysFSStream() override;

		bool load(const std::string_view fileName);

		sf::Int64 read(void* data, sf::Int64 size) noexcept override;
		sf::Int64 seek(sf::Int64 position) noexcept override;
		sf::Int64 tell() noexcept override;
		sf::Int64 getSize() noexcept override;

		bool hasError() const noexcept { return file == nullptr; }

		const char* getLastError() const noexcept
		{
			return PHYSFS_getErrorByCode(PHYSFS_getLastErrorCode());
		}
	};
}
