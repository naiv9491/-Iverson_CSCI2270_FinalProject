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
	
class Travel
{
    public:
        Travel();
        virtual ~Travel();

        void readIn(std::string location, int nature, int food, int culture, int nightLife, int adventure, int relax);
        void displayMenu();

    protected:
    private:
        placeNode* head;
};

#endif // TRAVEL_H
