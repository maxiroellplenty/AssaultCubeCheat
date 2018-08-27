#include "menu.h"

void menuframework::Update() 
{
	if (Status == "off") Status = "on";
	else { 
		Status = "off"; 
		active = false;
	}
	Sleep(200);
}

void menuframework::Create()
{
	CreateStatus = true;
	strbutton = VK_list(ButtontoEnable);
	strExitMenuButton = VK_list(ButtontoExit);
	strIngameButton = VK_list(ButtonforIngame);
	Textedit();
	if (MenuName != "") 
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MenuColor);
		std::cout << MenuName;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.white);
		if (strExitMenuButton != "") {
			std::cout << " | [" << strExitMenuButton << "] to exit" << std::endl << std::endl;
		}
		else std::cout << std::endl;
	}
	else std::cout << std::endl;
	std::cout <<"  "<< MenuText << " [" << strbutton << "] to enable | status: ";
	if (Status == "off")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.red);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.green);
	std::cout << Status;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.white);
	if (strIngameButton != "")
	{
		if (Status == "on") {
			std::cout << "  | [" << strIngameButton << "] to use in game" << std::endl;
		}
		else std::cout << " | [" << strIngameButton << "] to use in game" << std::endl;
	}
	else std::cout << std::endl;
}

void menuframework::recreate()
{
	
	if (MenuName != "")
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), MenuColor);
		std::cout << MenuName;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.white);
		if (strExitMenuButton != "") {
			std::cout << " | [" << strExitMenuButton << "] to exit" << std::endl << std::endl;
		}
		else std::cout << std::endl;
	}
	else std::cout << std::endl;
	std::cout << "  " << MenuText << " [" << strbutton << "] to enable | status: ";
	if (Status == "off")SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.red);
	else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.green);
	std::cout << Status;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color.white);
	if (strIngameButton != "")
	{
		if (Status == "on") {
			std::cout << "  | [" << strIngameButton << "] to use in game" << std::endl;
		}
		else std::cout << " | [" << strIngameButton << "] to use in game" << std::endl;
	}
	else std::cout << std::endl;
}


void menuframework::Initialize() {
	//color
	color.white = 15;
	color.yellow = 14;
	color.pink = 13;
	color.red = 12;
	color.turquoise = 11;
	color.green = 10;
	color.blue = 9;
	color.grey = 8;
	color.darkwhite = 7;
	color.darkyellow = 6;
	color.darkpink = 5;
	color.darkred = 4;
	color.darkturquoise = 3;
	color.darkgreen = 2;
	color.darkblue = 1;
	//button
	button.F1 = VK_F1;
	button.F2 = VK_F2;
	button.F3 = VK_F3;
	button.F4 = VK_F4;
	button.F5 = VK_F5;
	button.F6 = VK_F6;
	button.F7 = VK_F7;
	button.F8 = VK_F8;
	button.F9 = VK_F9;
	button.F10 = VK_F10;
	button.F11 = VK_F11;
	button.F12 = VK_F12;
	button.ALT = VK_MENU;
	button.BACKSPACE = VK_BACK;
	button.CAPS = VK_CAPITAL;
	button.CTRL = VK_CONTROL;
	button.ENTER = VK_RETURN;
	button.INSERT = VK_INSERT;
	button.LMbutton = VK_LBUTTON;
	button.RMbutton = VK_RBUTTON;
	button.MMbutton = VK_MBUTTON;
	button.SHIFT = VK_SHIFT;
	button.SPACE = VK_SPACE;
	button.TAB = VK_TAB;
	button.NUM0 = VK_NUMPAD0;
	button.NUM1 = VK_NUMPAD1;
	button.NUM2 = VK_NUMPAD2;
	button.NUM3 = VK_NUMPAD3;
	button.NUM4 = VK_NUMPAD4;
	button.NUM5 = VK_NUMPAD5;
	button.NUM6 = VK_NUMPAD6;
	button.NUM7 = VK_NUMPAD7;
	button.NUM8 = VK_NUMPAD8;
	button.NUM9 = VK_NUMPAD9;

	Status = "off";
	active = false;
	UpdateStatus = false;
	CreateStatus = false;
	MenuColor = color.white;
}

void menuframework::Run()
{
	if (CreateStatus == false)Create();
	if (GetAsyncKeyState(ButtontoEnable)) {
		Update();
		UpdateStatus = true;
	}
	else UpdateStatus = false;

}
void menuframework::Textedit() {
	int i = MenuText.length();
	if (i < 18) {
		for (int x = 0; i <= 18;x++) {
			MenuText = MenuText + " ";
			i = MenuText.length();
		}
	}
}

std::string menuframework::VK_list(DWORD buttontp)
{
	std::string temp;
	if (buttontp == VK_F1)temp = "F1";
	else if (buttontp == VK_F2)temp = "F2";
	else if (buttontp == VK_F3)temp = "F3";
	else if (buttontp == VK_F4)temp = "F4";
	else if (buttontp == VK_F5)temp = "F5";
	else if (buttontp == VK_F6)temp = "F6";
	else if (buttontp == VK_F7)temp = "F7";
	else if (buttontp == VK_F8)temp = "F8";
	else if (buttontp == VK_F9)temp = "F9";
	else if (buttontp == VK_F10)temp = "F10";
	else if (buttontp == VK_F11)temp = "F11";
	else if (buttontp == VK_F12)temp = "F12";
	else if (buttontp == VK_INSERT)temp = "INSERT";
	else if (buttontp == VK_SPACE)temp = "SPACE";
	else if (buttontp == VK_NUMPAD0)temp = "NUM 0";
	else if (buttontp == VK_NUMPAD1)temp = "NUM 1";
	else if (buttontp == VK_NUMPAD2)temp = "NUM 2";
	else if (buttontp == VK_NUMPAD3)temp = "NUM 3";
	else if (buttontp == VK_NUMPAD4)temp = "NUM 4";
	else if (buttontp == VK_NUMPAD5)temp = "NUM 5";
	else if (buttontp == VK_NUMPAD6)temp = "NUM 6";
	else if (buttontp == VK_NUMPAD7)temp = "NUM 7";
	else if (buttontp == VK_NUMPAD8)temp = "NUM 8";
	else if (buttontp == VK_NUMPAD9)temp = "NUM 9";
	else if (buttontp == VK_MENU)temp = "ALT";
	else if (buttontp == VK_RBUTTON)temp = "RMB";
	else if (buttontp == VK_LBUTTON)temp = "LMB";
	else if (buttontp == VK_MBUTTON)temp = "MMB";
	else if (buttontp == VK_SHIFT)temp = "SHIFT";
	else if (buttontp == VK_RETURN)temp = "ENTER";
	else if (buttontp == VK_BACK)temp = "BACKSPACE";
	else if (buttontp == VK_CAPITAL)temp = "CAPS";
	else if (buttontp == VK_TAB)temp = "TAB";
	else if (buttontp == VK_CONTROL)temp = "CTRL";
	return temp;
}

menuframework::menuframework() 
{
	Initialize();

}
menuframework::~menuframework()
{
	
}