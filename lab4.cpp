#include <iostream>

using namespace std;

// Функція з варіанта 7
bool func(bool x, bool y, bool z) {
    return (((x && !y) || z) && (!x || y)) || !z;
}

int main() {
    cout << "\nЗавдання 7: Карта Карно для f = ((x & !y) | z) & (!x | y) | !z\n\n";
    cout << "      yz\n";
    cout << "   | 00 | 01 | 11 | 10 |\n";
    cout << "---|----|----|----|----|\n";
    
    // Рядок x = 0
    cout << "x=0|";
    cout << "  " << func(0, 0, 0) << " |";
    cout << "  " << func(0, 0, 1) << " |";
    cout << "  " << func(0, 1, 1) << " |";
    cout << "  " << func(0, 1, 0) << " |\n";
    
    // Рядок x = 1
    cout << "x=1|";
    cout << "  " << func(1, 0, 0) << " |";
    cout << "  " << func(1, 0, 1) << " |"; // Тут буде 0
    cout << "  " << func(1, 1, 1) << " |";
    cout << "  " << func(1, 1, 0) << " |\n";
    
    cout << "\nЗгрупувавши одиниці на карті, отримуємо мінімізовану формулу:\n";
    cout << "МДНФ f = !x | y | !z\n";
    
    return 0;
}
```<ElicitationsGroup>

</ElicitationsGroup>