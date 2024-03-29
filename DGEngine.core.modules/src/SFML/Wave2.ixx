module;

#define DR_WAV_NO_STDIO
#include "dr_wav.h"

export module dgengine.sfml.wave2;

import sfml;

// Wave file reader using a different decoder from SFML's default.
export class Wave2FileReader : public sf::SoundFileReader
{
private:
	drwav wave{};
	bool isInitialized{ false };

public:
	Wave2FileReader() = default;
	~Wave2FileReader() override;

	static bool check(sf::InputStream& stream_);

	bool open(sf::InputStream& stream_, Info& info) override;
	void seek(sf::Uint64 sampleOffset) override;
	sf::Uint64 read(sf::Int16* samples, sf::Uint64 maxCount) override;
};
