//Connor Sullivan
//Sep-13-2023
//COCS220
#include <fstream>
#include <iostream>

using namespace std;

int main(){
ifstream input;
ofstream output;
int number = -1; //User input
char name[50]; //name of food
char tax; //tax
char sale; //Unit measurment
int current;//Current item
float price;//Price
bool found; //Flag if found
//Set up file
output.open("Sullivan_Connor.txt",ios::out);
output << left << setw(13) << "Item Number" << setw(14) << "Item Name" << setw(6) << "Unit"         << setw(10) << "Unit Price" << setw(5) << "  Tax" << setw(12) << "   Subtotal" << endl;
output << "-------------- " << "---------- " << "------ " << "----------- " << "----- " << "--------- " << endl;
//Open file
input.open("item.txt", ios::in);
if(!input){
	cerr << "No file found" <<endl;
	exit(1);
}
//Get user input
while(true){
	cout << "Enter Item Number: ";
	cin >> number;
	//End program
	if(number == 0)
		break;
	found = false;
	//Reset to top of list
	input.clear();
	input.seekg(0);
	//Begin the linear search
	while(!input.eof()){
		input >> current;
		input >> name;
		input >> tax;
		input >> sale;
		input >> price;
		//If found stop
		if(current == number){
			found = true;
			break;
		}
	}
	//If found add to list
	if(found == true){
		//Calculate tax and unit price
		float taxPrice = 0.0;
		float unit = 1.0;
		float unitPrice = price;
		if(sale == 'p'){
			cout << "How many pounds: ";
			cin >> unit;
			price = price * unit;
		}
		else if(sale == 'n'){
			int numUnits;
                	cout << "How many units: ";
                	cin >> numUnits;
                	unit = static_cast<float>(numUnits);
					price = unit * price;
		
		}
		else{
			int numUnits = 1;
			unit = static_cast<float>(numUnits);
			price = price;
		}

              	if(tax == 't'){
                        taxPrice = price * 0.06;
                }
		float total = price + taxPrice;
		//Output to file
		output << left << setw(13) << number << setw(15) << name << setw(10) << unit << setw(10) << unitPrice << setw(10) << taxPrice << setw(12) << total << endl;  	
	}

}
//Close the streas
input.close();
output.close();
return 0;
}
