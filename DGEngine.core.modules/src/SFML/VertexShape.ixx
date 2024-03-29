export module dgengine.sfml.vertexshape;

import sfml;

export class VertexShape : public sf::Drawable, public sf::Transformable
{
private:
	sf::VertexArray vertices;
	sf::FloatRect bounds;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void update();

public:
	explicit VertexShape(sf::PrimitiveType type) : vertices(type) {}

	void addVertex(const sf::Vertex& v);

	sf::FloatRect getLocalBounds() const noexcept { return bounds; }
	sf::FloatRect getGlobalBounds() const;
	size_t getPointCount() const { return vertices.getVertexCount(); }
};
