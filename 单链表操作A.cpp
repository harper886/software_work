#include <iostream>

using namespace std;
struct node {
	int data;
	struct node* next;
};
typedef struct node Node;
Node *Create(int n) {
	Node* head = new Node;
	head->next = NULL;
	Node* p = head;//始终指向最后一个节点
	Node* q = NULL;//始终指向新建立的节点
	int e;
	for (int i = 1; i <= n; i++) {
		cin >> e;
		q = new Node;
		q->next = NULL;
		q->data = e;
		p->next = q;
		p = p->next;
	}
	return head;
}
//用来计算带头节点的链表的长度
int length(Node *head) {
	int len = 0;
	Node* p = head->next;
	while (p != NULL) {
		len++;
		p = p->next;
	}
	return len;
}
//用来打印带头节点的链表
void print(Node *head) {
	Node* p = head->next;
	while (p != NULL) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << '\n';
}
//删除链表里面和e相同的全部节点
void delete_list (Node *head, int e) {
	Node *q = head;
	Node *p = head->next;
	//q指针在前,p指针在后
	while (p != NULL) {
		if (p->data == e) {
			q->next = p->next;
			p = q->next;
		} else {
			q = p;
			p = p->next;
		}
	}
}
int main() {
	int n;
	cin >> n;
	int e;
	Node *head = Create(n);
	cout << length(head) << '\n';
	print(head);
	cin >> e;
	delete_list(head, e);
	cout << length(head) << '\n';
	print(head);
	return 0;
}
