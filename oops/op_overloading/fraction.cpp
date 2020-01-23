#include<iostream>
using namespace std;


class Fraction {

public:
     Fraction(int numerator, int denominator):m_Numerator(numerator), m_Denominator(denominator) {
         
     }
     
     void set(int numerator, int denominator){
         m_Numerator = numerator;
        m_Denominator = denominator;
     }
     
     void print(){
         cout<<m_Numerator<<" / "<<m_Denominator<<endl;
     }
     
     
     int findGCD(int a, int b){
         
     }
     
     void simplify(){
         
     }
     
     Fraction operator+(const Fraction& other){
         
     }
     Fraction operator-(const Fraction& other){
         
     }
     

private:
     int m_Numerator;
     int m_Denominator;
};

