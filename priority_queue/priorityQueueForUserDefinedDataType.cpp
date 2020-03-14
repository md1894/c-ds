#include <iostream>
#include <queue>
#include <string>
using namespace std;

class user{
  public:
  string name;
  int age;

  user(string nm, int age){
    this->name = nm;
    this->age = age;
  }
};

class compare_fn{
public:
  /*
  swap the sequence of arguments to change the sorting order
  currently it will give ascending order of age
  */
  bool operator()(user &u1, user &u2){
    return u1.age > u2.age;
  }
};

int main(){
    priority_queue<user, vector<user>, compare_fn> pq;
    user u1("mehul", 25);
    user u2("nakul", 23);
    user u3("meena", 50);
    user u4("nkd", 57);

    pq.push(u1);
    pq.push(u2);
    pq.push(u3);
    pq.push(u4);
    while(!pq.empty()){
        user u = pq.top();
        cout<<u.name<<" "<<u.age<<" "<<endl;
        pq.pop();
    }
    return 0;
}
