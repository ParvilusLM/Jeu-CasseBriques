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
    void afficheMenu();
    void gestionDplSouris();
    void gestionSelecSouris();
    void afficheFondEc();
    void afficheJeu();

    void gestionMaJ();
    bool gestCollisBalle();
    bool gestCollisPalette();
    void gestMouvBalle();
    void gestMouvPalette(int dir);


private:
    sf::RenderWindow* m_fenetre;
    Decor* m_decor;



};

#endif // DEF_CONTROLEUR
