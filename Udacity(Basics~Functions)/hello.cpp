// g++ hello.cpp -o hello.exe && ./hello.exe
#include "header.hpp"

int main()
{
    std::freopen("input.txt", "r", stdin);

    int variableName = 123;
    std::cout << "Hello Wor234235ld!\n"
              << "test"
              << "\n"
              << variableName << "\n";
    std::cout << "int size = " << sizeof(variableName) << std::endl;

    /*const 상수는 변경불가*/
    const int weightGoal = 100;
    std::cout << "WeightGoal = " << weightGoal << "\n";
    // weightGoal = 200; 오류남
    std::cout << "WeightGoal = " << weightGoal << "\n";

    int year;
    std::cout << "What is your favorite year? ";
    std::cin >> year;
    std::cout << year << "\n";
    std::cout << "How interesting, your favorite year is " << year << "!\n";

    /*
    cin은 '\n'를 처리하지 않고 입력버퍼에 남겨둔다.
    geline은 '\n'를 입력버퍼에서 가져와서 처리한다.
    s2에  '\n'가 전달되며 '\n'를 제거 후  s2에 ''을 담기 때문에 s1과 ''이 출력되고 종료된다.

    year에서 cin을 하고 입력버퍼에 '\n'이 남아있고 아래 'std::getline(std::cin, userName);'
    하면서 입력버퍼에 남아있는 '\n'을 username에 전달한다. 따라서 cin 다음에 getline을 같이 사용할거면
    입력버퍼 맨앞 입력을 1개 지워주는 cin.ignore()를 사용할 것.
    반대의 경우는 상관없음
    */
    std::cin.ignore();
    std::string userName2;
    std::cout << "Tell me your nickname?: ";
    std::getline(std::cin, userName2);
    std::cout << userName2 << "\n";
    std::cout << "Hello " << userName2 << "\n";

    std::cout << "3^5 = " << std::pow(3, 5) << std::endl;
    std::cout << M_PI << "\n";

    int coeff1, coeff2, constant;
    int exp1, exp2;
    int y;
    int x;
    // Calculate the value of y for a user defined three term polynomial
    // Get the coefficients, exponents, and the constants
    std::cout << "What is the first coefficient?";
    std::cin >> coeff1;
    std::cout << coeff1 << "\n";
    std::cout << "What is the exponent of the first term?";
    std::cin >> exp1;
    std::cout << exp1 << "\n";
    std::cout << "What is the second coefficient?";
    std::cin >> coeff2;
    std::cout << coeff2 << "\n";
    std::cout << "What is the exponent of the second term?";
    std::cin >> exp2;
    std::cout << exp2 << "\n";
    std::cout << "What is the constant?";
    std::cin >> constant;
    std::cout << constant << "\n";
    // Print the complete equation
    std::cout << "The polynomial we are solving is:\n";
    std::cout << "\t" << coeff1 << "*x^" << exp1 << " + " << coeff2 << "*x^" << exp2 << "+ " << constant;
    std::cout << "\nWhat is the value of x?";
    std::cin >> x;
    std::cout << x << "\n";
    // Solve the equation with the given x
    y = coeff1 * pow(x, exp1) + coeff2 * pow(x, exp2) + constant;
    std::cout << "y = " << coeff1 << "*" << x << "^" << exp1 << " + " << coeff2 << "*" << x << "^" << exp2 << "+ " << constant << " = " << y << "\n";

    char skin, location;
    std::cout << "Would you like an animal with fur(f), feathers(t), or scales(s)?";
    std::cin >> skin;
    std::cout << skin << "\n";

    // Use if-else statements to control program flow
    if (skin == 'f')
    {
        std::cout << "Get a dog"
                  << "\n";
    }
    else if (skin == 't')
    {
        std::cout << "Get a bird"
                  << "\n";
    }
    else if (skin == 's')
    {
        std::cout << "Would you like an animal that lives in water(w), land(l), or both(b)?";
        std::cin >> location;
        std::cout << location << "\n";

        // Use if-else statements to control program flow
        // note that the curly braces are not necessary if there is only
        // one line of code.

        if (location == 'w')
            std::cout << "Get a fish"
                      << "\n";
        else if (location == 'l')
            std::cout << "Get a gecko"
                      << "\n";
        else if (location == 'b')
            std::cout << "Get a frog"
                      << "\n";
        else
            std::cout << "Enter water(w), land(l), or both(b)\n";
    }
    else
        std::cout << "Please choose fur(f), feathers(t), scales(s)"
                  << "\n";

    float in1, in2;
    char operation;
    float answer;

    std::cout << "Enter two numbers:\n";
    std::cin >> in1;
    std::cin >> in2;
    std::cout << "Enter the operation '+','-','*','/':\n";
    std::cin >> operation;

    switch (operation)
    {
    case ('+'):
    {
        answer = in1 + in2;
        break;
    }
    case ('-'):
    {
        answer = in1 - in2;
        break;
    }
    case ('*'):
    {
        answer = in1 * in2;
        break;
    }
    case ('/'):
    {
        answer = in1 / in2;
        break;
    }
    default:
        std::cout << "Illegal operation";
    }

    std::cout << in1 << operation << in2 << " = " << answer << "\n";

    float input;
    float sum = 0;

    for (int i = 0; i < 5; i++)
    {
        std::cout << "What is the next number?\n";
        std::cin >> input;
        sum = sum + input;
    } // end of for loop

    std::cout << "Sum = " << sum << "\n";
    std::cout << "Average = " << sum / 5 << "\n";

    /*The break statement:
    The break statement will end the loop and begin executing the first statement that comes AFTER the end of the loop.
    The continue statement: The continue statement will force the next iteration to be executed.*/

    int *pointerI;
    int number;
    char character;
    char *pointerC;
    std::string sentence;
    std::string *pointerS;

    pointerI = &number;
    *pointerI = 45;

    pointerC = &character;
    *pointerC = 'f';

    pointerS = &sentence;
    *pointerS = "Hey look at me, I know pointers!";

    std::cout << "number = " << number << "\n";
    std::cout << "character = " << character << "\n";
    std::cout << "sentence = " << sentence << "\n";

    int userInput[40];

    // Enter the numbers into an array called userInput
    for (int i = 0; i < 40; i++)
    {
        scanf("%d", &userInput[i]);
        // std::cin >> userInput[i];
    }
    std::cout << *userInput;
    std::cout << "\nThe array\n";
    for (int i = 0; i < 40; i++)
    {
        std::cout << userInput[i] << " ";
    }

    int m1 = 4;
    int m2 = 5;
    int product = 0;
    int *pt = &product;
    int product2 = 0;
    // product = m1 * m2;
    int product3 = 0;

    printpointProduct(m1, m2, pt);
    printProduct(m1, m2, product2);
    printpointProduct2(m1, m2, product3);
    std::cout
        << *pt << "\n"
        << product2 << "\n"
        << product3 << "\n";

    const int size = 4;
    int array[] = {345, 75896, 2, 543};
    int searchKey = 543;
    std::cout << "Found at: " << search(array, size, searchKey) << "\n";

    /***********************************************/

    // user information
    string userName = " ";
    string phoneNumber = " ";
    string userAddress = " ";
    string remodelRoom = " ";
    float roomWidth = 0;
    float roomDepth = 0;
    float roomHeight = 0;
    float wallSurfaceArea = 0;
    float floorArea = 0;
    int task = 0;

    // estimate variables
    int paintCost = 0;
    int wallpaperCost = 0;
    int carpetCost = 0;
    int tileCost = 0;
    int woodFloorCost = 0;

    // the possible task list
    enum task
    {
        paint,
        wallpaper,
        carpet,
        tile,
        woodFloor
    };

    getUserInformation(userName, userAddress, phoneNumber);
    remodelRoom = getRoomChoice();
    task = getTaskAssignment();

    getRoomInformation(task, roomWidth, roomDepth, roomHeight);

    // print the information of the user and room
    printJobInformation(userName, phoneNumber, userAddress, remodelRoom, task);

    // If a wall treatment is to be done, get the wall surface area
    // assume all four walls of the room are to be redone
    if (task == paint || task == wallpaper)
    {
        // calculate and print the estimates
        wallSurfaceArea = calcWallSurfaceArea(roomWidth, roomDepth, roomHeight);
        paintCost = calcPaintCost(wallSurfaceArea);
        wallpaperCost = calcWallPaperCost(wallSurfaceArea);
        printWallCostComparisons(paintCost, wallpaperCost);
    }

    // if a floor is to be done, get the square footage of the room
    if (task == carpet or task == tile or task == woodFloor)
    {
        // calculate and print the estimates
        floorArea = calcFloorArea(roomWidth, roomDepth);
        carpetCost = calcCarpetCost(floorArea);
        tileCost = calcTileCost(floorArea);
        woodFloorCost = calcWoodFloor(floorArea);
        printFloorCostComparisons(carpetCost, tileCost, woodFloorCost);
    }
    return 0;
}