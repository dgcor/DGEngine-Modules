export module dgengine.sfml.utils;

import dgengine.blendmode;
import sfml;
import stl;

export namespace SFMLUtils
{
	sf::Color rgbToColor(unsigned val);
	sf::Color rgbaToColor(unsigned val);
	sf::Color stringToColor(const std::string_view str);

	void spriteCenterTexture(sf::Sprite& sprite);

	sf::BlendMode getBlendMode(BlendMode blendMode);

	float getScaleToStretchAndKeepAR(const sf::Vector2u& size,
		const sf::Vector2u& windowSize);

	void viewStretchKeepAR(sf::View& view, const sf::Vector2u& windowSize,
		sf::FloatRect viewPort = sf::FloatRect(0, 0, 1, 1));
}
