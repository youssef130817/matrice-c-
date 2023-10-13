#include "Matrice.hpp"
int main()
{
    // Creation de deux objets Matrice
    Matrice M1(2, 2);
    Matrice M2(2, 2);
    // Saisie des valeurs pour les deux matrices
    cout << "---------Saisir les valeurs pour la premiere matrice---------\n";
    M1.Saisir();
    cout << "---------Saisir les valeurs pour la deuxieme matrice---------\n";
    M2.Saisir();

    // Affichage des matrices originales
    cout << "Premiere matrice : \n";
    M1.afficher();
    cout << "Deuxieme matrice : \n";
    M2.afficher();

    // Test de l'operateur +
    Matrice M3 = M1 + M2;
    cout << "Resultat de l'addition des deux matrices : \n";
    M3.afficher();

    // Test de l'operateur -
    Matrice M4 = M1 - M2;
    cout << "Resultat de la soustraction des deux matrices : \n";
    M4.afficher();

    // Test de l'operateur * pour la multiplication par un scalaire
    Matrice M5 = M1 * 3;
    cout << "Resultat de la multiplication de la premiere matrice par 3 : \n";
    M5.afficher();

    // Test de l'operateur * pour la multiplication de deux matrices
    Matrice M6 = M1 * M2;
    cout << "Resultat de la multiplication des deux matrices : \n";
    M6.afficher();

    return 0;
}
