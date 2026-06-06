#include <cstdint>
#include <iostream>
#include "lib/ringbuffer.h"

using namespace ringbuffer;

int main() {
	RingBuffer<std::int8_t, 128> rBuff{};

	rBuff.push(1);
	rBuff.push(2);
	rBuff.push(4);
	rBuff.push(5);

	std::int8_t x{};
	rBuff.pop(&x);
	std::int8_t y{};
	rBuff.pop(&y);
	std::int8_t z{};
	rBuff.pop(&z);
	std::int8_t a{};
	rBuff.pop(&a);
	std::int8_t b{};
	rBuff.pop(&b);

	auto cap = rBuff.capacity();

	std::cout << 
		std::format("X: {}\nY: {}\nZ: {}\nA: {}\nB: {}\nCapacity: {}\nSize Of Buffer: {}\nSize Of size_t: {}", x, y, z, a, b, cap, sizeof(rBuff), sizeof(size_t)) << "\n";
	
	return 0;
}
