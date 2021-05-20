//singly linked list program
/*

This Programs contains the following functions
1. Node addition at the beigning
2. Node addition at the end
3. Node addition at any position
4. Displaying the whole created list

*/

#include<iostream>

using namespace std;

//declaring structure
struct node{
	int data;
	node *next;
};

//linkedlist class
class linkedList{
	private:
	node *head, *tail;
	
	public:
	//constructor
	linkedlist(){
		head = NULL;
		tail = NULL;
	}
	
	//adding node at the end
	int add_enode(int dt){
		node *temp = new node;
		temp->data = dt;
		temp->next = NULL;
		
		if(head == NULL){
			head = temp;
			tail = temp;
		}else{
			tail->next = temp;
			tail = tail->next;
		}
		return 0;
	}
	
	//adding node at the beigning
	int add_bnode(int dt){
		node *temp = new node;
		temp->data = dt;
		temp->next = NULL;
		
		if(head == NULL){
			head = temp;
			tail = temp;
		}else{
			temp->next = head;
			head = temp;
		}
		return 0;
	}
	
	//adding node at any position
	int add_position_node(int position,int dt){
		node *temp = new node;
		temp->data = dt;
		temp->next = NULL;
		
		int count = 1, isNodeAdded = 0;
		
		node *currentNode = new node;
		node *prevCurrent = new node;
		
		currentNode = head;
		if(head == NULL){
			head = temp;
			tail = temp;
		}else{
			while(currentNode != NULL){
				if(position == 1){
					temp->next = head;
					head = temp;
				}
				if(count == position){
					prevCurrent->next = temp;					
					temp->next = currentNode;
					cout<<"Node added at position "<<position<<endl;
					isNodeAdded = 1;
					break;
				}else{
					count++;
					prevCurrent = currentNode;
					currentNode = currentNode->next;
				}
			}
			if(!isNodeAdded){
				cout<<"Position not found"<<endl;
			}
		}
		return 0;
	}
	//displaying the list
	int display(){
		node *temp = new node;
		temp = head;
		cout<<"The linked list contains the following items:"<<endl;
		while(temp->next != NULL){
			cout<<temp->data<<" -> ";
			temp = temp->next;
		}
		cout<<temp->data;
	}
	
};
int main(){
	linkedList myList;
	myList.add_bnode(50);
	myList.add_enode(1);
	myList.add_enode(2);
	myList.add_enode(3);
	myList.add_enode(10);
	myList.add_enode(20);
	myList.add_bnode(30);
//	myList.add_position_node(2,100);
	myList.display();
	return 0;
}
