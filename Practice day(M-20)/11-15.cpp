#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int value;
	Node *next;

	//Constructor creation
	Node(int val)
	{
		value = val;
		next = NULL;
	}
};

void insert_node(Node *& head, int val)
{
	Node* newNode = new Node(val);
	if(head == NULL){
		head = newNode;
		return;
	}
	Node* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
}
void insertionAtSpecificPosition(Node *&head, int pos, int val){
	int i = 0;
	Node *temp = head;
	Node * newNode = new Node(val);
	if(temp == NULL){
		head = newNode;
		return;
	}

	while(i < pos - 2){
		temp = temp->next;
		i++;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}
int countLength(Node *&head){
	int count = 0;
	Node *temp = head;
	while(temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}

void deletionAtHead(Node *&head){
	Node *temp = head;
	if(temp != NULL)
		temp = temp->next;
	else
		cout<<"There is no value in The Link List";
}
void deletionAtTail(Node *&head){
	Node *temp = head;

	if(temp != NULL && temp->next != NULL){
		while(temp->next->next!=NULL){
		temp = temp->next;
		}
		Node *delNode = temp->next;
		temp->next = NULL;
		delete delNode;
	}
	else{
		if(temp == NULL) cout<<"There is no value in the Link List"<<endl;
		else
			deletionAtHead(head);
	}
}

void deletionAtSpecificPosition(Node *&head, int position){
	Node *temp = head;
	if(position <= countLength(head))
	{

		if(position == 1) deletionAtHead(head);
		else if(position == countLength(head)) deletionAtTail(head);
		else{
			int i = 1;
			while(i < position - 1){
				temp = temp->next;
				i++;
			}
			Node *delNode = temp->next;
			temp->next = delNode->next;
			delete delNode;
		}
		
	}
}
void move_tail(Node *&head){
	Node *temp = head;
	if(head==NULL){
		cout<<"There is no value in the Link List"<<endl;
		return;
	}
	else if(head->next == NULL){
		cout<<"Head and Tail are same"<<endl;
		return;
	}

	while(temp->next->next != NULL){
		temp = temp->next;
	}
	Node *newNode = new Node(temp->next->value);
	newNode->next = head;
	head = newNode;

	temp->next = NULL;
}
void display(Node *n)
{
	while(n!=NULL){
		cout<<n->value;
		if(n->next != NULL)
			cout<<"->";
		n = n->next;
	}
	cout<<endl;
}

int main()
{
	Node *head = NULL;
	int value, position;

	cout<<"Choice 1: Insert node (at the end)"
	<<endl<<"Choice 2: Insertion at specific position"
	<<endl<<"Choice 3: Deletion At specific position"
	<<endl<<"Choice 4: Move tail to head"
	<<endl<<"Choice 0: Exit"<<endl;

	cout<<"Next Choice: ";
	int choice;
	cin>>choice;

	while(choice != 0)
	{
		switch(choice)
		{
		case 1:
			cout<<"Enter the value: ";
			cin>>value;
			insert_node(head, value);
			break;
		case 2:
			cout<<"Enter the desired position: ";
			cin>>position;
			cout<<"Enter the value: ";
			cin>>value;
			insertionAtSpecificPosition(head, position, value);
			break;
		case 3:
			if(head == NULL)
			{
				cout<<"There is no value in the Link List"<<endl;
				break;
			}
			cout<<"Enter the desired position: ";
			cin>>position;
			deletionAtSpecificPosition(head, position);
			break;
		case 4:
			move_tail(head);
			break;
		default:
			break;
		}
		cout<<"Next Choice: ";
		cin>>choice;
	}
	cout<<endl<<"Linear Link List: ";
    display(head);
    cout<<"Length Of the List: "<<countLength(head)<<endl;


}