#pragma once
/*
*基于C++template实现的单链表类
*作者：刘涵
*时间：2017/11/13
*/

#ifndef _SINGLELIST_H
#define _SINGLELIST_H

//结点结构
template<class T>
class Node
{
public:
	Node() = default;
	Node(T _value,Node* _next):value(_value),next(_next){}

public:
	T value;
	Node* next;
};

//单链表
template<class T>
class SingleList
{
public:
	typedef Node<T>* pointer;//用来遍历链表
	SingleList();
	~SingleList();

	int size();//获取长度
	bool isEmpty();//判断是否为空

	Node<T>* insert(int index, T t);//在指定位置进行插入
	Node<T>* insert_head(T t);//在链表头插入
	Node<T>* insert_last(T t);//在链尾插入

	Node<T>* del(int index);//在指定位置删除
	Node<T>* del_head();//删除链表头
	Node<T>* del_last();//删除表尾

	T get(int index);//获取指定位置的元素
	T get_head();//获取链表头元素
	T get_last();//获取链表尾元素

	Node<T>* getHead();//获取链表头结点
	
private:
	int count;
	Node<T>* head;//头结点

private:
	Node<T>* getNode(int index);//获取指定位置的结点
};

template<class T>
SingleList<T>::SingleList():count(0),head(nullptr)
{
	//创建头结点
	head = new Node<T>();
	head->next = nullptr;
}

template<class T>
SingleList<T>::~SingleList()
{
	Node<T>* node = head->next;
	while (node!=nullptr)
	{
		Node<T>* temp = node;
		node = node->next;
		delete temp;
	}
}

template<class T>
int SingleList<T>::size()
{
	return count;
}

template<class T>
bool SingleList<T>::isEmpty()
{
	return count == 0;
}

template<class T>
Node<T>* SingleList<T>::insert(int index, T t)
{
	Node<T>* node = getNode(index);
	if (node)
	{
		Node<T>* newnode = new Node<T>(t, node->next);
		node->next = newnode;
		count++;
		return newnode;

	}
	return nullptr;
}

template<class T>
Node<T>* SingleList<T>::insert_head(T t)
{
	return insert(0, t);

}

template<class T>
Node<T>* SingleList<T>::insert_last(T t)
{
	return insert(count, t);
}

template<class T>
Node<T>* SingleList<T>::getHead()
{
	return head->next;
}

template<class T>
T SingleList<T>::get(int index)
{
	Node<T>* node = getNode(index);
	node = node->next;
	return node->value;
}

template<class T>
T SingleList<T>::get_head()
{
	return get(0);
}

template<class T>
T SingleList<T>::get_last()
{
	return get(count);
 }

template<class T>
Node<T>* SingleList<T>::getNode(int index)//返回指定索引的前一个位置结点，若链表为空，则返回头结点
{
	if (index > count || index < 0)
		return nullptr;
	int temp = 0;
	Node<T>* node = head;
	while (temp < index)
	{
		temp++;
		node = node->next;
	}
	return node;
}

template<class T>
Node<T>* SingleList<T>::del(int index)
{
	if (isEmpty())
		return nullptr;
	Node<T>* node = getNode(index);
	Node<T>* delnode = node->next;
	node->next = delnode->next;
	delete delnode;
	count--;
	return node->next;

}

template<class T>
Node<T>* SingleList<T>::del_head()
{
	return del(0);

}

template<class T>
Node<T>* SingleList<T>::del_last()
{
	return del(count);
}








#endif // !_SINGLELIST_H
