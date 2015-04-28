#include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <sstream>
#include "Travel.h"


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


    //opening the text file
    if (inFile.is_open()) {


        getline(inFile, object);
        for(int i = 0; i < 21; i++)
        {

			getline(inFile, fileLine);

            //Reading in first line
            istringstream iss(fileLine);

                //Skip of entire first line. Don't do anything here.

            //Read in all other components of line separated by commas
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

            //call function to read in information and store in linked list. This is called one line at a time.
            places.readIn(location, nature, food, culture, nightLife, adventure, relax);

        }//end while loop
    }//end if (file is open)
    inFile.close();

    int choice = 0;

    while(choice != 6)
    {
		choice = 0;
		while(choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6)
		{
			cout << "Welcome to to the Travel Program!" << endl;
			cout << "1. Show my best places\n" << "2. Show Places\n" << "3. Reverse Places\n";
			cout << "4. Add Place\n" << "5. Remove Place\n" << "6. Quit " << endl;

			cin >> choice;
		}

	if(choice == 1)
	{
		places.displayMenu();
		places.computePlaceScores();
		places.sortPlaceScores();
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

}// end of while loop
    return 0;
}// end of main
