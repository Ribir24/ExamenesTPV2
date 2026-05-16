//#pragma once
//#include <array>
//#include <bitset>
//#include <cassert>
//#include <cstddef>
//#include <vector>
//
//template<typename T>
//class ObjectPool {
//public:
//
//	using iterator = T*;
//
//	ObjectPool(std::size_t size) {
//	}
//
//	virtual ~ObjectPool() {
//	}
//
//	T* alloc() {
//	}
//
//	void free(T *p) {
//	}
//
//	iterator begin() {
//	}
//
//	iterator end() {
//	}
//
//private:
//};
//
//struct Ent {
//};
//
//// ejemplo de uso
//void main_q2() {
//	ObjectPool<Ent> ent_pool(20);
//
//	for (Ent &e : ent_pool) {
//		// ...
//	}
//
//	std::vector<Ent*> v;
//
//	for (int i = 0; i < 10; i++)
//		v.push_back(ent_pool.alloc());
//
//	for (Ent *e : v)
//		ent_pool.free(e);
//}
//
