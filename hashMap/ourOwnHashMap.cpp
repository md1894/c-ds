/*
in our hash function we have used one very important property of mod operator
because the number is likely to cross the limits of an integer value , so we have to compress it

(X*Y*Z) % A == [(X % A)*(Y % A)*(Z % A)] % A

*/
#include<string>
#include<iostream>
using namespace std;

template<typename V>
class mapNode{
    public:
    V value;
    string key;
    mapNode* next;

    mapNode(string key, V value){
        this->key = key;
        this->value = value;
        this->next = NULL;
    }

    ~mapNode(){
        delete this->next;
    }
};

template<typename V>
class ourMap{
    int count;
    mapNode<V>** buckets;
    int num_of_buckets;

    /*
    this is the hash function , it is doing hashing and compressing the hashcode
    we used the modulus operator property , also we are generating a number which has a base
    37 a famous prime number , so that we can get better distribution of our values inside the 
    buckets (which will hold the key value pairs)
    */
    int getBucketIndex(string key){
        int currentCoeff = 1;
        int hashCode = 0;
        for(int i = key.length() - 1; i >= 0 ; i--){
            hashCode += key[i]*currentCoeff;
            hashCode = hashCode % this->num_of_buckets;
            currentCoeff = currentCoeff*37;
            currentCoeff = currentCoeff % this->num_of_buckets;
        }
        return hashCode % this->num_of_buckets;
    }

    void rehash(){
        int oldNumberOfBuckets = this->num_of_buckets;
        mapNode<V>** oldBuckets = this->buckets;
        this->num_of_buckets = this->num_of_buckets*2;
        this->count = 0;
        this->buckets = new mapNode<V>*[this->num_of_buckets];
        for(int i = 0; i < this->num_of_buckets; i++){
            this->buckets[i] = NULL;
        }
        for(int i = 0; i < oldNumberOfBuckets; i++){
            mapNode<V>* head = oldBuckets[i];
            while(head != NULL){
                insert(head->key, head->value);
                head = head->next;
            }
        }
        for(int i = 0; i < oldNumberOfBuckets; i++){
            delete oldBuckets[i];
        }
        delete [] oldBuckets;
        cout<<"---"<<endl;
    }

    public:
        ourMap(){
            this->num_of_buckets = 5;
            this->buckets = new mapNode<V>*[num_of_buckets];
            this->count = 0;
            for(int i = 0; i < this->num_of_buckets; i++){
                this->buckets[i] = NULL;
            }
        }

        int size(){
            return this->count;
        }

        double getLoadFactor(){
            return (1.0*this->count)/this->num_of_buckets;
        }

        ~ourMap(){
            for(int i = 0; i < this->num_of_buckets; i++){
                delete buckets[i];
            }
            delete [] buckets;
        }

        void insert(string key, V value){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = this->buckets[bucketIndex];
            while (head != NULL)
            {
                if(head->key == key){
                    head->value = value;
                    return;
                }
                head = head->next;
            }
            mapNode<V>* nwNode = new mapNode<V>(key,value);
            head = this->buckets[bucketIndex];
            nwNode->next = head;
            this->buckets[bucketIndex] = nwNode;
            this->count++;
            double loadFactor = (1.0*this->count)/this->num_of_buckets;
            if(loadFactor > 0.7){
                rehash();
            }
        }

        V getValue(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = this->buckets[bucketIndex];
            while (head != NULL)
            {
                if(head->key == key){
                    return head->value;
                }
                head = head->next;
            }
            return 0;
        }

        V remove(string key){
            int bucketIndex = getBucketIndex(key);
            mapNode<V>* head = this->buckets[bucketIndex];
            mapNode<V>* prev = NULL;
            while (head != NULL)
            {
                if(head->key == key){
                    if(prev == NULL){
                        this->buckets[bucketIndex] = head->next;
                    }else{
                        prev->next = head->next;
                    }
                    V value = head->value;
                    head->next = NULL;
                    delete head;
                    this->count--;
                    return value;
                }
                prev = head;
                head = head->next;
            }
            return 0;
        }
};


int main(){
    ourMap<int> mp;
    string key = "abc";
    cout<<mp.size()<<endl;
    for(int i = 0; i < 10; i++){
        char c = '0' + i;
        string k = key + c;
        mp.insert(k,i); 
        cout<<mp.getLoadFactor()<<endl; 
    }
    cout<<mp.size()<<endl;
    cout<<mp.getValue("abc5")<<endl;
    for(int i = 0; i < 10; i++){
        char c = '0' + i;
        string k = key + c;
        cout<<k<<":"<<"value:"<<mp.getValue(k)<<endl;
    }
    return 0;
}