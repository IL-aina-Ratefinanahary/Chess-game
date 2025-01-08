#include <iostream>
#include "Cell.h"				//utilisation Cell.h (Cases)
#include "EnumMessage.h"		//utilisation des differents messages

#define NLIG 8					//définition d'une constante NLIG sur x				
#define NCOL 8					//définition d'une constante NCOL sur y

class GameArea					//Création d'une classe GameArea
{
	//int area[NLIG][NCOL];
	public:
	Cell listCell[NLIG][NCOL];		// Crée chaque case de notre Echequier
	private : string lettre = "abcdefgh";		//lettre contient ces alphabets pour permettre l'affichage après

	/*
		fonction qui permet d'initialiser les elements de la surface de jeu
	*/
	public : GameArea() {
		/*
			********   JOUEUR 1    *********
		*/
		// positionnement de Pions du joueur 1
		//placer sur chaque colonne de a à h et sur la ligne 2, tous les pions du joueur 1 , des pièces de type P (Pion)
		for (int j = 0; j < NCOL; j++) {
			listCell[1][j] = Cell(1, j, Jeton(1, 1, P));	
		}
		
		// positionnement des Tours du joueur 1
		//les Tours se trouvent sur les cases de la ligne 1 ,de la colonne 1(a) et 8(h) du joueur 1 et les Tours sont des jetons de type R (Rook)
		listCell[0][0] = Cell(0, 0, Jeton(1, 1, R));
		listCell[0][7] = Cell(0, 7, Jeton(1, 1, R));
		
		// positionnement des Cavaliers du joueur 1
		//les Cavaliers se trouvent sur les cases de la ligne 1 ,de la colonne 2(b) et 7(g) du joueur 1 et les Cavaliers sont des jetons de type N (kNight)
		listCell[0][1] = Cell(0, 1, Jeton(1, 1, N));
		listCell[0][6] = Cell(0, 6, Jeton(1, 1, N));
		
		// positionnement des Fous du joueur 1
		//les Fous se trouvent sur les cases de la ligne 1 ,de la colonne 3(c) et 6(f) du joueur 1 et les Fous sont des jetons de type B (Bishop)
		listCell[0][2] = Cell(0, 2, Jeton(1, 1, B));
		listCell[0][5] = Cell(0, 5, Jeton(1, 1, B));
		
		// positionnement de la reine du joueur 1
		//la reine se trouve sur la case de la ligne 1 et de la colonne 4(d), elle est un jeton de type Q (Queen)
		listCell[0][3] = Cell(0, 3, Jeton(1, 1,Q));
		
		// positionnement du Roi du joueur 1
		//le Roi se trouve sur la case de la ligne 1 et de la colonne 5(e), il est un jeton de type K (King)
		listCell[0][4] = Cell(0, 4, Jeton(1, 1,K));
		
		/*
			*********   JOUEUR 2	********
		*/
		// positionnement des Pions du joueur 2
		//placer sur chaque colonne de a à h et sur la ligne 7, tous les pions du joueur 2 , des pièces de type P (Pion)
		for (int j = 0; j < NCOL; j++) {
			listCell[6][j] = Cell(6, j, Jeton(2, 2, P));
		}
		
		// positionnement des Tours du joueur 2
		//les Tours se trouvent sur les cases de la ligne 8 ,de la colonne 1(a) et 8(h) du joueur 2 et les Tours sont des jetons de type R (Rook)
		listCell[7][0] = Cell(7, 0, Jeton(2, 2, R));
		listCell[7][7] = Cell(7, 7, Jeton(2, 2, R));

		// positionnement des Cavaliers du joueur 2
		//les Cavaliers se trouvent sur les cases de la ligne 8 ,de la colonne 2(b) et 7(g) du joueur 2 et les Cavaliers sont des jetons de type N (kNight)
		listCell[7][1] = Cell(7, 1, Jeton(2, 2, N));
		listCell[7][6] = Cell(7, 6, Jeton(2, 2, N));
		
		// positionnement du fou du joueur 2
		//les Fous se trouvent sur les cases de la ligne 8 ,de la colonne 3(c) et 6(f) du joueur 2 et les Fous sont des jetons de type B (Bishop)
		listCell[7][2] = Cell(7, 2, Jeton(2, 2, B));
		listCell[7][5] = Cell(7, 5, Jeton(2, 2, B));
		
		// positionnement de la reine du joueur 2
		//la reine se trouve sur la case de la ligne 8 et de la colonne 4(d), elle est un jeton de type Q (Queen)
		listCell[7][3] = Cell(7, 3, Jeton(2, 2, Q));
		
		// positionnement du Roi du joueur 2
		//le Roi se trouve sur la case de la ligne 8 et de la colonne 5(e), il est un jeton de type K (King)
		listCell[7][4] = Cell(7, 4, Jeton(2, 2,K));

		// initialisation des cases restantes du tableau
		//à partir de la ligne 3 jusqu'à la ligne 6, de la colonne a à h, on met les cases avec ses propres coordonnées (x,y) et le type de jeton présent sur les cases VIDE!
		for (int i = 2; i < 6; i++) {
			for (int j = 0; j < NCOL; j++)
				listCell[i][j] = Cell(i, j, Jeton());
		}
		
	}
	
	/*
		fonction qui permet de dessiner la surface du jeu à la console
	*/
	public: void drawArea() {
		cout << endl << endl << endl;
		// affichage des lettres pour les colonnes
		cout << "		";
		for (int i = 0; i < NCOL; i++)
			cout << lettre[i] << "	";
		cout << endl;
		for (int i = 0; i < NLIG; i++) {
			cout <<"	"<< NLIG - i << "	"; 	// on affiche le numéro de chaque ligne
			for (int j = 0; j < NCOL; j++) {
				if ((listCell[i][j]).getJeton().getLabel()>0)
					cout << (char)(listCell[i][j]).getJeton().getTypeJeton() << (listCell[i][j]).getJeton().getLabel() << "	";
				else
					cout << "	";
			}
			cout << NLIG - i << "   ";
			cout << endl << endl;
		}
		cout << "		";
		for (int i = 0; i < NCOL; i++)
			cout << lettre[i] << "	";
		cout << endl;
	}
	
	/*
		Permet de deplacer un jeton vers une case vide
	*/
	private: void move(int start[], int end[]) {
		listCell[end[0]][end[1]] = listCell[start[0]][start[1]];
		listCell[start[0]][start[1]] = Cell(start[0], start[1], Jeton());
	}
	
	/*
		Permet de deplacer un jeton vers une case occupée par un jeton adverse
	*/
	private:void  kill(int start[], int end[]) {
		listCell[end[0]][end[1]] = listCell[start[0]][start[1]];
		listCell[start[0]][start[1]] = Cell(start[0], start[1], Jeton());
	}
	
	/*
		Permet de permuter le roi et la tour	(Roque)
	*/
	private: void permute(int start[], int end[]) {
		if (start[1] < end[1]) {
			listCell[end[0]][end[1] - 1] = listCell[start[0]][start[1]] ;
			listCell[start[0]][start[1] + 1] = listCell[end[0]][end[1]];
			listCell[end[0]][end[1]] = Cell(end[0], end[1], Jeton());
			listCell[start[0]][start[1]] = Cell(start[0], start[1], Jeton());
		}
		if (start[1] > end[1]) {
			listCell[end[0]][end[1]+2] = listCell[start[0]][start[1]];
			listCell[start[0]][start[1] - 1] = listCell[end[0]][end[1]];
			listCell[end[0]][end[1]] = Cell(end[0], end[1], Jeton());
			listCell[start[0]][start[1]] = Cell(start[0], start[1], Jeton());
		}
		
	}
	
	/*
		Permet d'obtenir le jeton dans un case donnée
	*/
	public: Jeton getJeton(int xy[2]) {
		return listCell[xy[0]][xy[1]].getJeton();
	}
	
	/*
		Permet de definir quel deplacement à effectuer
	*/
	public: Message getMove(int start[2], int end[2]) {
		// on check si le joueur ne se deplace pas hors de plateau de jeu
		if (start[0] >= NLIG || start[1] >= NCOL || end[0] >= NLIG || end[1] >= NCOL || start[0]<0|| start[1] < 0|| end[0] < 0|| end[1] < 0) {
			return ERROR_MOVE_OUT_AREA;
		}
		else
		{   // on check si le joueur veut faire une permutation
			if (getJeton(start).getTypeJeton() == K && getJeton(end).getTypeJeton() == R && getJeton(start).getLabel() == getJeton(end).getLabel()) {
				// avant faut tester si le deplacement est correct et s'il n'ya pas d'autre jeton sur le trajet
				if (isFirstMove(getJeton(start), getJeton(end)) && isJetonInLig(start, end)) {
					permute(start, end);
					return OK;
				}
				else
					return ERROR_PERMUT_IMPOSSIBLE;
			}
			else
			{	// on test si le joueur veut eliminer le jeton adverse.
				if (getJeton(start).getLabel() > 0 && getJeton(end).getLabel() > 0 && (getJeton(start).getLabel() != getJeton(end).getLabel())) {
					// on test si c'est le pion qui elimine un jeton adverse.
					if (getJeton(start).getTypeJeton() == P) {
						if ((abs(end[0] - start[0]) == 1) && (abs(end[1] - start[1]) == 1)) {
							if (getJeton(end).getTypeJeton() == K) {
								cout << "je fini avec toi 1" << endl;
								return KILL_KING;
							}
							kill(start, end);
							return OK;
						}
					}
					else {
						// avant faut tester si le deplacement est correct et s'il n'ya pas d'autres jetons sur le trajet du jeton
						MoveDirection moveDirection = getJeton(start).isMove(start, end);
						if (moveDirection != NONE) {
							bool canMove = ifCanMove(moveDirection, start, end);
							if (canMove) {

								cout << "j'ai fini avec toi 00000" << endl;
								// test s'il s'agit du roi adverse
								if (getJeton(end).getTypeJeton() == K) {
									cout << "j'ai fini avec toi 2" << endl;
									return KILL_KING;
								}
								kill(start, end);
								return OK;
							}
							else
								return ERROR_MOVE_IMPOSSIBLE;
						}
						else return ERROR_MOVE_INCORECT;
					}
				}
				else
				{
					//"on teste si le joueur veut se deplacer sur son propre joueur"
					if (getJeton(start).getLabel() > 0 && (getJeton(start).getLabel() == getJeton(end).getLabel())) {
						return ERROR_MOVE_IN_YOUR_JETON;
					}
					MoveDirection moveDirection = getJeton(start).isMove(start, end);
					if (moveDirection!=NONE) {	// on test si le jeton se deplace correctement!
						// on va tester s'il existe un jeton sur le trajet
						bool canMove = ifCanMove(moveDirection, start, end);
									
						if (canMove) {
							move(start, end);
							listCell[end[0]][end[1]].jeton.setIsFirstMove();
							return OK;
						}
						else
							return ERROR_MOVE_IMPOSSIBLE;
					}
					else
						return ERROR_MOVE_INCORECT;
				}
			}
		}
		return KO;
	}
		  
		  /*
		  * on test s'il est possible de permuter le roi et la tour
		  */
	private: bool isFirstMove(Jeton king, Jeton rook) {
		if (!king.getIsFirstMove() || !rook.getIsFirstMove())
			return false;
		return true;
	}

	private: bool isJetonInLig(int start[2], int end[2]) {
	bool find = true;
	if (start[0] == end[0]) {
		if (start[1] > end[1]) {
			int i = start[1] - 1;
			while (find && i > end[1]) {
				if ((listCell[start[0]][i]).getJeton().getTypeJeton() > 0)
					find = false;
				i--;
			}
		}
		else {
			if (start[1] < end[1]) {
				int i = start[1] + 1;
				while (find && i < end[1]) {
					if ((listCell[start[0]][i]).getJeton().getTypeJeton() > 0)
						find = false;
					i++;
				}
			}
		}
	}
	return find;
}

	private: bool isJetonInCol(int start[2], int end[2]) {
		bool find = true;
		if (start[1] == end[1]) {
			if (start[0] > end[0]) {
				int i = start[0] - 1;
				while (find && i > end[0]) {
					if ((listCell[i][start[1]]).getJeton().getTypeJeton() > 0)
						find = false;
					i--;
				}
			}
			else {
				if (start[0] < end[0]) {
					int i = start[0] + 1;
					while (find && i < end[0]) {
						if ((listCell[i][start[1]]).getJeton().getTypeJeton() > 0)
							find = false;
						i++;
					}
				}
			}
		}
		return find;
	}

	private: bool isJetonInDiagonal(int start[2], int end[2]) {
		bool find = true;
		if (start[0] < end[0]) {
			if (start[1] < end[1]) {
				int i = start[0] + 1, j=1;
				while (find && i < end[0]) {
					if ((listCell[i][start[1]+j]).getJeton().getTypeJeton() > 0)
						find = false;
					i++;
					j++;
				}
			}
			else {
				if (start[1] > end[1]) {
					int i = start[0] + 1, j=1;
					while (find && i < end[0]) {
						if ((listCell[i][start[1] - j]).getJeton().getTypeJeton() > 0)
							find = false;
						i++;
						j++;
					}
				}
			}
		}
		else {
			if (start[0] > end[0]) {
				if (start[1] < end[1]) {
					int i = start[0] - 1, j=1;
					while (find && i > end[0]) {
						if ((listCell[i][start[1]+j]).getJeton().getTypeJeton() > 0)
							find = false;
						i--;
						j++;
					}
				}
				else {
					if (start[1] > end[1]) {
						int i = start[0] - 1, j=1;
						while (find && i > end[0]) {
							if ((listCell[i][start[1] -j]).getJeton().getTypeJeton() > 0)
								find = false;
							i--;
							j++;
						}
					}
				}
			}
		}
		return find;
	}
	private:bool ifCanMove(MoveDirection moveDirection, int start[2], int end[2]) {
	bool canMove = false;
		switch (moveDirection)
		{
		case LIG:

			canMove = isJetonInLig(start, end);
			break;

		case COL:
			canMove = isJetonInCol(start, end);
			break;
		case DIAG:
			canMove = isJetonInDiagonal(start, end);
			break;
		case L:
			canMove = true;
		}
		return canMove;
	}
};
