#ifndef MYBIGNUMBER_H
#define MYBIGNUMBER_H
#include "BigNumber.h"

class MyBigNumber : public BigNumber{


public:
    static MyBigNumber multByOneDigit (BigNumber myBig , int num){
        MyBigNumber sum;
      for(size_t i = 0 ; i < num; ++i){
       sum += myBig;
      }
      return sum;
}
MyBigNumber (){}
MyBigNumber (const char * myCharArray);
MyBigNumber( const std::string & str );
MyBigNumber(const long & intNum );
BigNumber operator<<( unsigned shift );

};
#endif // MYBIGNUMBER_H
