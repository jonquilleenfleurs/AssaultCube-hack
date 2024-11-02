#pragma once
#include <iostream>
#include "memory.h"
#include "offsets.h"

class Coordinates{
public:
	struct Vec3{
		float x;
		float y;
		float z;
	};
	
private:
	const Memory& mem;
	const uintptr_t address;
	Vec3 coordinates;

public:
	Coordinates(const Memory& mem, const uintptr_t address):
		mem{mem}, address{address}{
		update();
	}
	void update(){
		coordinates.x=mem.Read<float>(address + offsets::xPosition);
		coordinates.y=mem.Read<float>(address + offsets::yPosition);
		coordinates.z=mem.Read<float>(address + offsets::zPosition);
	}
	void print(){
		update();
		std::cout << "x = " << coordinates.x << "  ";
		std::cout << "y = " << coordinates.y << "  ";
		std::cout << "z = " << coordinates.z << "\n\n";
	}

};