#include<iostream>
using namespace std;


/*
     Note that for post increment operator we cant do nesting
     with post increment operator --> example (i++)++ --> it gives compilation error
     , if we overload post-increment operator , and do nesting then 
     it will give unpredictable result
*/

class Fraction {

public:
     Fraction(int numerator, int denominator):m_Numerator(numerator), m_Denominator(denominator) {
         simplify();
     }
     
     void set(int numerator, int denominator){
         m_Numerator = numerator;
         m_Denominator = denominator;
         simplify();
     }

     int gcd(int a, int b){
          if(a % b == 0)
               return b;
          else
               return gcd(b, a % b);
     }

     void simplify(){
          int fact = gcd(m_Denominator, m_Numerator);
          this->m_Numerator = this->m_Numerator / fact;
          this->m_Denominator = this->m_Denominator / fact;
     }
     
     void print()const{
         cout<<m_Numerator<<" / "<<m_Denominator<<endl;
     }
     
     
     Fraction operator+(const Fraction& other) const {
         int n = (this->m_Numerator*other.m_Denominator) + (this->m_Denominator*other.m_Numerator);
         int d = this->m_Denominator * other.m_Denominator;
         return Fraction(n, d);
     }

     Fraction operator-(const Fraction& other) const {
         int n = (this->m_Numerator*other.m_Denominator) - (this->m_Denominator*other.m_Numerator);
         int d = this->m_Denominator * other.m_Denominator;
         return Fraction(n, d);
     }

     Fraction & operator++(){
          this->m_Numerator = this->m_Denominator + this->m_Numerator;
          simplify();
          return *this;
     }

     // overloading post increment operator
     Fraction operator++(int){
          Fraction newFra(m_Numerator, m_Denominator);
          this->m_Numerator = this->m_Denominator + this->m_Numerator;
          simplify();
          return newFra;
     } 
     

private:
     int m_Numerator;
     int m_Denominator;
};


int main(){
     Fraction f(12,8);
     f.print();
     f.set(9,8);
     f.print();

     Fraction f1(2, 3);
     Fraction f2(3, 2);
     (f1+f2).print();
     (f1-f2).print();

     Fraction f3(2,3);
     Fraction f4 = ++(++f3);
     f3.print();
     f4.print();
     (f4++).print();
     f4.print();
     return 0;
}

