#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;


struct Pair {
    int x, y;
    bool operator<(const Pair& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Pair& other) const {
        return x == other.x && y == other.y;
    }
};

void printRelation(const string& name, const set<Pair>& rel) {
    cout << name << " = { ";
    for (const auto& p : rel) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << "}\n";
}

int main() {
    cout << "=== ЛАБОРАТОРНА РОБОТА №2 (ВАРІАНТ 7) ===\n\n";

    // --- ЗАВДАННЯ 2 ---
    // A = {-3, -2, -1, 0, 1, 2, 3}, B = {1, 2, 3, 4, 5, 6}
    set<int> A = {-3, -2, -1, 0, 1, 2, 3};
    set<int> B = {1, 2, 3, 4, 5, 6};
    set<Pair> P1;

    // Умова 7: x, y - парні числа
    for (int x : A) {
        for (int y : B) {
            if (x % 2 == 0 && y % 2 == 0) {
                P1.insert({x, y});
            }
        }
    }
    cout << "--- Завдання 2 (Генерація P1) ---\n";
    printRelation("P1 (парні x та y)", P1);
    cout << "\n";

    // --- ЗАВДАННЯ 3 ---
    set<Pair> P2;
    // Умова: -1 <= x <= 1, 0 <= y <= 3
    for (int x = -1; x <= 1; ++x) {
        for (int y = 0; y <= 3; ++y) {
            P2.insert({x, y});
        }
    }
    cout << "--- Завдання 3 (Операції) ---\n";
    printRelation("P2", P2);

    // Перетин P1 ∩ P2
    set<Pair> intersectionSet;
    set_intersection(P1.begin(), P1.end(), P2.begin(), P2.end(), inserter(intersectionSet, intersectionSet.begin()));
    printRelation("P1 ∩ P2", intersectionSet);

    // Різниця P1 \ P2
    set<Pair> diffSet;
    set_difference(P1.begin(), P1.end(), P2.begin(), P2.end(), inserter(diffSet, diffSet.begin()));
    printRelation("P1 \\ P2", diffSet);
    
    // Обернене P1^(-1)
    set<Pair> inverseP1;
    for (const auto& p : P1) {
        inverseP1.insert({p.y, p.x});
    }
    printRelation("Обернене P1^-1", inverseP1);
    cout << "\n";

    // --- ЗАВДАННЯ 5 ---
    cout << "--- Завдання 5 (Перевірка властивостей) ---\n";
    set<int> A5 = {1, 2, 3, 4};
    set<Pair> R = {{1,1}, {2,2}, {3,3}, {1,2}, {2,3}, {3,1}};
    
    printRelation("Відношення R", R);

    // Перевірка на рефлексивність
    bool isReflexive = true;
    for (int a : A5) {
        if (R.find({a, a}) == R.end()) {
            isReflexive = false;
            break;
        }
    }
    cout << "Рефлексивність: " << (isReflexive ? "Так" : "Ні (немає (4,4))") << endl;

    // Перевірка на симетричність
    bool isSymmetric = true;
    for (const auto& p : R) {
        if (R.find({p.y, p.x}) == R.end()) {
            isSymmetric = false;
            break;
        }
    }
    cout << "Симетричність: " << (isSymmetric ? "Так" : "Ні (немає зворотних пар)") << endl;

    return 0;
}