#include <iostream>

using namespace std;

struct node {
	int data;
	struct node* next;
};
typedef struct node Node;
Node * Creat(int n) {
	Node* head = new Node;
	head->next = NULL;
	Node* p = head;
	Node* q = NULL;
	for (int i = 1; i <= n; i++) { //n个节点
		q = new Node;
		q->next = NULL;
		cin >> q->data;
		p->next = q;
		p = q;
	}
	return head;
}
void print(Node* head) {
	Node* p = head->next;
	while (p != NULL) {
		cout << p->data << ' ';
		p = p->next;
	}
	cout << '\n';
}
//L1存放偶数,L2存放奇数
void split(Node* L, Node* L1, Node* L2) {
	Node * p = L->next; //p指向当前要划分的节点
	Node* p1 = L1;
	Node* p2 = L2;
	//将链表的次数放在头节点的数据域当中
	while (p != NULL) {
		if (p->data % 2 == 0) {//如果是偶数的话
			p1->next = p;
			p1 = p1->next;
			p = p->next;
			L1->data++;
		} else {
			p2->next = p;
			p2 = p2->next;
			p = p->next;
			L2->data++;
		}
		p1->next = NULL;
		p2->next = NULL;
	}
}

int main() {
	int n;
	cin >> n;
	Node *L = Creat(n);
//	print(L);
	Node *L1 = new Node;
	L1->next = NULL;
	L1->data = 0;
	Node *L2 = new Node;
	L2->next = NULL;
	L2->data = 0;
	split(L, L1, L2);
	cout << L1->data << ' ' << L2->data << '\n';
	print(L1);
	print(L2);


	return 0;
}
