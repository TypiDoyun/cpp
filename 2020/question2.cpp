#include <iostream>
#include <algorithm>
#include <array>
#include <string>

using namespace std;

template <size_t S>
int find(array<string, S> list, string x)
{
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].compare(x) == 0)
            return i;
    }
    return -1;
}

int main(void)
{
    int time;
    array<string, 12> keyMap = {"A", "AS", "B", "C", "CS", "D", "DS", "E", "F", "FS", "G", "GS"};

    cin >> time;
    int *indexList = new int[time];
    int *octaveList = new int[time];

    cout << fixed;
    cout.precision(2);

    for (int i = 0; i < time; i++)
    {
        int octave;
        string key;

        cin >> octave;
        cin >> key;

        octaveList[i] = octave;
        indexList[i] = find(keyMap, key);
    }

    for (int i = 0; i < time; i++)
    {

        if (indexList[i] == -1)
        {
            cout << "입력 오류" << endl;
            continue;
        }

        float hz = 440 * pow(pow(2, 1 / 12.0), ((octaveList[i] - 4) * 12) + indexList[i]);

        cout << hz << endl;
    }

    delete[] octaveList;
    delete[] indexList;
}