module;

#include <string>
#include <variant>
#include <vector>

export module dgengine.sfml.music2;

import sfml;

export struct MusicFile
{
	sf::InputSoundFile file;
	std::vector<sf::Int16> samples;

	MusicFile() = default;
	~MusicFile() = default;
};

export struct MusicBuffer
{
	const sf::Int16* samples{ nullptr };
	sf::Uint64 sampleCount{ 0 };
	size_t channelCount{ 0 };
	size_t sampleRate{ 0 };
	size_t sampleBufferSize{ 0 };
	sf::Uint64 sampleBufferOffset{ 0 };
	sf::Time duration;
};

export namespace sf
{
	class InputStream;

	// based on SFML's Music class
	class Music2 : public SoundStream
	{
	protected:
		std::variant<std::nullptr_t, MusicFile, MusicBuffer> m_data;
		Mutex m_mutex;
		Music::Span<Uint64> m_loopSpan;

		void initializeFile();
		void initializeBuffer(const sf::SoundBuffer& buffer);

		Uint64 timeToSamples(Time position) const
		{
			return timeToSamples(position, getSampleRate(), getChannelCount());
		}
		Time samplesToTime(Uint64 samples) const
		{
			return samplesToTime(samples, getSampleRate(), getChannelCount());
		}

		bool onGetDataFile(Chunk& data);
		bool onGetDataBuffer(Chunk& data);

		Int64 onLoopFile();
		Int64 onLoopBuffer();

		bool onGetData(Chunk& data) override;
		void onSeek(Time timeOffset) override;
		Int64 onLoop() override;

	public:
		Music2() : m_loopSpan(0, 0) { }
		~Music2();

		bool openFromFile(const std::string& filename);
		bool openFromMemory(const void* data, std::size_t sizeInBytes);
		bool openFromStream(InputStream& stream);
		bool openFromSoundBuffer(const sf::SoundBuffer& buffer);

		Time getDuration() const;

		Music::TimeSpan getLoopPoints() const;

		void setLoopPoints(Music::TimeSpan timePoints);

		static Uint64 timeToSamples(Time position,
			unsigned sampleRate, unsigned channelCount);
		static Time samplesToTime(Uint64 samples,
			unsigned sampleRate, unsigned channelCount);
	};
}
