**Chess Game with C++

Simpler as possible!

Structure et Utilité des Fichiers du Projet
1. Cell.h

    Définit ce qu’est une case de l’échiquier.
   
    Une case est caractérisée par :
   
        Coordonnées : x et y.
        Type de jeton : Le type de pièce (ou absence de pièce) occupant cette case.

3. EnumMessage.h

    Contient les messages standard utilisés dans le jeu, tels que les erreurs ou les notifications d'état.

4. EnumTypeJeton.h

    Définit les constantes associées aux différents types de pièces du jeu (roi, reine, fou, etc.).
   
    Simplifie la gestion et l’identification des jetons.

6. Utils.h

    Regroupe des fonctions utilitaires génériques utilisées dans plusieurs parties du code, optimisant la réutilisabilité.

7. GameArea.h

    Définit les éléments essentiels pour gérer l’échiquier :
   
        Règles de jeu : Implémentation des règles des échecs.
        Mouvements possibles : Gestion des déplacements des pièces.
        Disposition initiale : Placement des pièces sur l’échiquier au début de la partie.

9. Jeton.h

    Décrit les différents types de pièces d'échecs.
   
    Définit leurs caractéristiques et comportements :
   
        Déplacement : Types de mouvements autorisés pour chaque pièce.
        Attaque : Règles pour capturer une pièce adverse.

Relations entre les Fichiers

Source.cpp

    Fichier principal, incluant tous les autres fichiers pour exécuter le programme.

Dépendances

    GameArea.h dépend de :
        Cell.h pour gérer les cases de l’échiquier.
        EnumMessage.h pour utiliser les messages standard.

    Jeton.h dépend de :
        EnumTypeJeton.h pour identifier les types de pièces.
        Utils.h pour utiliser des fonctions utilitaires.

    Fichiers indépendants :
        Utils.h, EnumTypeJeton.h, et EnumMessage.h sont autonomes et n’utilisent pas d’autres fichiers, bien que d'autres modules dépendent d’eux.

I.R (07/01/2025)
