#include "info.h"

using namespace std;

Info::Info(sf::RenderWindow& fenetre):m_fenetre(0)
{
    m_fenetre=&fenetre;

    initInfo();
    chargementDonnees();
    gestTableauScore();
}

void Info::initInfo()
{
    //les fonts
    m_fntTemps.loadFromFile("donnees/charlbold.ttf");
    m_fntChiffres.loadFromFile("donnees/keypunc.ttf");
    m_fntNoms.loadFromFile("donnees/ALGER.ttf");

    //les textes
    m_txtNbVie.setFont(m_fntChiffres);
    m_txtNbVie.setCharacterSize(20);
    m_txtNbVie.setPosition(19.2f*20.f,17.1f*20.f);
    m_txtNbVie.setFillColor(sf::Color::Black);


    m_txtNomsJ.setFont(m_fntNoms);
    m_txtNomsJ.setCharacterSize(40);
    m_txtNomsJ.setPosition(11.f*20.f+4.f,14.f*20.f-3.f);
    m_txtNomsJ.setFillColor(sf::Color::Red);


    m_txtScoresJ.setFont(m_fntNoms);
    m_txtScoresJ.setCharacterSize(40);
    m_txtScoresJ.setPosition(24.f*20.f+10.f,14.f*20.f-3.f);
    m_txtScoresJ.setFillColor(sf::Color::Yellow);



    m_txtInfoJeu.setFont(m_fntChiffres);
    m_txtInfoJeu.setCharacterSize(35);
    m_txtInfoJeu.setPosition(3.9f*20.f,20.7f*20.f+5.f);
    m_txtInfoJeu.setFillColor(sf::Color::White);
    m_txtInfoJeu.setLineSpacing(2.2f);

    m_txtNomAEnreg.setFont(m_fntNoms);
    m_txtNomAEnreg.setCharacterSize(30);
    m_txtNomAEnreg.setPosition(18.f*20.f+10.f,17.9f*20.f+5.f);
    m_txtNomAEnreg.setFillColor(sf::Color::White);

    m_txtTemps.setFont(m_fntTemps);
    m_txtTemps.setCharacterSize(40);
    m_txtTemps.setPosition(700,300);
    m_txtTemps.setFillColor(sf::Color::Black);





}

void Info::reinitInfo()
{
    m_nomAENreg.clear();
    gestTableauScore();
}

void Info::initInfo2()
{
    //info sur le niveau en cours
    m_score=0;
    m_niveau=1;
    m_nbVie=3;
    m_nbBrRestants=0;

    //gestion des info durant la partie
    demarrerH();
    gestionTemps();
    gestInfoPartEnCours();
}

void Info::reinitInfo2()
{
    void reinitialiserH();
}

int Info::chargementDonnees()
{
    //gestion fichier noms des joueurs
    std::string const nomFichierN("donnees/nomsJ.plm");
    FILE* fichierNoms=NULL;
    char ligneFichierN[6]={0};
    int caractereLu=0,nbNoms=0,noNoms=0,noLigneChoisi=0;

    fichierNoms=fopen(nomFichierN.c_str(),"r");
    if(fichierNoms==NULL)
    {
        fclose(fichierNoms);
        initDonneesN();
        fichierNoms=fopen(nomFichierN.c_str(),"r");
    }

    while(nbNoms<3)
    {
        fgets(ligneFichierN,10,fichierNoms);
        std::string nom=ligneFichierN;
        while(nom.size()<2)
        {
            fgets(ligneFichierN,10,fichierNoms);
            nom=ligneFichierN;
        }

        m_vecNoms.insert(m_vecNoms.end(),nom);

        nbNoms++;

    }

    fclose(fichierNoms);

    //gestion des scores des joueurs
    std::string const nomFichierScores("donnees/scoresJ.plm");
    FILE* fichierScores=NULL;
    char ligneFichierSc[6]={0};
    caractereLu=0,noLigneChoisi=0;
    int nbScores=0,noScores=0;

    fichierScores=fopen(nomFichierScores.c_str(),"r");
    if(fichierScores==NULL)
    {
        fclose(fichierScores);
        initDonneesScores();
        fichierScores=fopen(nomFichierScores.c_str(),"r");

    }

    while(nbScores<3)
    {
        fgets(ligneFichierSc,10,fichierScores);
        std::string score=ligneFichierSc;
        while(score.size()<2)
        {
            fgets(ligneFichierSc,10,fichierScores);
            score=ligneFichierSc;
        }

        m_vecScores.insert(m_vecScores.end(),score);

        nbScores++;

    }

    fclose(fichierScores);
}

void Info::initDonneesN()
{
    std::string const nomFichierN("donnees/nomsJ.plm");

    std::ofstream monFlux(nomFichierN.c_str());

    int nbN=3;
    while(nbN>0)
    {
        monFlux<<"Nul"<<std::endl;

        nbN--;
    }
    monFlux.close();

}

void Info::initDonneesScores()
{
    std::string const nomFichierS("donnees/scoresJ.plm");
    std::ofstream monFlux(nomFichierS.c_str());

    int nbN=3;
    while(nbN>0)
    {
        monFlux<<"0"<<std::endl;

        nbN--;
    }
    monFlux.close();
}

void Info::gestTableauScore()
{


    m_streamNomsJ.str("");
    m_streamNomsJ<<m_vecNoms.at(0)<<"\n"<<m_vecNoms.at(1)<<"\n"<<m_vecNoms.at(2)<<"\n";
    m_txtNomsJ.setString(m_streamNomsJ.str());
    m_txtNomsJ.setLineSpacing(0.75f);


    m_streamScoresJ.str("");
    m_streamScoresJ<<m_vecScores.at(0)<<"\n"<<m_vecScores.at(1)<<"\n"<<m_vecScores.at(2)<<"\n";
    m_txtScoresJ.setString(m_streamScoresJ.str());
    m_txtScoresJ.setLineSpacing(0.75f);

}

void Info::gestInfoPartEnCours()
{
    if(scoreTemp!=0)
    {
        m_score+=scoreTemp;
        scoreTemp=0;
    }

    //
    m_streamInfoJeu.str("");
    m_streamInfoJeu<<nbEnString(m_nbVie)<<"\n"<<nbEnString(m_score)<<"\n"<<nbEnString(m_nbBrRestants);
    m_txtInfoJeu.setString(m_streamInfoJeu.str());

    gestionTemps();
}

void Info::gestSaisieNom(char characTape)
{
    if(m_nomAENreg.size()<5)
    {
        m_nomAENreg+=characTape;
        m_txtNomAEnreg.setString(m_nomAENreg);
    }

}

void Info::sauvegardeScore()
{
    int posJoueur=0;

    int compt=0;
    int dern_el=m_vecScores.size()-1;
    while(compt<m_vecScores.size())
    {
        int score=std::stoi(m_vecScores.at(dern_el));
        if(m_score>=score)
        {
            posJoueur=dern_el+1;
        }
        dern_el--;
        compt++;
    }

    //remplir les vecteurs scores et noms
    posJoueur--;

    m_vecScores.insert(m_vecScores.begin()+posJoueur,nbEnString(m_score));
    m_vecScores.pop_back();

    m_vecNoms.insert(m_vecNoms.begin()+posJoueur,m_nomAENreg);
    m_vecNoms.pop_back();

    std::cout<<"Taille m_vecScores :"<<m_vecScores.size()<<"\n Taille m_vecNoms :"<<m_vecNoms.size()<<std::endl;


    //Sauvegarde dans les fichiers

    std::string const nomFichierS("donnees/scoresJ.plm");
    std::string const nomFichierN("donnees/nomsJ.plm");

    //ecriture dans le fichier score
    {
        int posCurseur=0;
        std::ofstream monFlux(nomFichierS.c_str());

        monFlux<<m_vecScores.at(0)<<std::endl;

        monFlux<<m_vecScores.at(1)<<std::endl;

        monFlux<<m_vecScores.at(2)<<std::endl;

        monFlux.close();

    }

    //ecriture dans le fichier nom
    {
        int posCurseur=0;
        std::ofstream monFluxN(nomFichierN.c_str());

        monFluxN<<m_vecNoms.at(0)<<std::endl;

        monFluxN<<m_vecNoms.at(1)<<std::endl;

        monFluxN<<m_vecNoms.at(2)<<std::endl;

        monFluxN.close();
    }

}

void Info::maj_Info()
{
    gestionTemps();
}

void Info::afficheInfo()
{
    if(jeuEnCours)
    {
        m_fenetre->draw(m_txtInfoJeu);
        m_fenetre->draw(m_txtTemps);
    }
    else
    {
        m_fenetre->draw(m_txtNomsJ);
        m_fenetre->draw(m_txtScoresJ);
    }
}

void Info::reinitialiserH()
{
    m_horlJ.m_horlJeu.restart();
    pauseH();
    m_horlJ.m_tempsEcoule=0.f;
}

void Info::demarrerH()
{
    if(m_horlJ.etat !=EnMarche)
    {
        m_horlJ.m_horlJeu.restart();
        m_horlJ.etat=EnMarche;
    }
}

void Info::pauseH()
{
    if(m_horlJ.etat !=EnPause)
    {
        m_horlJ.etat=EnPause;
        m_horlJ.m_tempsEcoule += m_horlJ.m_horlJeu.getElapsedTime().asSeconds();
    }
}

float Info::getTemps()
{
    float temps;
    if(m_horlJ.etat == EnPause)
    {
        temps=m_horlJ.m_tempsEcoule;
    }
    else
    {
        temps= m_horlJ.m_horlJeu.getElapsedTime().asSeconds() + m_horlJ.m_tempsEcoule;
    }

    return temps;
}

void Info::gestionTemps()
{
    int temps=int(getTemps());
    std::ostringstream m_streamTxtTemps;
    m_streamTxtTemps.str("");
    m_streamTxtTemps<< nbEnString(temps/60) << " : "<< nbEnString(temps%60);

    m_txtTemps.setString(m_streamTxtTemps.str());
}

void Info::afficheNomAEnreg()
{
    m_fenetre->draw(m_txtNomAEnreg);
}

bool Info::surPodium()
{
    bool podium=false;

    int cmpt=0;
    while(cmpt<3)
    {
        if(std::stoi(m_vecScores.at(cmpt))<m_score)
        {
            podium=true;
        }
        cmpt++;
    }

    return podium;
}

template <class T> std::string Info::nbEnString(T nb)
{
    std::ostringstream chaineCar;
    chaineCar << nb;
    return chaineCar.str();
}

Info::~Info()
{

}
