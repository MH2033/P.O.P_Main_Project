#define MAX 10000
int intArray[MAX];
int front = 0;
int rear = -1;
int itemCount = 0;
int peek() {
    return intArray[front];
}

int isEmpty() {
    return itemCount == 0;
}

int isFull() {
    return itemCount == MAX;
}

int size() {
    return itemCount;
}

void insert(int data) {

    if(!isFull()) {

        if(rear == MAX-1) {
            rear = -1;
        }

        intArray[++rear] = data;
        itemCount++;
    }
}

int removeData() {
    int data = intArray[front++];

    if (front == MAX) {
        front = 0;
    }

    itemCount--;
}
