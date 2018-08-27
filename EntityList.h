#pragma once
#include "Header.h"

class EntityList {
private:
	int ID;
	DWORD HealthValue;
	DWORD TeamValue;
	char NameValue[25];
	DWORD EntityBaseAdd;

	DWORD Offset;
	DWORD HealthOffset;
	DWORD TeamOffset;
	DWORD NameOffset;
	float myxPos,myyPos,myzPos;
	DWORD XYZposOffsets[3];
	double Distance;
public:
	void setDistance(double Distance) {
		this->Distance = Distance;
	}
	double getDistance() {
		return Distance;
	}
	float getmyxPos(){
		return myxPos;
	}
	float getmyyPos() {
		return myyPos;
	}
	float getmyzPos() {
		return myzPos;
	}
	DWORD getHealth() {
		if (HealthValue > 100)return 0;
		else return HealthValue;
	}
	DWORD getTeam() {
		return TeamValue;
	}
	DWORD getPlayerEntityAddress() {
		return EntityBaseAdd;
	}
	char* getName() {
		return NameValue;
	}
	int getID() {
		return ID;
	}
	void ReadInformation(int player, HANDLE ProcHndl, DWORD EntityBase) {
		ID = player;
		Offset = (player*(BYTE)4);
		ReadProcessMemory(ProcHndl, (PBYTE*)(EntityBase + Offset), &EntityBaseAdd, sizeof(DWORD), NULL);
		ReadProcessMemory(ProcHndl, (PBYTE*)(EntityBaseAdd + HealthOffset), &HealthValue, sizeof(DWORD), NULL);
		ReadProcessMemory(ProcHndl, (PBYTE*)(EntityBaseAdd + TeamOffset), &TeamValue, sizeof(DWORD), NULL);
		ReadProcessMemory(ProcHndl, (PBYTE*)(EntityBaseAdd + NameOffset), &NameValue, sizeof(NameValue), NULL);
		ReadProcessMemory(ProcHndl, (PBYTE*)(EntityBaseAdd + XYZposOffsets[0]), &myxPos, sizeof(myxPos), NULL);
		ReadProcessMemory(ProcHndl, (PBYTE*)(EntityBaseAdd + XYZposOffsets[1]), &myyPos, sizeof(myyPos), NULL);
		ReadProcessMemory(ProcHndl, (PBYTE*)(EntityBaseAdd + XYZposOffsets[2]), &myzPos, sizeof(myzPos), NULL);


	}
	EntityList() {
		Offset = { 0x0 };
		HealthOffset = 0xF8;
		TeamOffset = 0x32C;
		NameOffset = 0x225;
		XYZposOffsets[0] = 0x4;
		XYZposOffsets[1] = 0x8;
		XYZposOffsets[2] = 0xc;
	}
	EntityList(int player,HANDLE ProcessHandle,DWORD EntityBase){
		Offset = { 0x0 };
		HealthOffset = 0xF8;
		TeamOffset = 0x32C;
		NameOffset = 0x225;
		XYZposOffsets[0] = 0x4;
		XYZposOffsets[1] = 0x8;
		XYZposOffsets[2] = 0xc;
		ReadInformation(player, ProcessHandle, EntityBase);

	}
	~EntityList(){
		
	}
};