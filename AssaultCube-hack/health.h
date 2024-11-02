#pragma once
#include <iostream>
#include <vector>
#include "memory.h"
#include "offsets.h"

class Health{
public:
	struct Data{
		std::string name;
		int defaultValue;
		uintptr_t address;
	};
private:
	const Memory& mem;
	const uintptr_t address;
	std::vector<Data> vec;

public:
	Health(const Memory& mem, const uintptr_t address):
		mem{mem}, address{address}{
		vec = {
			{"HEALTH",	228,	address + offsets::health}
		};
	}

	void godMode(){
		for(const auto& data : vec){
			mem.Write(data.address, data.defaultValue);
		}
	}
};