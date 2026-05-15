// This file is part of the course TPV2@UCM - Samir Genaim

#include "Game.h"
#include "GameObject.h"
#include "Resource.h"

Game::Game() {
}

Game::~Game() = default;

bool Game::init() {
	for (int i = 0; i < 10; i++) {
		add(std::make_unique<GameObject>(std::make_shared<Resource>()));
	}
	return true;
}

void Game::start(unsigned int n) {

	// EL BUCLE DEL "JUEGO"
	while (n > 0) {

		// actualizar las entidades
		std::size_t vsize = _v.size();
		for (std::size_t i = 0u; i < vsize; i++) {
			_v[i]->update();
		}

		/*
		// actualizar la entidades: bucle alternativo usando for-each
		for (GameObject* o : _v) {
			o->update();
		}
		*/

		// borrar las entidades muertas
		refresh();
		n--;
	} 
	_v.clear();
}

void Game::refresh() {
	
	// borrar entidades muertas
	_v.erase(std::remove_if(_v.begin(), _v.end(), [](const std::unique_ptr<GameObject>& a) {
		return !a->isAlive();
		}), _v.end());

}

void Game::add(std::unique_ptr<GameObject> e) {
	_v.push_back(std::move(e));
}
