// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

#include "Resource.h"

class GameObject {

public:
	GameObject(std::shared_ptr <Resource> r);
	virtual ~GameObject();
	void update();
	bool isAlive();

	static int _count;

private:
	bool _alive;

	std::shared_ptr<Resource> _r;
	unsigned int _x;
	unsigned int _y;
};

