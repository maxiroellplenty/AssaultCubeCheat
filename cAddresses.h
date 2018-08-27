#pragma once
#include "Header.h"
class cAddresses {
public:
	//Addresses
	DWORD LocalPlayerAddress= 0x109B74;
	DWORD EntityBaseAddress= 0x110D90;
	DWORD ActiveWeaponAddress= 0x10FC84;
	DWORD PlayersAtServerAddress= 0x10F500;
	DWORD MapNameAddress= 0x27A54;
	//Offsets
	DWORD MapOffset = 0x34C;
	DWORD healthOffset = 0xF8;
	DWORD armorOffset = 0xFC;
	DWORD NameOffset = 0x225;
	DWORD TeamOffset = 0x32C;
	DWORD JediJumpOffset = 0x69;
	DWORD JediJumpOffset2 = 0x70;
	DWORD XAches = 0x40;
	DWORD YAches = 0x44;
	DWORD Xposition = 0x4;
	DWORD Zposition = 0xc;
	DWORD Yposition = 0x8;
	DWORD AssRiflereloadtime = 0x178;
	DWORD Shutgunreloadtime = 0x16C;
	DWORD Sniperreloadtime = 0x174;
	cAddresses(){}
	~cAddresses(){}
};