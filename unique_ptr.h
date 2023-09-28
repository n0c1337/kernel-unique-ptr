#pragma once

#include <wdm.h>

#define POOL_TAG = 0x1337;

namespace std
{
	template<class T>
	class unique_ptr
	{
	private:
		T* ptr = nullptr;
	public:
		unique_ptr() {
			ptr = static_cast<T*>(ExAllocatePoolWithTag(NonPagedPool, sizeof(T), POOL_TAG));
		}

		T* getPointer() {
			return ptr;
		}

		~unique_ptr() {
			ExFreePoolWithTag(ptr, POOL_TAG);
		}
	};
}
