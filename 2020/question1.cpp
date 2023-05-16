#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int time, weight = 0;

    cin >> time;

    int *list = new int[time];

    for (int i = 0; i < time; i++)
    {
        int price, amount;
        cin >> price;
        cin >> amount;

        list[i] = price * amount;
    }

    sort(list, list + time);

    for (int i = 0; i < time; i++)
    {
        weight += list[i];

        if (weight > 10000)
        {
            cout << "중량초과" << endl;
            break;
        }

        cout << weight << endl;
    }

    delete[] list;
}