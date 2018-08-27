#include "RDev Memory.h"


cMemory::cMemory()
{
}

cMemory::cMemory(wchar_t *ProcessName) 
{
	errormessage = "Process not found make sure its running...";
	getProcess(ProcessName);
	dwModuleAddress = getModule(ProcessName);
	getProcessHandle();
}

cMemory::~cMemory()
{
}

void cMemory::initialize(wchar_t *ProcessName)
{
	errormessage = "Process not found make sure its running...";
	getProcess(ProcessName);
	dwModuleAddress = getModule(ProcessName);
	getProcessHandle();
}

DWORD cMemory::getModule(wchar_t * ModuleName)
{
	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessID);
	if (hModuleSnap == NULL)return 0;
	ModEntry32.dwSize = sizeof(MODULEENTRY32);
	if (!Module32First(hModuleSnap, &ModEntry32))
	{
		CloseHandle(hModuleSnap);
		return 0;
	}
	do
	{
		if (wcscmp(ModEntry32.szModule, ModuleName)==0) 
		{
			DWORD temp = (DWORD)ModEntry32.modBaseAddr;
			CloseHandle(hModuleSnap);
			return temp;
		}
	}while (Module32Next(hModuleSnap, &ModEntry32));
}

void cMemory::getProcess(wchar_t * ProcessName)
{
	std::cout << errormessage;
	hProcessSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hProcessSnap == NULL)return;
	ProcEntry32.dwSize = sizeof (PROCESSENTRY32);

	if (!Process32First(hProcessSnap, &ProcEntry32)) 
	{
		CloseHandle(hProcessSnap);
		return;
	}
	do 
	{
		if (wcscmp(ProcEntry32.szExeFile, ProcessName)==0) 
		{
			dwProcessID = ProcEntry32.th32ProcessID;
			CloseHandle(hProcessSnap);
			system("CLS");
			return;
		}
	} while(Process32Next(hProcessSnap, &ProcEntry32));
}

void cMemory::getProcessHandle()
{
	hProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, false, dwProcessID);
}

DWORD cMemory::addModule(wchar_t * ModuleName)
{
	return getModule(ModuleName);
}

void cMemory::ProcessByWindow(LPCWSTR WindowName)
{
	HWND ProcessWindow = NULL;
	std::cout << errormessage;
	while (ProcessWindow == NULL)
	{
		ProcessWindow = FindWindow(NULL, WindowName);
	}
	GetWindowThreadProcessId(ProcessWindow, &dwProcessID);
	system("CLS");
}

void cMemory::setProcessHandle(HANDLE ProcessHandle)
{
	this->hProcessHandle = ProcessHandle;
}

HANDLE cMemory::getProcHandle()
{
	return hProcessHandle;
}

DWORD cMemory::getProcessID()
{
	return dwProcessID;
}

DWORD cMemory::getBaseModule()
{
	return dwModuleAddress;
}

template <typename T1>
T1 cMemory::rpm(DWORD dw_Address) 
{
	T1 Temp;
	ReadProcessMemory(hProcesshandle, (PBYTE)(dw_Address), &Temp, sizeof(Temp), NULL);
	return Temp;
}

template <typename T2>
void cMemory::wpm(DWORD dw_Address,T2 value)
{
	WriteProcessMemory(hProcesshandle, (PBYTE)(dw_Address), &value, sizeof(value), NULL);
}
