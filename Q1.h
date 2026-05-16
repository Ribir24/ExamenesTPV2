
#include <iostream>
#include <vector>


class IntPtr {
public:
	int *p;

	IntPtr():
			IntPtr(0) {
	}

	IntPtr(int n) {
		p = new int(n);
	}

	IntPtr(const IntPtr& other) {
		p = new int(*other.p);
	}

	IntPtr(IntPtr&& other) {
		p = other.p;
		other.p = nullptr;
	}

	IntPtr& operator= (const IntPtr& other) {
		if (this == &other) return *this;

		delete p;
		p = new int(*other.p);

		return *this;
	}

	IntPtr& operator= (IntPtr&& other) {
		if (this == &other) return *this;

		delete p;
		p = other.p;
		other.p = nullptr;

		return *this;
	}

	~IntPtr() {
		if (p != nullptr) {
			delete p;
		}
	}

};

void main_q1() {
	IntPtr a(1);
	IntPtr b(a);
	IntPtr c(std::move(a));

	IntPtr d;
	d = c;

	IntPtr e;
	e = std::move(b);

}
