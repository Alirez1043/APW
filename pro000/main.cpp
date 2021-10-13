#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct student{
   std::string na
};

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5, 6};
    a = reverse(a);
    for (int i=0; i < a.size(); i++) {
        std::cout << a[i] << std::endl;
    }

}

std::vector<int> reverse(std::vector<int> numbers) {
    std::vector<int> reversed;
    for (int i = numbers.size() - 1; i >= 0; --i) {
        reversed.push_back(numbers[i]);
    }
    return reversed;
}
