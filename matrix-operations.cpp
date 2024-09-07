#include <iostream>
#include <vector>
using namespace std;

void inputMatrix(vector<vector<int>>& matrix, int rows, int cols) {
    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }
}
vector<vector<int>> multiplyMatrices(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, int rows1, int cols1, int cols2) {
    vector<vector<int>> result(rows1, vector<int>(cols2, 0));
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

int main() {
    int rows1, cols1, rows2, cols2;
    cout << "Enter dimensions of the first matrix (rows cols): ";
    cin >> rows1 >> cols1;
    cout << "Enter dimensions of the second matrix (rows cols): ";
    cin >> rows2 >> cols2;
    if (cols1 != rows2) {
        cout << "Error: Number of columns in the first matrix must be equal to the number of rows in the second matrix." << endl;
        return 1;
    }
    vector<vector<int>> matrix1(rows1, vector<int>(cols1));
    vector<vector<int>> matrix2(rows2, vector<int>(cols2));
    cout << "First matrix:" << endl;
    inputMatrix(matrix1, rows1, cols1);
    cout << "Second matrix:" << endl;
    inputMatrix(matrix2, rows2, cols2);
    vector<vector<int>> resultMatrix = multiplyMatrices(matrix1, matrix2, rows1, cols1, cols2);
    cout << "First matrix:" << endl;
    printMatrix(matrix1);
    cout << "Second matrix:" << endl;
    printMatrix(matrix2);
    cout << "Result matrix:" << endl;
    printMatrix(resultMatrix);
    return 0;
}
