#ifndef __MONEY__
#define __MONEY__
#include <iostream>


struct money {
    unsigned long long pound;
    unsigned char shilling;
    unsigned char pension;
    money();
    money(unsigned long long po, unsigned char sh, unsigned char pe);
    void m_scan(std::istream& is);
    void m_print(std::ostream& os) const;
    money operator+ (const money& rhs) const;
    money operator/ (const double a) const;
    double operator/ (const money& rhs) const;
    money operator* (const double a) const;
    bool operator> (const money& rhs) const;
    bool operator>= (const money& rhs) const;
    bool operator< (const money& rhs) const;
    bool operator<= (const money& rhs) const;
    bool operator== (const money& rhs) const;
    void m_unif();
private:
    unsigned long long m_all() const;
    int m_cmp(const money& a) const;
};

std::istream& operator>> (std::istream& is, money& m);
std::ostream& operator<< (std::ostream& os, const money& m);
money operator"" _po (unsigned long long po);
money operator"" _sh (unsigned long long sh);
money operator"" _pe (unsigned long long pe);


#endif