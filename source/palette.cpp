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
    m_palette.sPalette.setOrigin(45.f,17.5f);
    m_palette.sPalette.setPosition(LARGEUR_F/2,HAUTEUR_F-17.5f-20.f);
    m_palette.sPalette.setTexture(m_tPalette);
    m_palette.sPalette.setTextureRect(sf::IntRect(0,0,90,35));


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
    m_fenetre->draw(m_palette.sPalette);
}

void Palette::afficheProjectiles()
{

}

Palette::~Palette()
{

}
