#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong danh sách liên kết đôi
typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

// Hàm tạo một nút mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Hàm thêm một nút vào cuối danh sách
void append(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

// Hàm duyệt danh sách từ cuối về đầu và in ra giá trị
void printReverse(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách rỗng\n");
        return;
    }

    // Tìm phần tử cuối cùng
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    // Duyệt từ cuối về đầu
    while (tail != NULL)
    {
        printf("%d <-> ", tail->data);
        tail = tail->prev;
    }
    printf("NULL\n");
}

// Hàm in danh sách từ đầu đến cuối (để kiểm tra)
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    Node *head = NULL;

    // Test Case 1
    append(&head, 1);
    append(&head, 3);
    append(&head, 5);
    append(&head, 7);

    printf("Danh sách ban đầu:\n");
    printList(head);

    printf("Danh sách ngược:\n");
    printReverse(head);

    // Test Case 2
    head = NULL; // Xóa danh sách cũ
    append(&head, 10);
    append(&head, 20);

    printf("Danh sách ban đầu:\n");
    printList(head);

    printf("Danh sách ngược:\n");
    printReverse(head);

    return 0;
}
