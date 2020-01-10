#include <string>
#ifndef BIGINTEGER_H
#define BIGINTEGER_H


class BigInteger
{
public:
    static const int size=4096;
    bool Number[size];
    bool Sign;
    BigInteger();
    BigInteger(std::string number);
    void NullNumber();
    unsigned int SizeNumber();
    void PrintBinary();

    //Unary +
    friend const BigInteger& operator+(const BigInteger& i);
    //Unary -
    friend const BigInteger operator-(const BigInteger& i);
    //Prefix increment
    friend const BigInteger& operator++(const BigInteger& i);
    //Postfix increment
    friend const BigInteger operator++(const BigInteger& i,int);
    //Prefix decrement
    friend const BigInteger& operator--(const BigInteger& i);
    //Postfix decrement
    friend const BigInteger operator--(const BigInteger& i,int);

    //Binary +
    friend const BigInteger operator+ (const BigInteger& left,const BigInteger& right);
    //Binary -
    friend const BigInteger operator- (const BigInteger& left,const BigInteger& right);
    //Binary *
    friend const BigInteger operator* (const BigInteger& left,const BigInteger& right);
    //Binary /
    friend const BigInteger operator/ (const BigInteger& left,const BigInteger& right);

};

#endif // BIGINTEGER_H
