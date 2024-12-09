#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút
typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

// Hàm tạo nút mới
Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Hàm thêm phần tử vào cuối danh sách
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

// Hàm in danh sách
void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Danh sách rỗng\n");
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
        {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Hàm đảo ngược danh sách
void reverseList(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng, không thể đảo ngược\n");
        return;
    }

    Node *current = *head;
    Node *temp = NULL;

    // Đổi hướng các liên kết
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev; // Chuyển sang nút tiếp theo (trong hướng mới)
    }

    // Cập nhật nút đầu tiên
    if (temp != NULL)
    {
        *head = temp->prev;
    }
}

// Hàm chính
int main()
{
    Node *head = NULL;

    // Nhập dữ liệu từ bàn phím
    int n, data;
    printf("Nhập số lượng phần tử trong danh sách: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Danh sách rỗng\n");
        return 0;
    }

    printf("Nhập các phần tử của danh sách: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        append(&head, data);
    }

    printf("Danh sách ban đầu: ");
    printList(head);

    // Đảo ngược danh sách
    reverseList(&head);

    printf("Danh sách sau khi đảo ngược: ");
    printList(head);

    return 0;
}