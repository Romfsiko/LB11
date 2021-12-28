#include "Header.h"
#include <conio.h>
#include<iostream>

template <typename T>
Queue<T>::Queue() {}

template <typename T>
Queue<T>::Queue(T a)
{
	next = new Node<T>;
	next->prev = nullptr;
	next->next = nullptr;
	next->a = a;
}

template <typename T>
Queue<T>& Queue<T>::operator=(Queue&& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete next;
	next = other.next;
	other.next = nullptr;
}

template <typename T>
int Queue<T>::GetSize() const
{
	if (!HasElements()) { return 0; }
	int i = 0;
	Node<T>* a = next;
	while (a != nullptr)
	{
		a = a->next;
		++i;
	}
	return i;
}

template <typename T>
void Queue<T>::Push(const T a)
{
	Node<T>* newnode = new Node<T>;
	Node<T>* checking = next;
	if (HasElements())
	{
		while (checking->next != nullptr)
		{
			checking = checking->next;
		}
		checking->next = newnode;
	}
	else
	{
		next = newnode;
	}
	newnode->a = a;
	newnode->prev = checking;
	newnode->next = nullptr;
}

template <typename T>
void Queue<T>::Pop(T& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	Node<T>* tempnode = next->next;
	if (next->next != nullptr)
	{
		next->next->prev = nullptr;
	}
	a = next->a;
	delete next;
	next = tempnode;
}

template <typename T>
void Queue<T>::Peek(T& a)
{
	if (!HasElements()) { throw NoElementsException("Deck is Empty!"); };
	a = next->a;
}

template <typename T>
bool Queue<T>::HasElements() const
{
	if (this->next != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void menu()
{
	cout << "1. Добавить элемент в очередь\n";
	cout << "2. Получить элемент из очереди\n";
	cout << "3. Посмотреть элемент из очереди\n";
	cout << "4. Длина очереди\n";
	cout << "5. Выход\n";
};

int main()
{
	setlocale(LC_ALL, "RUS");
	Queue<int> a;
	int b;
	bool flag = true;
	while (flag)
	{
		menu();
		switch (_getch())
		{
		case '1':
			cout << "Добавить элемент: ";
			cin >> b;
			a.Push(b);
			break;
		case '2':
			try
			{
				a.Pop(b);
				cout << "Полученный элемент " << b << endl;
			}
			catch (NoElementsException ex)
			{
				cout << "Очередь пуста\n";
			}
			break;
		case '3':
			try
			{
				a.Peek(b);
				cout << "Последний элемент " << b << endl;
			}
			catch (NoElementsException ex)
			{
				cout << "Очередь пуста\n";
			}
			break;
		case '4':
			b = a.GetSize();
			cout << "Длина очереди: " << b << endl;
			break;
		case '5':
			flag = false;
			break;

		}
	}

}
