#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	node *next;
};

node *head=NULL;

void addNode(int d){
	node *temp,*trav;
	temp = (node*)malloc(sizeof(node));
	temp->data =d;
	temp->next = NULL;
	if(head == NULL){
		head = temp;
	}else{
		trav = head;
		while(trav->next != NULL){
			trav = trav->next;
		}
		trav->next = temp;
	}
}

void CreateLoop(){
	node *temp,*secondNode,*LastNode;
	temp = head;
	while(temp != NULL){
		if(temp->data == 2){
			secondNode = temp;
		}
		if(temp->data == 5){
			LastNode = temp;
		}
		temp=temp->next;
	}
	LastNode->next = secondNode;
}

void IsLoopExists(){
	node *slow,*fast;
	slow = head;
	fast = head->next;
	while(slow != fast){
		fast = fast->next;
		if(fast == slow){
			printf("\nLoop Exists");
			break;
		}else{
			fast = fast->next;
			slow = slow->next;
		}
	}
}

void printList(){
	node *temp;
	temp = head;
	while(temp->next != NULL){
		printf("%d->",temp->data);
		temp=temp->next;
	}
	printf("%d",temp->data);
}

int main(){
	addNode(1);
	addNode(2);
	addNode(3);
	addNode(4);
	addNode(44);
	addNode(5);
	printList();
	CreateLoop();
//	printList();
	IsLoopExists();
	return 0;
}
