#include<iostream>
using namespace std;

class Polynomial {
    
    
    public:
    
    int *degCoeff;      
    int capacity;
    
    Polynomial(){
        this->degCoeff = new int[5];
        this->capacity = 5;
        for(int i = 0; i < this->capacity; i++){
            this->degCoeff[i] = 0;
        }
    }
    // Complete the class
    
    Polynomial(const Polynomial& p){
        this->capacity = p.capacity;
        degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++){
            degCoeff[i] = p.degCoeff[i];
        }
    }
    
    void operator=(const Polynomial& p){
        this->capacity = p.capacity;
        degCoeff = new int[p.capacity];
        for(int i = 0; i < p.capacity; i++){
            degCoeff[i] = p.degCoeff[i];
        }
    }
    
    void print(){
        for(int i = 0; i < capacity; i++){
            if(degCoeff[i] != 0){
                cout<<degCoeff[i]<<"x"<<i<<" ";
            }
        }
        cout<<endl;
    }
    
    Polynomial operator+(Polynomial other){
        Polynomial sum, small;
        if(this->capacity > other.capacity){
            sum = *this;
            small = other;
        }else{
            sum = other;
            small = *this;
        }
        for(int i = 0; i < small.capacity ; i++){
            sum.degCoeff[i] +=  small.degCoeff[i];
        }
        
        return sum;
    }
    
     Polynomial operator-(Polynomial other){
        Polynomial sum, small;
        bool fl;
        if(this->capacity > other.capacity){
            sum = *this;
            small = other;
            fl = false;
        }else{
            sum = other;
            small = *this;
            fl = true;
        }
        
        for(int i = 0; i < small.capacity ; i++){
            sum.degCoeff[i] -=  small.degCoeff[i];
        }
        if(fl){
            for(int i = 0; i < sum.capacity ; i++){
                sum.degCoeff[i] = sum.degCoeff[i]*-1;
            } 
        }
        return sum;
    }

    Polynomial operator*(Polynomial p){
        Polynomial pNew;
        for(int j = 0; j < p.capacity; j++){
            for(int i = 0; i < capacity; i++){
                int deg = i + j;
                int temp;
                if(deg >= pNew.capacity)
                    temp = 0;
                else
                    temp = pNew.degCoeff[deg];
                int coeff = temp + (this->degCoeff[i]*p.degCoeff[j]);
                pNew.setCoefficient(deg,coeff);
            }
        }
        return pNew;
    }

    void setCoefficient(int degree, int coef){
        if(degree <= (this->capacity-1)){
            this->degCoeff[degree] = coef;
            return;
        }else{
            int cap = this->capacity*2;
            int* nwArr = new int[cap];
            for(int i = 0; i < cap ; i++){
                if(i < this->capacity)
                    nwArr[i] = this->degCoeff[i];
                else
                    nwArr[i] = 0;
            }
            this->capacity = cap;
            this->degCoeff = nwArr;
            setCoefficient(degree, coef);
        }
    }
    
};

