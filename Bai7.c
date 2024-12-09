#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc một nút
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
        printf("Danh sách không còn phần tử nào\n");
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

// Hàm xóa một nút
void deleteNode(Node **head, Node *nodeToDelete)
{
    if (*head == NULL || nodeToDelete == NULL)
    {
        return;
    }

    if (*head == nodeToDelete)
    {
        *head = nodeToDelete->next;
    }

    if (nodeToDelete->next != NULL)
    {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    if (nodeToDelete->prev != NULL)
    {
        nodeToDelete->prev->next = nodeToDelete->next;
    }

    free(nodeToDelete);
}

// Hàm xóa tất cả các phần tử có giá trị là số chẵn
void removeEven(Node **head)
{
    Node *temp = *head;
    while (temp != NULL)
    {
        Node *next = temp->next;
        if (temp->data % 2 == 0)
        {
            deleteNode(head, temp);
        }
        temp = next;
    }
}

// Hàm sắp xếp danh sách liên kết đôi theo thứ tự tăng dần
void sortList(Node **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }

    Node *i = *head;
    while (i != NULL)
    {
        Node *j = i->next;
        while (j != NULL)
        {
            if (i->data > j->data)
            {
                int temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
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
        printf("Danh sách không còn phần tử nào\n");
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

    // Xóa các phần tử số chẵn
    removeEven(&head);

    // Sắp xếp danh sách còn lại
    sortList(&head);

    // In danh sách sau khi thực hiện thao tác
    printf("Danh sách sau khi xóa và sắp xếp: ");
    printList(head);

    return 0;
}
