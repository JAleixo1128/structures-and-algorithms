#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <string>
#include <utility> // for std::pair

class AdjList {
private:
    std::vector<std::list<std::pair<int, int>>> adjList;
    int numVertices;

public:
    // Constructor
    AdjList() : numVertices(9) {
        adjList.resize(numVertices);
    }

    // Add edge to the adjacency list
    void addEdge(int source, int dest, int weight) {
        adjList[source].emplace_back(dest, weight);
    }

    // Print the adjacency list
    void printGraph() {
        for (int i = 0; i < numVertices; ++i) {
            std::cout << i << " -> ";
            if (adjList[i].empty()) {
                std::cout << "None";
            } else {
                for (const auto& [neighbor, weight] : adjList[i]) {
                    std::cout << "(" << neighbor << ", " << weight << ") ";
                }
            }
            std::cout << std::endl;
        }
    }

    // Problem 1: Basic adjacency list visualization
    void problem1(const std::string& ofname) {
        std::ofstream ofs(ofname);
        ofs << "digraph G {\n";

        for (int i = 0; i < numVertices; ++i) {
            bool hasOutgoingEdges = false;
            for (const auto& [neighbor, weight] : adjList[i]) {
                ofs << "  " << i << " -> " << neighbor
                    << " [label=\"" << weight << "\"];\n";
                hasOutgoingEdges = true;
            }
            if (!hasOutgoingEdges) {
                ofs << "  " << i << ";\n";
            }
        }

        ofs << "}\n";
        ofs.close();
    }

    // Problem 2: Even/odd weight coloring
    void problem2(const std::string& ofname) {
        std::ofstream ofs(ofname);
        ofs << "digraph G {\n";

        for (int i = 0; i < numVertices; ++i) {
            bool hasOutgoingEdges = false;
            for (const auto& [neighbor, weight] : adjList[i]) {
                std::string color = (weight % 2 == 0) ? "blue" : "red";
                ofs << "  " << i << " -> " << neighbor
                    << " [label=\"" << weight << "\" color=\"" << color << "\"];\n";
                hasOutgoingEdges = true;
            }
            if (!hasOutgoingEdges) {
                ofs << "  " << i << ";\n";
            }
        }

        ofs << "}\n";
        ofs.close();
    }

    // Problem 3: Color edges based on position in adjacency list
    void problem3(const std::string& ofname) {
        static const std::string colors[] = {"green", "blue", "red", "purple"};
        std::ofstream ofs(ofname);
        ofs << "digraph G {\n";

        for (int i = 0; i < numVertices; ++i) {
            int position = 0;
            bool hasOutgoingEdges = false;
            for (const auto& [neighbor, weight] : adjList[i]) {
                std::string color = colors[position % 4];
                ofs << "  " << i << " -> " << neighbor
                    << " [label=\"" << weight << "\" color=\"" << color << "\"];\n";
                ++position;
                hasOutgoingEdges = true;
            }
            if (!hasOutgoingEdges) {
                ofs << "  " << i << ";\n";
            }
        }

        ofs << "}\n";
        ofs.close();
    }

    // Problem 4: Color edges by distance from root
    void problem4(const std::string& ofname) {
        static const std::string colors[] = {"green", "blue", "red", "purple"};
        std::vector<int> distances(numVertices, -1);
        distances[0] = 0;

        std::ofstream ofs(ofname);
        ofs << "digraph G {\n";

        for (int i = 0; i < numVertices; ++i) {
            bool hasOutgoingEdges = false;
            for (const auto& [neighbor, weight] : adjList[i]) {
                if (distances[neighbor] == -1) {
                    distances[neighbor] = distances[i] + 1;
                }
                std::string color = colors[distances[neighbor] % 4];
                ofs << "  " << i << " -> " << neighbor
                    << " [label=\"" << weight << "\" color=\"" << color << "\"];\n";
                hasOutgoingEdges = true;
            }
            if (!hasOutgoingEdges) {
                ofs << "  " << i << ";\n";
            }
        }

        ofs << "}\n";
        ofs.close();
    }
};

#endif // ADJACENCY_LIST_H


