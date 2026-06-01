#include <vector>

class AdjacencyMatrix
{
private:
    int matrix_size;
    std::vector<std::vector<int>> matrixVector;

public:

    AdjacencyMatrix(int size);

    void setEdge(int from, int to, int weight);
    int getWeight(int from, int to) const;
    void printMatrix() const;
};