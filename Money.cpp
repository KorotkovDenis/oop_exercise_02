#include "Money.hpp"
#include <iostream>

money::money() {
    pound = 0;
    shilling = 0;
    pension = 0;
}


money::money(unsigned long long po, unsigned char sh, unsigned char pe) {
    pound = po;
    shilling = sh;
    pension = pe;
}


unsigned long long money::m_all() const {
    return this->pension + this->shilling * 12 + this-> pound * 12 * 20;
}


void money::m_print(std::ostream& os) const {
    unsigned char zer = 0;
    os << this->pound << ' ' << this->shilling - zer << ' ' << this->pension - zer << '\n';
}


void money::m_scan(std::istream& is) {
    int sh, pe;
    is >> this->pound >> sh >> pe;
    this->shilling = sh;
    this->pension = pe;
}


money operator"" _po (unsigned long long po) {
    money tmp {po, 0, 0};
    return tmp;
}


money operator"" _sh (unsigned long long sh) {
    money tmp {0, sh, 0};
    return tmp;
}


money operator"" _pe (unsigned long long pe) {
    money tmp {0, 0, pe};
    return tmp;
}


std::istream& operator>> (std::istream& is, money& m) {
    m.m_scan(is);
    return is;
}


std::ostream& operator<< (std::ostream& os, const money& m) {
    m.m_print(os);
    return os;
}


int money::m_cmp(const money &a) const {
    if ((*this).m_all() > a.m_all()) return 1;
    else if ((*this).m_all() == a.m_all()) return 0;
    else return -1;

}


money money::operator+ (const money &rhs) const{
    money res;
    res.pound = this->pound + rhs.pound;
    res.shilling = this->shilling + rhs.shilling;
    res.pension = this->pension + rhs.pension;
    res.pension = this->pension + rhs.pension;
    res.m_unif();
    return res;
}


money money::operator/ (const double a) const{
    money res;
    unsigned long long all = (*this).m_all() / a;
    res.pound = all / 240;
    all %= 240;
    res.shilling = all / 12;
    all %= 12;
    res.pension = all;
    return res;
}


money money::operator* (const double a) const{
    money res;
    unsigned long long all = (*this).m_all() * a;
    res.pound = all / 240;
    all %= 240;
    res.shilling = all / 12;
    all %= 12;
    res.pension = all;
    return res;
}


double money::operator/ (const money& rhs) const{
    return (*this).m_all() / rhs.m_all();
}


bool money::operator> (const money& rhs) const{
    return (*this).m_cmp(rhs) > 0;
}


bool money::operator>= (const money& rhs) const{
    return (*this).m_cmp(rhs) >= 0;
}


bool money::operator< (const money& rhs) const{
    return (*this).m_cmp(rhs) < 0;
}


bool money::operator<= (const money& rhs) const{
    return (*this).m_cmp(rhs) <= 0;
}


bool money::operator== (const money& rhs) const{
    return (*this).m_cmp(rhs) == 0;
}


void money::m_unif() {
    this->pound += this->shilling / 20;
    this->shilling = this->shilling % 20;
    this->shilling += this->pension / 12;
    this->pension = this->pension % 12;
    this->pound += this->shilling / 20;
    this->shilling = this->shilling % 20;
}


