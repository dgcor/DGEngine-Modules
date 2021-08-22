export module dgengine.textureinfo;

import dgengine.blendmode;
import dgengine.palette;
import sfml;
import stl;

export struct TextureInfo
{
	const sf::Texture* texture{ nullptr };
	sf::IntRect textureRect;
	std::shared_ptr<Palette> palette;
	sf::Vector2f offset;
	bool absoluteOffset{ false };
	BlendMode blendMode{ BlendMode::Alpha };
	int32_t nextIndex{ -1 };
};

export typedef class std::variant<TextureInfo, std::vector<TextureInfo>> TextureInfoVar;
