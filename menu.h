#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>


class menuframework
{
	private:
		bool CreateStatus;
		std::string  strbutton,strExitMenuButton,strIngameButton;
	protected:
		std::string VK_list(DWORD);
		void Update();
		void Create();
		void Textedit();
		void Initialize();
	public:
		//vars
		DWORD ButtontoEnable,ButtontoExit, ButtonforIngame;
		int MenuColor;
		std::string MenuName, MenuText, Status;
		struct Color
		{
			int white, yellow, pink, red, turquoise, green, blue, grey, darkwhite, darkyellow, darkpink, darkred, darkturquoise, darkgreen, darkblue;
		}color;
		struct Button {
			DWORD F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12;
			DWORD INSERT, SPACE, RMbutton, LMbutton, MMbutton, BACKSPACE, TAB, ENTER, SHIFT, CTRL, ALT, CAPS;
			DWORD NUM0, NUM1, NUM2, NUM3, NUM4, NUM5, NUM6, NUM7, NUM8, NUM9;
		}button;
		
		bool UpdateStatus;
		bool active;
		//functions
		void recreate();
		void Run();

		menuframework();
		~menuframework();

};



