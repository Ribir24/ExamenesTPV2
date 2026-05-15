// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

#include <vector>

#include "Singleton.h"

class GameObject;

//
class Game: public Singleton<Game> {
	friend Singleton<Game> ;

public:
	void start(unsigned int);
	void add(std::unique_ptr<GameObject> e);

private:

	// Métodos privados no se pueden hacer públicos.
	Game();
	virtual ~Game();
	bool init();
	void refresh();

	std::vector<std::unique_ptr<GameObject>> _v;
};




