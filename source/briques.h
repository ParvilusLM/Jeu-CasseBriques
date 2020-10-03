#ifndef DEF_BRIQUES
#define DEF_BRIQUES

#include <iostream>
#include <SFML/Graphics.hpp>
#include "enums.h"
#include "constantes.h"
#include "varG.h"

class Brique
{
public:
    Brique(sf::RenderWindow &fenetre);
    ~Brique();
    void initBrique(int niveau);
    void afficheBrique();
    int chargerNiveau(int niveau);
    void changerNiveau(int niveau);
    std::vector<ElBrique >& getBriques();
    void gestiontextures();
    void effacementBriques();



private:
    sf::RenderWindow *m_fenetre;
    sf::Texture m_tBrique;
    std::vector<ElBrique > m_vecBrique;



};

#endif // DEF_BRIQUES

