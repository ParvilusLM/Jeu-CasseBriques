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

    void deplaceB(int indicB);
    void afficheBalle();
    void getBoitEngloBalle(int indicB);



private:
    sf::RenderWindow *m_fenetre;
    std::vector<sf::Sprite > m_vecBalle;
    std::vector<float >  m_vecAngleB;
    std::vector<float > m_vecVitesseB;
    std::vector<sf::Vector2f > m_directionB;


};

#endif // DEF_BALLE
