#include <iostream>
#include <iomanip>

using namespace std;

// Функція для вихідної формули (A -> (B -> C)) -> (!A -> !B)
bool originalFormula(bool A, bool B, bool C) {
    bool p1 = !A || (!B || C); // A -> (B -> C)
    bool p2 = A || !B;         // !A -> !B
    return !p1 || p2;          // p1 -> p2
}

// Функція для ДНФ
bool dnfFormula(bool A, bool B, bool C) {
    return A || !B;
}

int main() {
    cout << "Завдання 1: Таблиця істинності та перевірка еквівалентності\n";
    cout << "A B C | Оригінал | ДНФ | Еквівалентні?\n";
    cout << "----------------------------------------\n";
    
    bool allEquivalent = true;
    
    for (int i = 0; i < 8; ++i) {
        bool A = (i >> 2) & 1;
        bool B = (i >> 1) & 1;
        bool C = i & 1;
        
        bool orig = originalFormula(A, B, C);
        bool dnf = dnfFormula(A, B, C);
        bool equiv = (orig == dnf);
        
        if (!equiv) allEquivalent = false;
        
        cout << A << " " << B << " " << C << " |    " 
             << orig << "       |  " << dnf << "  |    " 
             << (equiv ? "Так" : "Ні") << "\n";
    }
    
    if(allEquivalent) cout << "\nВихідна формула та ДНФ є строго еквівалентними.\n";
    else cout << "\nФормули не еквівалентні!\n";
    
    return 0;
}