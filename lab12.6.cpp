#include <iostream>
#include <fstream>

using namespace std;

struct Queue {
    int data;
    Queue* next;
};

void printQueue(Queue* front, Queue* rear) {
    Queue* temp = front;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

bool isEmpty(Queue* front) {
    return front == NULL;
}

Queue* copyQueue(Queue* front) {
    if (front == NULL) {
        return NULL;
    }
    Queue* rear = new Queue();
    Queue* newFront = new Queue();
    newFront->data = front->data;
    newFront->next = rear;
    while (front->next != NULL) {
        rear->data = front->next->data;
        if (front->next->next != NULL) {
            rear->next = new Queue();
            rear = rear->next;
        }
        front = front->next;
    }
    rear->next = NULL;
    return newFront;
}

int queueLength(Queue* front) {
    int length = 0;
    while (front != NULL) {
        length++;
        front = front->next;
    }
    return length;
}

int main() {
    Queue* front = NULL;
    Queue* rear = NULL;

    ifstream inputFile("input.txt");
    int num;

    while (inputFile >> num) {
        if (rear == NULL) {
            front = new Queue();
            front->data = num;
            front->next = NULL;
            rear = front;
        }
        else {
            rear->next = new Queue();
            rear = rear->next;
            rear->data = num;
            rear->next = NULL;
        }
    }

    inputFile.close();

    cout << "Input queue: ";
    printQueue(front, rear);

    cout << "Queue is empty: " << (isEmpty(front) ? "true" : "false") << endl;

    Queue* newQueue = copyQueue(front);

    cout << "Copied queue: ";
    printQueue(newQueue, rear);

    cout << "Queue length: " << queueLength(front) << endl;

    return 0;
}
