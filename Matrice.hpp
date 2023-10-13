#include <iostream>
#define Maxelem 20
using namespace std;

class Matrice
{
    int m, n; // m :lignes et n:colonnes
    int Mat[Maxelem][Maxelem];

public:
    // Constructeur qui prend deux entiers comme paramètres(dimension de la matrice)
    Matrice(int x, int y)
    {
        m = x;                           // Initialise m avec la valeur de x
        n = y;                           // Initialise n avec la valeur de y
        for (int i = 0; i <= m; i++)     // Boucle sur les lignes de la matrice
            for (int j = 0; j <= n; j++) // Boucle sur les colonnes de la matrice
                Mat[i][j] = 0;           // Met chaque élément de la matrice à 0
    }
    void Saisir() // Méthode pour entrer des valeurs dans la matrice
    {
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                cout << "Entrez les valeurs " << i << j << endl;
                cin >> Mat[i][j];
            }
    }
    Matrice operator+(Matrice M2) // Surcharge de l'opérateur + pour ajouter deux matrices
    {
        Matrice M3(m, n);           //
        if (M2.n == n && M2.m == m) // Vérifie si les dimensions des deux matrices sont compatibles pour l'addition
        {

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    M3.Mat[i][j] = Mat[i][j] + M2.Mat[i][j]; // Ajoute les éléments correspondants des deux matrices et stocke le résultat dans M3
                }
            }
        }
        else
        {
            cout << "dimensions des deux matrices ne sont pas compatibles "; // Affiche un message d'erreur si les dimensions ne sont pas compatibles pour l'addition
            exit(0);
        }
        return M3;
    }
    Matrice operator-(Matrice M2) // Surcharge de l'opérateur - pour soustraire deux matrices
    {
        Matrice M3(m, n);
        if (M2.n == n && M2.m == m) // Vérifie si les dimensions des deux matrices sont compatibles pour la soustraction
        {

            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                    M3.Mat[i][j] = Mat[i][j] - M2.Mat[i][j]; // Soustrait les éléments correspondants des deux matrices et stocke le résultat dans M3
            }
        }
        else
        {
            cout << "dimensions des deux matrices ne sont pas compatibles "; // Affiche un message d'erreur si les dimensions ne sont pas compatibles pour la soustraction
            exit(0);
        }
        return M3;
    }

    Matrice operator*(Matrice M2) // Surcharge de l'opérateur * pour multiplier deux matrices
    {
        if (M2.m == n) // Vérifie la comptabilité des dimensions des deux matrices pour le produit
        {
            Matrice M3(m, M2.n); // matrice résultat avec le nombre de lignes de la première matrice et le nombre de colonnes de la deuxième matrice
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < M2.n; j++)
                {
                    M3.Mat[i][j] = 0; // Initialiser les éléments de M3 à 0
                    for (int k = 0; k < n; k++)
                    {
                        M3.Mat[i][j] += Mat[i][k] * M2.Mat[k][j];
                    }
                }
            }
            return M3;
        }
        else
        {
            cout << "les dimensions des deux matrices ne sont pas compatibles "; // Affiche un message d'erreur si les dimensions ne sont pas compatibles pour la multiplication
            exit(0);
        }
    }
    Matrice operator*(int a) // Surcharge de l'opérateur * pour multiplier une matrice par un scalaire
    {
        Matrice M3(m, n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                M3.Mat[i][j] = Mat[i][j] * a; // Multiplie chaque élément de la matrice par le scalaire et stocke le résultat dans la nouvelle matrice
        }
        return M3;
    }

    void afficher() // Méthode pour afficher les éléments de la matrice
    {
        for (int i = 0; i < m; i++) // Boucle sur les lignes de la matrice
        {
            for (int j = 0; j < n; j++) // Boucle sur les colonnes de la matrice
                cout << Mat[i][j] << "\t";
            cout << endl;
        }
    }
};
