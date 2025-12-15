#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <iostream>
#include <fstream>
#include <vector>

class AdjMatrix {
private:
    std::vector<std::vector<int>> matrix;
    int numVertices;

public:
    // Constructor
    AdjMatrix() : numVertices(9) {
        matrix.resize(numVertices, std::vector<int>(numVertices, 0));
    }

    // Add edge to the adjacency matrix
    void addEdge(int source, int dest, int weight) {
        matrix[source][dest] = weight;
    }

    // Print the adjacency matrix
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            for (int j = 0; j < numVertices; ++j) {
                std::cout << matrix[i][j];
                if (j < numVertices - 1) std::cout << " ";
            }
            std::cout << std::endl;
        }
    }

    // Output graph to a .dot file
    void outputGraph(const std::string& ofname) {
        std::ofstream ofs(ofname);
        ofs << "digraph G {\n";

        for (int i = 0; i < numVertices; ++i) {
            bool hasOutgoingEdges = false;
            for (int j = 0; j < numVertices; ++j) {
                if (matrix[i][j] != 0) {
                    ofs << "  " << i << " -> " << j
                        << " [label=\"" << matrix[i][j] << "\"];\n";
                    hasOutgoingEdges = true;
                }
            }
            // Add isolated node explicitly
            if (!hasOutgoingEdges) {
                ofs << "  " << i << ";\n";
            }
        }

        ofs << "}\n";
        ofs.close();
    }
};

#endif // ADJACENCY_MATRIX_H


