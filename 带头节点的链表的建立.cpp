#include <iostream>
using namespace std;
struct node {
	int a;
	struct node* next;
};
typedef struct node Node;
Node* Creat() {
	int x;
	Node* head = new Node;
	head->next = NULL;
	Node* p = head;//p始终指向最后一个节点
	Node* q = NULL;//q始终指向新生成的节点
	while (1) {
		cout << "请输入成绩以负数结束循环\n";
		cin >> x;
		if (x < 0) {
			break;
		} else {
			q = new Node;
			q->a = x;
			q->next = NULL; //新节点的指针域始终为NULL
			p->next = q; //让尾节点指向新节点
			p = q;//更新p,始终为最后一个
		}
	}
	return head;
}
void print(Node *head) {
	if (head->next == NULL) {
		cout << "链表为空无法打印\n";
	} else {
		Node* p = head->next;
		cout << "链表为:";
		while (p != NULL) {
			cout << p->a;
			if (p->next != NULL) {
				cout << "->";
			}
			p = p->next;
		}
		cout << '\n';
	}
}
int main() {
	Node* head = Creat();
	print(head);
	return 0;
}
