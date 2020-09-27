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

    void deplaceB();
    void afficheBalle();
    void getBoitEngloBalle(int indicB);



private:
    sf::RenderWindow *m_fenetre;

    sf::Texture m_tBalle;
    std::vector<ElBalle > m_vecBalle;
    sf::Clock m_horlBalle;
    float m_deltaTime;

};

#endif // DEF_BALLE
