
#include <iostream>

using namespace std;

int main()
{
    unsigned char half_limit = 150;

    // Hint to the answer: run this code as is.
    // then uncomment the line below. What happens?
    // cout<<"half_limit = "<<half_limit<<"\n";
    int count = 0;
    cout << "i = \n";
    for (unsigned char i = 0; i < 2 * half_limit; ++i) // unsinged char  최댓값은 255 따라서 무한루프
    {
        count++;
        cout << "\n"
             << count;
    }

    return 0;
}
