#ifndef Animation_H
#define Animation_H

#include "Typedefs.h"

class Animation
{
	animid_t id;
public:
	animid_t GetId();
	virtual Animation* Clone(animid_t newId) const = 0;

	Animation(animid_t _id);
	virtual ~Animation();
};


#endif
