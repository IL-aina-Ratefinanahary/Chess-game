#include <iostream>
using namespace std;
#include "EnumTypeJeton.h"
#include "Utils.h"
enum MoveDirection {
	LIG,// delacement sur la ligne
	COL,//deplacement sur une colonne
	DIAG,//deplacement en diagole
	L, // deplacement du cavalier
	NONE // deplacement incorrect
};
class Jeton
{
	int label;
	bool isFirstMove;
	TypeJeton typeJeton;
	public: Jeton(int label, int color, TypeJeton typeJeton) {
		this->label = label;
		this->typeJeton = typeJeton;
		isFirstMove = true;
	};
public: void setTypeJeton(TypeJeton type) { this->typeJeton = type; }
	public: bool getIsFirstMove() { return this->isFirstMove; }
	public: void setIsFirstMove() { 
		this->isFirstMove = false; 
	}
	public: int getLabel() { return label; }
	public: int getTypeJeton() { return typeJeton; }
	public : Jeton(){
		this->label = -1;
	}
	/*
	   permet de tester si le deplacement est correct en fonction du type de jeton
   */
	public: MoveDirection isMove(int startCell[2], int endCell[2]) {
		switch (typeJeton)
		{
			case K :
				return isMoveKing(startCell, endCell);
			break;
			case Q:
				return isMoveQueen(startCell, endCell);
				break;
			case P:
				return isMovePawn(startCell, endCell);
				break;
			case R:
				return isMoveRook(startCell, endCell);
				break;
			case N:
				return isMoveKNight(startCell, endCell);
				break;
			case B:
				return isMoveBishop(startCell, endCell);
				break;

		}
	}
		  // Roi
	private: MoveDirection isMoveKing(int startCell[2], int endCell[2]) {
		if ((abs(startCell[0] - endCell[0]) == 1) && (abs(startCell[1] - endCell[1]) == 1))
			return DIAG;
		if ((abs(startCell[0] - endCell[0]) == 1) && startCell[1] == endCell[1])
			return COL;
		if ((abs(startCell[1] - endCell[1]) == 1) && startCell[0] == endCell[0])
			return LIG;
		return NONE;
	}
		   // Reine
	private:MoveDirection isMoveQueen(int startCell[2], int endCell[2]) {
		if ((startCell[0] == endCell[0]))
			return LIG;
		if((startCell[1] == endCell[1]))
			return COL;
		if (abs(startCell[0] - endCell[0]) == abs(startCell[1] - endCell[1]))
			return DIAG;
		return NONE;
	}
		   // Tour
	private:MoveDirection isMoveRook(int startCell[2], int endCell[2]) {
		if ((startCell[0] == endCell[0]))
			return LIG;
		if (startCell[1] == endCell[1])
			return COL;
		return NONE;
	}
		// Fou
	private:MoveDirection isMoveBishop(int startCell[2], int endCell[2]) {
		if (abs(startCell[0] - endCell[0]) == abs(startCell[1] - endCell[1]))
			return DIAG;
		return NONE;
	}

	// Pion
	private:MoveDirection isMovePawn(int startCell[2], int endCell[2]) {

		/*
			pour un pion si c'est la premiere fois : il peut faire un saut de deux cases
		*/
		if (startCell[1] != endCell[1])
			return NONE;
		else
		{
			if (isFirstMove) {
				if (label == 1) {// joueur 1
					if (startCell[0] - endCell[0] == -2 || startCell[0] - endCell[0] == -1) {
						return COL;
					}
				}
				else {
					if (startCell[0] - endCell[0] == 2 || startCell[0] - endCell[0] == 1) {
						return COL;
					}
				}
			}
			else {
				if (label == 1) {// joueur 1
					if (startCell[0] - endCell[0] == -1) {
						return COL;
					}
				}
				else {
					if (startCell[0] - endCell[0] == 1) {
						return COL;
					}
				}
			}
		}
		return NONE;
	}

	// cavalier
	private:MoveDirection isMoveKNight(int startCell[2], int endCell[2]) {
		if (abs(endCell[0] - startCell[0]) == 1 && abs(endCell[1] - startCell[1]) == 2)
			return L;
		if (abs(endCell[0] - startCell[0]) == 2 && abs(endCell[1] - startCell[1]) == 1)
			return L;
		return NONE;
	}
};

/*0
// roi
class King : public Jeton
{
	
	public:King(int label, int color) : Jeton(label, color) {
		this->typeJeton = K;

	};
	
	
		//permet de tester si le deplacement est correct en fonction du type de jeton
	
	public:bool isMove(int startCell[2], int endCell[2]) {
		if ((abs(startCell[0] - endCell[0]) == 1) && (abs(startCell[1] - endCell[1]) == 1))
			return true;
		if((abs(startCell[0] - endCell[0]) == 1) && startCell[1] == endCell[1])
			return true;
		if ((abs(startCell[1] - endCell[1]) == 1) && startCell[0] == endCell[0])
			return true;
		return false;
	}
		
};

//Reine
class Queen :public Jeton
{
	
	public:Queen(int label, int color) : Jeton(label, color) {
		this->typeJeton = Q;
	};

	public:bool isMove(int startCell[2], int endCell[2]) {
		if ((startCell[0] == endCell[0]) || (startCell[1] == endCell[1]))
			return true;
		if (abs(startCell[0] - endCell[0]) == abs(startCell[1] - endCell[1]))
			return true;
		return false;
	}
};
//Tour
class Rook : public Jeton
{
	public:Rook(int label, int color) :Jeton(label, color) {
		this->typeJeton = R;
	};
	
	public:bool isMove(int startCell[2], int endCell[2]) {
		if ((startCell[0] == endCell[0]) || (startCell[1] == endCell[1]))
			return true;
		return false;
	}

};

//Fou

class Bishop : public Jeton
{

	public:Bishop(int label, int color) : Jeton(label, color) {
		this->typeJeton = B;
	};

	public:bool isMove(int startCell[2], int endCell[2]) {
		if (abs(startCell[0] - endCell[0]) == abs(startCell[1] - endCell[1]))
			return true;
		return false;
	}

};

//Pion
class Pawn : public Jeton
{
	bool isFirstMove = true;
	public:
	void setFirstMove() {
		isFirstMove = false;
	}

	public:Pawn(int label, int color) : Jeton(label, color) { this->typeJeton = P; };
	


	public:bool isMove(int startCell[2], int endCell[2], bool desc) {
		
	
		if (isFirstMove) {
			if (!desc) {
				if ((endCell[0] - startCell[0] == 2) && (endCell[1] == startCell[1]))
					return true;
			}
			else
				if ((endCell[0] - startCell[0] == -2) && (endCell[1] == startCell[1]))
					return true;
		}

		if(!isFirstMove)
			if (!desc) {
				if (endCell[0] - startCell[0] == 1 && (endCell[1] == startCell[1]))
					return true;
			}else 
				if (endCell[0] - startCell[0] == -1 && (endCell[1] == startCell[1]))
					return true;
		
		return false;
	}

};


//chevalier
class KNight : public Jeton
{

	public:KNight(int label, int color) : Jeton(label, color) { this->typeJeton = N; };

	public:bool isMove(int startCell[2], int endCell[2]) {
		if (abs(endCell[0]-startCell[0]) == 1 && abs(endCell[1]-startCell[1]) == 2)
			return true;
		if (abs(endCell[0] - startCell[0]) == 2 && abs(endCell[1] - startCell[1]) == 1)
			return true;
		return false;
	}
};*/