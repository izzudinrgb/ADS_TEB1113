#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangle(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    vector<vector<int>> width(rows, vector<int>(cols, 0));
    int maxArea = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {

            if (matrix[i][j] == 0)
                continue;

            // Count consecutive 1's to the left
            width[i][j] = (j == 0) ? 1 : width[i][j - 1] + 1;

            int minWidth = width[i][j];

            // Check rectangles ending at (i, j)
            for (int k = i; k >= 0; k--) {
                minWidth = min(minWidth, width[k][j]);
                maxArea = max(maxArea, minWidth * (i - k + 1));
            }
        }
    }

    return maxArea;
}

int main() {

    vector<vector<int>> matrix = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 0},
        {1, 1, 0, 0}
    };

    cout << "Maximum Area = " << largestRectangle(matrix) << endl;

    return 0;
}