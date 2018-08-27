//FrankWizard
//10.01.2017

#pragma once
#include <windows.h>
#include <TlHelp32.h>
#include <string>

class cAccess {
private:

	//ProcessEntry Vars
	DWORD ProcessID = NULL;
	PROCESSENTRY32 PE32;
	HANDLE hProcSnap;

	//ModuleEntry Vars
	DWORD ModAddress = NULL;
	MODULEENTRY32 ME32;
	HANDLE hModlSnap;

	//Module Vars
	DWORD FirstModule, SecondModule;

	//ProcessHandel Var
	HANDLE Processhandle;

	//Window Var
	HWND hGameWindow = NULL;

	//Status for Processhandle creation
	bool ProcesshandleStatus = true;

	//error message
	std::string errormessage = " not found make sure the game is running...";
public:
//Return-Functions
#pragma region ReturnFunktions
	DWORD getProcessID()
	{
		return ProcessID;
	}
	DWORD getFirstModuleBase()
	{
		return FirstModule;
	}
	DWORD getSecondModuleBase()
	{
		return SecondModule;
	}
	HANDLE getProcesshandle()
	{
		return Processhandle;
	}
	bool getStatus()
	{
		return ProcesshandleStatus; //if you want to know if there was an error you can check the status
	}
#pragma endregion

	
	
	//set Methods
	void setProcesshandle(HANDLE Processhandle)
	{
		this->Processhandle = Processhandle;
	}


	//ReadProcessMemory (RPM)
	template <typename T1>
	T1 RPM(DWORD dw_Address)
	{
		T1 Temp;
		ReadProcessMemory(Processhandle, (PBYTE)(dw_Address), &Temp, sizeof(Temp),NULL);
		return Temp;
	}

	//WriteProcessMemory (WPM)
	template <typename T1>
	void WPM(DWORD dw_Address,T1 ValueToWrite)
	{
		WriteProcessMemory(Processhandle, (PBYTE)(dw_Address), &ValueToWrite, sizeof(ValueToWrite), NULL);
	}

	//ProcessID-Function
	void getProcess_Window(LPCWSTR LGameWindow) 
	{
		while (hGameWindow == NULL)
		{
			hGameWindow = FindWindow(NULL, LGameWindow);
			std::cout << "Window " << LGameWindow <<errormessage << std::endl;
			Sleep(100);
			system("CLS");
			
		}
		GetWindowThreadProcessId(hGameWindow, &ProcessID);
	}

	//ProcessEntry-Function
	DWORD getProcess(char *processName) 
	{
		while (!ProcessID) 
		{
			hProcSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
			if (hProcSnap == NULL)return 0;
			PE32.dwSize= { sizeof(PROCESSENTRY32) };
			if (Process32First(hProcSnap, &PE32)) 
			{
				do {
					if (!strcmp(PE32.szExeFile, processName)) 
						{
							ProcessID = PE32.th32ProcessID;
							break;
						}
					else 
					{
						std::cout << "Process " << processName << errormessage << std::endl;
						Sleep(100);
						system("CLS");
					}
					
					} while (Process32Next(hProcSnap, &PE32));
			}
		}
		CloseHandle(hProcSnap);
		return 0;
	}
	//ModuleEntry-Function
	DWORD getModule(char *moduleName) 
	{
		if (ProcessID == NULL)return 0;
		while (!ModAddress)
		{
			hModlSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, ProcessID);
			if (hModlSnap == NULL)return 0;
			ME32.dwSize = { sizeof(MODULEENTRY32) };
			if (Module32First(hModlSnap, &ME32)) 
			{
				do {
					if (!strcmp(ME32.szModule, moduleName)) 
					{
						ModAddress = (DWORD)ME32.modBaseAddr;
						break;
					}
				} while (Module32Next(hModlSnap, &ME32));
			}
			CloseHandle(hModlSnap);
			return 0;
		}
		return 0;
	}
	//Initialize used to set data for std construktor
	void Initialize(char *processName, LPCSTR LWindowName, bool processhandle, char *FirstModule, char* SecondModule) {
		if (processName != NULL)
		{
			getProcess(processName);
		}
		if (LWindowName != NULL)
		{
			getProcess_Window(LWindowName);
		}

		if (processName == NULL && LWindowName == NULL)
		{
			ProcesshandleStatus = false;
		}

		if (ProcesshandleStatus == true)
		{
			if (FirstModule != NULL)
			{
				getModule(FirstModule);
				this->FirstModule = ModAddress;
				ModAddress = NULL;
			}
			if (SecondModule != NULL)
			{
				getModule(SecondModule);
				this->SecondModule = ModAddress;
				ModAddress = NULL;
			}
			if (processhandle == true)
			{
				Processhandle = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessID);
			}
		}
		else
		{
			std::cout << "no ProcessName or WindowName found" << std::endl;
			Sleep(5000);
		}
	}
	
	//std construktor
	cAccess()
	{
		
	}
	//paramenter construktor
	cAccess(char *processName, LPCSTR LWindowName, bool processhandle, char *FirstModule, char* SecondModule) {
		if (processName != NULL)
		{
			getProcess(processName);
		}
		if (LWindowName != NULL)
		{
			getProcess_Window(LWindowName);
		}

		if (processName == NULL && LWindowName == NULL)
		{
			ProcesshandleStatus = false;
		}

		if (ProcesshandleStatus == true)
		{
			if (FirstModule != NULL)
			{
				getModule(FirstModule);
				this->FirstModule = ModAddress;
				ModAddress = NULL;
			}
			if (SecondModule != NULL)
			{
				getModule(SecondModule);
				this->SecondModule = ModAddress;
				ModAddress = NULL;
			}
			if (processhandle == true)
			{
				Processhandle = OpenProcess(PROCESS_ALL_ACCESS, false, ProcessID);
			}
		}
		else
		{
			std::cout << "no ProcessName or WindowName found" << std::endl;
			Sleep(5000);
		}
	}
	//deconstruktor
	~cAccess()
	{
	}
};