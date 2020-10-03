#ifndef DEF_ENUMS
#define DEF_ENUMS

#include <SFML/Graphics.hpp>

struct ElBrique
{
    sf::Sprite sBrique;
    int etat;
    int couleur;
};

struct ElBalle
{
    sf::Sprite sBalle;
    int etat;
    float angleB;
    float vitesseB;
    int dirX;
    int dirY;
    int numBalle;
};

struct ElPalette
{
    sf::Sprite sPalette;
    int etat;
    float vitesseP;
    std::vector<sf::Sprite > vecProjectiles;
};

struct ElHorl
{
    sf::Clock m_horlJeu;
    float m_tempsEcoule;
    int etat;
};

enum
{
    EnMarche,
    EnPause
};


enum TypeMenu
{
    MenuPrincipal,
    MenuInstructions1,
    MenuInstructions2,
    MenuInstructions3,
    MenuPause,
    MenuFinPartie,
    MenuEnregScore

};

enum
{
    AUCUN_EL_ACT,
    JOUER_ACTIF,
    INSTRUCTIONS_ACTIF,
    QUITTER_ACTIF,
    OK_ACTIF,
    PRECEDENT_ACTIF,
    SUIVANT_ACTIF,
    RETOUR_ACTIF,
    PAUSER_ACTIF,
    PAUSEI_ACTIF,
    PAUSEQ_ACTIF,
    FINPQ_ACTIF,
    FINPR_ACTIF,
    ESOk_ACTIF

};

enum
{
    C_VIDE,
    BRIQUE1,
    BRIQUE2,
    BRIQUE3,
    BRIQUE4,
    BRIQUE5
};

enum
{
    NORMAL,
    CASSE,
    DETRUIT
};

enum
{
    CAPTURE,
    LANCEE
};

enum
{
    DIR_GAUCHE,
    DIR_DROITE
};

enum
{
    AUCUNE_COLLIS,
    COLLIS_BORD_G,
    COLLIS_BORD_D,
    COLLIS_BORD_H,
    COLLIS_BORD_B,
    COLLIS_BRIQUE_G,
    COLLIS_BRIQUE_D,
    COLLIS_BRIQUE_H,
    COLLIS_BRIQUE_B
};

#endif // DEF_ENUMS
