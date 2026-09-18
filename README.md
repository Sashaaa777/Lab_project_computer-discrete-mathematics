#include <iostream>
#include <set>
#include <algorithm>
#include <iterator>
#include <cmath>

// Допоміжна функція для зручного виведення множин на екран
void printSet(const std::string& name, const std::set<int>& s) {
    std::cout << name << " = {";
    for (auto it = s.begin(); it != s.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != s.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

// Функція для об'єднання множин (U)
std::set<int> SetUnion(const std::set<int>& s1, const std::set<int>& s2) {
    std::set<int> result;
    std::set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(result, result.begin()));
    return result;
}

// Функція для перетину множин (∩)
std::set<int> SetIntersection(const std::set<int>& s1, const std::set<int>& s2) {
    std::set<int> result;
    std::set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(result, result.begin()));
    return result;
}

// Функція для різниці множин (\)
std::set<int> SetDifference(const std::set<int>& s1, const std::set<int>& s2) {
    std::set<int> result;
    std::set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(result, result.begin()));
    return result;
}

// Функція для симетричної різниці (Δ)
std::set<int> SetSymmetricDifference(const std::set<int>& s1, const std::set<int>& s2) {
    std::set<int> result;
    std::set_symmetric_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), std::inserter(result, result.begin()));
    return result;
}

int main() {
    // Ініціалізація множин для Варіанта 7
    std::set<int> U = {1, 2, 3, 4, 5, 6, 7, 8};
    std::set<int> A = {1, 3, 5, 7};
    std::set<int> B = {2, 4, 6, 8};
    std::set<int> C = {1, 2, 3, 4};

    std::cout << "--- Вихідні дані (Варіант 7) ---\n";
    printSet("U", U);
    printSet("A", A);
    printSet("B", B);
    printSet("C", C);
    std::cout << "\n";

    // ==========================================
    // 1-ШЕ ЗАВДАННЯ (Завдання 1 з лабораторної)
    // ==========================================
    std::cout << "--- 1. Операції з множинами ---\n";
    
    // a) Знайти: B \ (A U C)
    std::set<int> A_union_C = SetUnion(A, C);
    std::set<int> task1_a = SetDifference(B, A_union_C);
    printSet("Результат 1.а", task1_a);

    // б) Знайти: (A Δ B') ∩ C
    std::set<int> B_prime = SetDifference(U, B); // Знаходимо доповнення B'
    std::set<int> A_sym_diff_B_prime = SetSymmetricDifference(A, B_prime);
    std::set<int> task1_b = SetIntersection(A_sym_diff_B_prime, C);
    printSet("Результат 1.б", task1_b);

    // ==========================================
    // 2-ГЕ ЗАВДАННЯ (Завдання 2 з лабораторної)
    // ==========================================
    std::cout << "\n--- 2. Знаходження нової множини та булеана ---\n";
    
    // Нова множина: (A ∩ C) U B'
    std::set<int> A_int_C = SetIntersection(A, C);
    std::set<int> task2_set = SetUnion(A_int_C, B_prime);
    
    printSet("Нова множина D", task2_set);
    std::cout << "Потужність множини D: " << task2_set.size() << "\n";
    std::cout << "Потужність булеана: " << pow(2, task2_set.size()) << "\n";

    // ==========================================
    // 3-ТЄ ЗАВДАННЯ (Завдання 7 з лабораторної)
    // ==========================================
    std::cout << "\n--- 3. Спрощення виразу (Закон поглинання) ---\n";
    
    // Вираз: A ∩ (A U B)
    std::set<int> A_union_B = SetUnion(A, B);
    std::set<int> task7_result = SetIntersection(A, A_union_B);
    
    printSet("Результат виразу A ∩ (A U B)", task7_result);
    
    // Програмна перевірка тотожності
    if (task7_result == A) {
        std::cout << "Перевірка пройдена: результат дійсно дорівнює множині A!\n";
    } else {
        std::cout << "Помилка у розрахунках.\n";
    }

    return 0;
}
