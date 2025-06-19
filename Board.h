#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>
#include <map>
#include <set>

// Classe Board
class Board {
private:
    int dimension;
    std::vector<int> Dimensions; // Membre pour stocker les dimensions
    const std::set<std::vector<int>> Cases; // Marqué comme const

public:
    std::map<std::vector<int>, std::set<std::vector<int>>> adjacences;

    explicit Board(int k, const std::vector<int>& dims);
    void genererAdjacences();

    // Réinitialiser les adjacences
    void resetAdjacences();

    // Getter pour Cases, garantit un accès en lecture seule
    [[nodiscard]] const std::set<std::vector<int>>& getCases() const;

private:
    static std::set<std::vector<int>> genererCases(int k, const std::vector<int>& Dimensions);
};

#endif // BOARD_H