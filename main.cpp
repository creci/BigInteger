#include <iostream>
#include "biginteger.h"
using namespace std;

int main()
{
    string test1="1";
    string test2="-3";
    cout<<"Number:"<<test1<<endl;
    BigInteger test1_1(test1),test1_2(test2);
    test1_2=test1-test1_2;
    test1_2.PrintBinary();
    test1_1.PrintBinary();
    return 0;
}
