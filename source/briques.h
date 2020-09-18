#ifndef DEF_BRIQUES
#define DEF_BRIQUES

#include <SFML/Graphics.hpp>

class Brique
{
public:
    Brique(sf::RenderWindow &fenetre);
    ~Brique();
    void afficherBrique();




private:
    sf::RenderWindow *m_fenetre;
    std::vector<ElBrique > m_vecBrique;


};

#endif // DEF_BRIQUES

