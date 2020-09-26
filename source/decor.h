#ifndef DEF_DECOR
#define DEF_DECOR

#include <SFML/Graphics.hpp>

#include "menu.h"
#include "info.h"
#include "palette.h"
#include "balle.h"
#include "briques.h"
#include "bonus.h"

#include "enums.h"
#include "varG.h"
#include "constantes.h"

class Decor
{
public:
    Decor(sf::RenderWindow& fenetre);
    ~Decor();
    Menu& getMenu();
    Brique& getBrique();
    Palette& getPalette();

    void afficheFondEc();
    void afficheCadreJeu();

private:
    sf::RenderWindow* m_fenetre;
    Menu* m_menu;
    Brique* m_brique;
    Palette* m_palette;


    sf::Texture m_tFondG;
    sf::Sprite m_sFondG;

    sf::Texture m_tCadreJeu;
    sf::Sprite m_sCadreJeu;

};

#endif // DEF_DECOR
