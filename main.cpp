#include "Game/Board.h"
#include "Game/Knight.h"
#include <iostream>
#include <vector>
#include <algorithm> // Pour shuffle
#include <random>    // Générateur de nombres aléatoires

std::vector<int> readDimensions(int k) {
    std::vector<int> dims;
    int x;
    for (int i = 0; i < k; i++) {
        std::cout << "Dimension n°" << i + 1 << " : ";
        std::cin >> x;
        dims.push_back(x);
    }
    return dims;
}

int main() {
    char replay = 'y';
    int dim;
    std::cout << "Nombre de dimensions de l'échiquier : ";
    std::cin >> dim;

    std::vector<int> dimensions = readDimensions(dim);
    Board echiquier(dim, dimensions); // L'instanciation initialise également `Cases`

    std::vector<int> startPosition(dim);
    std::cout << "Entrez la position de départ du chevalier : ";
    for (int i = 0; i < dim; i++) {
        std::cin >> startPosition[i];
    }

    do {
        echiquier.resetAdjacences(); // Réinitialise les adjacences avant chaque partie
        Knight chevalier(startPosition, &echiquier);

        while (true) {
            auto mouvements = chevalier.getPossibleMoves();
            if (mouvements.empty()) {
                if (chevalier.checkCompletion()) {
                    std::cout << "Toutes les cases ont été visitées !\n";
                } else {
                    std::cout << "Le cavalier n'a plus de mouvements possibles.\n";
                }
                break;
            }

            // Mélange aléatoire et déplacement
            std::vector<std::vector<int>> mouvementsListe(mouvements.begin(), mouvements.end());
            std::ranges::shuffle(mouvementsListe, std::mt19937{std::random_device{}()});

            try {
                chevalier.moveTo(mouvementsListe.front());
            } catch (const std::invalid_argument&) {
                break;
            }
        }

    } while (true);

    return 0;
}