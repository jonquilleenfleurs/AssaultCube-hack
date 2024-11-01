#include <iostream>
#include "memory.h"
#include "health.h"
#include "ammo.h"

namespace offsets{
	const auto localPlayer = 0x0017E0A8;
	const auto healthOffset = 0xEC;
	const auto ammoOffset = 0x140;
}

int main(){
	const std::string proccesName = "ac_client.exe";

	const auto mem = Memory{proccesName};

	const uintptr_t baseAddress = mem.GetModuleAddress(proccesName);
	const uintptr_t playerAddress = mem.Read<uintptr_t>(baseAddress + offsets::localPlayer);
	const uintptr_t healthAddress = playerAddress + offsets::healthOffset;
	const uintptr_t ammoAddress = playerAddress + offsets::ammoOffset;

	Health health{mem, healthAddress};
	Ammo ammo{mem, ammoAddress};

	while(true){
		health.checkHealth();
		ammo.checkAmmo();
	}

	return 0;
}