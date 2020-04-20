#include <iostream>
#include <chrono>

#define N 100000000

struct SimpleStruct {
	int u;
	int v;
	int w;
};

class SimpleClass {
public:
	int x;
	int y;
	int z;
};

int main() {
	auto start = std::chrono::steady_clock::now();

	SimpleStruct str;

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> diff = end-start;
	std::cout << "Struct creation of took " << diff.count() * 1000 << " ms\n";

	start = std::chrono::steady_clock::now();

	SimpleClass* cls = new SimpleClass();

	end = std::chrono::steady_clock::now();

	diff = end-start;
	std::cout << "Class creation took " << diff.count() * 1000 << " ms\n";

	start = std::chrono::steady_clock::now();

	SimpleClass cls2;

	end = std::chrono::steady_clock::now();

	diff = end-start;
	std::cout << "Class static creation took " << diff.count() * 1000 << " ms\n";

	start = std::chrono::steady_clock::now();

	for (int i = 0; i < N; i++) {
		str.u = 0;
		str.v = 0;
		str.w = 0;
	}

	end = std::chrono::steady_clock::now();

	diff = end-start;
	std::cout << "Struct access of " << N << " times took " << diff.count() * 1000 << " ms\n";

	start = std::chrono::steady_clock::now();

	for (int i = 0; i < N; i++) {
		cls->x = 0;
		cls->y = 0;
		cls->z = 0;
	}

	end = std::chrono::steady_clock::now();

	diff = end-start;
	std::cout << "Class access of " << N << " times took " << diff.count() * 1000 << " ms\n";

	start = std::chrono::steady_clock::now();

	for (int i = 0; i < N; i++) {
		cls2.x = 0;
		cls2.y = 0;
		cls2.z = 0;
	}

	end = std::chrono::steady_clock::now();

	diff = end-start;
	std::cout << "Class static access of " << N << " times took " << diff.count() * 1000 << " ms\n";


	return 0;
}