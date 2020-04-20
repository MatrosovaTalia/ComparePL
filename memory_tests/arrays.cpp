#include <iostream>
#include <chrono>

#define N 1000000

void check_arr(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		arr[i] = 0;
	}
}

int main() {

	auto start = std::chrono::steady_clock::now();

	int stack[N];

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> diff = end-start;
	std::cout << "Stack creation of " << N << " elements took " << diff.count() * 1000 << " ms\n";

	start = std::chrono::steady_clock::now();

	int* heap = new int[N];

	end = std::chrono::steady_clock::now();

	diff = end-start;
	std::cout << "Heap creation of " << N << " elements took " << diff.count() * 1000 << " ms\n";

	start = std::chrono::steady_clock::now();

	check_arr(stack, N);

	end = std::chrono::steady_clock::now();

	diff = end-start;
	std::cout << "Stack access of " << N << " elements took " << diff.count() * 1000 << " ms\n";

	start = std::chrono::steady_clock::now();

	check_arr(heap, N);

	end = std::chrono::steady_clock::now();

	diff = end-start;
	std::cout << "Heap access of " << N << " elements took " << diff.count() * 1000 << " ms\n";

	return 0;
}