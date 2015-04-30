#ifndef TRAVEL_H
#define TRAVEL_H
# include <string>
# include <iostream>
# include <cstring>


struct placeNode{
    std::string location;
    int nature;
    int food;
    int culture;
    int nightLife;
    int adventure;
    int relax;
	int cityScore;
    placeNode *next = NULL;
    //placeNode *previous = NULL;

};

struct userPref{
	int nature;
    int food;
    int culture;
    int nightLife;
    int adventure;
    int relax;
};

struct sortInfo{
	int score;
	std::string name;
};


class Travel
{
    public:
        Travel();
        virtual ~Travel();

        void readIn(std::string location, int nature, int food, int culture, int nightLife, int adventure, int relax);
        void displayMenu();
        void displayPlaces();
        void reversePlaces();
        void addPlace();
        void removePlace();
        void computePlaceScores();
        void sortPlaceScores();
        //void insertionSortValues(int &sizeOfArray, sortInfo &firstElementofArray);
        void insertionSortValues(int sizeOfArray, sortInfo *firstElementofArray);
        
        
        void quickSortValues(sortInfo *arr, int leftIndex, int rightIndex);

    protected:
    private:
        placeNode* head;
        userPref* user;
};

#endif // TRAVEL_H
