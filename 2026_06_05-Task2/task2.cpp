#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int findMedian(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int low = INT_MAX;
    int high = INT_MIN;

    for (int i = 0; i < rows; i++) {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][cols - 1]);
    }

    int target = (rows * cols + 1) / 2;

    while (low < high) {
        int mid = (low + high) / 2;
        int total = 0;

        for (int i = 0; i < rows; i++) {
            total += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (total < target)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    cout << "Median = " << findMedian(matrix) << endl;

    return 0;
}