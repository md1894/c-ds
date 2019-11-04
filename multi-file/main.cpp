#include <iostream>
#include "div.h"
using namespace std;

int main(){
    int x;  cin >> x;
    int y;  cin >> y;
    
    int quotient = divison(x, y);
    cout << quotient;
    return 0;
}
