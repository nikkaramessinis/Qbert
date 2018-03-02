#pragma once
#include <list>
#include "Animation.h"
#include "Typedefs.h"
#include "vector"
struct PathEntry {
	int pos;
	offset_t dx, dy;
	frame_t frame;
	delay_t delay;
	PathEntry() :dx(0), dy(0), frame(0xff), delay(0) {}
	PathEntry(const PathEntry& p) :
		dx(p.dx), dy(p.dy), frame(p.frame), delay(p.delay),pos(p.pos) {}

};

class MovingPathAnimation :
	public Animation
{
	int pos;
	std::vector<PathEntry> path;
public:
	const std::vector<PathEntry>& GetPath(void) const;
	void SetPath(const std::vector<PathEntry>& p);
	Animation* Clone(animid_t newId)const;
	//-----paizei oxi -------

	int GetPos() const;
	void SetPos(int _p);
	void NextPos();
	int GetMaxPos() const;
	delay_t GetCurrentDelay() const;
	offset_t GetCurrentDx() const;
	offset_t GetCurrentDy() const;
	frame_t GetFrame() const;

	//------Karam-----




	MovingPathAnimation(const std::vector<PathEntry>& _path,animid_t id);
	~MovingPathAnimation();
};

