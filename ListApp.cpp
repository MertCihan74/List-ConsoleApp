#include<iostream>																	//Adding libraries 
using namespace std;
enum  CATEGORY {Food,Drink,Junk,Stationary};										//Enumeration for category
struct PRODUCT {																	//Defining struct for product
	string name;
	int id;
	CATEGORY category;								
	int price;
	float tax;
};
PRODUCT p[10];																		//At most 10 product
void addProduct(int i) {															//Defining function for adding product
	int a;																			//Defining a for category number input  
	cout << "Product Name.......: "; cin >> p[i].name;
	cout << "Product Id.........: "; cin >> p[i].id;
	cout << "Product Type.......:[Food = 0, Drink = 1, Junk = 2, Stationary = 3] "; cin >> a;
	cout << "Product Price......: "; cin >> p[i].price;
	p[i].category = static_cast<CATEGORY>(a);
	
	
}
void printProducts(int i) {															//Defining function for saving and printing products
	
	cout << "Product Name.......: "<<p[i].name << endl;								//Printing products name,id,category,price and tax
	cout << "Product Id.........: "<< p[i].id << endl;
	switch (p[i].category) {																	//Switch-case for calculating tax and category type
	case 0:
		p[i].tax = p[i].price * 0.03;
		cout << "Product Category...: Food" << endl;
		break;
	case 1:
		p[i].tax = p[i].price * 0.05;
		cout << "Product Category...: Drink" << endl;
		break;
	case 2:
		p[i].tax = p[i].price * 0.18;
		cout << "Product Category...: Junk" << endl;
		break;
	case 3:
		p[i].tax = p[i].price * 0.08;
		cout << "Product Category...: Stationary" << endl;
		break;
	}
	cout << "Product Price......: "<< p[i].price<<" $"<< endl;
	cout << "Tax Price..........: "<<p[i].tax<<" $"<< endl;
	cout << "-----------------------------------------------------\n";
}
int main() {																		//Main function
	cout << "-----------------------------------------------------\n---------------------Product List--------------------\n-----------------------------------------------------\n";
	p[0] = { "Bread",1,Food,4,0.12};												//Product list which are registered 
	p[1] = { "Ayran",2,Drink,4,0.2};
	p[2] = { "Chips",3,Junk,9,1.62};
	p[3] = { "Pencil",5,Stationary,20,1.6};
	printProducts(0); printProducts(1);												//Calling printProducts function for printing first 4 product
	printProducts(2); printProducts(3);
	char yesno;																		//Defining char variable
	cout << "Do you want to add new product?[Y/N]: "; cin >> yesno;
	for (int i = 4; i < 10; i++) {													//Defining for loop for adding and printing products
		if (yesno == 'y' || yesno == 'Y') {											//If statement
			addProduct(i);															//Calling function for adding product
			cout << "-----------------------------------------------------\n";
			for (int k = 0; k <= i; k++) {											//defining one more for loop for printing products
				printProducts(k);													//Calling printProducts function
			}
			cout << "-----------------------------------------------------\n";
			cout << "Do you want to add new product?[Y/N]: "; cin >> yesno;
		}
		else																		//Else statement for getting N or any other buttons except y and Y
			break;																	//Breaking loop
	}

}
