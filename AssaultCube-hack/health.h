#pragma once
#include <iostream>
#include "memory.h"

class Health{
public:
private:
	Memory mem;
	uintptr_t healthAddress;
	const int HEALTH = 1337;

public:
	Health(auto& mem, const uintptr_t healthAddress):
		mem{mem}, healthAddress{healthAddress}{}

	void set(const int newHealth){
		mem.Write(healthAddress, newHealth);
	}

	int get()const{
		return mem.Read<uintptr_t>(healthAddress);
	}

	void checkHealth(){
		if(get() != HEALTH){
			set(HEALTH);
		}
	}
};