#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Функція для обчислення значення бульового виразу 7 варіанта
bool evaluateFunction(bool x, bool y, bool z) {
    return (((x && !y) || z) && (!x || y)) || !z;
}

int main() {
    cout << "Таблиця iстинностi:" << endl;
    cout << "x | y | z | f(x,y,z)" << endl;
    cout << "--------------------" << endl;

    vector<int> valuesVector;
    vector<int> trueSets;
    int decimalNumber = 0;

    // Перебір всіх можливих наборів змінних (від 000 до 111)
    for (int i = 0; i < 8; ++i) {
        bool x = (i >> 2) & 1;
        bool y = (i >> 1) & 1;
        bool z = i & 1;

        bool result = evaluateFunction(x, y, z);
        valuesVector.push_back(result);

        cout << x << " | " << y << " | " << z << " |    " << result << endl;

        if (result) {
            trueSets.push_back(i);
        }

        // Обчислення десяткового номера (старший біт відповідає набору 000)
        decimalNumber += result * pow(2, 7 - i);
    }

    cout << "\nВектор значень: (";
    for (size_t i = 0; i < valuesVector.size(); ++i) {
        cout << valuesVector[i] << (i == valuesVector.size() - 1 ? "" : ", ");
    }
    cout << ")" << endl;

    cout << "Порядковий номер: " << decimalNumber << endl;

    cout << "Номери наборiв, на яких f=1: ";
    for (size_t i = 0; i < trueSets.size(); ++i) {
        cout << trueSets[i] << (i == trueSets.size() - 1 ? "" : ", ");
    }
    cout << endl;

    return 0;
}