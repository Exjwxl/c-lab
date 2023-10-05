#include <stdio.h>
#include<stdlib.h>


int queue[100];
int front = -1;
int rear = -1;

void enqueue() {
  if (rear == 100 - 1) {
    printf("Queue overflow!\n");
    return;
  }

  int element;
  printf("Enter the element to enqueue: ");
  scanf("%d", &element);

  rear++;
  queue[rear] = element;
}

void dequeue() {
  if (front == rear) {
    printf("Queue underflow!\n");
    return;
  }

  front++;
  int element = queue[front];

  printf("Dequeued element: %d\n", element);
}

void display() {
  if (front == rear) {
    printf("Queue is empty!\n");
    return;
  }

  printf("Queue: ");
  for (int i = front + 1; i <= rear; i++) {
    printf("%d ", queue[i]);
  }
  printf("\n");
}

int main() {
  int choice;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        enqueue();
        break;
      case 2:
        dequeue();
        break;
      case 3:
        display();
        break;
      case 4:
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}
