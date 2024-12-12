#pragma once
#include<iostream>

template <class T>
class TQueue
{
	T* pMem;
	int size;
	int finish, start;
	int count;

public:
	TQueue();
	TQueue(int _size);                       //Конструктор по умолчанию
	~TQueue();                               //Деструктор
	TQueue(const TQueue& object);            //Конструктор копирования
	bool empty();                            //Проверка на пустоту
	bool full();                             //Проверка на полноту

	void Push(const T& element);             //Вставка в конец очереди
	T Pop();                                 //Возвращаем из начала очереди
	T front();                               //Возращает значение, которое лежит в начале очереди
	T back();                                //Возращает значение, которое лежит в начале очереди

	void operator = (const TQueue& object);  //Оператор присваивания
	bool operator ==(const TQueue& object);  //Оператор сравненияя
	bool operator !=(const TQueue& object);  //Оператор сравнения

	int GetHeadIndex();                      //Получить индекс, на котором стоит первый элемент в очереди
	int GetCurrentSize();                    //Получить текущий размер
	int GetMaxSize();                        //Получить размер хранилища
	int NumberOfElements();                  //Количество элементов в очереди

	void output();                           //Вывод
};

template <class T>
TQueue<T>::TQueue() :size(10) {}

// Конструктор с параметром для задания размера очереди
template<class T>
TQueue<T>::TQueue(int _size)
{
	if (_size < 1)
		throw std::exception();

	size = _size;
	pMem = new T[size];
	start = 0;
	finish = -1;
	count = 0;
}

// Деструктор освобождает выделенную память
template<class T>
TQueue<T>::~TQueue()
{
	delete[] pMem;
}

// Конструктор копирования для создания копии очереди
template<class T>
TQueue<T>::TQueue(const TQueue& object)
{
	delete[] pMem;
	size = object.size;
	pMem = new T[size];
	std::copy(object.pMem, object.pMem + size, pMem);
	start = object.start;
	finish = object.finish;
	count = object.count;
}

// Метод проверки, пуста ли очередь
template<class T>
bool TQueue<T>::empty()
{
	return count == 0;
}

// Метод проверки, полна ли очередь
template<class T>
bool TQueue<T>::full()
{
	return count == size;
}

// Добавление элемента в очередь
template<class T>
void TQueue<T>::Push(const T& element)
{
	if (full())
	{
		throw std::exception("Очедерь переполнена!", -2);
	}
	finish++;
	finish = finish % size;
	pMem[finish] = element;
	count++;
}

// Извлечение элемента из очереди
template<class T>
T TQueue<T>::Pop()
{
	if (empty())
		throw std::exception("Очередь пуста!", -1);

	T element = pMem[start];
	start++;
	start = start % size;
	count--;

	return element;
}

// Метод получения элемента из начала очереди без удаления
template<class T>
T TQueue<T>::front()
{
	if (this->empty())
		throw std::exception("Очередь пуста!", -1);

	return pMem[start];
}

// Метод получения последнего элемента в очереди без удаления
template<class T>
T TQueue<T>::back()
{
	if (this->empty())
		throw std::exception("Очередь пуста!", -1);

	return pMem[finish];
}

// Перегрузка оператора присваивания
template<class T>
void TQueue<T>::operator=(const TQueue& object)
{
	start = object.start;
	finish = object.finish;
	count = object.count;
	if (count == object.count)
	{
		std::copy(object.pMem, object.pMem + size, pMem);
	}
	else
	{
		delete[] pMem;
		size = object.size;
		pMem = new T[size];
		std::copy(object.pMem, object.pMem + size, pMem);
	}
}

// Перегрузка оператора сравнения на равенство
template<class T>
bool TQueue<T>::operator==(const TQueue& object)
{
	if (count != object.count)
	{
		return false;
	}
	else
	{
		TQueue this_tmp = *this;
		TQueue obj_tmp = object;
		while (!this_tmp.empty())
		{
			if (this_tmp.front() != obj_tmp.front())
			{
				return false;
			}
			this_tmp.Pop();
			obj_tmp.Pop();
		}
	}

	return true;
}

// Перегрузка оператора сравнения на неравенство
template<class T>
bool TQueue<T>::operator!=(const TQueue& object)
{
	return !(*this == object);
}

// Метод получения индекса начала очереди.
template<class T>
int TQueue<T>::GetHeadIndex()
{
	return start;
}

// Метод получения текущего количества элементов в очереди
template<class T>
int TQueue<T>::GetCurrentSize()
{
	return count;
}

// Метод получения максимального размера очереди.
template<class T>
int TQueue<T>::GetMaxSize()
{
	return size;
}

// Альтернативный метод для получения текущего количества элементов
template<class T>
int TQueue<T>::NumberOfElements()
{
	return count;
}

// Метод вывода содержимого очереди на консоль.
template<class T>
void TQueue<T>::output()
{
	if (this->empty())
		throw std::exception("Очередь пуста!", -1);

	TQueue<T> this_tmp(*this);
	std::cout << "(";
	while (!(this_tmp.empty()))
	{
		std::cout << " " << this_tmp.Pop();
	}
	std::cout << " )";
	std::cout << std::endl;
}
