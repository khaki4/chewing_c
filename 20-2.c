// 문제4
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prevNode;
    struct Node* nextNode;
};

struct Node **CreateList(int data);
struct Node *InsertNode(struct Node* current, int data);
void DestroyNode(struct Node* destroy, struct Node* head);
void PrintNodeFrom(struct Node* from);
int CountNode(struct Node* from);
int SearchNode(struct Node* head, struct Node *search);

int main() {
    struct Node** List = CreateList(100);
    struct Node* Node1 = List[0];
    struct Node* Node2 = List[1];
    struct Node* Node3 = InsertNode(Node2, 300);
    struct Node* Node4 = InsertNode(Node3, 400);
    struct Node* Node5 = InsertNode(Node4, 500);
    int i;

    int cnt = 0;
    int seachData;

    PrintNodeFrom(Node1);

    DestroyNode(Node3, Node1);

    PrintNodeFrom(Node1);

    cnt = CountNode(Node1);
    printf("count: %d \n", cnt);

    seachData = SearchNode(Node1, Node4);
    printf("seachData: %d \n", seachData);

    DestroyNode(Node5, Node1);
    DestroyNode(Node4, Node1);

    for(i = 0; i < 2; i++)
    {
        free(List[i]);
    }
    free(List);

    return 0;
}

struct Node** CreateList(int data)
{
    struct Node *Head = (struct Node*)malloc(sizeof(struct Node));
    struct Node *Tail = (struct Node*)malloc(sizeof(struct Node));
    struct Node **list = (struct Node**)malloc(sizeof(struct Node*) * 2);

    Head->data = 100;
    Head->prevNode = Tail;
    Head->nextNode = Tail;
    Tail->data = 200;
    Tail->prevNode = Head;
    Tail->nextNode = Head;
    list[0] = Head;
    list[1] = Tail;

    return list;
}

struct Node *InsertNode(struct Node* current, int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->prevNode = current;
    newNode->nextNode = current->nextNode;

    current->nextNode = newNode;

    return newNode;
}

int SearchNode(struct Node* head, struct Node *search)
{
    struct Node* next = head;

    do {
        if (next == search)
        {
            return next->data;
        }
        next = next->nextNode;
    } while (next && next->nextNode != head);

    return 0;
}

void DestroyNode(struct Node* destroy, struct Node* head)
{
    struct Node* next = head;

    if (next == destroy)
    {
        free(destroy);
        return;
    }

    do {
        if (next->nextNode == destroy)
        {
            next->nextNode = destroy->nextNode;
            next = next->nextNode->prevNode;
        }
        next = next->nextNode;
    } while (next && next-> nextNode != head);

    free(destroy);
}

void PrintNodeFrom(struct Node* from)
{
    struct Node* head = from;
    do {
        printf("노드의 데이터 : %d \n", from->data);
        from = from->nextNode;
    } while (from && from->nextNode != head);

    printf("---------------------\n");
}

int CountNode(struct Node* from)
{
    int cnt = 1;
    struct Node* head = from;
    struct Node *next = from->nextNode;

    do {
        {
            ++cnt;
            next = next->nextNode;
        }
    } while (next && next->nextNode != head);


    return cnt;
}

