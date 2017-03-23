#ifndef _SPINLOCK_H_
#define _SPINLOCK_H_

class SpinLock
{
	volatile LONG *lockValue;
public:

	SpinLock(void) : lockValue(NULL) {;};
	SpinLock(volatile LONG *value) : lockValue(value) {;};

	void Initlock(volatile LONG * value) {
		lockValue = value;
	}

	bool isInit() { return (NULL != lockValue);};
	
	void Lock() {
		while (InterlockedCompareExchange((volatile LONG*)lockValue, 1, 0) != 0) {
		}
	}
	
	void Unlock() { InterlockedExchange((volatile LONG*)lockValue, 0); }
};

#endif /*_SPINLOCK_H_*/