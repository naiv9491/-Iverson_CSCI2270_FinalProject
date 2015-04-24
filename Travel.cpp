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

void displayPlaces(placeNode* head)
{
    placeNode* temp = new placeNode;
    temp = head;
    while(temp != NULL){
        cout<<temp->location;
        cout<<", ";
        temp=temp->next;
    }//end while
       // cout<<" NULL"<<endl;
}

void reversePlaces()
{
	
}

void addPlace(placeNode* head, string newLocation)
{

//The original function definition: node* addCity(node* head, string previous, string newCity){
//should we return the head instead of having a void function? does it help at all?

        placeNode* temp1 = new placeNode;
        temp1 = head;
        placeNode* added = new placeNode;

        while(temp1 != NULL){
           /* if(temp1->cityName == previous){
                if(temp1->next == NULL){
                    added->next = NULL;
                    temp1->next = added;
                    added->cityName = newCity;
                    return head;
                }
                else{
                added->next = temp1->next;
                temp1->next = added;
                added->cityName = newCity;
                return head;
                }
            }//end if
*/
            temp1 = temp1->next;
        }//end while loop
        added->next = NULL;
        temp1->next = added;
        added->location = newLocation;

        //return head;
}
        
void removePlace(placeNode* head, string toDelete)
{
    placeNode* temp1 = new placeNode;
    temp1 = head;
    placeNode* n = new placeNode;
    n = temp1->next;

    while(n != NULL){
            if(temp1->location == toDelete){
                head = n;
                delete temp1;
                return;
            }
            else if(n->location == toDelete){
                temp1->next = n->next;
                delete n;
                return;
            }

            temp1 = n;
            n = n->next;
        }//end while loop
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

