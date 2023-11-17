/*
��������� �����, ���� �� ������ �����, ����� � ���������� ��������� 5 ������.
����������� ���������� ����� ������� � ������ 60 ������, ��� �������� � ����
������� �������. �� ��������� ������� �� ����� ������� ������������ 5 ����.
���� ������ ���� ��� ���� �����, �� 0 ���� � ���������� �������� �������. ��
����� ������� ������ 60 ������ ��� �������, ��� ������� ���� �� ���������
������� �� 1 �����, �� �� ��������. ʳ������ ����, �� ���������� ������� ��
�������� �����, �� �� ���.
������ ��������, ��� �� �� ���� �������� ����������� 5 ������ � �����������
�������� ������� ���� �� �������� ������.
� ���� ��������� ������� � ������� ��������� ���� ������� �� �����.
*/
#include <iostream>
#include <string>
#include <conio.h>
#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <map>
#include <chrono>

// ������� ��� ��������� ������ ����������� � ���������� � 60 ������
std::string getUserAnswer() {
    auto start = std::chrono::steady_clock::now();
    std::string answer;

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            std::cout << ch;
            if (ch == '\r') {  // �������� �������� ��� ��������� ENTER
                break;
            }
            answer += ch;
        }

        auto end = std::chrono::steady_clock::now();
        auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

        if (elapsedSeconds >= 60) {
            break;  // �������� ���� �� 60 ������
        }        
    }
    return answer;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // ����� � ��������� �� ���������
    std::map<std::string, std::string> questions = {
        {"������� 1: 2 - 1 = ?", "1"},
        {"������� 2: 6 + 2 = ?", "2"},
        {"������� 3: 1 + 2 = ?", "3"},
        {"������� 4: 1 + 3 = ?", "4"},
        {"������� 5: 3 + 2 = ?", "5"}
    };

    int totalScore = 0;
    int currentPoints = 5;

    for (const auto& pair : questions) {
        std::cout << pair.first << ": ";

        std::string userAnswer = getUserAnswer();

        if (userAnswer == pair.second) {
            totalScore += currentPoints;          
        }
        currentPoints--;
        std::cout << std::endl;
    }

    std::cout << "\n��������� ������� �� ������� ��������� ����:\n";
    std::cout << "�������� ������� ����: " << totalScore << "/15\n";

    return 0;
}
