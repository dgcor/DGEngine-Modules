export module dgengine.sfml.music2;

import sfml;
import stl;

export namespace sf
{
	class InputStream;

	// based on SFML's Music class
	class Music2 : public SoundStream
	{
	protected:
		struct MusicFile
		{
			InputSoundFile file;
			std::vector<Int16> samples;

			MusicFile() = default;
			~MusicFile() = default;
		};

		struct MusicBuffer
		{
			const Int16* samples{ nullptr };
			Uint64 sampleCount{ 0 };
			size_t channelCount{ 0 };
			size_t sampleRate{ 0 };
			size_t sampleBufferSize{ 0 };
			Uint64 sampleBufferOffset{ 0 };
			Time duration;
		};

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
