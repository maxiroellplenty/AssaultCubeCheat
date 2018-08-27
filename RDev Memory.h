#pragma once
#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>



	class cMemory {
	private:
		PROCESSENTRY32 ProcEntry32;
		DWORD dwProcessID = NULL;
		HANDLE hProcessSnap = NULL;

		MODULEENTRY32 ModEntry32;
		DWORD dwModuleAddress = NULL;
		HANDLE hModuleSnap = NULL;

		HANDLE hProcessHandle;

		DWORD getModule(wchar_t*);
		void getProcess(wchar_t*);
		void getProcessHandle();

		std::string errormessage;

	public:
		DWORD addModule(wchar_t*);
		void ProcessByWindow(LPCWSTR);
		void setProcessHandle(HANDLE);
		void initialize(wchar_t*);

		HANDLE getProcHandle();
		DWORD getProcessID();
		DWORD getBaseModule();

		template <typename T1>T1 rpm(DWORD);
		template <typename T2>void wpm(DWORD, T2);


		cMemory();
		cMemory(wchar_t*);
		~cMemory();
	};

