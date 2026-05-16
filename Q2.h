#pragma once
#include <array>
#include <bitset>
#include <cassert>
#include <cstddef>
#include <vector>

template<typename T>
class ObjectPool {
public:

	using iterator = T*;

	ObjectPool(std::size_t size):
	_pool(new T[size]),
		_size(size),
		_used(size, false),
		_lastUsed(size - 1)
	{
	}

	virtual ~ObjectPool() {
		delete[] _pool;
	}

	T* alloc() {
		auto i = (_lastUsed + 1) % _size;
		while (_used[i] && i != _lastUsed)
			i = (i + 1) % _size;

		if (!_used[i]) {
			_used[i] = true;
			return _pool + i;
		}
		else {
			return nullptr;
		}
	}

	void free(T *p) {
		auto idx = p - _pool;
		assert(idx >= 0 && idx < _size);
		_used[idx] = false;
	}

	iterator begin() {
		return iterator{ _pool };
	}

	iterator end() {
		return iterator{ _pool + _size};
	}

private:
	T* _pool;
	std::size_t _size;
	std::vector<bool> _used;
	std::size_t _lastUsed;
};

struct Ent {
};

// ejemplo de uso
void main_q2() {
	ObjectPool<Ent> ent_pool(20);

	for (Ent &e : ent_pool) {
		e = Ent{};
	}

	std::vector<Ent*> v;

	for (int i = 0; i < 10; i++)
		v.push_back(ent_pool.alloc());
	
	for (Ent *e : v)
		ent_pool.free(e);
}

