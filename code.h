#include "Header.h"
#include "EntityList.h"
#include "cWeapon.h"
#include "cPlayer.h"
#include "cAddresses.h"
#include "menu.h"
void run();
void menu();
DWORD AddOffsetToAddress(HANDLE, DWORD, DWORD[], int);
double getDistance(float, float, float, float, float, float);
void shoot();
void TeleKill(DWORD,DWORD,HANDLE);
void InfiniteHealh(DWORD, DWORD, HANDLE);
void run() {
	//cAccess *acc = new cAccess(NULL, "AssaultCube", true, "ac_client.exe", NULL);
	cAccess acc;
	cAddresses off;
	cWeapon currWeapon;
	acc.Initialize(NULL, "AssaultCube", true, "ac_client.exe", NULL);
	cPlayer player;
	DWORD Client = acc.getFirstModuleBase();
	EntityList EntityListe[32];
	std::vector <EntityList> TestListe;

	DWORD Playerbase = 0x109B74;
	DWORD Entitybase = 0x110D90;
	DWORD ActiveWeapon = 0x10FC84;
	DWORD PlayersAtGame = 0x10F500;
	DWORD MapNameAddress = 0x27A54;
	DWORD MapOffset = 0x34C;
	DWORD healthOffset = 0xF8;
	DWORD armorOffset = 0xFC;
	DWORD NameOffset = 0x225;
	DWORD TeamOffset = 0x32C;
	DWORD JediJumpOffset = 0x69;
	DWORD JediJumpOffset2 = 0x70;
	DWORD TestVar;
	DWORD TeamNumber;
	DWORD JediJumpValue;
	DWORD EntityBase;
	DWORD MapAddTemp;
	DWORD LocalPlayer;
	DWORD CurrentWeapon;
	DWORD Healthvalue;
	DWORD ArmorValue;
	DWORD HealthofPlayer;
	DWORD ArmorofPlayer;
	DWORD myTeamNumber;
	char *NameValue;
	char MapName[25];
	int newAmmo = 1337;
	int newhealth = 1337;
	int defaultHealth = 100;
	int newArmor = 1337;
	int newJediJump = 1;
	int newJediJump2 = 1;
	int WeaponID;
	int sizeofName;
	int PlayerNr;
	float zahlenarray[22] = { -5.5,-4.5,-3.5,-2.5,-1.5,-0.5,0.5,1.5,2.5,3.5,4.5,5.5,6.5,7.5,8.5,9.5,10.5,11.5,12.5,13.5,14.5,15.5 };

	LocalPlayer = acc.RPM<DWORD>(Client + Playerbase);
	CurrentWeapon = acc.RPM<DWORD>(Client + ActiveWeapon);
	EntityBase = acc.RPM<DWORD>(Client + Entitybase);
	Healthvalue = acc.RPM<int>(LocalPlayer + healthOffset);
	ArmorValue = acc.RPM<int>(LocalPlayer + armorOffset);
	myTeamNumber = acc.RPM<int>(LocalPlayer + TeamOffset);


	currWeapon.createWeaponID(acc.getProcesshandle(), CurrentWeapon);
		

	acc.WPM<DWORD>(LocalPlayer + currWeapon.returnOffsets[0],1337);
	
	int AmmoValue = acc.RPM<int>(LocalPlayer + currWeapon.returnOffsets[0]);

	std::cout << "Health        value= " << Healthvalue <<std::endl;
	std::cout << "Armor         value= " << ArmorValue << std::endl;
	std::cout << "Ammo          value= " << AmmoValue << std::endl;
	std::cout << "TeamNumber    value= " << myTeamNumber << std::endl;
	std::cout << std::endl;

	acc.WPM((LocalPlayer + healthOffset), 1337);
	acc.WPM((LocalPlayer + armorOffset), 1337);

	//Filling EntityList

	//while (true) {
	//	PlayerNr = acc->RPM<int>(Client + PlayersAtGame);
	//	MapAddTemp = acc->RPM<DWORD>(Client + MapNameAddress);



	//	ReadProcessMemory(acc->getProcesshandle(), (PBYTE*)(MapAddTemp+0x0), &MapName, sizeof(MapName), NULL);
	//	if (MapName != MapName || PlayerNr != PlayerNr) {
	//		for (int i = 0; i < 32;i++)
	//		{
	//			 EntityListe[i].~EntityList();
	//		}
	//	}
	//	for (int x = 0;x < (PlayerNr - 1);x++) {
	//		EntityListe[x].ReadValue(x, acc->getProcesshandle(), EntityBase);
	//	}
	//	std::cout << "Location: " << MapName <<  "   Players: " << PlayerNr << std::endl << std::endl;
	//	for (int x = 0;x < (PlayerNr - 1);x++) {
	//		NameValue = EntityListe[x].getName();
	//		std::cout<<  NameValue   <<" Health-> "<< EntityListe[x].getHealth() <<" Team-> "<<EntityListe[x].getTeam()<<  std::endl;
	//	}
	//	Sleep(500);
	//	system("CLS");
	//}


	// JediJump

	/*while (true) {
	WriteProcessMemory(ProcessHandl, (PBYTE*)(LocalPlayer + JediJumpOffset), &newJediJump, sizeof(BYTE), NULL);
	WriteProcessMemory(ProcessHandl, (PBYTE*)(LocalPlayer + JediJumpOffset2), &newJediJump2, sizeof(newJediJump2), NULL);
	}*/

	/*while (true) {
		if (GetAsyncKeyState(VK_SPACE)) {
		float value = acc->RPM<float>(LocalPlayer + 0xC);
		if (value == value) {
			keybd_event(MapVirtualKey(0x20, 0), 0x39, KEYEVENTF_EXTENDEDKEY, NULL);
			Sleep(3);
			keybd_event(MapVirtualKey(0x20, 0), 0x39, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, NULL);
		}
		for (int x = 0;x < 21;x++) {
			if (value == zahlenarray[x]) {
				keybd_event(MapVirtualKey(0x20, 0), 0x39, KEYEVENTF_EXTENDEDKEY, NULL);
				Sleep(3);
				keybd_event(MapVirtualKey(0x20, 0), 0x39, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, NULL);
			}
		}
	}
}*/

	//tele kill
	int a = 7;
	while(!GetAsyncKeyState(VK_INSERT)) 
	{
		if (a == 7)
		{
			a = 0;
			for (int x = 0;x < 7;x++) 
			{
				EntityListe[x].ReadInformation(x, acc.getProcesshandle(), EntityBase);
			}
		}
		if (GetAsyncKeyState(VK_F5)) 
		{
			do {
				acc.WPM(LocalPlayer + currWeapon.returnOffsets[1], 0);
				acc.WPM(LocalPlayer + 0x44, 7);
				acc.WPM(LocalPlayer + 0x8, (float)EntityListe[a].getmyyPos());
				acc.WPM(LocalPlayer + 0x4, (float)EntityListe[a].getmyxPos());
				acc.WPM(LocalPlayer + 0xC, (float)EntityListe[a].getmyzPos());
				EntityListe[a].ReadInformation(a, acc.getProcesshandle(), EntityBase);
				shoot();
			} while (EntityListe[a].getHealth()>1);
			a++;
			Sleep(500);
		}
	}

	for (int i = 0; i < 8;i++)
	{
		TestListe.push_back(EntityList(i, acc.getProcesshandle(), EntityBase));
	}


	for (auto elem : TestListe) {
		std::cout << elem.getName();
		std::cout <<" "<< elem.getHealth() << std::endl;
	}
	//while (true) {
	//	//acc.WPM(LocalPlayer + off.AssRiflereloadtime,0);
	//	acc.WPM(LocalPlayer + off.Sniperreloadtime, 0);
	//}
}

	
	
	

	
	


void menu() {

	menuframework mainmenu,m1;
	cAccess acc(NULL, "AssaultCube", true, "ac_client.exe", NULL);
	
	mainmenu.MenuName = "AssaultCube Trainer";
	mainmenu.MenuText = "TeleKill";
	mainmenu.ButtontoEnable = mainmenu.button.F1;
	mainmenu.ButtontoExit = mainmenu.button.INSERT;
	mainmenu.MenuColor = mainmenu.color.yellow;
	mainmenu.ButtonforIngame = mainmenu.button.F5;

	m1.ButtontoEnable = mainmenu.button.F2;
	m1.MenuText = "Infinite Health";

	

	while (!GetAsyncKeyState(mainmenu.ButtontoExit)) {
		mainmenu.Run();
		m1.Run();
	

		if (mainmenu.Status == "on" && mainmenu.active == false) {
			mainmenu.active = true;
			std::thread T1(TeleKill,mainmenu.ButtontoEnable,acc.getFirstModuleBase(),acc.getProcesshandle());
			T1.detach();
		}

		if (m1.Status == "on" && m1.active == false) {
			m1.active = true;
			std::thread T1(InfiniteHealh, m1.ButtontoEnable, acc.getFirstModuleBase(), acc.getProcesshandle());
			T1.detach();
		}

		if (mainmenu.UpdateStatus == true || m1.UpdateStatus == true) {
			system("cls");
			mainmenu.recreate();
			m1.recreate();
		}
	}
}














DWORD AddOffsetToAddress(HANDLE PrcHndl,DWORD BaseAddress,DWORD Offsets[],int PointerLevel) {
	DWORD Temp,FinalAddress;
	ReadProcessMemory(PrcHndl, (PBYTE*)(BaseAddress+Offsets[0]), &Temp, sizeof(DWORD), NULL);
	for (int x = 1;x < PointerLevel;x++) {
		FinalAddress = Temp;
		ReadProcessMemory(PrcHndl, (PBYTE*)(FinalAddress + Offsets[x]), &Temp, sizeof(DWORD), NULL);
	}
	return FinalAddress=Temp;
}
double getDistance(float myCoordsX, float myCoordsZ, float myCoordsY,
	float eNx, float eNz, float eNy)
{
	//Use the 3d distance formula to get a resulting Floating distance value POW!!
	return sqrt(
		pow(double(eNx - myCoordsX), 2.0) +
		pow(double(eNy - myCoordsY), 2.0) +
		pow(double(eNz - myCoordsZ), 2.0));
}
void shoot() {
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	Sleep(50);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
	Sleep(50);
}

void TeleKill(DWORD ButtonToPress,DWORD Module,HANDLE ProcessHandle) {
	EntityList EntityListe[32];
	cAccess acc;
	acc.setProcesshandle(ProcessHandle);
	cWeapon cWP;
	cAddresses addr;
	DWORD Weapon = acc.RPM<DWORD>(Module + 0x10FC84);
	DWORD LocalPlayer = acc.RPM<DWORD>(Module + addr.LocalPlayerAddress);
	DWORD EntityBase = acc.RPM<DWORD>(Module + addr.EntityBaseAddress);
	int a = 7;
	while (!GetAsyncKeyState(ButtonToPress))
	{
		cWP.createWeaponID(acc.getProcesshandle(), Weapon);
		if (a == 7)
		{
			a = 0;
			for (int x = 0;x < 7;x++)
			{
				EntityListe[x].ReadInformation(x, acc.getProcesshandle(), EntityBase);
			}
		}
		if (GetAsyncKeyState(VK_F5))
		{
			do {
				if (GetAsyncKeyState(ButtonToPress))return;
				acc.WPM(LocalPlayer + cWP.returnOffsets[1], 0);
				acc.WPM(LocalPlayer + 0x44, 7);
				acc.WPM(LocalPlayer + 0x8, (float)EntityListe[a].getmyyPos());
				acc.WPM(LocalPlayer + 0x4, (float)EntityListe[a].getmyxPos());
				acc.WPM(LocalPlayer + 0xC, (float)EntityListe[a].getmyzPos());
				EntityListe[a].ReadInformation(a, acc.getProcesshandle(), EntityBase);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				Sleep(50);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(50);
			} while (EntityListe[a].getHealth()>1);
			a++;
			Sleep(500);
		}
	}
	for (int x = 0;x < 8;x++) {
		EntityListe[x].~EntityList();
	}
}

void InfiniteHealh(DWORD ButtonToPress, DWORD Module, HANDLE ProcessHandle) {
	cAddresses addr;
	cAccess acc;
	acc.setProcesshandle(ProcessHandle);
	DWORD LocalPlayer = acc.RPM<DWORD>(Module + addr.LocalPlayerAddress);
	while (!GetAsyncKeyState(ButtonToPress)) {
		acc.WPM(LocalPlayer + addr.healthOffset, 1000);
		Sleep(50);
	}
}

