#include<bits/stdc++.h>
using namespace std;

class doublyNode{
public:
	int value;
	doublyNode *prev;
	doublyNode *next;

	//constructor creation
	doublyNode(int val){
		value = val;
		prev = NULL;
		next = NULL;
	}
};

void insert_node(doublyNode *&head, int val){
	doublyNode *newNode = new doublyNode(val);
	if(head == NULL){
		head = newNode;
		return;
	}
	doublyNode *temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
}

int countLength(doublyNode *&head){
	int count = 0;
	doublyNode *temp = head;

	while(temp != NULL){
		count++;
		temp = temp -> next;
	}
	return count;
}

void insertoinAtSpecificPosition(doublyNode *&head, int pos, int val){
	int i = 0;
	doublyNode *temp = head;
	doublyNode *newNode = new doublyNode(val);
	if(head == NULL){
		head = newNode;
		return;
	}
	else if(head->next == NULL){
		insert_node(head,val);
		return;
	}

	while(i < pos - 2){
		temp = temp->next;
		i++;
	}
	
	doublyNode *save = temp->next;

	// newNode->next = temp->next;
	temp->next = newNode;
	newNode->prev = temp;

	newNode->next = save;
	save->prev = newNode;
}
void deletionAtHead(doublyNode *&head){
	doublyNode *temp = head;

	if(temp!=NULL){
		head = head->next;
	}
	else
		cout<<"There is no value in the Link List"<<endl;
}
void deletionAtTail(doublyNode *&head){
	doublyNode *temp = head;
	if(temp != NULL && temp->next != NULL){
		while(temp->next->next != NULL){
			temp = temp->next;
		}
		doublyNode *delNode = temp->next;
		temp->next = NULL;
		delete delNode;
	}
	else{
		if(temp == NULL) cout<<"There is no value in the Link List"<<endl;
		else
			deletionAtHead(head);
	}
}
void deletionAtSpecificPostition(doublyNode *&head, int position){
	doublyNode *temp = head;

	if(position <= countLength(head)){
		if(position == 1)
			deletionAtHead(head);
		else if(position == countLength(head))
			deletionAtTail(head);
		else{
			int i = 1;
			while(i < position-1){
				temp = temp->next;
				i++;
			}
			doublyNode *delNode = temp->next;
			temp->next = delNode->next;
			delNode->next->prev = temp;
			delete delNode;
		}
	}
}
void move_head(doublyNode *&head){
	doublyNode * temp = head;
	if(head == NULL){
		cout<<"There is no value in the Link List"<<endl;
		return;
	}
	else if(head->next == NULL){
		cout<<"Head and Tail are same"<<endl;
		return;
	}

	doublyNode *newNode = new doublyNode(head->value);
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;

	head = head->next;
}


void display(doublyNode *n){
	while(n != NULL){
		cout<<n->value;
		if(n->next != NULL)
			cout<<"-->";
		n = n->next;
	}
	cout<<endl;
}

int main()
{
	doublyNode * head = NULL;
	int value, position;

	cout<<"Choice 1: Insert Node(at the end)"
	<<endl<<"Choice 2: Insertion at specific position"
	<<endl<<"Choice 3: Deletion ar specific position"
	<<endl<<"Choice 4: Move Head to Tail"
	<<endl<<"Choice 0: Exit"<<endl;

	int choice;
	cout<<"Next Choice: ";
	cin>>choice;

	while(choice != 0){
		switch(choice){
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
				insertoinAtSpecificPosition(head, position, value);
				break;
			case 3:
				if(head == NULL){
					cout<<"There is no value in the Link List";
					break;
				}
				cout<<"Enter the desired position: ";
				cin>>position;
				deletionAtSpecificPostition(head, position);
				break;
			case 4:
				move_head(head);
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

	return 0;
}