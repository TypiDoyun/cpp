#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string data, string word)
{
    vector<string> output;
    int end = data.find(word);

    if (end == -1)
    {
        output.push_back(data);
        return output;
    }

    while (end != -1)
    {
        output.push_back(data.substr(0, end));
        data.erase(data.begin(), data.begin() + end + 1);
        end = data.find(word);
    }

    output.push_back(data.substr(0));

    return output;
}

int main()
{
    string timeTemplate;
    vector<string> dateVector;
    int n, speed, h, m, s;

    cin >> n;

    double distance = 0, time = 0;

    for (int repeat = 0; repeat < n; repeat++)
    {
        cin >> speed;
        cin >> timeTemplate;

        dateVector = split(timeTemplate, ":");

        h = stoi(dateVector.at(0));
        m = stoi(dateVector.at(1));
        s = stoi(dateVector.at(2));

        time += (h + (m * (1 / 60.0)) + (s * (1 / 3600.0)));

        distance += speed * (h + (m * (1 / 60.0)) + (s * (1 / 3600.0)));
    }

    double avg = distance / time;

    printf("%.2lf", avg);
}