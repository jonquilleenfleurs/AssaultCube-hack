#include <iostream>
#include <thread>
#include "memory.h"
#include "health.h"
#include "offsets.h"
#include "ammo.h"
#include "coordinates.h"

int main(){
	const std::string proccesName = "ac_client.exe";

	Memory mem = Memory{proccesName};

	const uintptr_t baseAddress = mem.GetModuleAddress(proccesName);
	const uintptr_t playerAddress = mem.Read<uintptr_t>(baseAddress + offsets::localPlayer);

	Health health{mem, playerAddress};
	Ammo ammo{mem, playerAddress};
	Coordinates coords{mem,playerAddress};

	while(true){
		ammo.noReaload();
		health.godMode();
		coords.print();

		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}

	return 0;
}