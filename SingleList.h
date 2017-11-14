#pragma once
/*
*����C++templateʵ�ֵĵ�������
*���ߣ�����
*ʱ�䣺2017/11/13
*/

#ifndef _SINGLELIST_H
#define _SINGLELIST_H

//���ṹ
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

//������
template<class T>
class SingleList
{
public:
	typedef Node<T>* pointer;//������������
	SingleList();
	~SingleList();

	int size();//��ȡ����
	bool isEmpty();//�ж��Ƿ�Ϊ��

	Node<T>* insert(int index, T t);//��ָ��λ�ý��в���
	Node<T>* insert_head(T t);//������ͷ����
	Node<T>* insert_last(T t);//����β����

	Node<T>* del(int index);//��ָ��λ��ɾ��
	Node<T>* del_head();//ɾ������ͷ
	Node<T>* del_last();//ɾ����β

	T get(int index);//��ȡָ��λ�õ�Ԫ��
	T get_head();//��ȡ����ͷԪ��
	T get_last();//��ȡ����βԪ��

	Node<T>* getHead();//��ȡ����ͷ���
	
private:
	int count;
	Node<T>* head;//ͷ���

private:
	Node<T>* getNode(int index);//��ȡָ��λ�õĽ��
};

template<class T>
SingleList<T>::SingleList():count(0),head(nullptr)
{
	//����ͷ���
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
Node<T>* SingleList<T>::getNode(int index)//����ָ��������ǰһ��λ�ý�㣬������Ϊ�գ��򷵻�ͷ���
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
