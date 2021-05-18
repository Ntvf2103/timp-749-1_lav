#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct node {
	int value;          // значение, которое хранит узел 
	struct node *next;  // ссылка на следующий элемент списка
} node;

typedef struct list {
	struct node *head;  // начало списка
} list;


// инициализация пустого списка
void init(list *l);

// удалить все элементы из списка
void clean(list *l);

// проверка на пустоту списка
bool is_empty(list *l);

// поиск элемента по значению. вернуть NULL если эжемент не найден
node *find(list *l, int value);

// вставка значения в конец списка, вернуть 0 если успешно
int push_back(list *l, int value);

// вставка значения в начало списка, вернуть 0 если успешно
int push_front(list *l, int value);

// вставка значения после указанного узла, вернуть 0 если успешно
int insert_after(node *n, int value);

// удалить первый элемент из списка с указанным значением, 
// вернуть 0 если успешно
int remove_node(list *l, int value);

// вывести все значения из списка в прямом порядке через пробел,
// после окончания вывода перейти на новую строку
void print(list *l);


int main() {
	// Место для вашего кода
	return 0;
};
