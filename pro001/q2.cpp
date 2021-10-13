#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void reverse(vector<int> &);
void getValue(vector<int> &);

int main() {
    vector<int> numbers;
    getValue(numbers);
    reverse(numbers);
    for (int i=0; i < numbers.size(); i++) {
        cout << numbers[i] << endl;
    }
}

void reverse(vector<int> &numbers) {
    int end = numbers.size() -1 ;
    int start = 0;
    while(end > start){
    	swap(numbers[end--], numbers[start++]);
	}
}

void getValue(vector<int> &vec){
	int number;
	while (cin >> number){
		vec.push_back(number);
	}
}

