#include <iostream>
#include <stack>
#include <vector>

void printNGE(const std::vector<int>& arr) {
    std::stack<int> st;
    std::vector<int> nge(arr.size(), -1);

    for (int i = arr.size() - 1; i >= 0; --i) {
        //iterate left to right cause then the biggest element will always be in a checked state
        while (!st.empty() && arr[i] >= st.top()) {
            st.pop();
        }

        if (!st.empty()) {
            nge[i] = st.top();
        }

        st.push(arr[i]);
    }

    // Print the NGE for each element
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << nge[i] << std::endl;
    }
}

int main() {
    std::vector<int> arr;
    int num;

    while (std::cin >> num && num != -1) {
        arr.push_back(num);
    }

    printNGE(arr);

    return 0;
}
