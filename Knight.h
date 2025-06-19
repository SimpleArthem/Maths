// Fichier : Knight.h
#ifndef KNIGHT_H
#define KNIGHT_H

#include <vector>
#include <set>
#include "Board.h"

// Classe Knight (cavalier)
class Knight {
    std::vector<int> position;            // Position actuelle du chevalier
    std::vector<int> previousPosition;    // Position précédente du chevalier
    Board* board;                         // Référence au plateau
    std::set<std::vector<int>> moveHistory; // Historique des déplacements

public:
    // Constructeur
    Knight(const std::vector<int>& startPosition, Board* parentBoard);

    // Déplace le chevalier
    void moveTo(const std::vector<int>& newPosition);

    // Marque une position comme visitée
    void markVisited() const;

    // Renvoie les mouvements possibles
    [[nodiscard]] std::set<std::vector<int>> getPossibleMoves() const;

    // Vérifie si toutes les cases ont été visitées
    [[nodiscard]] bool checkCompletion() const;

    // Getter pour la position
    [[nodiscard]] std::vector<int> getPosition() const;

    // Getter pour l'historique des déplacements
    [[nodiscard]] const std::set<std::vector<int>>& getMoveHistory() const;
};

#endif // KNIGHT_H