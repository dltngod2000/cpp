#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
#include <sstream>
#include <fstream>

using namespace std;

// Cost of materials for the remodel
const float PAINTCOST = 0.50;     // per square foot
const float WALLPAPERCOST = 2.00; // per square foot
const float CARPETCOST = 4.00;    // per square foot
const float TILECOST = 5.50;      // per square foot
const float WOODCOST = 6.00;      // per square foot

void printpointProduct(int a, int b, int *c);
void printProduct(int m1, int m2, int product);
void printpointProduct2(int a, int b, int &product3);
int search(int *array, int size, int searchKey);
/*The header file for main.cpp
**This file has functions called from main.
*/
void getUserInformation(string &userName, string &phoneNumber, string &userAddress);
string getRoomChoice();
int getTaskAssignment();
void printTask(int task);
void getRoomInformation(int task, float &roomWidth, float &roomDepth, float &roomHeight);
void printJobInformation(string userName, string phoneNumber, string userAddress, string remodelRoom, int task);
float calcWallSurfaceArea(float roomWidth, float roomDepth, float roomHeight);
float calcPaintCost(float wallSurfaceArea);
float calcWallPaperCost(float wallSurfaceArea);
void printWallCostComparisons(float paintCost, float wallpaperCost);
float calcFloorArea(float roomWidth, float roomDepth);
float calcCarpetCost(float floorArea);
float calcTileCost(float floorArea);
float calcWoodFloor(float floorArea);
void printFloorCostComparisons(float carpetCost, float tileCost, float woodFloorCost);

void getUserInformation(string &userName, string &phoneNumber, string &userAddress)
{
    std::cout << "Customer Name: \n";
    getline(cin, userName);

    std::cout << "Customer Phone Number: \n";
    getline(cin, phoneNumber);

    std::cout << "Customer Address: \n";
    getline(cin, userAddress);
}

string getRoomChoice()
{ // We don't do anything with this information in the program
    string room;
    cout << "What room are we remodeling?: \n";
    getline(std::cin, room);
    return room;
}

int getTaskAssignment()
{ // the possible task list
    // enum task {paint, wallpaper, carpet, tile, woodFloor};
    int task;
    std::cout << "What job needs to be done?\n";
    std::cout << "0: Wallpaper\n";
    std::cout << "1: Paint\n";
    std::cout << "2: Carpet\n";
    std::cout << "3: Tile\n";
    std::cout << "4: Wood Floor\n";
    cin >> task;
    return task;
}

void printTask(int task)
{ // depending on which task was selected, print the corresponding string
    switch (task)
    {
    case 0:
        std::cout << " paint ";
        break;
    case 1:
        std::cout << " wallpaper ";
        break;
    case 2:
        std::cout << " carpet ";
        break;
    case 3:
        std::cout << " tile ";
        break;
    case 4:
        std::cout << " wood floor ";
        break;
    default:
        std::cout << " Ivalid task ";
    }
}

void getRoomInformation(int task, float &roomWidth, float &roomDepth, float &roomHeight)
{ // all the tasks require the width and depth.
  // wall treatments require the height also
    std::cout << "What is the room width? \n";
    std::cin >> roomWidth;
    std::cout << "What is the room depth? \n";
    std::cin >> roomDepth;
    if (task == 0 or task == 1)
    {
        std::cout << "What is the room height? \n";
        std::cin >> roomHeight;
    }
}

void printJobInformation(string userName, string phoneNumber, string userAddress, string remodelRoom, int task)
{ // print user information. This is the only place the
  // remodel room string is used
    cout << "\n\nPreparing order for:\n\n"
         << userName << "\n";
    cout << "\t" << phoneNumber << "\n";
    cout << "\t" << userAddress << "\n";
    cout << "\t"
         << "Remodeling the " << remodelRoom << " with";
    printTask(task);
}

float calcWallSurfaceArea(float roomWidth, float roomDepth, float roomHeight)
{
    // Calculate the wall surface area. Assume the room is rectangluar
    // Assume the two walls opposite each other are the same
    float wallWide = roomWidth * roomHeight * 2; // two walls
    float wallDeep = roomDepth * roomHeight * 2; // two walls
    return wallWide + wallDeep;
}

float calcPaintCost(float wallSurfaceArea)
{ // cost estimates are simply surface area times material per sq. foot
    return PAINTCOST * wallSurfaceArea;
}

float calcWallPaperCost(float wallSurfaceArea)
{ // cost estimates are simply surface area times material per sq. foot
    return WALLPAPERCOST * wallSurfaceArea;
}

void printWallCostComparisons(float paintCost, float wallpaperCost)
{ // print the estimates for the wall coverings
    std::cout << "\nPaint Estimate: " << paintCost << "\n\n ";
    std::cout
        << "Wallpaper Estimate: " << wallpaperCost << "\n\n";
}

float calcFloorArea(float roomWidth, float roomDepth)
{
    return roomWidth * roomDepth;
}
float calcCarpetCost(float floorArea)
{ // cost estimates are simply surface area times material per sq. foot
    return CARPETCOST * floorArea;
}
float calcTileCost(float floorArea)
{ // cost estimates are simply surface area times material per sq. foot
    return TILECOST * floorArea;
}
float calcWoodFloor(float floorArea)
{ // cost estimates are simply surface area times material per sq. foot
    return WOODCOST * floorArea;
}
void printFloorCostComparisons(float carpetCost, float tileCost, float woodFloorCost)
{ // print the estimates for the floor coverings
    cout << "\n\t\tCarpet Estimate: " << carpetCost;
    cout << "\n\t\tTile Estimate: " << tileCost;
    cout << "\n\t\tWood Estimate: " << woodFloorCost;
}

/*******************************/

void printpointProduct2(int a, int b, int &product3)
{
    product3 = a * b;
    std::cout << a << " * " << b << " = " << product3 << "\n";
}

void printpointProduct(int a, int b, int *c)
{
    *c = a * b;
    std::cout << "\n"
              << a << "*" << b << "=" << *c << "\n";
}

void printProduct(int m1, int m2, int product)
{
    product = m1 * m2;
    std::cout << m1 << " * " << m2 << " = " << product << "\n";
}

int search(int *array, int size, int searchKey)
{

    int found = -1;
    for (int i = 0; i < size; i++)
    {
        if (array[i] == searchKey)
        {
            found = i;
        }
    }
    return found;
}
