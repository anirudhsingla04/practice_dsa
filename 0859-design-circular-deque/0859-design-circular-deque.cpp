class MyCircularDeque {
public:
    int *arr;
    int front;
    int rear;
    int size;
    MyCircularDeque(int k) {
        size=k;
        front=-1;
        rear=-1;
        arr=new int[size];
    }
    
    bool insertFront(int value) {
        if(isFull()){
            return false;
        }
        else if(front==-1){
            front=0;
            rear=0;
        }
        else if(front==0 && rear!=size-1){
            front=size-1;
        }
        else{
            front--;
        }
        arr[front]=value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()){
            return false;
        }
        else if(rear==-1){
            front=0;
            rear=0;
        }
        else if(front!=0 && rear==size-1){
            rear=0;
        }
        else{
            rear++;
        }
        arr[rear]=value;
        return true;
    }
    
    bool deleteFront() {
        
        if(isEmpty()){
            return false;
        }
        arr[front]=-1;
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(front==size-1){
            front=0;
        }
        else{
            front++;
        }
        return true;
    }
    
    bool deleteLast() {
        
        if(isEmpty()){
            return false;
        }
        arr[rear]=-1;
        if(front==rear){
            front=-1;
            rear=-1;
        }
        else if(rear==0){
            rear=size-1;
        }
        else{
            rear--;
        }
        return true;
    }
    
    int getFront() {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }
    
    int getRear() {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }
    
    bool isEmpty() {
        if(front==-1 && rear==-1){
            return true;
        }
        else{
            return false;
        }
    }
    
    bool isFull() {
        // Deque is full when the next position after rear is front.
        // This is only checked when not empty. If k=3, indices 0,1,2.
        // Empty: F=-1, R=-1
        // Full: F=0, R=2 or F=1, R=0 or F=2, R=1 -> (R + 1) % size == F
        return ((rear + 1) % size) == front;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */