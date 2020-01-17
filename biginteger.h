#include <string>
#ifndef BIGINTEGER_H
#define BIGINTEGER_H


class BigInteger
{
public:
    static const int size=4098;
    BigInteger();
    BigInteger(const BigInteger& number);
    BigInteger(const std::string number);
    void NullNumber();
    unsigned int SizeNumber();
    void PrintBinary();
    void Reverse();
    void Increment();
protected:
    bool Number[size];
    bool Sign;
public:
    //Assignment operator | +
    BigInteger& operator= (const BigInteger& right);
    //Unary + | +
    friend const BigInteger& operator+(const BigInteger& number);
    //Unary - | +
    friend const BigInteger operator-(const BigInteger& number);
    //Prefix increment | +
    friend const BigInteger& operator++( BigInteger& number);
    //Postfix increment | +
    friend const BigInteger operator++( BigInteger& number,int);
    //Prefix decrement | +
    friend const BigInteger& operator--( BigInteger& number);
    //Postfix decrement | +
    friend const BigInteger operator--( BigInteger& number,int);
    operator bool()const;//Bool |+

    //Binary >> | +
    friend BigInteger operator>>(const BigInteger& number, int n);
    //Binary << | +
    friend BigInteger operator<<(const BigInteger& number, int n);
    //Binary >>= | +
    friend BigInteger& operator>>= ( BigInteger& left,unsigned int n);
    //Binary <<= | +
    friend BigInteger& operator<<= ( BigInteger& left,unsigned int n);
    //Binary +=
    friend BigInteger& operator+=( BigInteger& left, const BigInteger& right);
    //Binary *=
    friend BigInteger& operator*=(BigInteger& left,const BigInteger& right);
    //Binary + | +
    friend const BigInteger operator+ (const BigInteger& left,const BigInteger& right);
    //Binary - | +
    friend const BigInteger operator- (const BigInteger& left,const BigInteger& right);
    //Binary *
    friend const BigInteger operator* (const BigInteger& left,const BigInteger& right);
    //Binary /
    friend const BigInteger operator/ (const BigInteger& left,const BigInteger& right);

};

#endif // BIGINTEGER_H
