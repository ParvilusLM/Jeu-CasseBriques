#ifndef DEF_INFO
#define DEF_INFO

#include <SFML/Graphics.hpp>
#include <iostream>
#include <iomanip>
#include "enums.h"
#include "varG.h"
#include "constantes.h"
#include "sstream"
#include <fstream>
#include <string>
#include <array>

class Info
{
public:
    Info(sf::RenderWindow& fenetre);

    //initialisation
    void initInfo();//pour les info du menuP
    void reinitInfo();//pour les info du menuP
    void initInfo2();//pour les info du jeu
    void reinitInfo2();//pour les info du jeu
    int chargementDonnees();
    void initDonneesN();
    void initDonneesScores();

    //traitement donnees
    void gestTableauScore();
    void gestInfoPartEnCours();
    void gestSaisieNom(char characTape);
    void sauvegardeScore();
    void maj_Info();
    bool surPodium();

    int getDonnees(int typDonnees);
    void setDonnees(int typDonnees, int action, int valeur=0);

    //affichage
    void afficheInfo();
    void afficheNomAEnreg();

    //fonctions pour gerer l'horloge
    void reinitialiserH();
    void demarrerH();
    void pauseH();
    float getTemps();
    void gestionTemps();

    template <class T> std::string nbEnString(T nb);
    ~Info();


private:
    sf::RenderWindow *m_fenetre;
    sf::Text m_txtNbVie;
    sf::Text m_txtNomsJ;
    sf::Text m_txtScoresJ;
    sf::Text m_txtInfoJeu;
    sf::Text m_txtNomAEnreg;
    sf::Text m_txtTemps;

    sf::Font m_fntNoms,m_fntTemps,m_fntChiffres;

    std::ostringstream m_streamNomsJ,m_streamScoresJ,m_streamInfoJeu,m_streamTxtTemps;

    int m_score;
    int m_niveau;
    int m_nbVie;
    int m_nbBrRestants;
    std::vector<std::string> m_vecNoms;
    std::vector<std::string> m_vecScores;

    std::string m_nomAENreg;

    //pour le chron
    ElHorl m_horlJ;


};

#endif // DEF_INFO
