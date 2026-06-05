#include <array>
#include <atomic>
#include <cstddef>

namespace ringbuffer {
	template <auto V>
	constexpr bool powerOfTwo = V && ((V & (V - 1)) == 0);
	
	template <typename T, size_t cap> 
		requires powerOfTwo<cap>
	struct RingBuffer {
		std::atomic<size_t> producerPointer_{};
		std::atomic<size_t> consumerPointer_{};
		std::array<T, cap> data_{};
		
		size_t capacity() {
			return cap;
		};

		bool pop(T* output) {
			if (consumerPointer_ == producerPointer_) return false;

			*output = data_[consumerPointer_];

			consumerPointer_ = (consumerPointer_ + 1) & (cap - 1);
			return true;
		};

		bool push(T input) {
			size_t step = (producerPointer_ + 1) & (cap - 1);
			if (step == consumerPointer_) return false;
			
			data_[producerPointer_] = input;
			producerPointer_ = step;

			return true;
		};
	};
}
