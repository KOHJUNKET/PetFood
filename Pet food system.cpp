//PET FOOD SALES SYSTEM   GROUP15
//KOHJUNKET 1211210437
//DANIELTANNAILE 1211209005
//ONGLIHENG 1211209085
//LIMLIANGYEA 1211210785

#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
#include<cstring>
#include <ctime>
#include <cstdio>

using namespace std;

const int row = 50;

class PetFood {
public:
    string code;
    string name;
    string petType;
    double price;
    int quantity;
    
};

class PetFoodStore {
private:
    vector<PetFood> petFoods;

public:
    void PetOptions() const {
        cout << "\n\t\t\tAvailable Pet Options\n";
        cout << "1. Cat\n";
    }
    ~PetFoodStore() //destructor
	{
        cout << "\nThank you, have a great day.\n";
    }
};

class admin_main_menu
{
	protected:
		int options;
		string search;
		
	public:
		void set_main_menu()
		{
			cout << "***********************************************" << endl;
			cout<<"------ \t\t  ADMIN MENU\t\t ------"<<endl;
			cout<<"==============================================="<<endl;
			cout<<"\t    >> [1] PET FOODS <<"<<endl;
			cout<<"\t      >> [2] EXIT <<"<<endl;
		}
		
};//end of class main menu
string CatID[row] = {};
string CatFoods[row] = {};
string CatType[row] = {};
float CFPrice[row] = {};
int CFQuantity[row] = {};

class PetFoods : public admin_main_menu
{
	private:
		string catid;
		string catfood;
		string cattype;
		float cfprice;
		int cfquantity;
		
public:
    void petfoods_menu()
    {
	     do
      {
        cout << "***********************************************" << endl;
        cout << "------ \t\tANIMALS CATEGORY\t ------" << endl;
        cout << "===============================================" << endl;
			cout<<"\t>>        [1] Cat           <<"<<endl;
			cout<<"\t>> [2] Return to Admin Menu <<"<<endl;
			cout<<"\t>>        [3] Exit          <<"<<endl;
			cout<<"==============================================="<<endl;
			
			
			cout<<endl<<"Select option >>";
			cin>>options;
			
			switch(options)
			{
				case 1:
					system("cls");
				    Cat();
					cin.ignore();
					cin.get();
					system("cls");
					break;
				case 2:
					return;
				case 3:
					exit(0);
				default:
					cout<<endl<<"Invalid code! Please try again...."<<endl;
					cin.ignore();
					cin.get();
					system("cls");
			}//end of switch
			
		   }while(options !=7);
    }
    
	 void Cat()
    {
    	read_cat_files();
    	do
    	{
    	    cout << "***********************************************" << endl;
			cout<<"------ \t\t  CAT FOODS\t\t ------"<<endl;
			cout<<"==============================================="<<endl;
			cout<<endl<<"\t    >> [1] Add Records  <<"<<endl;
			cout<<"\t   >> [2] Update Records <<"<<endl;
			cout<<"\t   >> [3] Delete Records <<"<<endl;
			cout<<"\t   >> [4] Search Records <<"<<endl;
			cout<<"\t>> [5] Display All Records <<"<<endl;
			cout<<"\t>> [6] Return to Animals Category <<"<<endl;
			cout<<"\t       >> [7] Exit <<"<<endl;
			cout<<"==============================================="<<endl;
			cout<<"Select options: ";
			cin>>options;
			switch(options)
			{
				case 1:
					Cat_Add_Records();
					save_cat_files();
					system("cls");
					break;
				case 2:
					cin.ignore();
					cout<<"Search by ID >>";
					getline(cin,search);
					Cat_Update_Records();
					save_cat_files();
					system("cls");
					break;
				case 3:
					cin.ignore();
					cout<<endl<<"Delete by ID >>";
					getline(cin,search);
					Cat_Delete_Records();
					save_cat_files();
					system("cls");
					break;
			    case 4:
			    	cin.ignore();
			    	cout<<"Search by ID >>";
			    	getline(cin,search);
					Cat_Search_Records();
					cin.ignore();
					system("cls");
					break;
				case 5:
					system("cls");
					Cat_Display_Records();
					cin.ignore();
					cin.get();
					system("cls");
					break;	
				case 6:
					return;
				case 7:
					exit(0);
				default:
					cout<<endl<<"Invalid code! Please try again...."<<endl;
					cin.ignore();
					cin.get();
                    system("cls");
			}
			
		   }while(options !=7);
	}
	
	void Cat_Add_Records()
	{
	cin.ignore();
	cout<<endl<<"Food ID :";
	getline(cin,catid);
	cout<<"Food Name :";
	getline(cin,catfood);
	cout<<"Food Name :";
	getline(cin,cattype);
	cout<<"Food Price :";
	cin>>cfprice;
	cout<<"Food Quantity :";
	cin>>cfquantity;
	
	for(int i=0;i<row;i++)
	{
		if(CatID[i].empty())
		{
			CatID[i] = catid;
			CatFoods[i] = catfood;
			CatType[i] = cattype;
			CFPrice[i] = cfprice;
			CFQuantity[i] = cfquantity;
			
			cin.ignore();
			cout<<endl<<"Successful Added!"<<endl;
			cin.get();
			break;
		}//If EmpID array is empty, it means that this slot is available for a new employee record
	}
	}
	
	void Cat_Update_Records()
	{
		int count=0;
	for(int i=0;i<row;i++)
	{
		if(CatID[i] == search)
		{
			count++;
			cin.ignore();
	
	    cout<<"Food Price :";
	    cin>>cfprice;
	    cout<<"Food Quantity :";
	    cin>>cfquantity;
	    
	    CFPrice[i] = cfprice;
	    CFQuantity[i] += cfquantity;
	    
	    cin.ignore();
	    cout<<endl<<"Successfull Updated!"<<endl;
	    cin.get();
	    break;
		}
	}
	if(count == 0)
	{
		cout<<endl<<"Name does'nt exist!"<<endl;
		cin.get();
	}
	}
	
	void Cat_Delete_Records()
	{
		int count = 0;
	
	for(int i=0;i<row;i++)
	{
		if(CatID[i] == search)
		{
			count++;
			
			CatID[i] = "";
			CatFoods[i] = "";
			CatType[i] = "";
			CFPrice[i] = 0;
			CFQuantity[i] = 0;
			
			cout<<endl<<"Successfully Deleted!"<<endl;
			cin.get();
		}
	}
	if(count == 0)
	{
		cout<<endl<<"ID does'nt exist!"<<endl;
		cin.get();
	}
	}
	
	void Cat_Search_Records()
	{
		system("cls");
	int count = 0;
	cout<<""<<endl;
	cout<<"\t\t\t\t         Current Cat Food"<<endl;
	cout<<"=================================================================================================================="<<endl;
	
	cout<<"No. |     ID      |       Foods                                                  | Type |    Price    | Quantity  "<<endl<<"------------------------------------------------------------------------------------------------------------------\n";
	for(int i=0;i<row;i++)
	{
		if(CatID[i] == search)
		{
			count++;
			cout << setw(10) << left << count << setw(9) << left << CatID[i] << setw(65) << left <<CatFoods[i]<< setw(1) << right << CatType[i] << setw(10) << right <<fixed<<setprecision(2)<<CFPrice[i]<<setw(11)<<CFQuantity[i]<<endl;
			break;
		}
	}	
	if(count == 0 )
	{
		cout<<"No Record Found!"<<endl;
	}
	else
	{
		cout<<"--------------------------------------------------"<<endl;
	}
	}
	
	void Cat_Display_Records()
	{
		int count = 0;
	cout<<""<<endl;
	cout<<"\t\t\t\t         Current Record"<<endl;
	cout<<"=================================================================================================================="<<endl;
	
	cout<<"No. |     ID      |       Foods                                                  | Type |    Price    | Quantity  "<<endl<<"------------------------------------------------------------------------------------------------------------------\n";
	for(int i=0;i<row;i++)
	{
		if(!CatID[i].empty())
		{
			count++;
			cout << setw(10) << left << count << setw(9) << left << CatID[i] << setw(65) << left <<CatFoods[i]<< setw(1) << right << CatType[i] << setw(10) << right <<fixed<<setprecision(2)<<CFPrice[i]<<setw(11)<<CFQuantity[i]<<endl;
		}
	}
	 if(count == 0)
	{
		cout<<"No Record found!"<<endl;
	}
	}
	
	void read_cat_files()
	{
		int i;
		ifstream read_cat;
		read_cat.open("Cat.txt");
		if(read_cat)
		{
		 
		  for (int i = 0; i < row; i++)
        {
            if (!(read_cat >> CatID[i] >> CatFoods[i] >> CatType[i] >> CFPrice[i] >> CFQuantity[i]))
                break;
        }
		}
		else
		{
			cout<<"File does not exist"<<endl;
			exit(0);
		}
		read_cat.close();
	}
	 
    void save_cat_files()
    {
  	    ofstream save_cat;
  	    save_cat.open("Cat.txt");
  	    
  	    if(save_cat)
  	    {
  	    	for(int i=0;i<row;i++)
  	    	{
  	    		if(CatID[i].empty())
  	    		{
  	    			break;
				}
				else
				{
					save_cat << CatID[i] <<" "<< CatFoods[i] <<" "<< CatType[i] <<" "<< CFPrice[i] <<" "<< CFQuantity[i];
				}
			}
		}
		else
		{
			cout<<"File does not exist!"<<endl;
			exit(0);
		}
		save_cat.close();
    }
    
};//end of class petfoods_menu

class admin
{	
private:
	string userID, password, id, pass;
	public:
		PetFoods pf;
        int options;
		void menu()
		{
			do
			{
			admin_main_menu mm;
			system("cls");
			mm.set_main_menu();
			cout<<endl<<"Select option >>";
			cin>>options;
			
			switch(options)
			{	
				case 1:
					system("cls");
					pf.petfoods_menu();
					cin.ignore();
					cin.get();
					system("cls");
					break;
				case 2:
					exit(0);
				default:
					cout<<endl<<"Invalid code! Please try again...."<<endl;
					cin.ignore();
					cin.get();
					system("cls");
			}//end of switch
			
		   }while(options !=4);
	    }//end of menu
};//end of class admin

void petmenu();  // Declare petmenu function
void display();// Declare display function  
PetFoodStore petStore;

int main() {
    // Existing main function code
    admin a;
    int choice;
    cout << "\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n\n";
    cout<<"\t\t\t   ============================================================"<<endl;
    cout << "\n\t\t\t	-----------     DOLK PET FOOD STORE     -----------           \n\n";
    cout<<"\t\t\t   ============================================================\n\n"<<endl;
    cout << "\t\t\t_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_\n\n\n";

    cout << "\t\t\t\t\t\t_Main Menu_\n\n\n";
    cout << "\t\t\t\t |          Press 1 for PetFood           |\n";
    cout << "\t\t\t\t |          Press 2 for Admin              |\n";
    cout << "\t\t\t\t |          Press 3 to Exit                |\n";
    cout << "\n\t\t\t   Please enter your choice: ";
    cin >> choice;
    system("cls");
    switch (choice) {
        case 1:
        	display();
            break;
        case 2:
            a.menu();
            break;
        case 3:
            cout << "\t\t\t  Thank you!   \n\n";
            break;
        default:
            cout << "\t\t\t  Invalid choice! Please try again\n";
            exit(0);
    }

    return 0;
}

// Structure for pet information
struct Pet {
    string code;
    string foodName;
    string petType;
    double price;
    int quantity;
};

class PetStore {
public:
	PetStore()//constructor 
	{
		cout<<endl<<"===================================================="<<endl;
		cout<<"----\t      WELCOME TO PET FOOD STORE  \t----"<<endl;
		cout<<"===================================================="<<endl;
	}
	
    void PetOptions() {
        // Implement the function to display pet options
        // You can customize this based on your requirements
        cout <<endl<< "1. Cat" << endl;
    }
};

void display() {
//display the pet menu
    int petChoice;
    PetStore petStore;

    do {
        petStore.PetOptions();

        cout << "Select a pet option (1-5, 0 to exit): ";
        cin >> petChoice;
         system("cls");
        if (petChoice >= 1 && petChoice <= 5) {
            string filename;

            // Set the appropriate filename based on petChoice
            switch (petChoice) {
                case 1:
                    filename = "Cat.txt";
                    break;
            }

            ifstream file(filename.c_str());

            if (!file.is_open()) {
                cout << "File does not exist or could not be opened." << endl;
                exit(0);
            }

            cout << "---------------------------------------------------------------------------------------------------------------------\n";
           cout << setw(6) << left << "Code" << setw(70) << left << "Food Name" << setw(20) << left << "Pet Type" << setw(9) << right << "Price" << setw(13) << right << "Quantity" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------\n";

            // Read and display the contents of the file
            Pet pet;
            while (file >> pet.code >> pet.foodName >> pet.petType >> pet.price >> pet.quantity) {
                // Display the content 
                cout << setw(6) << left << pet.code << setw(70) << left << pet.foodName << setw(20) << left << pet.petType << setw(10) << right << pet.price << setw(10) << right << pet.quantity << endl;
            }
			
            file.close();
        } else if (petChoice != 0) {
            cout << "Invalid choice. Please try again." << endl;
        }
		
    } while (petChoice != 0);
}

