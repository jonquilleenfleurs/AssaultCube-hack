#pragma once
#include <iostream>
#include <vector>
#include "memory.h"
#include "offsets.h"

class Ammo{
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
	Ammo(const Memory& mem, const uintptr_t address):
		mem{mem}, address{address}{
		vec = {
			{"ASSAULT RIFLE",	20,		address + offsets::assaultRifle},
			{"PISTOL",			10,		address + offsets::pistol},
			{"SUBMACHINE",		30,		address + offsets::submachine},
			{"SNIPER RIFLE",	5,		address + offsets::sniperRifle},
			{"SHOTGUN",			7,		address + offsets::shotgun},
			{"CARBINE",			15,		address + offsets::carbine},
			{"GRENADE",			3,		address + offsets::grenade}
		};
	}

	void noReaload(){
		for(const auto& data : vec){
			mem.Write(data.address, data.defaultValue);
		}
	}
};