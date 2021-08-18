module;

#include <vector>

export module dgengine.sfml.vertexarray2;

import dgengine.palette;
import dgengine.shader;
import sfml;

export class VertexArray2
{
private:
	void draw(const sf::Texture* texture, const Palette* palette,
		GameShader* spriteShader, sf::RenderTarget& target,
		sf::Transform transform, sf::Glsl::Vec2 pixelSize) const;

public:
	std::vector<sf::Vertex> vertices;

	void draw(const sf::Texture* texture, const Palette* palette,
		GameShader* spriteShader, sf::RenderTarget& target) const;

	void draw(const sf::Texture* texture, const sf::Vector2f& pos,
		const sf::Vector2f& size, const Palette* palette,
		GameShader* spriteShader, sf::RenderTarget& target) const;
};
