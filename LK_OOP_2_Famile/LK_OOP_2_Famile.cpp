#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "Point05_02.h"
#include <iostream>


/*******************************************************************************/
/*                   О С Н О В Н А Я     П Р О Г Р А М М А                     */
/*******************************************************************************/
#define KEY_DOWN(vk_code)((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

using namespace std;

HWND   GetConcolWindow();     //  Объявим дескриптор (описатель) окна . Указатель на консольное окно
HDC    hdc;      // объявим  контекст устройства
// контекст устройства это структура, содержащая описание видеокарты и всех необходимых граф. эл

int main()
{
	system("color F0");
	setlocale(LC_ALL, "Russian");

	int x0 = 130;
	int y0 = 140;
	int i;
	
	HWND hwnd = GetConcolWindow(); // дескриптор окна
	
	if (hwnd != NULL)
	{
		hdc = GetWindowDC(hwnd);
		if (hdc != 0) {
			//перемещение точки по экрану

			Point APoint(x0, y0);  //инициализация объекта скрытой формой
			//Point APoint = Point(x0, y0); - явная форма инициализации
			APoint.Show();
			cin.get();
			cout << APoint.GetX() << " координата X" << endl;

			APoint.MoveTo(230, 210);  //показать точку
			cin.get();
			APoint.MoveTo(230, 220);  //показать точку
			cin.get();
			APoint.MoveTo(230, 230);  //показать точку
			cin.get();
			APoint.MoveTo(230, 240);  //показать точку
			cin.get();
			APoint.MoveTo(230, 250);  //показать точку
			cin.get();

			while (1) //бесконечный цикл для регенерации экрана
			{
				for (int i = 0; i < 50; i++)
				{
					Sleep(100);
					APoint.MoveTo(210, 200 + i);//переместиться в точку
				} //for
			} //while
		}
	}

	getchar();
}//end main()

HWND GetConcolWindow() {
	char str[128];
	LPWSTR title = (LPWSTR)"xxxxxxxxxxxxxxxxxx";
	GetConsoleTitle((LPWSTR)str, sizeof((LPWSTR)str));
	SetConsoleTitle(title);
	Sleep(100);
	HWND hwnd = FindWindow(NULL, (LPWSTR)title);
	SetConsoleTitle((LPWSTR)str);
	return hwnd;
}
/*******************  END OF FILE Ex05_02.CPP  ********************/