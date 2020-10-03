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
    void inverserAngle(int numBalle,int zoneCollis);
    void resetHorlBalle();

    void mouvementBalle();
    void afficheBalle();
    std::vector<ElBalle >& getBalle();



private:
    sf::RenderWindow *m_fenetre;

    sf::Texture m_tBalle;
    std::vector<ElBalle > m_vecBalle;

    //horlBalle
    ElHorl m_horlBalle;
    float m_deltaTime;

    int m_nbBalleCree; //pour donner un identifiant a chaque balle

};

#endif // DEF_BALLE
