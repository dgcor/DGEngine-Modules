module;

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
//#include <SFML/Network.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

export module sfml;

export namespace sf
{
	//system
	using sf::operator==;
	using sf::operator!=;
	using sf::operator<;
	using sf::operator<=;
	using sf::operator>;
	using sf::operator>=;
	using sf::operator-;
	using sf::operator+;
	using sf::operator*;
	using sf::operator/;
	using sf::operator%;
	using sf::operator-=;
	using sf::operator+=;
	using sf::operator*=;
	using sf::operator/=;
	using sf::operator%=;
	//using sf::operator<<;
	//using sf::operator>>;

	using sf::Int8;
	using sf::Int16;
	using sf::Int32;
	using sf::Int64;
	using sf::Uint8;
	using sf::Uint16;
	using sf::Uint32;
	using sf::Uint64;

	using sf::Clock;
	using sf::err;
	using sf::FileInputStream;
	using sf::InputStream;
	using sf::Lock;
	using sf::MemoryInputStream;
	using sf::microseconds;
	using sf::milliseconds;
	using sf::Mutex;
	using sf::NonCopyable;
	using sf::seconds;
	using sf::sleep;
	using sf::String;
	using sf::Thread;
	using sf::ThreadLocal;
	using sf::ThreadLocalPtr;
	using sf::Time;
	using sf::Utf16;
	using sf::Utf32;
	using sf::Utf8;
	using sf::Utf;
	using sf::Vector2;
	using sf::Vector2f;
	using sf::Vector2i;
	using sf::Vector2u;
	using sf::Vector3;
	using sf::Vector3f;
	using sf::Vector3i;

	// audio
	using sf::InputSoundFile;
	using sf::Listener;
	using sf::Music;
	using sf::OutputSoundFile;
	using sf::Sound;
	using sf::SoundBuffer;
	using sf::SoundBufferRecorder;
	using sf::SoundFileFactory;
	using sf::SoundFileReader;
	using sf::SoundFileWriter;
	using sf::SoundRecorder;
	using sf::SoundSource;
	using sf::SoundStream;

	//graphics
	using sf::BlendMode;
	using sf::BlendAlpha;
	using sf::BlendAdd;
	using sf::BlendMultiply;
	using sf::BlendMin;
	using sf::BlendMax;
	using sf::BlendNone;
	using sf::CircleShape;
	using sf::Color;
	using sf::ConvexShape;
	using sf::Drawable;
	using sf::FloatRect;
	using sf::Font;
	using sf::Glyph;
	using sf::Image;
	using sf::IntRect;
	using sf::PrimitiveType;
	using sf::Rect;
	using sf::RectangleShape;
	using sf::RenderStates;
	using sf::RenderTarget;
	using sf::RenderTexture;
	using sf::RenderWindow;
	using sf::Shader;
	using sf::Shape;
	using sf::Sprite;
	using sf::Text;
	using sf::Texture;
	using sf::Transform;
	using sf::Transformable;
	using sf::Vertex;
	using sf::VertexArray;
	using sf::VertexBuffer;
	using sf::View;

	namespace Glsl
	{
		using sf::Glsl::Vec2;
		using sf::Glsl::Vec3;
		using sf::Glsl::Vec4;
	}

	namespace StaticColor
	{
		auto Black() { return sf::Color::Black; }
		auto Transparent() { return sf::Color::Transparent; }
		auto White() { return sf::Color::White; }
	}

	namespace StaticRenderStates
	{
		auto Default() { return sf::RenderStates::Default; }
	}

	//network
	//using sf::Ftp;
	//using sf::Http;
	//using sf::IpAddress;
	//using sf::Packet;
	//using sf::Socket;
	//using sf::SocketHandle;
	//using sf::SocketSelector;
	//using sf::TcpListener;
	//using sf::TcpSocket;
	//using sf::UdpSocket;

	//window
	using sf::Clipboard;
	using sf::Context;
	using sf::ContextSettings;
	using sf::Cursor;
	using sf::Event;
	using sf::GlResource;
	using sf::Joystick;
	using sf::Keyboard;
	using sf::Mouse;
	using sf::Sensor;
	using sf::Touch;
	using sf::VideoMode;
	using sf::Window;
	using sf::WindowHandle;

	enum StyleEnum
	{
		None = sf::Style::None,
		Titlebar = sf::Style::Titlebar,
		Resize = sf::Style::Resize,
		Close = sf::Style::Close,
		Fullscreen = sf::Style::Fullscreen,
		Default = sf::Style::Default
	};
}

//opengl
namespace
{
	constexpr auto GL_COLOR_ARRAY_ = GL_COLOR_ARRAY;
	constexpr auto GL_COLOR_BUFFER_BIT_ = GL_COLOR_BUFFER_BIT;
	constexpr auto GL_DEPTH_BUFFER_BIT_ = GL_DEPTH_BUFFER_BIT;
	constexpr auto GL_DEPTH_TEST_ = GL_DEPTH_TEST;
	constexpr auto GL_FLOAT_ = GL_FLOAT;
	constexpr auto GL_LIGHTING_ = GL_LIGHTING;
	constexpr auto GL_MODELVIEW_ = GL_MODELVIEW;
	constexpr auto GL_NORMAL_ARRAY_ = GL_NORMAL_ARRAY;
	constexpr auto GL_PROJECTION_ = GL_PROJECTION;
	constexpr auto GL_TEXTURE_2D_ = GL_TEXTURE_2D;
	constexpr auto GL_TEXTURE_COORD_ARRAY_ = GL_TEXTURE_COORD_ARRAY;
	constexpr auto GL_TRIANGLES_ = GL_TRIANGLES;
	constexpr auto GL_TRUE_ = GL_TRUE;
	constexpr auto GL_VERTEX_ARRAY_ = GL_VERTEX_ARRAY;
}

#undef GL_COLOR_ARRAY
#undef GL_COLOR_BUFFER_BIT
#undef GL_DEPTH_BUFFER_BIT
#undef GL_DEPTH_TEST
#undef GL_FLOAT
#undef GL_LIGHTING
#undef GL_MODELVIEW
#undef GL_NORMAL_ARRAY
#undef GL_PROJECTION
#undef GL_TEXTURE_2D
#undef GL_TEXTURE_COORD_ARRAY
#undef GL_TRIANGLES
#undef GL_TRUE
#undef GL_VERTEX_ARRAY

export namespace gl
{
	constexpr auto GL_COLOR_ARRAY = GL_COLOR_ARRAY_;
	constexpr auto GL_COLOR_BUFFER_BIT = GL_COLOR_BUFFER_BIT_;
	constexpr auto GL_DEPTH_BUFFER_BIT = GL_DEPTH_BUFFER_BIT_;
	constexpr auto GL_DEPTH_TEST = GL_DEPTH_TEST_;
	constexpr auto GL_FLOAT = GL_FLOAT_;
	constexpr auto GL_LIGHTING = GL_LIGHTING_;
	constexpr auto GL_MODELVIEW = GL_MODELVIEW_;
	constexpr auto GL_NORMAL_ARRAY = GL_NORMAL_ARRAY_;
	constexpr auto GL_PROJECTION = GL_PROJECTION_;
	constexpr auto GL_TEXTURE_2D = GL_TEXTURE_2D_;
	constexpr auto GL_TEXTURE_COORD_ARRAY = GL_TEXTURE_COORD_ARRAY_;
	constexpr auto GL_TRIANGLES = GL_TRIANGLES_;
	constexpr auto GL_TRUE = GL_TRUE_;
	constexpr auto GL_VERTEX_ARRAY = GL_VERTEX_ARRAY_;

	using ::GLbitfield;
	using ::GLboolean;
	using ::GLbyte;
	using ::GLclampd;
	using ::GLclampf;
	using ::GLdouble;
	using ::GLenum;
	using ::GLfloat;
	using ::GLint;
	using ::GLshort;
	using ::GLsizei;
	using ::GLubyte;
	using ::GLuint;
	using ::GLushort;
	using ::GLvoid;

	using ::glClear;
	using ::glClearColor;
	using ::glClearDepth;
	using ::glColorPointer;
	using ::glDepthFunc;
	using ::glDepthMask;
	using ::glDepthRange;
	using ::glDisable;
	using ::glDisableClientState;
	using ::glDrawArrays;
	using ::glEnable;
	using ::glEnableClientState;
	using ::glFrustum;
	using ::glLoadIdentity;
	using ::glMatrixMode;
	using ::glRotatef;
	using ::glTexCoordPointer;
	using ::glTranslatef;
	using ::glVertexPointer;
	using ::glViewport;
}
