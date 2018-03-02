#include "Animation.h"

animid_t Animation::GetId()
{
	return id;
}

Animation::Animation(animid_t _id)
{
	id = _id;
}

Animation::~Animation()
{
}
