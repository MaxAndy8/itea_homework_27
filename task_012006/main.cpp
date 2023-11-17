/*Розгляньте програму.Здійсніть рефакторинг кода :
1) щоб не було повторень оголошення і визначення змінних в тексті програми
2) фрагменти кода, які повторюються, оформіть функціями */

// Завдання виконане тільки для Windows тому що маю поки що тільки цю ОС.

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#elif __linux
#include <termios.h>
#endif
using namespace std;

void showMenu() {
	cout << "Натисніть 1 для заміни цифр пробілами\n";
	cout << "Натисніть 2 для заміни розділових знаків пробілами\n";
	cout << "Натисніть 3 для заміни англійських букв пробілами\n";
	cout << "Натисніть 4 для заміни українських букв пробілами\n";
}

int main() {
	string Ukr  = "йцукенгшщзхждлорпавфячсмитьбюЙЦУКЕНГШЩЗХЖДЛОРПАВФЯЧСМИТЬБЮґҐІіЄєЇї";
	string Eng  = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
	string Num  = "0123456789";
	string Symb = "`~!@#$%^&*()_+}{|\":<>?/.,\\';][=-№";
	int    choice = 0;	
	string text;

#ifdef __linux

	struct termios Old, New;
	bool menu_run = true;
	while (menu_run)
	{
		showMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			system("clear");
			cout << "Для закінчення введення даних натисніть клавішу esc\n";
			tcgetattr(0, &Old);
			New = Old;
			New.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &New);
			qt = getchar();
			while ((qt = getchar()) != 27) {
				for (int i = 0; i < Num.length(); i++) {
					if (qt == Num[i]) {
						qt = ' ';
					}
				}
				text += qt;
				cout << qt;
			}
			tcsetattr(0, TCSANOW, &Old);
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			break;
		case 2:
			system("clear");
			cout << "Для закінчення введення даних натисніть клавішу esc\n";
			tcgetattr(0, &Old);
			New = Old;
			New.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &New);
			qt = getchar();
			while ((qt = getchar()) != 27) {
				for (int i = 0; i < Symb.length(); i++) {
					if (qt == Symb[i]) {
						qt = ' ';
					}
				}
				text += qt;
				cout << qt;
			}
			tcsetattr(0, TCSANOW, &Old);
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			break;
		case 3:
			system("clear");
			cout << "Для закінчення введення даних натисніть клавішу esc\n";
			tcgetattr(0, &Old);
			New = Old;
			New.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &New);
			qt = getchar();
			while ((qt = getchar()) != 27) {
				for (int i = 0; i < Eng.length(); i++) {
					if (qt == Eng[i]) {
						qt = ' ';
					}
				}
				text += qt;
				cout << qt;
			}
			tcsetattr(0, TCSANOW, &Old);
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			break;
		case 4:
			system("clear");
			cout << "Для закінчення введення даних натисніть клавішу esc\n";
			tcgetattr(0, &Old);
			New = Old;
			New.c_lflag &= ~(ICANON | ECHO);
			tcsetattr(0, TCSANOW, &New);
			qt = getchar();
			while ((qt = getchar()) != 27) {
				for (int i = 0; i < Ukr.length(); i++) {
					if (qt == Ukr[i]) {
						qt = ' ';
					}
				}
				text += qt;
				cout << qt;
			}
			tcsetattr(0, TCSANOW, &Old);
			cout << endl << "Ви ввели текст:\n";
			cout << text << endl;
			break;
		default:
			menu_run = false;
			break;
		}
	}

#elif _WIN32
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
		
	auto lambda = [&text](const string& str) {
		system("CLS");
		cout << "Для закінчення введення даних натисніть клавішу esc\n";
		char   qt;
		bool run = true;
		while (run) {
			if (_kbhit()) {
				qt = _getch();

				switch (qt)
				{
				case 13:
					qt = '\n';
					break;
				case 27:
					qt = ' ';
					run = false;
					break;
				default:
					if (str.find(qt) != std::string::npos) {
						qt = ' ';
					}
					break;
				}
				text += qt;
				cout << qt;
			}
		}
	};

	bool menu_run = true;
	while (menu_run)
	{
		showMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			lambda(Num);
			break;
		case 2:
			lambda(Symb);
			break;
		case 3:
			lambda(Eng);
			break;
		case 4:
			lambda(Ukr);
			break;
		default:
			menu_run = false;
			break;
		}
	}
#endif
}