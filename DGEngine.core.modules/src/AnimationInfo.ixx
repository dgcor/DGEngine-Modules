export module dgengine.animationinfo;

import dgengine.animationtype;
import sfml;
import stl;

export struct AnimationInfo
{
	std::pair<uint32_t, uint32_t> indexRange;
	AnimationType animType{ AnimationType::Looped };
	sf::Time refresh;
};
