export module dgengine.imageutils;

import dgengine.imagecontainers.imagecontainer;
import dgengine.palette;
import sfml;
import stl;

export namespace ImageUtils
{
	void applyMask(sf::Image& image,
		const sf::Color& transparencyMask = sf::StaticColor::Transparent());

	sf::Image loadImage(const std::string_view fileName,
		const sf::Color& transparencyMask = sf::StaticColor::Transparent());

	sf::Image loadImage(const ImageContainer& imgContainer,
		const std::shared_ptr<Palette>& pal);

	sf::Image loadImageFrame(const ImageContainer& imgContainer,
		const PaletteArray* pal, uint32_t frameIdx);

	sf::Image loadBitmapFontImage(const ImageContainer& imgContainer,
		const std::string_view fileNameCharMap, const std::shared_ptr<Palette>& pal);

	sf::Image splitImageHorizontal(const sf::Image& img, unsigned pieces = 1);
	sf::Image splitImageVertical(const sf::Image& img, unsigned pieces = 1);
}
