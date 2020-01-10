#include "biginteger.h"
#include <stack>
#include <iostream>
using namespace std;
BigInteger::BigInteger()
{
    BigInteger::NullNumber();
    this->Sign=0;
}
void BigInteger::NullNumber(){
    for(unsigned int i=0;i<this->size;i++)
        this->Number[i]=0;
}
unsigned int BigInteger::SizeNumber(){
    unsigned int i=this->size-1;
    for(;this->Number[i]!=1&&i!=0;i--);
    return i+1;
}
void BigInteger::PrintBinary(){
    if(BigInteger::SizeNumber()==1 && !(this->Number[0])){
        cout<<"0.0"<<endl;
        return;
    }
    cout<<this->Sign<<".";
    unsigned int i=this->size-1;
    for(;!(this->Number[i]);i--);
    for(;i!=0;i--){
        cout<<this->Number[i];
    }
    cout<<this->Number[i];
    cout<<endl;
}
const BigInteger operator+ (const BigInteger& left,const BigInteger& right){
    bool p=0;
    bool buffer=0;
    BigInteger result;
    for(unsigned int i=0;i<result.size-1;i++){
        //cout<<left.Number[i]<<"^"<<right.Number[i]<<endl;
        buffer=left.Number[i]^right.Number[i];
        result.Number[i]=buffer^p;
        p=(p&buffer)|(left.Number[i]&right.Number[i]);
        cout<<left.Number[i]<<"+"<<right.Number[i]<<"="<<result.Number[i]<<endl;
    }
    buffer=left.Sign^right.Sign;
    result.Sign=buffer^p;
    p=(p&buffer)|(left.Sign&right.Sign);
    cout<<"Знак:";
    cout<<left.Sign<<"+"<<right.Sign<<"="<<result.Sign<<endl;
    result.PrintBinary();
    return result;
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
            temp2+=to_string(buffer/2);
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
        if(temp1[count]!='0')this->Number[count++]=1;
    }
}

