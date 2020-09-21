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

    void afficheFondEc();

private:
    sf::RenderWindow* m_fenetre;
    Menu* m_menu;
    sf::Texture m_tFondG;
    sf::Sprite m_sFondG;

};

#endif // DEF_DECOR
