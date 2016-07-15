/*



Name of Program : Doubly Link List
Student name : Chaudhari Prerana Vilas 
Course number : CSCI 311

Project description : 
A program to write a doubly linked list which has the functions that
adds data in link-list from front, 
adds data in link-list from back, 
counts total number of nodes in link-list, 
checks whether list is empty or not,
removes data from link-list from front,
removes data from link-list from back,
inserts elements in link list,
prints data present in link-list.


Change and Fix log

  Date											Work Done
9/13/2014 							 Understanding concept of doubly link-list.
9/14/2014 							 Rough drafting of functions.
9/16/2014 							 Creation of structure and class.
	  							     Developing function to add node from front.
		  							 Developing function to print data from nodes.
9/18/2014 							 Code for function that counts total number of nodes developed. 
								     Function for checking whether list is empty and printing the same developed.  	
9/20/2014 							 Code for inserting node in link-list drafted.
9/21/2014 							 Code for inserting node in link-list and sorting the same developed.
9/23/2014 							 Function for removing node from front developed.	
9/24/2014 							 Function for removing node from back completed.
9/25/2014 							 Giving a finishing touch to the GUI. 

*/


#include <iostream>
#include <cstdlib>
#include <cstdio>
using namespace std;

struct DLListNode					
{									
    int data;															//a structure for node		
    DLListNode *nextNode;			
    DLListNode *prevNode;				
}*startNode;				

/* Class DoublyLinkList contains declaration of all functions need to be excecuted in order to call them.
All functions are publically accessible.
*/

class DoublyLinkList
{
	public:
			void addFront(int element);									// Function to add elements from front
			void addBack(int element);									// Function to add elements from back
			void totalCount();											// Function to count total number of nodes
			void isEmpty();												// Function to determine whether list is empty or not
			void removeFront();											// Function to remove elements from front
			void removeBack();											// Function to remove elements from back
			void insertElement(int element);							// Function to insert elements
			void printElements();										// Function to print elements
			void pressEnter();				
			DoublyLinkList()
			{
				startNode = NULL;										// Initialization of Start to NULL
			}	
};

/*
Description : 
Funtions for 
adding data in link-list from front, 
adding data in link-list from back, 
counting total number of nodes in link-list, 
checking whether list is empty or not,
removing data from link-list from front,
removing data from link-list from back,
inserting elements in link list,
printing data present in link-list
are evoked in here.

In:
choice- Integer type of data which decides which function to call.  
element- Integer type of data which is the data inserted in the node.

Out:
Funtions are evoked for desired output.

*/
int main()
{
	DoublyLinkList list;
	int choice, element;
	while(1)																	
	{
		system("cls");															// Clears screen
		 cout << "\nDOUBLY LINKED LIST \n";
		 cout << "1) Add at Front\n";
		 cout << "2) Add at Back\n";
		 cout << "3) Total Element Count\n";									// Displaying choices
		 cout << "4) Is Empty\n";
		 cout << "5) Remove from Front\n";
		 cout << "6) Remove from Back\n";
		 cout << "7) Insert Element\n";
		 cout << "8) Print Elements\n";
		 cout << "9) Exit Menu\n\n";
		 cout << "   Menu Option -> ";											// Enter Choice
		 cin >> choice;


		 while (!cin)
		 {
			 cout<<"\nNot a Proper Choice.  \n";
			 cin.clear();
			 cin.ignore();

		 }

		 
		switch ( choice )
		{
			case 1:																
					system("cls");												// Clears screen
					 cout<<"Please Enter element's value: ";					// Accepting value for data to insert into node
					 cin>>element;												
					while (!cin)												
					{															
							cout<<"\nNot a Proper Choice.  \n";					
							cin.clear();										
							cin.ignore();										// Checking for accepted value to be integer
							cout<<"\nPlease Enter element's value : ";			
							cin>>element;										
					 }															

					list.addFront(element);										// Calling function to add node at front
					list.printElements();										
					list.pressEnter();										
					break;														
			case 2:
					system("cls");												// Clears screen
					 cout<<"Please Enter element's value: ";					// Accepting value for data to insert into node
					 cin>>element;
					while (!cin)
					{
							cout<<"\nNot a Proper Choice.  \n";
							cin.clear();
							cin.ignore();										// Checking for accepted value to be integer
							cout<<"\nPlease Enter element's value : ";
							cin>>element;
					 }

					list.addBack(element);										// Calling function to add node at back
					list.printElements();
					list.pressEnter();
					break;
			case 3:
					list.totalCount();											// Calling function to count total number of nodes
					list.printElements();
					list.pressEnter();
					break;
			case 4:
					list.isEmpty();												// Calling function to check for list empty or not
					list.pressEnter();
					break;
			case 5:
					list.removeFront();											// Calling function to remove node from front
					list.printElements();
					list.pressEnter();
					break;
			case 6:
					list.removeBack();											// Calling function to remove node from back
					list.printElements();
					list.pressEnter();
					break;
			case 7:
					system("cls");												// Clears screen
					 cout<<"Please Enter element's value: ";					// Accepting value for data to insert into node
					 cin>>element;
					while (!cin)
					{
							cout<<"\nNot a Proper Choice.  \n";
							cin.clear();
							cin.ignore();										// Checking for accepted value to be integer
							cout<<"\nPlease Enter element's value : ";
							cin>>element;
					 }
					

					list.insertElement(element);								// Calling function to insert node
					list.printElements();
					list.pressEnter();
					break; 
			case 8:
					list.printElements();										// Calling function to insert node
					list.pressEnter();
					break;
			case 9:
					exit(1);													// Calling function to exit
			default:
					 cout<<"\nPlease Enter correct choice to contiue...\n";
					list.pressEnter();
					break;														// Default action
		}
	}
	return 0;
}

/*
Description : Evokes enter when press enter key

In : 
temp- char type of data for predication of new line

out : 
On stroke of enter key you are entered onto a new line.

*/
void DoublyLinkList::pressEnter()
{
	char temp='x';															
	cout<<"\nPress Enter to contiue...\n";
	flushall();																	// Clears memory
	while(temp != '\n')
		 cin.get(temp);
}

/*
Description : Function to add node from front.

In:
temp- pointer of DLListNode structure type for temporary node creation.

Out:
Add's a node from front.

*/
void DoublyLinkList::addFront(int element)
{
	struct DLListNode *temp;
	temp = new(struct DLListNode);												// Creation of new node of DLListNode type
	temp->data = element;															
	if (startNode == NULL)														// Checks if node if first 
	{
        temp->nextNode = NULL;
		temp->prevNode = NULL;													// Adds data, previous and next addresses to the node.
        startNode = temp;
    }
	else
	{
			temp->nextNode = startNode;
			temp->prevNode = NULL;
			startNode = temp;
      	    cout<<"\nElement "<<temp->data<<" Inserted...\n";					// Adds from fornt when already nodes exist in the link-list.
	}
}

/*
Description : Function to add node from back.

In:
temp- pointer of DLListNode structure type for temporary node creation.

Out:
Add's a node from back.

*/
void DoublyLinkList::addBack(int element)
{
	struct DLListNode *search, *temp;
	temp = new(struct DLListNode);												// Creates a new node.
	temp->data = element;
	if (startNode == NULL)														// Checks if the node is first.
    {
        temp->nextNode = NULL;
		temp->prevNode = NULL;
        startNode = temp;														// Adds data, previous and next addresses to the node.
    }
	else
	{
		search = startNode;
		while(search->nextNode != NULL)
		{
			search = search->nextNode;											// Traversing to the end of list.
		}
			temp->nextNode = NULL;
			temp->prevNode = search;
			search->nextNode = temp;
			 cout<<"\nElement "<<temp->data<<" Inserted...\n";					// Data added to the node when it isn't the first in link-list
	}
}


/*
Description : Function to count the number of nodes.

In:
search- pointer of DLListNode structure type for traversing through the link-list.
count- Integer type of data to count the number of nodes while traversing.

Out:
Counts total number of nodes in the link-list.

*/

void DoublyLinkList::totalCount()
{
	struct DLListNode *search;
	int count=0;																// Initializing count to 0 to start counting from 0.
	search = startNode;
	cout<<"\nTotal Count of Element is: ";
	while (search != NULL)
	{
			search = search->nextNode;											// Traversing through the link-list.
			count++;															// Increasing the counter of 'count'.
	}
	cout<<count<<"\n";															// Displaying total count of nodes.
   
}

/*
Description : Function to check whether the link-list is empty or not.

Out:
Display's whether link-list is empty of filled.

*/

void DoublyLinkList::isEmpty()
{
	if (startNode == NULL)														// Checks if node is first in link-list.
    {
         cout<<"\nList is Empty.. \n";
    }
	else
	{
		 cout<<"\nList is not Empty.. \n";
		DoublyLinkList::printElements();										// Displays elements in link-list if it isn't empty
	}
}

/*
Description : Function to remove node from front.

In:
search- pointer of DLListNode structure type for traversing through the link-list

Out:
Removes's a node from front.

*/

void DoublyLinkList::removeFront()
{
	struct DLListNode *search;

	if (startNode == NULL)														// Checks if the link-list is empty.
    {
		return;
         cout<<"\nList is Empty.. \n";
    }

	else
	{
		if (startNode->nextNode == NULL)										// Checks if the node is first.
		{
			cout<< "\nElement " << startNode->data <<" Deleted \n";
			startNode = NULL;													// If yes, makes the node NULL.
		}
		else
		{
			search = startNode;
			startNode = startNode->nextNode;
			startNode->prevNode = NULL;
			 cout<<"\nElement "<<search->data<<" Deleted...\n";					// Deletes the data in the node if it isn't first in the list.
			free(search);														// free's memory space allocated to node.
		}
	}
}

/*
Description : Function to remove node from back.

In:
temp- pointer of DLListNode structure type for temporary node creation.
search- pointer of DLListNode structure type for traversing through the link-list

Out:
Removes's a node from back.

*/

void DoublyLinkList::removeBack()
{
	struct DLListNode *search, *temp;
	if (startNode == NULL)														// Checks whether list is empty.
    {
		return;
         cout<<"\nList is Empty.. \n";
    }
	else
	{
		if (startNode->nextNode == NULL)										// Checks if node is first in link-list.
		{
			cout<< "\nElement " << startNode->data <<" Deleted \n";
			startNode = NULL;
			
		}
		else
		{
			search = startNode;
			while((search->nextNode)->nextNode != NULL)							// Checks for last node of the list.
			{
				search = search->nextNode;										// Treverses to last node of the list.
			}
			temp = search->nextNode;
			search->nextNode = NULL;
			 cout<<"\nElement "<<temp->data<<" Deleted...\n";					// Removes node if not the last in the list.
			free(temp);															// Free's memory allocated for the node.
		}
	}
}

/*
Description : Function to insert a node and sort the link-list.

In:
temp- pointer of DLListNode structure type for temporary node creation.
p, q, r- pointer of DLListNode structure for swapping data while sorting.

Out:
Inserts data in link-list and sorts the same.

*/

void DoublyLinkList::insertElement(int element)
{
	DLListNode *temp, *p, *q, *r;
	int value=0;

	temp = new(struct DLListNode);												// Create a new node.
	temp->data=element;

	if (startNode == NULL)														// Checks if node is first in the link-list.
	{
		startNode =temp;
		startNode->nextNode=NULL;
	}
	else
	{
		p= startNode;

		while(p->nextNode != NULL)												// Traverse through the list.
			p = p->nextNode;

		temp->nextNode=p->nextNode;
		temp->prevNode=p;
		p->nextNode=temp;

		p=startNode;
		q=startNode->nextNode;
		r=startNode;


		p->data= startNode->data;
		q->data=startNode->nextNode->data;

		while(r != NULL)
		{
			while (p->nextNode != NULL)
			{
				if (p->data > p->nextNode->data)
				{
					value = p->data;
					p->data = p->nextNode->data;								// Swapping data of nodes for sorting.
					p->nextNode->data=value;
				}
				p=p->nextNode;
				q=q->nextNode;

			}
			p=startNode;
			q=startNode->nextNode;												// Inserting data in the link-list.
			r=r->nextNode;

			}
		}
		
}

/*
Description : Function to display the data in link-list.

In:
search- pointer of DLListNode structure type for traversing through the link-list

Out:
Displays the data in link-list

*/


void DoublyLinkList::printElements()
{
	struct DLListNode *search;
	if (startNode == NULL)														// Check if link-list empty.
    {
         cout<<"\nList is Empty.. \n";
    }
	else
	{
		search = startNode;
		 cout<<"\nList Elements are: ";
		while (search != NULL)
		{
			 cout<<search->data<<" ";											// Displaying data of the node in the link-list.
			search = search->nextNode;											// Traverse through the link-list.
		}
		 cout<<"\n";
    }
}