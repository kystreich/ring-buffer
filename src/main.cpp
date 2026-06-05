#include <iostream>
#include "lib/ringbuffer.h"

using namespace ringbuffer;

int main() {
	RingBuffer<int, 128> rBuff{};

	rBuff.push(1);
	rBuff.push(2);
	rBuff.push(3);
	rBuff.push(4);
	rBuff.push(5);

	int x{};
	rBuff.pop(&x);
	int y{};
	rBuff.pop(&y);
	int z{};
	rBuff.pop(&z);
	int a{};
	rBuff.pop(&a);
	int b{};
	rBuff.pop(&b);

	std::cout << x << y << z << a << b << "\n";

	return 0;
}
