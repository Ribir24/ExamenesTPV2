#pragma once
#include <array>
#include <bitset>
#include <cassert>
#include <cstddef>
#include <vector>
// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

template<typename T>
class ObjectPool {
public:

	ObjectPool(std::size_t size) :
		pool_(new T[size]),
		_size(size),
		_used(size, false),
		_lastUsed(size - 1)
	{
	}

	virtual ~ObjectPool() {
		delete[] pool_;
	}

	T* alloc() {
		auto i = (_lastUsed + 1) % _size;

		while (_used[i] && i != _lastUsed) i = (i + 1) % _size;

		if (!_used[i]) {
			_lastUsed = i;
			_used[i] = true;
			return pool_ + i;
		}
		else return nullptr;
	}

	void free(T* p) {
		auto idx = p - pool_;
		assert(idx >= 0 && idx < _size);
		_used[idx] = false;
	}

private:
	T* pool_;
	std::size_t _size;
	std::vector<bool> _used;
	std::size_t _lastUsed;
};

