module dgengine.circle;

import dgengine.game;
import dgengine.gameutils;
import dgengine.utils.utils;

void Circle::updateSize(const Game& game)
{
	auto pos = getPosition();
	auto size = Size();
	GameUtils::setAnchorPosSize(anchor, pos, size, game.OldDrawRegionSize(), game.DrawRegionSize());
	setPosition(pos);
}

bool Circle::getProperty(const std::string_view prop, Variable& var) const
{
	if (prop.size() <= 1)
	{
		return false;
	}
	auto props = Utils::splitStringIn2(prop, '.');
	return getUIObjProp(str2int16(props.first), props.second, var);
}
