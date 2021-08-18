module;

#include <memory>

export module dgengine.shader;

import dgengine.utils.fixedarray;
import sfml;

export struct GameShader
{
	std::unique_ptr<sf::Shader> shader;
	FixedArray<uint16_t, 6> uniforms;
};

export struct GameShaders
{
	GameShader* Game{ nullptr };
	GameShader* Level{ nullptr };
	GameShader* Sprite{ nullptr };

	bool hasGameShader() const noexcept { return Game != nullptr; }
	bool hasLevelShader() const noexcept { return Level != nullptr; }
	bool hasSpriteShader() const noexcept { return Sprite != nullptr; }
};
