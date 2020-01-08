#include <string>
#ifndef BIGINTEGER_H
#define BIGINTEGER_H


class BigInteger
{
private:
    bool Number[4096];
    bool Sign;
public:
    BigInteger();
    BigInteger(std::string number);
    void NullNumber();
};

#endif // BIGINTEGER_H
