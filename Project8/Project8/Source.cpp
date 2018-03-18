#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>

using namespace std;


//funkcja, kt�ra przestawia kursor konsoli w dowolne miejsce
void gotoxy(const int x, const int y)
{
	COORD coord = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int OpcjaA()
{
	cout << "OPCJA A";
	_getch();
	return 0;
}

int OpcjaB()
{
	cout << "OPCJA B";
	_getch();
	return 0;
}

int OpcjaC()
{
	cout << "OPCJA C";
	_getch();
	return 0;
}

int Exit()
{
	exit(0);
}


int menu(int n, int wysokosc, int szerokosc, string FunctionNames[], int(*Functions[])()){
	int wybor;
	int poprzedniWybor;
	bool wykonujPetle;


	//p�tla g��wna programu
	while (1)
	{
		wybor = 0;
		poprzedniWybor = wybor;
		wykonujPetle = true;
		//rysowanie menu
		system("cls");

		for (int i = 0; i < n; i++) {
			gotoxy(szerokosc, wysokosc + 1 + 2 * i);
			cout << FunctionNames[i];
		}

		//przesuwanie strza�ki
		while (wykonujPetle)
		{
			//rysowanie strza�ki wyboru
			gotoxy(szerokosc-2, wybor * 2 + wysokosc+1);
			cout << static_cast < char >(16);

			//obs�uga klawiatury
			poprzedniWybor = wybor;
			switch (_getch())
			{
			case 224: //STRZA�KI
				switch (_getch())
				{
				case 72: //strza�ka w g�r�
					if (0 < wybor) wybor--;
					else wybor = n-1;

					break;

				case 80: //strza�ka w d�
					if (wybor < n-1) wybor++;
					else wybor = 0;

					break;
				}
				break;
			case 13: //enter
					 //je�eli wci�ni�to enter, sprawd� wybran� opcj� i wykonaj odpowiedni� akcj�
				Functions[wybor]();
				break;
				
			}

			//czyszczenie strza�ki wyboru
			gotoxy(szerokosc-2, wysokosc + poprzedniWybor * 2 + 1);
			cout << " ";
		}
	}
	return 0;
}

int main(int argc, char* argv[])
{

	const int n = 4;
	string *FunctionNames = new string[n];
	FunctionNames[0] = "Opcja A";
	FunctionNames[1] = "Opcja B";
	FunctionNames[2] = "Opcja C";
	FunctionNames[3] = "Exit";

	int(*Functions[n])();
	Functions[0] = OpcjaA;
	Functions[1] = OpcjaB;
	Functions[2] = OpcjaC;
	Functions[3] = Exit;

	

	menu(4, 10, 13, FunctionNames, Functions);
	return 0;
}