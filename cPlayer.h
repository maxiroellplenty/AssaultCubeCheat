#pragma once
#include "Header.h"
#include "cAccess.h"
#include "structs.h"
class cPlayer {
private:
	DWORD Offsets[2];
	DWORD XYZposOffsets[3];
	float Xpos, Ypos, Zpos;
	int iHealth, iArmor;

	

public:
	float getXpos() {
		return Xpos;
	}
	float getYpos() {
		return Ypos;
	}
	float getZpos() {
		return Zpos;
	}
	int getHealth() {
		return iHealth;
	}
	int getArmor() {
		return iArmor;
	}

	void ReadInformation(HANDLE Handle, DWORD dwLocalPlayer) {
		
		ReadProcessMemory(Handle, (PBYTE*)(dwLocalPlayer + Offsets[0]), &iHealth, sizeof(iHealth), NULL);
		ReadProcessMemory(Handle, (PBYTE*)(dwLocalPlayer + Offsets[1]), &iArmor, sizeof(iArmor), NULL);
		ReadProcessMemory(Handle, (PBYTE*)(dwLocalPlayer + XYZposOffsets[0]), &Xpos, sizeof(Xpos), NULL);
		ReadProcessMemory(Handle, (PBYTE*)(dwLocalPlayer + XYZposOffsets[1]), &Ypos, sizeof(Ypos), NULL);
		ReadProcessMemory(Handle, (PBYTE*)(dwLocalPlayer + XYZposOffsets[2]), &Zpos, sizeof(Zpos), NULL);
		
	}

	cPlayer() {
		Offsets[0] = 0xF8;
		Offsets[1] = 0xFC;
		XYZposOffsets[0]= 0x4;
		XYZposOffsets[1]= 0xC;
		XYZposOffsets[2]= 0x8;
	}
};