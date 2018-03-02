#include "MovingPathAnimation.h"


const std::vector<PathEntry>& MovingPathAnimation::GetPath(void) const
{
	return path;
}

void MovingPathAnimation::SetPath(const std::vector<PathEntry>& p)
{
	path.clear();
	path = p;
	pos = 0;
}

Animation * MovingPathAnimation::Clone(animid_t newId) const
{
	return new MovingPathAnimation(path, newId);

}



//---------karam------
int MovingPathAnimation::GetPos() const
{
	return pos;
}

void MovingPathAnimation::SetPos(int _p)
{
	pos = _p;
}

void MovingPathAnimation::NextPos()
{
	pos++;
}

int MovingPathAnimation::GetMaxPos() const
{
	return path.size() - 1;
}

delay_t MovingPathAnimation::GetCurrentDelay() const
{
	return path[pos].delay;
}

offset_t MovingPathAnimation::GetCurrentDx() const
{
	return path[pos].dx;
}

offset_t MovingPathAnimation::GetCurrentDy() const
{
	return path[pos].dy;
}

frame_t MovingPathAnimation::GetFrame() const
{
	return path[pos].frame;
}
//-----------------------------



MovingPathAnimation::MovingPathAnimation(const std::vector<PathEntry>& _path, animid_t id):path(_path),Animation(id)
{
}


MovingPathAnimation::~MovingPathAnimation()
{
}
