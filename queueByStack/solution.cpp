#include <iostream>

using namespace std;

class CQueue {
    stack<int> head;
    stack<int> tail;
public:
    CQueue() {
        this->head = stack<int>();
        this->tail = stack<int>();
    }
    
    void appendTail(int value) {
        if(this->tail.empty() && !this->head.empty()) {
            while(!this->head.empty()){
                this->tail.push(this->head.top());
                this->head.pop();
            }
        }
        this->tail.push(value);
    }
    
    int deleteHead() {
        if(this->head.empty() && this->tail.empty()) {
            return -1;
        } else if (this->head.empty()) {
            while(!this->tail.empty()) {
                this->head.push(this->tail.top());
                this->tail.pop();
            }
        }
        int tmp = this->head.top();
        this->head.pop();
        return tmp;
    }
};