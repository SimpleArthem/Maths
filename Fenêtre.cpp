//
// Created by deck on 30/05/25.
//

#include "Fenêtre.h"

Fenêtre::Fenêtre() {
    // Initialisation de la fenêtre
    window.create(sf::VideoMode(800, 600), "Chess");
}

void Fenêtre::ouvrirFenêtre() {
    // Boucle principale de la fenêtre
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                std::cout << "The left button was pressed" << std::endl;
                std::cout << "Mouse x: " << event.mouseButton.x << std::endl;
                std::cout << "Mouse y: " << event.mouseButton.y << std::endl;
            }
        }
        window.display();
    }
}