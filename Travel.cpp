#include "Travel.h"
using namespace std;



Travel::Travel()
{
	//creating two pointers that we'll use later on
    head = NULL;
    user = NULL;
}

Travel::~Travel()
{
    //dtor
}

//Function reads in values from text file and stores them in a linked list
//First in main.cpp we loop through each line of the text file called locations.txt and store them in variables,
//which are passed to the Travel function below
void Travel::readIn(string location, int nature, int food, int culture, int nightLife, int adventure, int relax){

//Special case for reading in first line of text file (assigning values to head pointer):
    if(head == NULL){
        head = new placeNode;
        head->location = location;
        head->nature = nature;
        head->food = food;
        head->culture = culture;
        head->nightLife = nightLife;
        head->adventure = adventure;
        head->relax = relax;
    }
    else{
//For all other lines in text create a node with all of the components
        placeNode* currentNode = new placeNode;

        currentNode->location = location;
        currentNode->nature = nature;
        currentNode->food = food;
        currentNode->culture = culture;
        currentNode->nightLife = nightLife;
        currentNode->adventure = adventure;
        currentNode->relax = relax;

        placeNode* cursor = head;

        while(cursor->next != NULL){
            cursor = cursor->next;
        }
        cursor->next = currentNode;
    }

}

//This is the second menu which is called in option 1. Here, we provide the environmental components for the user to rank.
//We store these rankings in a new pointer called "user". Then we implement the "user" pointer in a function later on called computePlaceScores.
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

}

//Print the locations in linked list.
void Travel::displayPlaces()
{
    placeNode* temp = new placeNode;
    temp = head;
    while(temp->next != NULL){
        cout << temp->location;
        cout<<" -> ";
        temp=temp->next;
    }//end while
    cout << temp->location;
    cout << endl;
}

//We reverse the linked list here. Therefore, when you call the displayPlaces function again, it will print the locations in reverse order.
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

//This function allows the user add a new location and rank each environmental component
void Travel::addPlace()
{
		string newLocation;
		int nature = 0;
		int food = 0;
		int culture = 0;
		int night = 0;
		int adventure = 0;
		int relax = 0;


		cout << "Enter a city to add: ";
		cin.ignore();
		getline(cin, newLocation);

		cout<<"Please rank the location's environmental components from 1 to 10,"<<endl;
		cout<<"10 being the most representative of the location."<<endl;
		cout<<"For example, if you added New York City, you would give food and night life a 10,"<<endl;
		cout<<"while nature would be closer to a 1"<<endl;

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



        placeNode* temp1 = head;

        placeNode* added = new placeNode;

        while(temp1->next != NULL){
            temp1 = temp1->next;
        }//end while loop

        temp1->next = added;
        added->next = NULL;
        added->location = newLocation;
        added->nature = nature;
        added->food = food;
        added->culture = culture;
        added->nightLife = night;
        added->adventure = adventure;
        added->relax = relax;

        //return head;
}

//This function allows the user to remove a location from the list
void Travel::removePlace()
{
    string toDelete;
    cout << "Enter a city to delete: ";
    cin.ignore();
    getline(cin, toDelete);

    placeNode* temp1 = head;

    placeNode* n = new placeNode;
    n = temp1->next;

    //searching for location to delete
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

//Takes the user's score (preferences) and matches it to the rankings already stored for each location to give the best locations for the user to visit
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

//This function uses the computed place score and reorders the linked list from best to worst, displaying the top 9 destinations
void Travel::sortPlaceScores()
{
	sortInfo scoreArr[25]; //I wonder about using a vector here in case we have added/removed cities
	placeNode *temp1 = head;

	//for loop reads scores into an unsorted array
	int k = 0;
	cout << endl;
	cout << "=========================================================================\n";
	cout << "These are the cities on are list and your personal travel scores for them.\n";
	cout << "The higher the score, the more you want to go there.\n";
	while(temp1 != NULL)
	{
		scoreArr[k].name = temp1->location;
		cout << scoreArr[k].name << " : ";
        scoreArr[k].score = temp1->cityScore;
		cout << scoreArr[k].score << endl;
		temp1 = temp1->next;
		k++;
	}
	int answer = 0;
	cout << "==================================\n";
	while(answer != 1 && answer != 2)
	{
		cout << "\n" << "Would you like to: \n" << "1. Sort using insertion sort\n" << "2. Sort using QuickSort\n";
		cin >> answer;
	}
	//choose your own adventure! (a.k.a sorting algorithm)
	if(answer == 1)
		insertionSortValues(k, &scoreArr[0]);
	else if(answer == 2){
		sortInfo *first = &scoreArr[0];
		quickSortValues(first, 0, k);
	}

    //now scoreArr is sorted in increasing order
    //cout the city name followed by its score in decreasing order
    cout << "===============================\n";
    cout << "Your top 10 cities on our list: " << endl;
    for(int i = k-1; i > k-10; i--)
    {
		cout << scoreArr[i].name << ": " << scoreArr[i].score << endl;
	}
}

//Implements the insertion sort algorithm
void Travel::insertionSortValues(int sizeOfArray, sortInfo *firstElementofArray)
{
	sortInfo *numbers = firstElementofArray;

	int arraySize = sizeOfArray;
    sortInfo index;
    for(int i = 1; i < arraySize; i++){
        index = numbers[i];
        int j = i;
        while((j > 0) && (numbers[j - 1].score > index.score)){
            numbers[j] = numbers[j - 1];
            j = j - 1;
        }
        numbers[j] = index;
    }
}

//Implements the quick sort algorithm
void Travel::quickSortValues(sortInfo *arr, int leftIndex, int rightIndex)
{
	//int *arr, int left, int right){
     int i = leftIndex;
     int j = rightIndex;
     sortInfo tmp;
     int pivot = arr[(i + j) / 2].score;
     while(i <= j){
          while(arr[i].score < pivot)
               i++;
          while(arr[j].score > pivot)
               j--;
          if(i <= j){
               tmp = arr[i];
               arr[i] = arr[j];
               arr[j] = tmp;
               i++;
               j--;
          }
     }
     if (leftIndex < j)
          quickSortValues(arr, leftIndex, j);
     if (i < rightIndex)
          quickSortValues(arr, i, rightIndex);
}


/*Notes:

Should probably have quickSort and insertionSort before the function we call it in (so codeblocks knows that the functions have been written)
The & and * in the arguments of the quickSort and insertionSort functions should be modified to match the .h file

*/
