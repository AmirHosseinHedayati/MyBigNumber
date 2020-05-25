#include "mybignumber.h"

MyBigNumber::MyBigNumber(const char * myCharArray )
    :BigNumber(myCharArray){}

MyBigNumber::MyBigNumber( const std::string & str )
    :BigNumber( str ){}
MyBigNumber::MyBigNumber(const long & intNum )
    :BigNumber(intNum ){}

MyBigNumber MyBigNumber::multByOneDigit (MyBigNumber &myBig , int num){
    MyBigNumber sum = "0";
  for(size_t i = 0 ; i < num; ++i){
   sum += myBig;
  }
  return sum;
}

MyBigNumber MyBigNumber::operator<<( unsigned shift ){
    MyBigNumber temp = "0";

    temp.sign = sign;
    temp.numOfDigits = numOfDigits + shift;
    temp.numArray = new int8_t[temp.numOfDigits];

    for(size_t i = 0 ; i<shift ; i++){
       temp[i] = 0;
    }
        for(size_t i = shift ; i<numOfDigits+shift ; i++){
           temp[i] = numArray[i-shift];
        }
        return  temp;
}

MyBigNumber operator*(MyBigNumber& myBig1 ,MyBigNumber& myBig2){
 MyBigNumber temp  = "0";
 MyBigNumber temp2 = "0";
for (int i = 0 ; i<myBig2.numOfDigits ; i++){
   temp2 = MyBigNumber::multByOneDigit(myBig1 , myBig2.numArray[i]);
   temp2 = (temp2<<i);
    temp+=temp2;
  }
if(myBig1 == "0" ||  myBig2 == "0"){
    temp.setSign(true);
}
if(myBig1.getSign()== myBig2.getSign()){
    temp.setSign(true);
}
else{
    temp.setSign(false);
}
return temp;
}

MyBigNumber& MyBigNumber::operator*=(MyBigNumber& myBig){
    *this = *this * (myBig);
    return *this;
}

MyBigNumber MyBigNumber::power(MyBigNumber& myBig, unsigned powerStep){
MyBigNumber temp = 1;
for (size_t i = 0; i < powerStep; i++){
    temp *= myBig;
}
if(powerStep % 2 == 0){
    temp.setSign(true);
}
else{
    temp.setSign(myBig.sign);
}
return temp;
}

/*MyBigNumber MyBigNumber::operator()(const unsigned num1 , const unsigned num2){
    MyBigNumber temp = "0";
    temp.numOfDigits= num2;
    for(size_t i = num1 ; i<num1+num2 ; i++){
        temp[i-num1] = numArray[i];
    }
    return temp;
}*/

MyBigNumber MyBigNumber::operator()(const unsigned num1 , const unsigned num2){
    MyBigNumber temp = "0";
    temp.numOfDigits= num2;
    for(size_t i = num1-num2+1 ; i<=num1 ; i++){
        temp[i-(num1-num2+1)] = numArray[i];
    }
    return temp;
}

