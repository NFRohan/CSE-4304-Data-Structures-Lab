#include <iostream>
using namespace std;
int main()
{
    int numberSoldier{0}, numRounds{0}, heroPower{0}, killedPowerSum{0}, numKilled{0}, powerSoldier[1024] = {0};
    cin >> numberSoldier >> numRounds;

    for (int i = 0; i < numberSoldier; i++)
    {
        cin >> powerSoldier[i];
    }

    
    while (numRounds != 0)
    {
        cin >> heroPower;
        numRounds--;

        for (int j = 0; j < numberSoldier; j++)
        {
            if (heroPower >= powerSoldier[j])
            {
                numKilled++;
            }
        }
        cout << numKilled << endl;
        numKilled = 0;
        killedPowerSum = 0;
    }
}