#include <iostream>
#include<ctime>
#include "GameArea.h"
#include "Player.h"
#include <time.h>

using namespace std;

//pour la transformation du pion à la fin de la ligne adverse
void transformPawn(Jeton pawn, int choix) {
	switch (choix)
	{
	case 1 :
		//transforme en reine
		pawn.setTypeJeton(Q);
		break;
	case 2:
		//transforme en tour
		pawn.setTypeJeton(R);
		break;
	case 3:
		//transforme en cavalier
		pawn.setTypeJeton(N);
		break;
	case 4:
		//transforme en fou
		pawn.setTypeJeton(B);
		break;
	}
}

//embellir l'affichage
void getXY(string xy, int coord[2]) {
	int count = 0;
	for (int i = 0; xy[i] != '\0'; i++) {
		count++;
	}
	if (count == 2) {
		string lettre = "abcdefgh";
		int i = 0;
		for (; i < NCOL; i++)
			if (lettre[i] == xy[0]) {
				coord[1] = i;
				break;
			}
			else coord[1] = 10;
		coord[0] = NLIG - ((int)xy[1]) + 48;
	}

}

int main() {
	clock_t begin_time;
	Message m;
	Player player1 = Player("",1), player2=Player("",2);
	string name;
	string yx;
	cout << "nom premier joueur : ";
	cin >> name;
	player1.setName(name);

	cout << "nom deuxieme joueur : ";
	cin >> name;
	player2.setName(name);

	GameArea gameArea = GameArea();
	system("cls");
	gameArea.drawArea();
	int start[] = { 1,0 }, end[]= { 3,0};
	Player currentPlayer = player1;
	while (true) {
		begin_time = clock();
		system("cls");
		gameArea.drawArea();
		cout << currentPlayer.getName() << endl;
		cout << "	selectionner votre pion : ";
		cin >> yx;
		getXY(yx, start);
		cout << "	deplacer a : ";
		cin >> yx;
		getXY(yx, end);
		if (gameArea.getJeton(start).getLabel() == currentPlayer.getLabel()) {
			m = gameArea.getMove(start, end);
			if (m == OK) {
				if(gameArea.getJeton(end).getLabel() == P && (end[0]))
				currentPlayer.ajout_temps(float(clock() - begin_time));
				if (currentPlayer.getLabel() == player1.getLabel())
					currentPlayer = player2;
				else
					currentPlayer = player1;
				// on va tester si le pion est arrivé à la fin de la ligne, il faudra le transformer en (reine, tour cavalier ou fou) selon le choix du joueur
				if (gameArea.getJeton(end).getTypeJeton() == P && (end[0] == 0 || end[0] == 7)) {
					cout << "faut tranformer le pion " << endl;
				}
			}
			else {
				if (m == KILL_KING) {
					cout << "Temps ecoule : " << endl;
					cout << "	Joueur1 : " << player1.getName() << " " << player1.getTime() << endl;
					cout << "	Joueur2 : " << player2.getName() << " " << player2.getTime() << endl;
					cout << "Temps total " << player1.getTime() + player2.getTime() << endl;
					cout << currentPlayer.getName() << "  a gagné" << endl;
					break;
				}
				if (m == ERROR_MOVE_IMPOSSIBLE)
					cout << "Deplacement impossible" << endl;
				if (m == ERROR_MOVE_INCORECT)
					cout << "Deplacement incorrect du jeton" << endl;
				if (m == ERROR_MOVE_OUT_AREA)
					cout << "Deplacement hors surface de jeu" << endl;
				if (m == ERROR_MOVE_IN_YOUR_JETON)
					cout << "Deplacement sur votre propre jeton" << endl;
				system("pause");
			}
		}
		else {
			cout << " vous ne selectionner pas le bon jeton" << endl;
			system("pause");
		}
	}
	
	

}
