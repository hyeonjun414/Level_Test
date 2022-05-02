// ex3.cpp : 링크드 리스트 구현

// 링크드리스트 : 노드를 이용하여 선형으로
//				연결한 형태의 자료구조로 삽입 삭제가 자유롭다는 특징이 있다.

#include <iostream>

using namespace std;

class Node
{
public:
	Node* m_pPrev;
	Node* m_pNext;
	int m_iData;


	Node(Node* _pPrev, Node* _pNext, int _iData)
	{
		m_pPrev = _pPrev;
		m_pNext = _pNext;
		m_iData = _iData;
	}
	~Node() {}
};

class LinkedList
{
	Node* m_pHead;
	Node* m_pTail;
	int size;

public:
	LinkedList()
	{
		m_pHead = nullptr;
		m_pTail = nullptr;
		size = 0;
	}
	~LinkedList() {}

	void push_front(int i)
	{
		if (size == 0)
		{
			Node* newHead = new Node(nullptr, nullptr, i);
			m_pHead = newHead;
			m_pTail = newHead;
			size++;
		}
		else
		{
			Node* newHead = new Node(nullptr, m_pHead, i);
			m_pHead->m_pPrev = newHead;
			m_pHead = newHead;
			size++;
		}
	}
	void pop_front()
	{
		if (size == 0) return;

		Node* deleteNode = m_pHead;
		m_pHead = m_pHead->m_pNext;
		delete deleteNode;
		size--;
	}
	void push_back(int i)
	{
		if (size == 0)
		{
			Node* newNode = new Node(nullptr, nullptr, i);
			m_pHead = newNode;
			m_pTail = newNode;
			size++;
		}
		else
		{
			Node* newNode = new Node(m_pTail, nullptr, i);
			m_pTail->m_pNext = newNode;
			m_pTail = newNode;
			size++;
		}
	}
	void pop_back()
	{
		if (size == 0) return;

		Node* deleteNode = m_pTail;
		m_pTail = m_pTail->m_pPrev;
		m_pTail->m_pNext = nullptr;
		delete deleteNode;
		size--;
	}
	void printAll()
	{
		Node* curNode = m_pHead;
		for (size_t i = 0; i < size; i++)
		{
			cout << curNode->m_iData << " ";
			curNode = curNode->m_pNext;
		}
		cout << endl;
	}
};

int main()
{
	LinkedList ll;
	ll.push_front(3);
	ll.push_front(4);
	ll.push_front(5);
	ll.printAll();
	ll.pop_back();
	ll.pop_front();
	ll.printAll();
	ll.push_back(10);
	ll.printAll();
}
