#include<iostream>
using namespace std;

class Polynomial {
    int *degCoeff;      // Name of your array (Don't change this)
    int capacity;
    
    public:
    
    Polynomial(){
        this->degCoeff = new int[5];
        this->capacity = 5;
        for(int i = 0; i < this->capacity; i++){
            this->degCoeff[i] = 0;
        }
    }
    // Complete the class
    
    Polynomial(Polynomial& p){
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
        for(int i = 0; i < sum.capacity ; i++){
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
        
        for(int i = 0; i < sum.capacity ; i++){
            sum.degCoeff[i] -=  small.degCoeff[i];
        }
        if(fl){
            for(int i = 0; i < sum.capacity ; i++){
                sum.degCoeff[i] = sum.degCoeff[i]*-1;
            } 
        }
        return sum;
    }

    Polynomial operator*(Polynomial other){
        int c = this->capacity + other.capacity;
        int *nwArr = new int[c];
        for(int i = 0; i < c; i++){
            nwArr[i] = 0;
        }
        Polynomial p;
        p.capacity = c;
        p.degCoeff = nwArr;
        for(int i = 0; i < this->capacity; i++){
            if(this->degCoeff[i] != 0){
                for(int j = 0; j < other.capacity; j++){
                    if(other.degCoeff[j] != 0){
                        p.degCoeff[i+j] = this->degCoeff[i]*other.degCoeff[j];
                    }
                }
            }
        }

        return p;
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

int main(){
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    first.print();
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    second.print();
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        // case 4 : // Copy constructor
        // {
        //     Polynomial third(first);
        //     if(third.degCoeff == first.degCoeff) {
        //         cout << "false" << endl;
        //     }
        //     else {
        //         cout << "true" << endl;
        //     }
        //     break;
        // }
            
        // case 5 : // Copy assignment operator
        // {
        //     Polynomial fourth(first);
        //     if(fourth.degCoeff == first.degCoeff) {
        //         cout << "false" << endl;
        //     }
        //     else {
        //         cout << "true" << endl;
        //     }
        //     break;
        // }
            
    }
    return 0;
}