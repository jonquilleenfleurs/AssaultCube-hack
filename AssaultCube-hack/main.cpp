#include <iostream>
#include "memory.h"

namespace offsets{
	const auto localPlayer = 0x0017E0A8;
	const auto healthOffset = 0xEC;
}

int main(){
	const auto mem = Memory{"ac_client.exe"};

	return 0;
}