#ifndef DEF_BALLE
#define DEF_BALLE

#include <SFML/Graphics.hpp>
#include "enums.h"
#include "varG.h"
#include "constantes.h"

class Balle
{
public:
    Balle(sf::RenderWindow &fenetre);
    ~Balle();
    void initBalle();
    void mouvementB(int indicB);
    void mouvementProject();
    void afficheBalle();
    sf::FloatRect getBoitEnglBalle(int indicB);
    sf::FloatRect getBoitEnglProject()
    void changerVitesseBalle(int action);
    void multiplierBalle();



private:
    sf::RenderWindow *m_fenetre;
    std::vector<sf::Sprite > m_vecBalle;
    std::vector<float >  m_vecAngleB;
    std::vector<float > m_vecVitesseB;
    std::vector<sf::Vector2f > m_directionB;
    std::vector<sf::Sprite > m_vecProjectiles


};

#endif // DEF_BALLE
