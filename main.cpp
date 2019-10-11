#include "Money.hpp"
#include <iostream>


signed main() {
    money l;
    l.m_scan(std::cin);
    unsigned long long rpo;
    int rsh, rpe;
    double div, prod;
    std::cin >> rpo >> rsh >> rpe;
    std::cin >> div >> prod;
    money r {rpo, (unsigned char)(rsh), (unsigned char)(rpe)};
    money t;
    t = 1_po + 2_sh + 3_pe;
    money res {};
    int comp;
    comp = l > r;
    std::cout << ">: " << comp << '\n';
    comp = l >= r;
    std::cout << ">=: " << comp << '\n';
    comp = l < r;
    std::cout << "<: " << comp << '\n';
    comp = l <= r;
    std::cout << "<=: " << comp << '\n';
    comp = l == r;
    std::cout << "==: " << comp << '\n';
    std::cout << "sum: ";
    res = l + r;
    res.m_print(std::cout);
    std::cout << "digital division: ";
    res = l / div;
    res.m_print(std::cout);
    std::cout << "digital product: ";
    res = l * prod;
    res.m_print(std::cout);
    std::cout << "money division: " << l / r << '\n';
}