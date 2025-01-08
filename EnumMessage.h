

enum Message {
	KILL_KING,							// le ROI est mort
	ERROR_MOVE_OUT_AREA,				// le mouvement selectionné n'est pas dans GameArea
	ERROR_MOVE_IN_YOUR_JETON,			//Erreur de déplacement du jeton
	ERROR_MOVE_IMPOSSIBLE,				//Déplacement impossible
	ERROR_MOVE_INCORECT,				// le jeton ne se deplace come il faut
	ERROR_PERMUT_IMPOSSIBLE,			//Permutation impossible
	OK,									
	KO
};
