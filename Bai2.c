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

// Hàm in danh sách liên kết
void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf(" <-> ");
        temp = temp->next;
    }
    printf(" <-> NULL\n");
}

// Hàm chèn phần tử vào vị trí bất kỳ
void insertAtPosition(Node **head, int value, int position)
{
    Node *newNode = createNode(value);

    // Nếu danh sách rỗng
    if (*head == NULL)
    {
        if (position == 0)
        {
            *head = newNode;
        }
        else
        {
            printf("Lỗi vị trí không hợp lệ\n");
            free(newNode);
        }
        return;
    }

    // Nếu vị trí là đầu danh sách
    if (position == 0)
    {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    // Tìm vị trí chèn
    Node *temp = *head;
    int count = 0;
    while (temp != NULL && count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    // Nếu vị trí vượt quá độ dài danh sách
    if (temp == NULL || (temp->next == NULL && count < position - 1))
    {
        printf("Lỗi vị trí không hợp lệ\n");
        free(newNode);
        return;
    }

    // Chèn nút mới vào vị trí
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

int main()
{
    Node *head = NULL;
    int n, value, position;

    // Nhập danh sách ban đầu
    printf("Nhập số lượng phần tử trong danh sách ban đầu: ");
    scanf("%d", &n);

    printf("Nhập các phần tử của danh sách: ");
    for (int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        insertAtPosition(&head, data, i); // Thêm vào cuối danh sách
    }

    printf("Danh sách ban đầu: ");
    printList(head);

    // Nhập phần tử mới cần chèn
    printf("Nhập giá trị cần chèn: ");
    scanf("%d", &value);
    printf("Nhập vị trí cần chèn: ");
    scanf("%d", &position);

    // Chèn phần tử mới vào danh sách
    insertAtPosition(&head, value, position);

    // In danh sách sau khi chèn
    printf("Danh sách sau khi chèn: ");
    printList(head);

    return 0;
}
