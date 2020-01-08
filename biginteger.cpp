#include "biginteger.h"
#include <stack>
#include <iostream>
using namespace std;
BigInteger::BigInteger()
{

}
void BigInteger::NullNumber(){
    for(unsigned int i=0;i<4096;i++)
        this->Number[i]=0;
}
BigInteger::BigInteger(string number)
{
    BigInteger::NullNumber();
    if(number.length()==0){
        this->Sign=false;
    }else{
        if (number[0]=='-'){
            number=number.substr(1);
            this->Sign=true;
        }else{
            this->Sign=false;
        }
        string temp1(number),temp2;
        stack<bool> TempNumber;
        int buffer=0;
        unsigned int i=0,count=0;
        while(temp1.length()!=0 && !((temp1[0]=='1' || temp1[0]=='0')&& temp1.length()==1)){
        while(temp1.length()!=i){
            buffer=buffer*10+temp1[i]-'0';
            temp2+=std::to_string(buffer/2);
            buffer=buffer%2;
            i++;
        }
        i=0;
        this->Number[count++]=buffer;
        while(temp2[0]=='0')
            temp2=temp2.substr(1);
        temp1=temp2;
        temp2.clear();
        buffer=0;
        }
        this->Number[count++]=1;
}

