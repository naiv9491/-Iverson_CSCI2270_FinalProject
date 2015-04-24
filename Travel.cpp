#include "Travel.h"
using namespace std;



Travel::Travel()
{
    head = NULL;
}

Travel::~Travel()
{
    //dtor
}


void Travel::readIn(string location, int nature, int food, int culture, int nightLife, int adventure, int relax){

    if(head == NULL){
        head = new placeNode;
        head->location = location;
        head->nature = nature; //converting string to int
        head->food = food;
        head->culture = culture;
        head->nightLife = nightLife;
        head->adventure = adventure;
        head->relax = relax;
    }
    else{
        placeNode* currentNode = new placeNode;

        currentNode->location = location;
        currentNode->nature = nature; //converting string to int
        currentNode->food = food;
        currentNode->culture = culture;
        currentNode->nightLife = nightLife;
        currentNode->adventure = adventure;
        currentNode->relax = relax;

        placeNode* cursor = head;

        while(cursor->next != NULL){
            cursor = cursor->next;
        }

        //cout<<currentNode->location<<"->";

        cursor->next = currentNode;
        //currentNode->previous = cursor;
    }




}

void Travel::displayMenu(){
cout<<"It is time to go on the trip of your lifetime."<<endl;
cout<<"We will provide a list of locations around the world for you to visit depending on your preferences"<<endl;
cout<<"You can choose from these qualities:"<<endl;
cout<<endl;
cout<<"1. Nature"<<endl;
cout<<"2. Food"<<endl;
cout<<"3. Culture/History/Art"<<endl;
cout<<"4. Night Life"<<endl;
cout<<"5. Adventure"<<endl;
cout<<"6. Relax"<<endl;
cout<<endl;
cout<<"Please press the 's' key to rank (from 1 to 6) what you want to see on your trip."<<endl;
cout<<"Or press 'q' to quit"<<endl;
}

void displayPlaces()
{
	
}

void reversePlaces()
{
	
}

void addPlace()
{
	
}
        
void removePlace()
{
	
}

void computePlaceScores()
{
	int placeScore = 0;
	/* To compute the user's individual cityScore for each city, we loop through all the cities
	 * in the linked list and multiply whatever score that city got by the score the user gave as 
	 * a preferance for that characteristic. For example, a city with a nature score of 10 and a user
	 * nature score of 10 will contribute 100 points to the cityScore.  If that user gave a nature score 
	 * of 1, that would only contribute 10 points to that city's cityScore.
	 * */
	while(head != NULL)
	{
		placeScore += (head.nature * user.nature);
		placeScore += (head.food * user.food);
		placeScore += (head.culture * user.culture);
		placeScore += (head.nightLife * user.nightLife);
		placeScore += (head.adventure * user.adventure);
		placeScore += (head.relax * user.relax);
		head.cityScore = placeScore;
		
		placeScore = 0;
		head = head->next;
	}
		
}

void sortPlaceScores()
{
	
}

