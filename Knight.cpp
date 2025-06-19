// Fichier : Knight.cpp
#include "Knight.h"
#include <ranges> // Utilisation des vues pour moderniser les boucles

Knight::Knight(const std::vector<int>& startPosition, Board* parentBoard)
    : position(startPosition), previousPosition(startPosition), board(parentBoard) {
    if (!board->getCases().contains(startPosition)) {
        throw std::invalid_argument("Position initiale invalide pour le cavalier.");
    }
    moveHistory.insert(startPosition);
}

// Déplacement
void Knight::moveTo(const std::vector<int>& newPosition) {
    if (board->adjacences[position].contains(newPosition)) {
        previousPosition = position;
        position = newPosition;
        moveHistory.insert(newPosition);
        markVisited();
    } else {
        throw std::invalid_argument("Déplacement invalide pour le chevalier.");
    }
}

// Renvoie les mouvements possibles
std::set<std::vector<int>> Knight::getPossibleMoves() const {
    if (board->adjacences.contains(position)) {
        return board->adjacences.at(position);
    } else {
        throw std::logic_error("Position actuelle non trouvée dans les adjacences.");
    }
}

// Marque les cases comme visitées
void Knight::markVisited() const {
    for (auto &voisins : board->adjacences | std::views::values) {
        voisins.erase(previousPosition);
    }
    board->adjacences.erase(previousPosition);
}

// Vérifie si toutes les cases ont été visitées
bool Knight::checkCompletion() const {
    return moveHistory == board->getCases();
}

// Getter pour la position
std::vector<int> Knight::getPosition() const {
    return position;
}

// Getter pour l'historique des déplacements
const std::set<std::vector<int>>& Knight::getMoveHistory() const {
    return moveHistory;
}