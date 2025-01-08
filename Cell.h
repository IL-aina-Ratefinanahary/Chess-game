#include "Jeton.h"				//fichier Jeton.h est utilisé ici

class Cell						// création d'une classe Cell (une case de notre Echequier)
{
	int x;						//contenant les attributs (coordonnées) x (horizontale) et y (verticale)
	int y;
	public :Jeton jeton;		


	public:Cell(int x, int y, Jeton jeton) {			//constructeur Cell qui contient les coordonnées x, y puis le type de jeton
			this->x = x;
			this->y = y;
			this->jeton = jeton;
	}

	public:Cell(){}	

	public:int getX() {	return x;}			//Pour avoir la valeur sur x
	public:int getY() { return y;}			//Pour avoir la valeur sur y
	public: Jeton getJeton() { return jeton; }		//Pour avoir le type de jeton sur la case de notre echequier

};

