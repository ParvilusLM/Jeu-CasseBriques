#ifndef DEF_CONTROLEUR
#define DEF_CONTROLEUR

#include <SFML/Graphics.hpp>
#include "decor.h"

class Controleur
{
public:
    Controleur(sf::RenderWindow &fenetre);
    ~Controleur();
    void debutJeu();

    void gestionDplSouris();
    void gestionSelecSouris();

    void afficheMenu();
    void afficheFondEc();
    void afficheJeu();
    void afficheInfo();

    void gestionMaJ();
    void gestCollisBalle();
    bool gestCollisPalette();
    void gestMouvBalle();
    void gestMouvPalette(int dir);

    void saisieL(char lettre);
    void sauvegardeScore();
    void reinitTablScore();

    void pauseJeu();


private:
    sf::RenderWindow* m_fenetre;
    Decor* m_decor;



};

#endif // DEF_CONTROLEUR
