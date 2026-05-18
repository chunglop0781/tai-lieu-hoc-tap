#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};
// Con tro DAU va CUOI cua Queue
struct Node *front = NULL;
struct Node *rear = NULL;
//////////
void enqueue(int data_val) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Cap phat bo nho that bai!\n");
        return;
    }
    newNode->data = data_val;
    newNode->next = NULL;
    if (front == NULL) {
        front = newNode;
        rear = newNode;
    }
    else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("Enqueued %d vao Queue.\n", data_val);
}
//////////
int isQueueEmpty() {
    return front == NULL;
}
//////////
int dequeue() {
    if (isQueueEmpty()) {
        printf("Loi: Queue rong.\n");
        exit(EXIT_FAILURE);
    }
    struct Node *temp = front;
    int dequeued_data = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    temp = NULL;
    return dequeued_data;
}
//////////
void printTaskName(int taskID) {

    if (taskID == 1) {
        printf("Dang in: document_A\n");
    }
    else if (taskID == 2) {
        printf("Dang in: image_B\n");
    }
    else if (taskID == 3) {
        printf("Dang in: report_C\n");
    }
}
//////////
int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    printf("\nBat dau qua trinh in:\n");
    while (!isQueueEmpty()) {
        int task = dequeue();
        printTaskName(task);
    }

    return 0;
}