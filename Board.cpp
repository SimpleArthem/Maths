// Fichier : Board.cpp
#include "Board.h"

// Constructeur
Board::Board(int k, const std::vector<int>& dims) 
    : dimension(k), Dimensions(dims), Cases(genererCases(k, dims)) { // Initialisé dans l'initialiseur
    genererAdjacences(); // Adjacences calculées après
}

// Méthode statique pour générer les cases
std::set<std::vector<int>> Board::genererCases(int k, const std::vector<int>& Dimensions) {
    std::set<std::vector<int>> Cases;
    std::vector<int> Actuel(k, 1);

    // Générer toutes les combinaisons de coordonnées valides dans les dimensions données
    while (true) {
        Cases.insert(Actuel);
        int i = k - 1;
        while (i >= 0 && ++Actuel[i] > Dimensions[i]) {
            Actuel[i] = 1;
            --i;
        }
        if (i < 0) break;
    }
    return Cases;
}

// Réinitialisation des adjacences
void Board::resetAdjacences() {
    adjacences.clear(); // Efface les adjacences existantes
    genererAdjacences(); // Régénère les adjacences
}

// Génération des adjacences
void Board::genererAdjacences() {
    for (const auto& caseActuelle : Cases) { // Utilisation en tant que lecture seule
        std::set<std::vector<int>> voisins;

        // Appliquer les déplacements possibles
        for (size_t i = 0; i < caseActuelle.size(); i++) {
            for (size_t j = 0; j < caseActuelle.size(); j++) {
                if (i == j) continue;

                // Créer une copie de la case actuelle
                std::vector<int> caseDelta = caseActuelle;

                // Appliquer les écarts {2, 1} et {-2, -1}
                for (int delta1 : {-2, 2}) {
                    caseDelta[i] = caseActuelle[i] + delta1;

                    if (Cases.contains(caseDelta)) { // Vérifie si caseDelta[i] existe dans Cases
                        for (int delta2 : {-1, 1}) {
                            std::vector<int> voisinTemp = caseDelta;
                            voisinTemp[j] = caseActuelle[j] + delta2;

                            if (Cases.contains(voisinTemp)) { // Vérifie si voisinTemp existe dans Cases
                                voisins.insert(voisinTemp); // Ajout unique grâce à std::set
                            }
                        }
                    }
                }
            }
        }
        adjacences[caseActuelle] = voisins;
    }
}

// Getter pour les cases
const std::set<std::vector<int>>& Board::getCases() const {
    return Cases;
}
