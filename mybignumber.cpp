#include "mybignumber.h"

MyBigNumber::MyBigNumber(const char * myCharArray )
    :BigNumber(myCharArray){}

MyBigNumber::MyBigNumber( const std::string & str )
    :BigNumber( str ){}
MyBigNumber::MyBigNumber(const long & intNum )
    :BigNumber(intNum ){}

MyBigNumber MyBigNumber::operator<<( unsigned shift ){
    MyBigNumber temp;

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
 MyBigNumber temp;
for (int i = 0 ; i<myBig2.numOfDigits ; i++){
    temp+=MyBigNumber::multByOneDigit(myBig1 , myBig2.numArray[i]);
   (myBig1<<i);
  }
if(myBig1.getSign()== myBig2.getSign()){
    temp.setSign(true);
}
else{
    temp.setSign(false);
}
return temp;
}



