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

// Hàm thay thế giá trị
void replaceValue(Node *head, int oldValue, int newValue)
{
    Node *temp = head;
    int found = 0;

    // Duyệt danh sách để tìm phần tử có giá trị cần thay thế
    while (temp != NULL)
    {
        if (temp->data == oldValue)
        {
            temp->data = newValue; // Thay thế giá trị
            found = 1;
        }
        temp = temp->next;
    }

    // Kiểm tra xem có tìm thấy giá trị không
    if (!found)
    {
        printf("Không tìm thấy phần tử cần thay thế\n");
    }
}

// Hàm chính
int main()
{
    Node *head = NULL;

    // Nhập dữ liệu từ bàn phím
    int n, data, oldValue, newValue;
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

    // Nhập giá trị cần thay thế và giá trị mới
    printf("Nhập giá trị cần thay thế: ");
    scanf("%d", &oldValue);
    printf("Nhập giá trị mới: ");
    scanf("%d", &newValue);

    // Thay thế giá trị trong danh sách
    replaceValue(head, oldValue, newValue);

    // In danh sách sau khi thay thế
    printf("Danh sách sau khi thay thế: ");
    printList(head);

    return 0;
}
