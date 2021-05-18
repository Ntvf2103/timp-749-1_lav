#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct list
{
    struct list *next;
    double Data;
}list;
typedef struct node
{
    struct node *next;
}node;
// инициализация пустого списка
void Init(struct list **l)
{
    *l = (struct list *)malloc(sizeof(struct list));//выделение памяти
    (*l)->next = NULL;//присвоение NULL ссылке элементу
    (*l)->Data = 2147483648;
}
// удалить все элементы из списка
void Clean(struct list *l)
{
    struct list *T = l;
    do
    {
        T = T->next;
        free(l);//отчистка ячейки
        l = T;
    } while (l != NULL);
}
// проверка на пустоту списка
bool Is_empty(struct list *l)
{
    if (l == NULL)
        return 0;
    else
        return 1;
}
// поиск элемента по значению. вернуть NULL если элемент не найден
struct node *find(struct list *l, int value)
{
    struct list *T = l;
    while (1)
    {
        if (T == NULL)
            return NULL;
        else
        {
            if ((T->Data) == value)
                return ((struct node *)l);
        }
        T = T->next;
    }
}
// вставка значения в конец списка, вернуть 0 если успешно
int Push_back(struct list *l, int value)
{
    if (l->Data == 2147483648)
    {
        l->Data = value;
        return 0;
    }
    struct list *T = (struct list *)malloc(sizeof(struct list));
    T = l;
    while (T->next != NULL)
        T = T->next;
    T->next = (struct list *)malloc(sizeof(struct list));
    T = T->next;
    T->Data = value;
    T->next = NULL;
    return 0;
}
// вставка значения в начало списка, вернуть 0 если успешно
int Push_front(struct list **l, int value)
{
    struct list *T = (struct list *)malloc(sizeof(struct list));
    T->Data = value;
    T->next = (*l);
    (*l) = T;
    return 0;
}
// вставка значения после указанного узла, вернуть 0 если успешно
int Insert_after(struct node *l, int value)
{
    struct list *T = (struct list *)malloc(sizeof(struct list)), *Temp;
    Temp=(struct list *)l->next;
    l->next =(struct node *)T;
    T->Data = value;
    T->next = Temp;
    return 0;
}
// удалить первый элемент из списка с указанным значением,
// вернуть 0 если успешно
int Remove_node(struct list *l, int value)
{
    struct list *T = l;
    if (l != NULL)
    {
        while (1)
        {
            if ((T->next) == NULL)
                return 1;
            if ((T->next->Data) == value)
            {
                struct list *Temp = (struct list *)malloc(sizeof(struct list));
                Temp = T->next->next;
                free(T->next);
                T->next = Temp;
                return 0;
            }
            T = T->next;
        }
    }
    else
        return 1;
}
// вывод списка
void Print(struct list *l)
{
    while (l != NULL)
    {
        printf("%.0lf ", l->Data);
        l = l->next;
    }
    printf("\n");
}
int main()
{
    struct list *l, *T;
    int N, i;
    double a, b;
    scanf("%d", &N);              //1
    Init(&l);                     //2
    for (i = 0; i < N; i++)
    {
        scanf("%lf", &a);
        Push_back(l, a);
    }
    Print(l);                     //3
    for (i = 0; i < 3; i++)       //4
    {
        scanf("%lf", &a);
        if (find(l, a) == NULL)
            printf("0");
        else
            printf("1");
        if (i!=2)
            printf(" ");
        else
            printf("\n");
    }
    scanf("%lf", &a);            //5
    Push_back(l, a);
    Print(l);//6
    scanf("%lf", &a);            //7
    Push_front(&l, a);
    Print(l);                    //8
    scanf("%lf", &a);            //9
    scanf("%lf", &b);
    struct node *el=(struct node *)l;
    while (a != 1)
    {
        el = el->next;
        a--;
    }
    Insert_after(el, b);
    Print(l);                   //10
    scanf("%lf", &a);           //11
    if (l->Data==a)
    {
        T=l->next;
        free(l);
        l=T;
    }
    else
        Remove_node(l, a);
    Print(l);                  //12
    Clean(l);                  //13
    return 1;
}




