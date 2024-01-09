#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Structure pour représenter une question du quiz
struct questionnaire{
	 char questions[100];
	 char options[4][100];
	 int vrai_reponse;	
};
int score=0;
// Fonction pour poser une question au joueur
void poser_question(struct questionnaire q,int *vies) {
	int i;
    int reponse;

     printf("%s\n", q.questions);
     for ( i = 0; i < 4; i++) {
        printf("%d. %s\n", i + 1, q.options[i]);
     }
     printf("choisir une seul reponse de 1 a 4 : ");
     scanf("%d", &reponse);
     if(reponse==q.vrai_reponse){
    	printf("votre reponse est correcte \n");
    	score+=10;
    	printf("les vies qui vous reste:%d \n",*vies);
    	printf("votre score est:%d\n ",score);
    }else{
      	printf("votre reponse est incorrect \n");
      	*vies-=1;
      	printf("les vies qui vous reste:%d \n",*vies);
      	printf("votre score est:%d \n",score);
     }


	
}
// Fonction pour enregistrer les scores a  partir d'un fichier
void enregistrerScore(char* Nom, int score) {
    FILE* fichier = fopen("scores.txt", "w");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }

    fprintf(fichier, "Nom: %s, Score: %d\n", Nom, score);

    fclose(fichier);
}
// Fonction pour lire les anciens scores a partir d'un fichier
void lireAnciensScores() {
    FILE* fichier = fopen("scores.txt", "r");

    if (fichier == NULL) {
        // Le fichier n'existe pas encore, pas besoin de lire les anciens scores
        return;
    }

    printf("Anciens Scores :\n");

    char ligne[100];
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        printf("%s", ligne);
    }

    fclose(fichier);
}
int main(){
    int vies=3;
    lireAnciensScores();  // Lire les anciens scores au debut du programme
	//question sport
	 struct questionnaire sport[10];
	 // Initialisation des questions pour les thèmes sport, géographie et devinettes
	   //question 1
	    strcpy(sport[0].questions, "Quelle est la capitale du tennis ?");
        strcpy(sport[0].options[0], "Paris");
        strcpy(sport[0].options[1], "Londres");
        strcpy(sport[0].options[2], "Rome");
        strcpy(sport[0].options[3], "New York");
        sport[0].vrai_reponse = 2;
       //question 2
	    strcpy(sport[1].questions, "quel joueur de footbal a remporte le ballon d'or en 2020' ?");
        strcpy(sport[1].options[0], "Lionel Messi");
        strcpy(sport[1].options[1], "Cristiano Ronaldo");
        strcpy(sport[1].options[2], "Neymar");
        strcpy(sport[1].options[3], "Kylian Mbappé");
        sport[1].vrai_reponse = 1;
       //question 3
	    strcpy(sport[2].questions, "Dans quel pays a eu lieu la première Coupe du Monde de football en 1930 ?");
        strcpy(sport[2].options[0], "Brésil");
        strcpy(sport[2].options[1], " Allemagne");
        strcpy(sport[2].options[2], "Uruguay");
        strcpy(sport[2].options[3], "Italie");
        sport[0].vrai_reponse = 3;
       //question 4
	    strcpy(sport[3].questions, "Quel est le sport le plus pratiqué dans le monde?");
        strcpy(sport[3].options[0], "Football (soccer)");
        strcpy(sport[3].options[1], "Basketball");
        strcpy(sport[3].options[2], "Tennis");
        strcpy(sport[3].options[3], "Golf");
        sport[3].vrai_reponse = 1;
       //question 5
	    strcpy(sport[4].questions, "Qui est surnommé (The G.O.A.T) (The Greatest of All Time) dans le domaine du tennis?");
        strcpy(sport[4].options[0], " Rafael Nadal");
        strcpy(sport[4].options[1], "Novak Djokovic");
        strcpy(sport[4].options[2], "Roger Federer");
        strcpy(sport[4].options[3], "Andy Murray");
        sport[4].vrai_reponse = 3;
       //question 6
	    strcpy(sport[5].questions, " Quelle équipe de baseball joue à Fenway Park ?");
        strcpy(sport[5].options[0], "New York Yankees");
        strcpy(sport[5].options[1], "Los Angeles Dodgers");
        strcpy(sport[5].options[2], "Boston Red Sox");
        strcpy(sport[5].options[3], "Chicago Cubs");
        sport[5].vrai_reponse = 3;
       //question 7
	    strcpy(sport[6].questions, " Quel pays a remporté le plus grand nombre de médailles d'or aux Jeux Olympiques d'été de 2016 ?");
        strcpy(sport[6].options[0], " États-Unis");
        strcpy(sport[6].options[1], " Chine");
        strcpy(sport[6].options[2], "Russie");
        strcpy(sport[6].options[3], "Allemagne");
        sport[6].vrai_reponse = 1;
       //question 8
	    strcpy(sport[7].questions, "  Quel est le championnat de Formule 1 le plus prestigieux au monde?");
        strcpy(sport[7].options[0], "Grand Prix de Monaco");
        strcpy(sport[7].options[1], "Grand Prix d'Italie");
        strcpy(sport[7].options[2], " Grand Prix du Canada");
        strcpy(sport[7].options[3], " Grand Prix de France");
         sport[7].vrai_reponse = 1;
       //question 9
	    strcpy(sport[8].questions, "Quel joueur de basketball a remporté le plus grand nombre de titres de MVP (Most Valuable Player) en NBA ?");
        strcpy(sport[8].options[0], "Kobe Bryant");
        strcpy(sport[8].options[1], "LeBron James");
        strcpy(sport[8].options[2], "Michael Jordan");
        strcpy(sport[8].options[3], "Shaquille O'Neal");
        sport[8].vrai_reponse = 3; 
        //question 10
	    strcpy(sport[9].questions, "Quel est le terme utilisé pour désigner un score parfait de 300 points dans le bowling ?");
        strcpy(sport[9].options[0], " Strike");
        strcpy(sport[9].options[1], " Spare");
        strcpy(sport[9].options[2], " Split");
        strcpy(sport[9].options[3], "Gutter");
        sport[9].vrai_reponse = 1; 
        
    //question geographie
    struct questionnaire geographie[10];
	//question 1
	    strcpy(geographie[0].questions, "Quel est le plus grand désert du monde?");
        strcpy(geographie[0].options[0], "Sahara");
        strcpy(geographie[0].options[1], "Gobi");
        strcpy(geographie[0].options[2], "Antarctica");
        strcpy(geographie[0].options[3], "Atacama");
        geographie[0].vrai_reponse = 4;
    //question 2
	    strcpy(geographie[1].questions, " Quelle est la plus grande île au monde par sa superficie  ?");
        strcpy(geographie[1].options[0], "Groenland");
        strcpy(geographie[1].options[1], " Java");
        strcpy(geographie[1].options[2], " Île de Baffin");
        strcpy(geographie[1].options[3], "Madagascar");
        geographie[1].vrai_reponse = 1;
    //question 3
	    strcpy(geographie[2].questions, "Quelle est la capitale du Canada ?");
        strcpy(geographie[2].options[0], "Toronto");
        strcpy(geographie[2].options[1], "Ottawa");
        strcpy(geographie[2].options[2], "Vancouver");
        strcpy(geographie[2].options[3], "Montréal");
        geographie[2].vrai_reponse = 2;
    //question 4
	    strcpy(geographie[3].questions, "Quel est le fleuve le plus long du monde ?");
        strcpy(geographie[3].options[0], " Nil");
        strcpy(geographie[3].options[1], "Amazone");
        strcpy(geographie[3].options[2], "Yangtsé");
        strcpy(geographie[3].options[3], "Mississippi");
        geographie[3].vrai_reponse = 2;
    //question 5
	    strcpy(geographie[4].questions, "Dans quel océan se trouve l'île de Madagascar?");
        strcpy(geographie[4].options[0], " Océan Pacifique");
        strcpy(geographie[4].options[1], "Océan Indien");
        strcpy(geographie[4].options[2], "Océan Atlantique");
        strcpy(geographie[4].options[3], "Océan Arctique");
        geographie[4].vrai_reponse = 2;
    //question 6
	    strcpy(geographie[5].questions, "Quelle est la chaîne de montagnes la plus longue au monde?");
        strcpy(geographie[5].options[0], "Football");
        strcpy(geographie[5].options[1], "Basketball");
        strcpy(geographie[5].options[2], "Tennis");
        strcpy(geographie[5].options[3], "Golf");
        geographie[5].vrai_reponse = 1;
    //question 7
	    strcpy(geographie[6].questions, "Quel est votre sport prï¿½fï¿½rï¿½ ?");
        strcpy(geographie[6].options[0], "Les Alpes");
        strcpy(geographie[6].options[1], "Les Andes");
        strcpy(geographie[6].options[2], " Les Montagnes Rocheuses");
        strcpy(geographie[6].options[3], "L'Himalaya");
        geographie[6].vrai_reponse = 4;
    //question 8
	    strcpy(geographie[7].questions, "Quel est le pays le plus peuplé au monde?");
        strcpy(geographie[7].options[0], "Inde");
        strcpy(geographie[7].options[1], "Chine");
        strcpy(geographie[7].options[2], " États-Unis");
        strcpy(geographie[7].options[3], "Brésil");
        geographie[7].vrai_reponse = 2;
    //question 9
	    strcpy(geographie[8].questions, "Quel est le point le plus bas de la Terre?");
        strcpy(geographie[8].options[0], "Mont Everest");
        strcpy(geographie[8].options[1], " Mer Morte");
        strcpy(geographie[8].options[2], "Vallée de la Mort");
        strcpy(geographie[8].options[3], "Grand Canyon");
        geographie[8].vrai_reponse = 2;
    //question 10
	    strcpy(geographie[9].questions, "Quelle est la plus grande ville d'Australie ?");
        strcpy(geographie[9].options[0], "Melbourne");
        strcpy(geographie[9].options[1], "Sydney");
        strcpy(geographie[9].options[2], "Brisbane");
        strcpy(geographie[9].options[3], "Perth");
        geographie[9].vrai_reponse = 2;

//question devinette
    struct questionnaire devinette[10];
	//question 1
	    strcpy(devinette[0].questions, "Je suis un animal qui dort la journée et chasse la nuit. Qui suis-je ?");
        strcpy(devinette[0].options[0], "Tigre");
        strcpy(devinette[0].options[1], "Aigle");
        strcpy(devinette[0].options[2], " Chauve-souris");
        strcpy(devinette[0].options[3], " Singe");
        devinette[0].vrai_reponse = 3;
    //question 2
	    strcpy(devinette[1].questions, "Je vole sans ailes, je pleure sans yeux. Que suis-je ?");
        strcpy(devinette[1].options[0], "Nuage");
        strcpy(devinette[1].options[1], "Vent");
        strcpy(devinette[1].options[2], "Rivière");
        strcpy(devinette[1].options[3], "Oiseau");
        devinette[1].vrai_reponse = 2;
    //question 3
	    strcpy(devinette[2].questions, " Plus on me prend, moins je pèse. Qui suis-je?");
        strcpy(devinette[2].options[0], "Air");
        strcpy(devinette[2].options[1], "Lumière");
        strcpy(devinette[2].options[2], "Fardeau");
        strcpy(devinette[2].options[3], "Empreinte");
        devinette[2].vrai_reponse = 3;
    //question 4
	    strcpy(devinette[3].questions, "Je suis toujours affamé, je mange tout le temps, mais la nourriture ne me fait jamais grossir. Que suis-je ?");
        strcpy(devinette[3].options[0], "Feu");
        strcpy(devinette[3].options[1], "Temps");
        strcpy(devinette[3].options[2], "Océan");
        strcpy(devinette[3].options[3], "Miroir");
        devinette[3].vrai_reponse = 2;
    //question 5
	    strcpy(devinette[4].questions, "  Je suis un mot de quatre lettres, je commence par (e) et termine par (e). Contient une lettre mais n'en est pas. Que suis-je?");
        strcpy(devinette[4].options[0], " Encre");
        strcpy(devinette[4].options[1], "Eau");
        strcpy(devinette[4].options[2], "Élan");
        strcpy(devinette[4].options[3], "Erre");
        devinette[4].vrai_reponse = 1;
    //question 6
	    strcpy(devinette[5].questions, "Je suis présent en deuxième place dans la semaine, en milieu de l'océan, mais je ne suis pas dans le dictionnaire. Que suis-je?");
        strcpy(devinette[5].options[0], "Mer");
        strcpy(devinette[5].options[1], "E");
        strcpy(devinette[5].options[2], "R");
        strcpy(devinette[5].options[3], "Méditerranée");
        devinette[5].vrai_reponse = 2;
    //question 7
	    strcpy(devinette[6].questions, "Je suis un instrument de musique à cordes, mais je ne peux pas être joué. Que suis-je ?");
        strcpy(devinette[6].options[0], "Violon");
        strcpy(devinette[6].options[1], "Guitare");
        strcpy(devinette[6].options[2], "Harpe");
        strcpy(devinette[6].options[3], "Téléphone");
        devinette[6].vrai_reponse = 4;
    //question 8
	    strcpy(devinette[7].questions, "Je suis un pays célèbre pour mes pyramides. Où suis-je?");
        strcpy(devinette[7].options[0], "Brésil");
        strcpy(devinette[7].options[1], "Mexique");
        strcpy(devinette[7].options[2], "Égypte");
        strcpy(devinette[7].options[3], "Grèce");
        devinette[7].vrai_reponse = 3;
    //question 9
	    strcpy(devinette[8].questions, "Je suis la fin de la nuit et le début du jour. Quand le soleil se lève, je disparais. Que suis-je?");
        strcpy(devinette[8].options[0], "Crépuscule");
        strcpy(devinette[8].options[1], "Aube");
        strcpy(devinette[8].options[2], "Éclipse");
        strcpy(devinette[8].options[3], "Horizon");
        devinette[8].vrai_reponse = 2;
    //question 10
	    strcpy(devinette[9].questions, "Je suis un fruit jaune, courbé, et souvent associé à des singes. Que suis-je?");
        strcpy(devinette[9].options[0], "Pomme");
        strcpy(devinette[9].options[1], "Banane");
        strcpy(devinette[9].options[2], "Orange");
        strcpy(devinette[9].options[3], "Kiwi");
        devinette[9].vrai_reponse = 2;
        
    char nom[100];
    int theme;
    int instuction;
    
    printf("----------BIENVENUE AU QUIZ----------\n");
    printf("veuillez entrer votre nom \n");
    scanf("%s",&nom);
    printf("-------------------------------------\n");
    printf("%s si vous voulez commencer le jeu cliquer 1, si vous voulez voir les instructions de jeu cliquer o :\n",nom);
    scanf("%d",&instuction);
    switch (instuction) {
        case 0:
            printf("Les instructions sont :\n");
            printf("Les règles du jeu sont simples :\n");
            printf("1. Vous commencez avec 3 vies.\n");
            printf("2. Chaque question correcte vous rapporte 10 points.\n");
            printf("3. Chaque réponse incorrecte vous fait perdre une vie.\n");
            printf("4. Le jeu se termine lorsque vous n'avez plus de vies.\n");
            printf("5.Répondez aux questions en choisissant un numéro parmi les options proposées.\n");
            printf("6.Essayez de maximiser votre score tout en conservant vos vies !\n");
            break;
        case 1:    
        default:
            break;
    };
    printf("----------------LE JEU VA COMMENCER---------------- \n");
    printf("les theme du Quiz sont\n");
    printf("1-->sport\n2--> geographie\n3-->devinette\n");
    label:
    printf("entrer votre choix --> ");
    scanf("%d",&theme);
    int i;
    switch (theme){
    	case 1:
            for (i = 0; i < 10 ; ++i) {
              poser_question(sport[i], &vies);
               if(vies==0){
                    printf("malheureusement!vous avez perdu, le jeu est terminer ");
                    break;
                  }
            }
    		break;
    	case 2:
            for (i = 0; i < 10 ; ++i) {
              poser_question(geographie[i], &vies);
               if(vies==0){
                    printf("malheureusement!vous avez perdu, le jeu est terminer ");
                    break;
                  }
            }
			break;
		case 3:
        for (i = 0; i < 10 ; ++i) {
              poser_question(devinette[i], &vies);
               if(vies==0){
                    printf("malheureusement!vous avez perdu, le jeu est terminer ");
                    break;
                  }
            }
			break;
		default:
		    goto label;	
	}
	 if (vies > 0) {
        printf("Félicitations, vous avez gagné ! Votre score est : %d et vous avez %d vies.\n", score, vies);
    }

    enregistrerScore(nom, score);
	return 0;
}

    





















