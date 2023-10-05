#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push() {
  if (top == MAX_SIZE - 1) {
    printf("Stack overflow!\n");
    return;
  }

  int element;
  printf("Enter the element to push: ");
  scanf("%d", &element);

  top++;
  stack[top] = element;
}

void pop() {
  if (top == -1) {
    printf("Stack underflow!\n");
    return;
  }

  int element = stack[top];
  top--;

  printf("Popped element: %d\n", element);
}

void display() {
  if (top == -1) {
    printf("Stack is empty!\n");
    return;
  }

  printf("Stack: ");
  for (int i = top; i >= 0; i--) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int main() {
  int choice;

  while (1) {
    printf("\nMenu:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        push();
        break;
      case 2:
        pop();
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
