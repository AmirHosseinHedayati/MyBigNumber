#include <iostream>
#include "BigNumber.h"
#include "mybignumber.h"
using namespace std;

int main()
{

MyBigNumber m1  = 15728839;
MyBigNumber m2 = "2";
cout<<"overload operator ++ pre: "<<++m2<<endl;
cout<<"overload operator ++ post: "<<m2++<<endl;
cout<<"overload operator -- pre: "<<--m2<<endl;
cout<<"overload operator -- post: "<<m2--<<endl;
cout<<"overload operator <= : "<<(m1<= m2)<<endl;
cout<<"overload operator >= : "<<(m1>=m2)<<endl;
cout<<"overload operator < : "<<(m1<m2)<<endl;
cout<<"overload operator < : "<<(m1>m2)<<endl;
cout<<"overload  operator + : "<<m1+m2<<endl;
cout<<"overload  operator - : "<<m1-m2<<endl;
cout<<"operator *: "<<m1*m2<< endl;
cout<<"overload operator << : "<<(m2<<2)<<endl;
cout<<"overload operator >>: "<<(m1>>3)<<endl;
cout<<"multByOneDigit function: "<<MyBigNumber::multByOneDigit(m2 , 3)<<endl;
cout<<"power function: "<<MyBigNumber::power(m2,3)<<endl;
cout<<"overload  operator (): "<<m1(6,3)<<endl;


    return 0;
}
