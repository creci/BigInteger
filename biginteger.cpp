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
    for(unsigned int i=0;i<this->size && p;i++){
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

BigInteger::BigInteger(const BigInteger& number){
    for(unsigned int i=0;i<this->size;i++){
        this->Number[i]=number.Number[i];
    }
    this->Sign=number.Sign;
}

BigInteger::operator bool()const{
    if(this->Sign)return 1;
    for(unsigned int i=0;i<this->size;i++){
        if(this->Number[i]) return 1;
    }
    return 0;
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

//Binary -
const BigInteger operator- (const BigInteger& left,const BigInteger& right){
    BigInteger result=left+(-right);
    return  result;
}

//Prefix decrement
const BigInteger& operator--( BigInteger& number){
    number--;
    return number;
}

//Postfix decrement
const BigInteger operator--( BigInteger& number,int){
    bool p=0;
    bool buffer=0,buffer1=0;
    BigInteger result=number;
    for(unsigned int i=0;i<result.size;i++){
        buffer=number.Number[i]^1;
        buffer1=buffer^p;
        p=(p&buffer)|(number.Number[i]&1);
        number.Number[i]=buffer1;
    }
    buffer=number.Sign^1;
    number.Sign=buffer^p;
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
    bool buffer=0,buffer1=0;
    BigInteger result=number;
    for(unsigned int i=0;i<result.size && p;i++){
        buffer=number.Number[i]^0;
        buffer1=buffer^p;
        p=(p&buffer)|(number.Number[i]&0);
        number.Number[i]=buffer1;
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
    if(result.SizeNumber()!=1 || result.Number[0]){
        result.Sign=!(result.Sign);
        result.Reverse();
        result++;
    }
    return  result;
}

//Binary << | +
BigInteger operator<<(const BigInteger& number, int n){
    BigInteger Result=number;
    return Result<<=n;
}

BigInteger& operator<<= ( BigInteger& left,unsigned int n){
    if(n==0)return left;
    BigInteger Result=left;
    for(;n!=0;n--){
        for(unsigned int i=1;i<left.size;i++){
            Result.Number[i]=left.Number[i-1];
        }
        Result.Number[0]=left.Sign;
    }
    left=Result;
    return left;
}

//Binary >> | +
BigInteger operator>>(const BigInteger& number, int n){
    BigInteger Result=number;
    return Result>>=n;

}

//Binary =>> | +
BigInteger& operator>>= ( BigInteger& left,unsigned int n){
    if(n==0)return left;
    BigInteger Result=left;
    for(;n!=0;n--){
        for(unsigned int i=left.size-1;i!=0;){
            i--;
            Result.Number[i]=left.Number[i+1];
        }
        Result.Number[Result.size-1]=left.Sign;
    }
    left=Result;
    return left;

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
        while(temp1.length()!=0 && ((temp1[0]!='1' && temp1[0]!='0')|| temp1.length()!=1)){
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

BigInteger& operator*=(BigInteger& left,const BigInteger& right){
    if(!(left)){
        return left;
    }else if(!(right)){
        return left=right;
    }else{
        bool sign=left.Sign^right.Sign;
        if(left.SizeNumber()==1){
            left=right;
            left.Sign=sign;
            return left;
        }
        BigInteger buffer=right;
        if(buffer.SizeNumber()==1){
            left.Sign=sign;
            return left;
        }
        if(left.Sign){
            left--;
            left.Reverse();
        }
        if(buffer.Sign){
            buffer--;
            buffer.Reverse();
        }
        BigInteger temp;
        left.Sign=0;
        for(int i=0;i<=buffer.SizeNumber();i++,left<<=1){
            if(buffer.Number[i]){
                temp+=left;
            }
        }
        if(sign){
            temp.Reverse();
            temp.Increment();
        }
        left=temp;
        left.Sign=sign;
        return left;
    }
}
BigInteger& operator+=( BigInteger& left, const BigInteger& right){
    return left=left+right;
}
