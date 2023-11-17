/*
Розробити карту, який би містила слово, якому у відповідність ставиться 5 питань.
Користувачу виводиться перше питання і дається 60 секунд, щоб подумати і потім
вписати відповідь. За правильну відповідь на перше питання зараховується 5 балів.
Якщо відповіді нема або вона хибна, то 0 балів і виводиться наступне питання. На
кожне питання дається 60 секунд для роздумів, але кількість балів за правильну
відповідь на 1 менше, ніж за попереднє. Кількість балів, які користувач отримав за
попередні етапи, він не знає.
Зробіть програму, яка би по черзі задавала користувачу 5 питань і обчислювала
загальну кількість балів за правильні відповіді.
В кінці правильну відповідь і кількість отриманих балів виведіть на екран.
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

// Функція для отримання відповіді користувача з обмеженням у 60 секунд
std::string getUserAnswer() {
    auto start = std::chrono::steady_clock::now();
    std::string answer;

    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            std::cout << ch;
            if (ch == '\r') {  // Обриваємо введення при натисканні ENTER
                break;
            }
            answer += ch;
        }

        auto end = std::chrono::steady_clock::now();
        auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(end - start).count();

        if (elapsedSeconds >= 60) {
            break;  // Обмежуємо ввод до 60 секунд
        }        
    }
    return answer;
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    // Карта з питаннями та відповідями
    std::map<std::string, std::string> questions = {
        {"Питання 1: 2 - 1 = ?", "1"},
        {"Питання 2: 6 + 2 = ?", "2"},
        {"Питання 3: 1 + 2 = ?", "3"},
        {"Питання 4: 1 + 3 = ?", "4"},
        {"Питання 5: 3 + 2 = ?", "5"}
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

    std::cout << "\nПравильна відповідь та кількість отриманих балів:\n";
    std::cout << "Загальна кількість балів: " << totalScore << "/15\n";

    return 0;
}
