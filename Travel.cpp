#include "Travel.h"
using namespace std;



Travel::Travel()
{
    head = NULL;
    user = NULL;
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
	user = new userPref;
	
cout<<"It is time to go on the trip of your lifetime."<<endl;
cout<<"But first, we'll need your travel preferences."<<endl;
cout<<"Rate each of these qualities from 1-10:\n"<<endl;

int nature, food, culture, night, adventure, relax;
cout<<"1. Nature: ";
cin >> nature;
cout<<"2. Food: ";
cin >> food;
cout<<"3. Culture/History/Art: ";
cin >> culture;
cout<<"4. Night Life: ";
cin >> night;
cout<<"5. Adventure: ";
cin >> adventure;
cout<<"6. Relax: ";
cin >> relax;

user->nature = nature; 
user->food = food;
user->culture = culture;
user->nightLife = night;
user->adventure = adventure;
user->relax = relax;

//cout<<"Or press 'q' to quit"<<endl;
}

void Travel::displayPlaces()
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

void Travel::reversePlaces()
{
	placeNode* prev   = NULL;
    placeNode* current = head;
    placeNode* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    head = prev;
}


void Travel::addPlace()
{
		string newLocation;
		cout << "Enter a city to add: ";
		cin.ignore();
		getline(cin, newLocation);

        placeNode* temp1 = head;

        placeNode* added = new placeNode;

        while(temp1->next != NULL){
            temp1 = temp1->next;
        }//end while loop

        temp1->next = added;
        added->next = NULL;
        added->location = newLocation;

        //return head;
}

        
void Travel::removePlace()
{
    string toDelete;
    cout << "Enter a city to delete: ";
    cin.ignore();
    getline(cin, toDelete);
    
    placeNode* temp1 = head;
    
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

void Travel::computePlaceScores()
{
	int placeScore = 0;
	placeNode *temp = head;
	/* To compute the user's individual cityScore for each city, we loop through all the cities
	 * in the linked list and multiply whatever score that city got by the score the user gave as 
	 * a preferance for that characteristic. For example, a city with a nature score of 10 and a user
	 * nature score of 10 will contribute 100 points to the cityScore.  If that user gave a nature score 
	 * of 1, that would only contribute 10 points to that city's cityScore.
	 * */
	while(temp != NULL)
	{
		placeScore += (temp->nature * user->nature);
		placeScore += (temp->food * user->food);
		placeScore += (temp->culture * user->culture);
		placeScore += (temp->nightLife * user->nightLife);
		placeScore += (temp->adventure * user->adventure);
		placeScore += (temp->relax * user->relax);
		temp->cityScore = placeScore;
		
		placeScore = 0;
		temp = temp->next;
	}
		
}

void Travel::sortPlaceScores()
{
	  struct sortInfo{
		int score;
		string name;
	};

	sortInfo scoreArr[21];
	placeNode *temp1 = head;
    
	//for loop reads scores into an unsorted array
	int k = 0;
	while(temp1 != NULL)
	{
		scoreArr[k].score = temp1->cityScore;
		scoreArr[k].name = temp1->location;
		
		temp1 = temp1->next;
		k++;
	}

	//beginning of selection sort algorithm
	sortInfo *numbers = &scoreArr[0];
	int arraySize = (k-1);
    int index;
    for(int i = 1; i < arraySize; i++){
        index = numbers[i].score;
        int j = i;
        while((j > 0) && (numbers[j - 1].score > index)){
            numbers[j] = numbers[j - 1];
            j = j - 1;
        }
        numbers[j].score = index;
    }

    //now scoreArr is sorted in increasing order
    //cout the city name followed by its score in decreasing order
    cout << "Your best cities: " << endl;
    for(int i = 9; i >= 0; i--)
    {
		cout << scoreArr[i].name << ": " << scoreArr[i].score << endl;
	}
}
