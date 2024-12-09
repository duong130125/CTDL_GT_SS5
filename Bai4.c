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

// Hàm đếm số lượng phần tử trong danh sách
int countElements(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
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
        printf("Số lượng phần tử: 0\n");
        return 0;
    }

    printf("Nhập các phần tử của danh sách: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &data);
        append(&head, data);
    }

    // Đếm và in số lượng phần tử
    int count = countElements(head);
    printf("Số lượng phần tử trong danh sách: %d\n", count);

    return 0;
}
