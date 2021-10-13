#include <iostream>
#include <vector>

using namespace std;

vector<int> reverse(vector<int>);
void getValue(vector<int> &);

int main() {
    vector<int> a;
    getValue(a);
    a = reverse(a);
    for (int i=0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
}

vector<int> reverse(vector<int> numbers) {
    vector<int> reversed;
    for (int i = numbers.size() - 1; i >= 0; --i) {
        reversed.push_back(numbers[i]);
    }
    return reversed;
}

void getValue(vector<int> &vec){
	int number;
	while (cin >> number){
		vec.push_back(number);
	}
}



