int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int rows = matSize;
    int cols = matColSize[0];

    if (rows * cols != r * c) {
        *returnSize = rows;
        *returnColumnSizes = malloc(rows * sizeof(int));
        for (int i = 0; i < rows; i++) {
            (*returnColumnSizes)[i] = cols;
        }
        return mat;
    }

    *returnSize = r;
    *returnColumnSizes = malloc(r * sizeof(int));

    int** result = malloc(r * sizeof(int*));
    for (int i = 0; i < r; i++) {
        result[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    int count = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[count / c][count % c] = mat[i][j];
            count++;
        }
    }

    return result;
}