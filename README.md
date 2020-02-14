# cub3d
Petit jeu 3d en raycasting

Pour executer : ./cub3d map.cub

Le ray casting a proprement parler se fait dans testfelsprite.c
Quand le rayon projeté touche une case correspondant a un sprite, il relance un autre rayon a partir de la position de l'impact, et ce de maniere recursive, ce qui permet d'empiler les sprites touchés et d'imprimer le premier touché en dernier.
Ca a l'air d'etre une bonne base pour implementer des portals.
