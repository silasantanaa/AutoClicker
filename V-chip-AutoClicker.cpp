#include <iostream>
#include <Windows.h>

using namespace std;
// Configura por padrão falso
bool bState{ false };

void menu(bool bState)
{
	// Limpa o status do console
	system("cls");

	cout << "V-chip-AutoClicker v1" << endl;

	if (bState)
	{
		cout << "Status: ON\n";
	}
	else
	{
		cout << "Status: OFF\n";
	}
}

int main()
{
	menu(bState);
	while (true)
	{
		// Checar se o 'X' foi pressionado
		if (GetAsyncKeyState(0x58) & 1)
		{
			// Muda o valor de bState
			bState = !bState;
			// Status no console
			menu(bState);
		}

		if (bState)
		{
			// Simula o click do mouse
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		Sleep(10);
	}
}
