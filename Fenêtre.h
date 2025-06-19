//
// Created by deck on 30/05/25.
//

#ifndef FENÊTRE_H
#define FENÊTRE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

class Fenêtre {
private:
    sf::Window window;

public:
    Fenêtre();
    void ouvrirFenêtre();
};

#endif