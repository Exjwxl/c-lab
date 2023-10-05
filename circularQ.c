#include <stdio.h>
int queue[10];
int front = -1;
int rear = -1;

void insert(int element) {
  if ((front == rear + 1) || (front == 0 && rear == 10- 1)) {
    printf("Queue is full!\n");
    return;
  }

  if (front == -1) {
    front = 0;
    rear = 0;
  } else if (rear == 10- 1) {
    rear = 0;
  } else {
    rear++;
  }

  queue[rear] = element;
}

int delete() {
  if (front == -1) {
    printf("Queue is empty!\n");
    return -1;
  }

  int element = queue[front];

  if (front == rear) {
    front = -1;
    rear = -1;
  } else if (front == 10- 1) {
    front = 0;
  } else {
    front++;
  }

  return element;
}

int isEmpty() {
  return front == -1;
}

int isFull() {
  return (front == rear + 1) || (front == 0 && rear == 10- 1);
}

void display() {
  if (front == -1) {
    printf("Queue is empty!\n");
    return;
  }

  int i = front;
  while (i != rear) {
    printf("%d ", queue[i]);
    i = (i + 1) % 10;
  }
  printf("%d\n", queue[rear]);
}

int main() {
  int choice, element;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Is Empty?\n");
    printf("4. Is Full?\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter the element to insert: ");
        scanf("%d", &element);
        insert(element);
        break;
      case 2:
        element = delete();
        if (element != -1) {
          printf("Deleted element: %d\n", element);
        }
        break;
      case 3:
        if (isEmpty()) {
          printf("Queue is empty!\n");
        } else {
          printf("Queue is not empty!\n");
        }
        break;
      case 4:
        if (isFull()) {
          printf("Queue is full!\n");
        } else {
          printf("Queue is not full!\n");
        }
        break;
      case 5:
        display();
        break;
      case 6:
        exit(0);
        break;
      default:
        printf("Invalid choice!\n");
    }
  }

  return 0;
}
