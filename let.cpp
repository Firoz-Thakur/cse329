#include <iostream>
using namespace std;

struct node{
	int data;
	node *next, *prev;
}*head = NULL, *mid = NULL;

int cnt;

void push(int data){
	node *newnode = new node;
	newnode->data = data;
	newnode->next = head;
	newnode->prev = NULL;
	if(head == NULL)
		mid = newnode;
	else{
		head->prev = newnode;
		if(cnt % 2 == 0)
			mid = mid->prev;
	}
	cnt++;
	head = newnode;
}

int top(){
	if(head == NULL)
		return -1;
	return head->data;
}

int middle(){
	if(mid == NULL)
		return -1;
	return mid->data;
}

void pop(){
	if(head == NULL)
		return;
	node *curr = head;
	head = head->next;
	cnt--;
	if(cnt % 2 == 0)
		mid = mid->next;
	delete curr;
}

//4 -> 3 -> 2 -> 1 ... 4 -> 3 -> 1
void deletemiddle(){
	if(mid == NULL)
		return;
	node *curr = mid;
	cnt--;
	if(cnt % 2 == 0){
		node *next = mid->next;
		node *prev = mid->prev;
		if(next != NULL)
			next->prev = mid->prev;
		if(prev != NULL)
			prev->next = mid->next;
		mid = mid->next;
	}
	else {
		node *next = mid->next;
		node *prev = mid->prev;
		if(next != NULL)
			next->prev = mid->prev;
		if(prev != NULL)
			prev->next = mid->next;
		mid = mid->prev;
	}
	if(mid == NULL)
		head = mid;
	delete curr;
}

int main() {
	// your code goes here //3 -> 2 -> 1 ---> 3 -> 1 ---> 3 
	push(1);
	push(2);
	push(3);
	cout<<top()<<endl;
	cout<<middle()<<endl;
	deletemiddle();
	cout<<top()<<endl;
	cout<<middle()<<endl;
	deletemiddle();
	cout<<top()<<endl;
	cout<<middle()<<endl;
	deletemiddle();
	cout<<top()<<endl;
	cout<<middle()<<endl;
	return 0;
}
