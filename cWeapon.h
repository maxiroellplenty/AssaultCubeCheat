#pragma once
#include "Header.h"

class cWeapon {
private:
	int iWeaponID;
	DWORD Temp;
	DWORD Offsets[2] = {0x0,0x28c};
	std::string WeaponName;
public:
	DWORD returnOffsets[2];// 1 Ammooffsets 2 reloadtimeoffsets
	int getWeaponID() {
		return iWeaponID;
	}
	void createWeaponID(HANDLE ProcHandl,DWORD BaseAddress){
		ReadProcessMemory(ProcHandl, (PBYTE*)(BaseAddress+Offsets[0]), &Temp, sizeof(DWORD), NULL);
		ReadProcessMemory(ProcHandl, (PBYTE*)(Temp + Offsets[1]), &iWeaponID, sizeof(iWeaponID), NULL);
		WeaponOffsets();
	}
	void WeaponOffsets() {
		switch (iWeaponID) {
		case 0://knife
			break;
		case 1://Pistol
			returnOffsets[0] = 0x13C;
			returnOffsets[1] = 0x164;
			break;
		case 2://Carabine
			returnOffsets[0] = 0x140;
			returnOffsets[1] = 0x168;
			break;
		case 3://Shutgun
			returnOffsets[0] = 0x144;
			returnOffsets[1] = 0x16C;
			break;
		case 4://MP
			returnOffsets[0] = 0x148;
			returnOffsets[1] = 0x170;
			break;
		case 5://Sniper
			returnOffsets[0] = 0x14C;
			returnOffsets[1] = 0x174;
			break;
		case 6://Rifle
			returnOffsets[0] = 0x150;
			returnOffsets[1] = 0x178;
			break;
		case 8://Grenade
			returnOffsets[0] = 0x158;
			break;
		case 9://2xPistols
			returnOffsets[0] = 0x15C;
			returnOffsets[1] = 0x184;
			break;

		}
		
	}
	cWeapon(){}
	~cWeapon(){}
};