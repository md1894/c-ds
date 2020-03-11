/*
Split Array
Send Feedback
Given an integer array A of size N, check if the input array can be splitted in two parts such that -
- Sum of both parts is equal
- All elements in the input, which are divisible by 5 should be in same group.
- All elements in the input, which are divisible by 3 (but not divisible by 5) should be in other group.
- Elements which are neither divisible by 5 nor by 3, can be put in any group.
Groups can be made with any set of elements, i.e. elements need not to be continuous. And you need to consider each and every element of input array in some group.
Return true, if array can be split according to the above rules, else return false.
Note : You will get marks only if all the test cases are passed.
Input Format :
Line 1 : Integer N (size of array)
Line 2 : Array A elements (separated by space)
Output Format :
true or false
Constraints :
1 <= N <= 50
Sample Input 1 :
2
1 2
Sample Output 1 :
false
Sample Input 2 :
3
1 4 3
Sample Output 2 :
true
*/
#include <iostream>
#include <vector>
using namespace std;

class group{
public:
    vector<int> p1;
    int p1_sum;
    vector<int> p2;
    int p2_sum;
    
    group(){
        this->p1_sum = 0;
        this->p2_sum = 0;
    }
};

void push_el(group* g, int el, char type){
    switch(type){
        case '1':
            g->p1.push_back(el);
            g->p1_sum += el;
            break;
        case '2':
            g->p2.push_back(el);
            g->p2_sum += el;
            break;
    }
}

group splitArray1(int *input, int size){
    bool isP1 = false, isP2 = false;
    group g;
    if(*input % 3 == 0 && *input % 5 != 0){
        isP2 = true;
        push_el(&g,*input,'2');
    }else if(*input % 5 == 0){
        isP1 = true;
        push_el(&g,*input,'1');
    }
    if(size == 1){
        if(!isP1 && !isP2){
            push_el(&g,*input,'1');
        }
        return g;
    }else{
        g = splitArray1(input + 1, size - 1);
        if(isP1){
            push_el(&g,*input,'1');
        }else if(isP2){
            push_el(&g,*input,'2');
        }else if(!isP1 && !isP2){
            if(g.p1_sum >= g.p2_sum){
                push_el(&g,*input,'2');
            }else{
                push_el(&g,*input,'1');
            }
        }
        return g;
    }
}

bool splitArray(int *input, int size) {
    group g = splitArray1(input, size);
    return (g.p1_sum == g.p2_sum);
}

int main() {

	int size;
	cin>>size;
	int *input=new int[1+size];

	for(int i=0;i<size;i++)
		cin>>input[i];

    if(splitArray(input, size)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }


	return 0;

}
