module;

#include <cstdint>

export module dgengine.animationtype;

export enum class AnimationType : int32_t
{
	Looped,
	BackAndForth,
	PlayOnce,
	Size
};
