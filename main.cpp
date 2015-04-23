#include <iostream>
# include <fstream>
# include <string>
# include <cstdlib>
# include <sstream>
#include "Travel.h"

cout<<"hi"<<endl;

using namespace std;

int main(int argc, char **argv){

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

        //get each line (one at a time with the while loop) and store them as a string called fileLine
        getline(inFile, object);
        while(getline(inFile, fileLine)){

            istringstream iss(fileLine); //what does this do again?

                //Skip of entire first line. don't do anything here.

            getline(iss, object, ','); //theFile isn't right. could I just store these values in variables to use later when I call my addNewNode function?
                location = (object);


            getline(iss, object, ',');
            cout<<object<<endl;
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

    string choice;
    places.displayMenu();
    cin>>choice;
    //cin>>choice;

    if(choice == "s"){
        for(int i = 0; i < 6; i++){
            if(i = 0){
                cout<<"Please rank your preference for NATURE from 1-6"<<endl;
                //cin<<choice;

            }
        }
    }
    else{
        cout<<"Goodbye!"<<endl;
    }
    return 0;
}
