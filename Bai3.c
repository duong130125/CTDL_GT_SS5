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

// Hàm xóa phần tử cuối cùng
void deleteLast(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sách rỗng\n");
        return;
    }

    Node *temp = *head;

    // Nếu danh sách chỉ có một phần tử
    if (temp->next == NULL)
    {
        free(temp);
        *head = NULL;
        return;
    }

    // Duyệt đến phần tử cuối
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Xóa phần tử cuối
    temp->prev->next = NULL;
    free(temp);
}

// Hàm in danh sách liên kết
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
    printf(" <-> NULL\n");
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

    // Xóa phần tử cuối
    deleteLast(&head);

    printf("Danh sách sau khi xóa phần tử cuối: ");
    printList(head);

    return 0;
}
