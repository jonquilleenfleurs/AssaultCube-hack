#pragma once
#include <iostream>
#include "memory.h"

class Ammo{
public:
private:
	Memory mem;
	uintptr_t ammoAddress;
	const int AMMO = 20;

public:
	Ammo(auto& mem, const uintptr_t ammoAddress):
		mem{mem}, ammoAddress{ammoAddress}{
	}

	void set(const int newAmmo){
		mem.Write(ammoAddress, newAmmo);
	}

	int get()const{
		return mem.Read<uintptr_t>(ammoAddress);
	}

	void checkAmmo(){
		if(get() != AMMO){
			set(AMMO);
		}
	}
};