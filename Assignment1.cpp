// Assignment: #1
// Name: Szuching Valencia
// ASU ID: 1212544656
// ASU Email Address:
// Description: This program displays a menu of choices to a user
//              and performs the chosen task. It will keep asking a user to
//              enter the next choice until the choice of 'Q' (Quit) is entered.
//**********GRADER NEEDS TO READ THIS*******
// When I tested my cases by hand everything matched the output. However, if I let the program
// read them through the test file texts, for some reason it thinks there is a "\n" after each input.
// So if you test my program using the test cases inputs, there are additional "\n" in the results. 
// And I have no idea how to fix that. Anyways happy grading!!

#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

void printMenu();

int main()
{
   // local variables, can be accessed anywhere from the main method
   char input1 = 'Z';
   string inputInfo;
   string productName, oldName, newName;
   int id;
   double price;
   string line;
   bool success = false;

   // instantiate a Linked List object
   LinkedList * list1 = new LinkedList();

   printMenu();

   do  // will ask for user input
      {
         cout << "\nWhat action would you like to perform?\n";
         cin.get(input1);
         input1 = toupper(input1);    //change it to upper case
         cin.ignore(20, '\n'); //flush the buffer

         // matches one of the case statement
         switch (input1)
         {
           case 'A':   //Add the product
               cout << "Please enter the product information:\n";
               cout << "Enter the product name:\n";
               getline(cin, productName);
               cout << "Enter product id:\n";
               cin >> id;
               cout << "Enter the product price:\n";
               cin >> price;
               cin.ignore(20, '\n'); //flush the buffer
			   
               success = list1->addProduct(productName, id, price);

               if (success == true)
                cout << "The product \"" << productName << "\" is added\n";
               else
                cout << "The product \"" << productName << "\" is not added\n";
               break;

            case 'C':  //Change product name
                cout << "Please enter the product ID which you want to change the name:\n";
                cin >> id;
                cin.ignore(20, '\n'); //flush the buffer
                cout << "Please enter the new name: ";
                getline(cin, newName);

                //call the relevant function to change the product name
				success=list1->changeProductName(id, newName);

                if (success == true)
                     cout << "Product with ID #: " << id << " name was changed\n";
                else
                     cout << "Product with ID #: " << id << " does not exist\n";
                break;

             case 'D':   //Display all products
                 //call the relevant function to print the product list
				 list1->printProductList();

               break;

              case 'F':   //Find a product
                cout << "Please enter the product id you want to search:\n";
                cin >>id;
                cin.ignore(20, '\n');   //flush the buffer

                //call the relevant function to search the list by id
				success=list1->isFound(id);

                if (success == true)
                {
                    cout << "Product with ID #: " << id << " was found\n";
                }
                else
                    cout << "Product with ID #: " << id << " was not found\n";
                break;

             case 'P':  //Change a product price
                cout << "\nPlease enter the product id you want to change the price:\n";
                cin >> id;

                //call the relevant function to check whether the id is inside or not
				success=list1->isFound(id);

                if (success)  //product found inside
                {
                    cout << "\nPlease enter the new product price:\n";
                    cin >> price;
                    cin.ignore(20, '\n');   //flush the buffer

                    //call the relevant function to change the product price
					list1->changeProductPrice(id, price);

                    cout << "Product with ID #: " << id << " price was updated\n";
                 }
                else
                        cout << "Product with ID #: " << id << " does not exist\n";
                break;

            case 'R':  //Remove a product from the list
               cout << "Please enter the product ID to remove:\n";
               cin >> id;
               cin.ignore(20, '\n');   //flush the buffer

               //call the relevant function to remove the product
			   success=list1->removeProduct(id);

               if (success == true)
                cout << "Product with ID #: " << id << " was removed\n";
               else
                cout << "Product with ID #: " << id << " does not exist\n";
               break;

             case 'Q':   //Quit
                    delete list1;
                    break;

             case '?':   //Display Menu
                    printMenu();
                    break;

             default:
               cout << "Unknown action\n";
               break;
            }

        } while (input1 != 'Q');
      return 0;
   }

  /** The method printMenu displays the menu to a user**/
  void printMenu()
   {
     cout << "Choice\t\tAction\n";
     cout << "------\t\t------\n";
     cout << "A\t\tAdd Product\n";
     cout << "C\t\tChange A Product Title\n";
     cout << "D\t\tDisplay All Products\n";
     cout << "F\t\tFind A Product\n";
     cout << "P\t\tChange A product Price\n";
     cout << "R\t\tRemove Product\n";
     cout << "Q\t\tQuit\n";
     cout << "?\t\tDisplay Help\n\n";
  }
