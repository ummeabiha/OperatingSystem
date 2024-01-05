#include <stdio.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int req_size = 8;
int disk_size = 200;

void CSCAN(int array[], int initial_head)
{
    int seek_operations = 0;
    int distance, cur_track;
    vector<int> left, right;
    vector<int> seek_sequence;
    left.push_back(0);
    right.push_back(disk_size - 1);

    for (int i = 0; i < req_size; i++)
    {
        if (array[i] < initial_head)
            left.push_back(array[i]);
        if (array[i] > initial_head)
            right.push_back(array[i]);
    }

    std::sort(left.begin(), left.end());
    std::sort(right.begin(), right.end());
    for (int i = 0; i < right.size(); i++)
    {
        cur_track = right[i];
        seek_sequence.push_back(cur_track);
        distance = abs(cur_track - initial_head);
        seek_operations += distance;
        initial_head = cur_track;
    }

    initial_head = 0;
    seek_operations += (disk_size - 1);
    for (int i = 0; i < left.size(); i++)
    {
        cur_track = left[i];
        seek_sequence.push_back(cur_track);
        distance = abs(cur_track - initial_head);
        seek_operations += distance;
        initial_head = cur_track;
    }
    cout << "Total number of seek operations = " << seek_operations << endl;
    cout << "Seek Sequence is" << endl;
    for (int i = 0; i < seek_sequence.size(); i++)
    {
        cout << seek_sequence[i] << endl;
    }
}

int main()
{
    int array[req_size] = {176, 79, 34, 60, 92, 11, 41, 114};
    int initial_head = 50;
    cout << "Initial position of head: " << initial_head << endl;
    CSCAN(array, initial_head);
}
