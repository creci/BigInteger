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
void BigInteger::Reverse(){
    for(unsigned int i=0;i<this->size;i++)
        this->Number[i]=!(this->Number[i]);
}

BigInteger& BigInteger::operator=(const BigInteger& right){
        if(this==&right) {
            return *this;
        }
        for(unsigned int i=0;i<right.size;i++)
            Number[i]=right.Number[i];
        Sign=right.Sign;
        return *this;
}

void BigInteger::Increment(){
    bool p=1;
    bool buffer=0;
    for(unsigned int i=0;i<this->size-1 && p;i++){
        buffer=this->Number[i]^0;
        this->Number[i]=buffer^p;
        p=(p&buffer)|(this->Number[i]&0);
    }
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
//Binary +
const BigInteger operator+ (const BigInteger& left,const BigInteger& right){
    bool p=0;
    bool buffer=0;
    BigInteger result;
    for(unsigned int i=0;i<result.size-1;i++){
        buffer=left.Number[i]^right.Number[i];
        result.Number[i]=buffer^p;
        p=(p&buffer)|(left.Number[i]&right.Number[i]);
    }
    buffer=left.Sign^right.Sign;
    result.Sign=buffer^p;
   // p=(p&buffer)|(left.Sign&right.Sign);
    return result;
}
//Prefix increment
const BigInteger& operator++( BigInteger& number){
    number++;
    return number;
}
//Postfix increment
const BigInteger operator++( BigInteger& number,int){
    bool p=1;
    bool buffer=0;
    BigInteger result=number;
    for(unsigned int i=0;i<result.size-1 && p;i++){
        buffer=number.Number[i]^0;
        number.Number[i]=buffer^p;
        p=(p&buffer)|(number.Number[i]&0);
    }
    buffer=number.Sign^0;
    number.Sign=buffer^p;
   // p=(p&buffer)|(number.Sign&0);
    return result;
}
//Unary +
const BigInteger& operator+(const BigInteger& number){
    return number;
}
//Unary -
const BigInteger operator-(const BigInteger& number){
    BigInteger result=number;
    result.Sign=!(result.Sign);
    result.Reverse();
    result.Increment();
    return  result;
}
BigInteger::BigInteger(const string number)
{
    string temp1(number);
    BigInteger::NullNumber();
    while(temp1[0]=='0')
        temp1=temp1.substr(1);
    if(temp1.length()==0){
        this->Sign=false;
        return;
    }else{
        if (number[0]=='-'){
            temp1=temp1.substr(1);
            this->Sign=true;
        }else{
            this->Sign=false;
        }
        string temp2;
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
        if(this->Sign ){
            this->Reverse();
            this->Increment();
        }
    }
}

