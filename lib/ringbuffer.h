#include <array>
#include <atomic>
#include <cstddef>
#include <new>

namespace ringbuffer {
	template <auto V>
	constexpr bool powerOfTwo = V && ((V & (V - 1)) == 0);
	
	template <typename T, size_t cap> 
		requires powerOfTwo<cap>
	struct RingBuffer {
		alignas(std::hardware_destructive_interference_size) std::atomic<size_t> producerPointer_{};
		alignas(std::hardware_destructive_interference_size) std::atomic<size_t> consumerPointer_{};
		std::array<T, cap> data_{};
	
		[[nodiscard]] size_t capacity() const {
			return cap;
		};

		[[nodiscard]] bool empty() const {
			return producerPointer_ == consumerPointer_;
		}

		bool pop(T* output) {
			const auto currentConsumer = consumerPointer_.load(std::memory_order_relaxed);
			if (currentConsumer == producerPointer_.load(std::memory_order_acquire)) return false;

			*output = data_[consumerPointer_];

			consumerPointer_.store((consumerPointer_ + 1) & (cap - 1), std::memory_order_release);
			return true;
		};

		bool push(T input) {
			const auto currentProducer = producerPointer_.load(std::memory_order_relaxed);

			size_t step = (currentProducer + 1) & (cap - 1);
			if (step == consumerPointer_.load(std::memory_order_acquire)) return false;
			
			data_[currentProducer] = input;
			producerPointer_.store(step, std::memory_order_release);

			return true;
		};
	};
}
