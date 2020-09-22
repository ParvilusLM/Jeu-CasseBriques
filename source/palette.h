#ifndef DEF_PALETTE
#define DEF_PALETTE

class Palette
{
public:
    Palette(sf::RenderWindow& fenetre);
    ~Palette();

    void initPalette();

    void mouvementPalette(int dir);
    void mouvementProjectiles();

    sf::FloatRect getPosPalette();
    std::vector<sf::FloatRect > getPosProjectiles();


    void affichePalette();
    void afficheProjectiles();

private:
    sf::RenderWindow* m_fenetre;

    //pour la palette
    sf::Texture m_tPalette;
    sf::Sprite m_sPalette;

    //pour les projectiles
    sf::Texture m_tProjectiles;
    std::vector<sf::Sprite > m_vecProjectiles;

};

#endif // DEF_PALETTE
