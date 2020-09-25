#include "palette.h"

using namespace std;

Palette::Palette(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    m_tPalette.loadFromFile("donnees/spriteSheetPalette.png");
    m_tProjectiles.loadFromFile("donnees/projectile.png");


}

void Palette::initPalette()
{

}

sf::FloatRect Palette::getPosPalette()
{

}

std::vector<sf::FloatRect > Palette::getPosProjectiles()
{

}

void Palette::mouvementPalette(int dir)
{

}

void Palette::mouvementProjectiles()
{

}

void Palette::affichePalette()
{

}

void Palette::afficheProjectiles()
{

}

Palette::~Palette()
{

}
