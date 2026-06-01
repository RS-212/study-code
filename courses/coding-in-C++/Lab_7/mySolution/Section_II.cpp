#include <iostream>
#include <vector>

#include "Section_II.hpp"

AdjacencyMatrix::AdjacencyMatrix(int size)
: matrix_size(size), matrixVector(size, std::vector<int>(size, 0))
{}

void AdjacencyMatrix::setEdge(int from, int to, int weight)
{
    if ((from > (matrix_size - 1) || to > (matrix_size - 1)) || (from < 0 || to < 0))
    {
        std::cout << "Invalid nodes! (" << from << "," << to << ")" << std::endl;
        return;
    }

    this->matrixVector[from][to] = weight;
}

int AdjacencyMatrix::getWeight(int from, int to) const
{
    constexpr int NO_EDGE = 0;

    // Validity check
    if ((from > (matrix_size - 1) || to > (matrix_size - 1)) || (from < 0 || to < 0))
    {
        std::cout << "Invalid nodes! (" << from << "," << to << ")" << std::endl;
        return NO_EDGE;
    }
    if (matrixVector[from][to] == NO_EDGE)
    {
        std::cout << "No edge weight, because there is no edge there!" << std::endl;
        return NO_EDGE;
    }

    return matrixVector[from][to];
}

void AdjacencyMatrix::printMatrix() const
{
    for(int i = 0; i < matrix_size; i++)
    {
        std::cout << "[ ";
        for(int j = 0; j < matrix_size; j++)
        {
            std::cout << matrixVector[i][j] << " ";
        }
        std::cout << "]\n";
    }
    std::cout << std::endl;
}

int main()
{
    constexpr int SIZE = 3;
    AdjacencyMatrix matrix(SIZE);

    // Configure graph
    matrix.setEdge(0, 1, 1); // A -> B
    matrix.setEdge(0, 2, 2); // A -> C
    matrix.setEdge(1, 0, 3); // B -> A
    matrix.setEdge(1, 2, 4); // B -> C
    matrix.setEdge(2, 0, 5); // C -> A
    matrix.setEdge(2, 1, 6); // C -> B

    matrix.printMatrix();

    std::cout << "Weight at edge A -> B: " << matrix.getWeight(0, 1) << std::endl;

    // Current downsides (fixed size approach):
    // The matrix cannot be resized
    // Stores more data than needed in an undirected graph
    // Setting every element manually is tedious and error prone

    // Current downsides (vector)
    // Still uses way more storage space than needed!
    // Edges that don't exist need storage (O(n²) space complexity)

    return 0;
}