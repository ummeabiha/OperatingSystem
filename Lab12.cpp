#include <bits/stdc++.h>
using namespace std;
int size = 8, disk_size = 200;
void CLOOK(int arr[], int head){
    int seek_count = 0, distance, cur_track;
    vector<int> left, right, seek_sequence;
    for (int i = 0; i < size; i++)
        (arr[i] < head) ? left.push_back(arr[i]) : right.push_back(arr[i]);
    sort(left.begin(), left.end());
    sort(right.begin(), right.end());
    for (int i = 0; i < right.size(); i++) {
        cur_track = right[i];
        seek_sequence.push_back(cur_track);
        seek_count += abs(cur_track - head);
        head = cur_track;}
    seek_count += abs(head - left[0]);head = left[0];
    for (int i = 0; i < left.size(); i++){
        cur_track = left[i];
        seek_sequence.push_back(cur_track);
        seek_count += abs(cur_track - head);
        head = cur_track;}
    cout << "Total number of seek operations = " << seek_count << endl<<"Seek Sequence is" << endl;
    for (int i = 0; i < seek_sequence.size(); i++) cout << seek_sequence[i] << endl;}
int main(){
    int arr[size] = {176, 79, 34, 60, 92, 11, 41, 114}; int head = 50;
    CLOOK(arr, head);}
