#ifndef DEF_PALETTE
#define DEF_PALETTE

#include <SFML/Graphics.hpp>
#include "enums.h"
#include "constantes.h"
#include "varG.h"

class Palette
{
public:
    Palette(sf::RenderWindow& fenetre);
    ~Palette();

    void initPalette();

    void mouvementPalette(int dir);
    void mouvementProjectiles();

    sf::Vector2f getPosPalette();
    void setPosPalette(sf::Vector2f posPalette);
    std::vector<sf::FloatRect > getPosProjectiles();
    void DonneesMaJ();

    void affichePalette();
    void afficheProjectiles();

private:
    sf::RenderWindow* m_fenetre;

    //texture pour la palette
    sf::Texture m_tPalette;

    //texture pour les projectiles
    sf::Texture m_tProjectiles;

    ElPalette m_palette;

    sf::Clock m_horlPalette;
    float m_deltaTime;


};

#endif // DEF_PALETTE
