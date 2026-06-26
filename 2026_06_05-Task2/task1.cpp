#include <iostream>
#include <vector>
using namespace std;

void rotateMatrix(vector<vector<int>>& mat) {
    int top = 0;
    int left = 0;
    int bottom = mat.size();
    int right = mat[0].size();

    while (top < bottom && left < right) {

        if (top + 1 == bottom || left + 1 == right)
            break;

        int previous = mat[top + 1][left];
        int current;

        for (int i = left; i < right; i++) {
            current = mat[top][i];
            mat[top][i] = previous;
            previous = current;
        }
        top++;

        for (int i = top; i < bottom; i++) {
            current = mat[i][right - 1];
            mat[i][right - 1] = previous;
            previous = current;
        }
        right--;

        for (int i = right - 1; i >= left; i--) {
            current = mat[bottom - 1][i];
            mat[bottom - 1][i] = previous;
            previous = current;
        }
        bottom--;

        for (int i = bottom - 1; i >= top; i--) {
            current = mat[i][left];
            mat[i][left] = previous;
            previous = current;
        }
        left++;
    }
}

int main() {

    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    rotateMatrix(mat);

    for (auto row : mat) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}