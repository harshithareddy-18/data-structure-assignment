//1.REVERSE A STRING USING STACK
#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push function
void push(char c) {
    stack[++top] = c;
}

// Pop function
char pop() {
    return stack[top--];
}

int main() {
    char str[MAX];
    int i;

    printf("Enter a string: ");
    scanf("%s", str);

    // Push all characters to stack
    for(i = 0; i < strlen(str); i++) {
        push(str[i]);
    }

    printf("Reversed string: ");

    // Pop characters from stack
    while(top != -1) {
        printf("%c", pop());
    }

    return 0;
}


//2.BALANCED PARENTHNESS

#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    stack[++top] = c;
}

void pop() {
    top--;
}

int main() {
    char exp[MAX];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(i = 0; i < strlen(exp); i++) {

        if(exp[i] == '(') {
            push(exp[i]);
        }

        else if(exp[i] == ')') {
            if(top == -1) {
                printf("Not Balanced Expression");
                return 0;
            }
            pop();
        }
    }

    if(top == -1)
        printf("Balanced Expression");
    else
        printf("Not Balanced Expression");

    return 0;
}

//3.NEXT GREATER ELEMENT
#include <stdio.h>

int main() {
    int arr[100], n, i, j;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for(i = 0; i < n; i++) {
        int next = -1;

        for(j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                next = arr[j];
                break;
            }
        }

        printf("%d -> %d\n", arr[i], next);
    }

    return 0;
}





//4.PRINTER QUEUE SIMULATION
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int doc) {
    if(rear == MAX-1) {
        printf("Queue Full\n");
        return;
    }

    if(front == -1)
        front = 0;

    queue[++rear] = doc;
}

void dequeue() {
    if(front == -1 || front > rear) {
        printf("No documents to print\n");
        return;
    }

    printf("Printing document: %d\n", queue[front]);
    front++;
}

void display() {
    int i;

    if(front == -1 || front > rear) {
        printf("Queue Empty\n");
        return;
    }

    printf("Pending documents:\n");
    for(i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {

    int choice, doc;

    while(1) {

        printf("\n1.Add Document\n2.Print Document\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter document ID: ");
                scanf("%d", &doc);
                enqueue(doc);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}


//5.CIRCULAR QUEUE
#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {

    if((rear + 1) % MAX == front) {
        printf("Queue Full\n");
        return;
    }

    if(front == -1)
        front = 0;

    rear = (rear + 1) % MAX;
    queue[rear] = value;
}

void dequeue() {

    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Removed element: %d\n", queue[front]);

    if(front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX;
}

void peek() {
    if(front == -1)
        printf("Queue Empty\n");
    else
        printf("Front element: %d\n", queue[front]);
}

void display() {

    int i;

    if(front == -1) {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue elements: ");

    for(i = front; i != rear; i = (i + 1) % MAX) {
        printf("%d ", queue[i]);
    }

    printf("%d\n", queue[rear]);
}

int main() {

    int choice, value;

    while(1) {

        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice");
        }
    }
}