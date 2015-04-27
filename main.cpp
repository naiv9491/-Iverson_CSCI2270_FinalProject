#include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <sstream>
#include "Travel.h"
/*
cout<<"hi"<<endl;
cout << "Hola" << endl;
cout << "this might work";

cout<<"extra test"<<endl;
* */

using namespace std;

int main(int argc, char *argv[]){

    //is this how you create all objects (of a class (like creating a new node))
    Travel places = Travel();


    ifstream inFile;

    string fileName = argv[1];
    inFile.open(fileName);

    string fileLine;
    string object = "";

    string location = "";
    int nature = 0;
    int food = 0;
    int culture = 0;
    int nightLife = 0;
    int adventure = 0;
    int relax = 0;


    //if the file is open
    if (inFile.is_open()) {
        //cout << "File opened successfully!"<<endl;

        
        getline(inFile, object);
        while(getline(inFile, fileLine)){

            istringstream iss(fileLine); 

                //Skip of entire first line. don't do anything here.

            getline(iss, object, ','); 
                location = (object);


            getline(iss, object, ',');
                nature = stoi(object); //converting string to int


            getline(iss, object, ',');
                food = stoi(object);


            getline(iss, object, ',');
                culture = stoi(object);


            getline(iss, object, ',');
                nightLife = stoi(object);


            getline(iss, object, ',');
                adventure = stoi(object);


            getline(iss, object, ',');
                relax = stoi(object);

            //call function to read in information and store in doubly linked list:
            places.readIn(location, nature, food, culture, nightLife, adventure, relax);

        }//end while loop
    }//end if (file is open)
    inFile.close();

    int choice = 1;
   
    while(choice != 0)
    {
		cout << "Welcome to to the Travel Program!" << endl;
		cout << "1. \n" << "2. Show Places\n" << "3. Reverse Places\n"; // need an option for #1
		cout << "4. Add Place\n" << "5. Remove Place\n" << "6. Show my best places\n" << endl;
		 
		cin >> choice;

    if(choice == 1)
    {
        
    }
    else if(choice == 2)
    {
        places.displayPlaces(); 
    }
    else if(choice == 3)
    {
		places.reversePlaces();
	}
	else if(choice == 4)
	{
		 places.addPlace();
	}
	else if(choice == 5)
	{
		places.removePlace();
	}
	else if(choice == 6)
	{
		 places.displayMenu(); 
		 places.computePlaceScores();
		 places.sortPlaceScores();
	}
}// end of while loop 
    return 0;
}// end of main
