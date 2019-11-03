// Assignment: #1 (ASU Fall 2019)
// Name: Szuching Valencia
// ASU ID: 1212544656
// ASU Email Address: svalen16@asu.edu
// Description: This program displays a menu of choices to a user and performs the chosen task. It will keep asking a user to enter the next choice until the choice of 'Q' (Quit) is entered.

#include <iostream>
#include <iomanip> //to format the output
#include <string>

using namespace std;

//struct Product represents certain product information
struct Product
{
    string name;
    int id;
    double price;

    struct Product * next; //structure member next, declared as a pointer, is a successor pointer that points to the next node
};

//class LinkedList will contains a linked list of Products
class LinkedList
{
    private:
        struct Product* head;

    public:
        LinkedList();
        ~LinkedList();
        bool isFound(int productId);
        bool addProduct(string productName, int productId, double productPrice);
        bool removeProduct(int productId);
        bool changeProductName(int productId, string newProductName);
        bool changeProductPrice(int productId, double newPrice);
        void printProductList();
};

//Constructor to initialize an empty linked list
LinkedList::LinkedList()
{
    head = NULL;
}

//Destructor
//Before termination, the destructor is called to free the associated memory occupied by the existing linked list. 
//It deletes all the nodes including the head and finally prints the number of nodes deleted by it.
//Return value: Prints the number of nodes deleted by it.
LinkedList::~LinkedList()
{
   int productCount = 0;

	//Add your own code here
   Product* nodePtr = head; //nodePtr starts @ (head) 
   while (nodePtr != NULL) {
	  
	   Product* garbage = nodePtr;  // garbage keeps track of node/struct to be deleted
	   nodePtr = nodePtr->next; // pointer moves to the next node
	   delete garbage;  // deletes garbage
	   productCount++; 	   //increases number of product deleted

   }

	head = NULL;
	cout<< "The number of deleted products is: " << productCount <<"\n";

	return;
}

//A function to identify if the parametered Product is inside the LinkedList or not.
//Return true if it exists and false otherwise.
bool LinkedList::isFound(int productId)
{
	struct Product *start = head;
	bool found = false;
	while(start != NULL)
    {
		if(start->id == productId)
		{
			found = true;
			break;
		}
      else
			start = start->next;
	}
	return found;
}

//Creates a new node and inserts it into the list at the right place.
//It also maintains an alphabetical ordering of the Products by their names
//while inserting it into the list. Note: you cannot insert duplicated products
//Return value: true if it is successfully inserted and false in case of failures.
bool LinkedList::addProduct(string productName, int productId, double productPrice)
{
	//initializing the struct with addProduct parameters
	Product* product = new Product;
	product->name = productName;
	product->id = productId;
	product->price = productPrice;

	Product* current;	// setting current to point at product
	current = head;		// current starts at the beginning of list
	product->next = NULL; // makes sure that anything last in list is pointed to null

	while (current != NULL) {
		if (current->name == productName || current->id == productId) {
			cout << "Duplicated product. Not added." << endl;
			return false;
		}
		else {
			current = current->next;
		}
	}
	current = head;


	if (head == NULL) { //if there is nothing in the list add it as head
		head = product;
		return true;
	}

	else if ((product->name.compare(head->name) < 0)) { //if stack is the first thing in the list
		product->next = head;
		head = product;
		return true;
	}
		
	else {
		while (current!=NULL) {
			/*if (head->next == NULL) {
				product->next = NULL;
				head->next = product;
				return true;
			}*/ ///not sure what this if block is for
			if (((current->name).compare(product->name) < 0) && (current->next == NULL)) { //situation where it needs to be at the end of list
			current->next = product;
			product->next = NULL;
			return true;
			}
			else if (((current->name).compare(product->name) < 0) && ((current->next->name).compare(product->name) > 0)) { //puts in the middle
				product->next = current->next;
				current->next = product;
				//added = 1;
				return true;
			}
			current = current->next; //updates the current
		}
	}

}

//Removes the given Product from the list, releases the memory and updates pointers.
//Return true if it is successfully removed, false otherwise.
bool LinkedList::removeProduct(int productId)
{
	Product* current, * previousNode;
	previousNode = NULL;
	int remove = 0; 
	if (head==NULL) return false; //does nothing if list is empty

	//if head is equal to id then deletes head
	if (head->id == productId) {
		current = head;
		head = head->next;
		delete current;
		return true;
	}
	else {
		//current is head
		current = head;
		//skips nodes that are not the number
		while (current != NULL && current->id != productId) {
			previousNode = current; //previous node is head
			current = current->next; // current is the next node
		}
		//links previous node to the node after current then deletes current
		if (current) {
			previousNode->next = current->next;
			delete current;
			return true;
		} //end of if 
		else //when there is nothing in the list that matches the productId
			return false; 

	} // end of else
}

//Modifies the data of the given Product.
//Return true if it modifies successfully and false otherwise.
bool LinkedList::changeProductName(int oldProductId, string newProductName)
{
	Product* current;
	current = head;

	if (current == NULL){ //case where there is nothing in the list
		return false; //name is not successfully added in list
	}
	else {
		while (current != NULL) {
			if (current->id == oldProductId) {
				current->name = newProductName;
				double price1 = current->price;
				removeProduct(oldProductId);
				addProduct(newProductName, oldProductId, price1);
				return true;
			}
			else {
				current = current->next;
			}
		}
		return false;
	} //end of else
}

bool LinkedList::changeProductPrice(int productId, double newPrice)
{
	Product* current;
	current = head;
	if (head == NULL) {
		return false;
	}
	else{
		while (current != NULL) {
			if (current->id == productId) { //if id is equal to productID, it changes price
				current->price = newPrice;
				current = current->next;
				return true;
			}
			else { //if not equal then moves to next node
				current = current->next;
			}
		}
		return false;
	}
}

//Prints all the elements in the linked list starting from the head node.
void LinkedList::printProductList()
{
	Product* current;
	current = head;
	while (current != NULL) {
		cout << current->id << ", " << current->name << ", " << current->price << endl;
		current=current->next;
	}
}
