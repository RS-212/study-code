#ifndef SECTION_II_HPP
#define SECTION_II_HPP

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

#endif // SECTION_II_HPP