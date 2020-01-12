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
    BigInteger(const std::string number);
    void NullNumber();
    unsigned int SizeNumber();
    void PrintBinary();
    void Reverse();
    void Increment();

    BigInteger& operator= (const BigInteger& right);
    //Unary +
    friend const BigInteger& operator+(const BigInteger& number);
    //Unary -
    friend const BigInteger operator-(const BigInteger& number);
    //Prefix increment
    friend const BigInteger& operator++( BigInteger& number);
    //Postfix increment
    friend const BigInteger operator++( BigInteger& number,int);
    //Prefix decrement
    friend const BigInteger& operator--( BigInteger& number);
    //Postfix decrement
    friend const BigInteger operator--( BigInteger& number,int);

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
