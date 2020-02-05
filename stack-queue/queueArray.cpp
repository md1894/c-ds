#include<iostream>
#include<climits>
using namespace std;

class queue{
	int* data;
	int size;
	int nextIndex;
	int frontIndex;
	int capacity;

	public:
	queue(){
		this->data = new int[5];
		this->size = 0;
		this->nextIndex = 0;
		this->frontIndex = -1;
		this->capacity = 5;
	}

	int getSize(){
		return this->size;
	}

	bool isEmpty(){
		return this->size == 0;
	}

	void enqueue(int num){
		if(this->size == this->capacity){
			cout<<"Queue Is Full\r\n";
			return;
		}
		if(this->frontIndex == -1){
			this->frontIndex++;
		}
		this->data[nextIndex] = num;
		this->nextIndex = (this->nextIndex + 1) % this->capacity;
		this->size++;
	}

	int front(){
		if(this->size == 0){
			return INT_MIN;
		}else{
			return this->data[this->frontIndex];
		}
	}

	int dequeue(){
		if(this->size == 0){
			cout<<"Queue is Empty"<<endl;
			return INT_MIN;
		}else{
			int ans = this->data[this->frontIndex];
			this->frontIndex = (this->frontIndex + 1) % this->capacity;
			this->size--;
		}
	}
	
	void print(){
		cout<<"Queue is ";
		int n = this->frontIndex;
		for(int i = 0; i < size; i++){
			cout<<this->data[n]<<" ";
			n = (n + 1) % this->capacity;
		}
		cout<<endl;
	}
};

int main(){
	queue q;
	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	/*q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();*/
	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);
	q.print();
	return 0;
}














