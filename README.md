# Projet casse briques (3 AL2)

Lien du [dépôt](https://github.com/ZK1569/BomberMan) GitHub : https://github.com/ZK1569/BomberMan

- [Instructions pour démarrer](#instructions-pour-demarrer)
- [Informations du jeu](#informations-du-jeu)
  - [Touches](#touches)
  - [Motifs](#motifs)
- [Contributeurs groupe 1](#contributeurs-groupe-1)

<a id="instructions-pour-demarrer"></a>
## Instructions pour démarrer
- Au préalable sur sa machine, avoir installé `sdl2`, `sdl2_ttf` et `sdl2_image`.
  - Sinon si vous êtes sur Mac par exemple :
      ```
      brew install sdl2
      brew install sdl2_ttf
      brew install sdl2_image
      ```
- Si vous utilisez un éditeur tel que CLion, il suffit de lancer le programme à partir du bouton "Lancer" / "Run" ou à partir du menu correspondant.
- Sinon à partir de la racine du projet, vous pouvez utiliser la ligne de commande pour construire le programme puis l'exécuter :
  ```shell
  mkdir build
  cd build
  cmake ..
  make
  ./BomberMan
  ```
<br /><br />
Une fois que le programme a démarré, le jeu se déroule dans la console.

## Informations du jeu
### Touches
- Mode console :
  - Déplacements :
    - `E` : aller en haut
    - `S` : aller à gauche
    - `D` : aller en bas
    - `F` : aller à droite
  - Actions :
    - `P` : poser une bombe
    - `ESPACE` : passer son tour
    - `Entrée` : valider son choix
- Mode graphique :
  - Déplacements (joueur 1) :
  - `↑` : aller en haut
  - `←` : aller à gauche
  - `↓` : aller en bas
  - `→` : aller à droite
  - Actions :
    - `E` : poser une bombe

### Motifs
- Mode console :
  - Décor :
    - ⬜️ : mur incassable
    - 🟫 : mur fragile
    - 💥 : explosion de mur ne contenant aucun objet
    - ⬛️ : espace vide
    - 🔥 : déflagration de bombe
  - Joueurs :
    - 🙂 : joueur 1
    - 😛 : joueur 2
    - 🙁 : joueur 3
    - 😮 : joueur 4
    - 💀 : joueur mort durant un tour
  - Objets :
    - 💣 : bombe
    - 🔽 : ajoute une bombe au joueur
    - 🔼 : diminue une bombe au joueur
    - 🟡 : ajoute une portée aux bombes du joueur
    - 🔵 : diminue d'une portée aux bombes du joueur
    - 🔴 : ajout maximal de la portée des bombes du joueur (objet rare)
    - 🏃 : permet de traverser les bombes (remplace 👟)
    - 👟 : permet d'envoyer une bombe au loin (remplace 🏃)
    - 🦺 : invincibilité (2 tours ou 10 secondes pour le temps réel)
    - 💖 : survivre à une explosion (objet utilisable qu'une fois durant la partie)
    - 🆙 : ajoute un point de vie au joueur

## Contributeurs du groupe 1
- [Abdoulaye DIA](https://github.com/adia-dev)
- [Cristian URSU](https://github.com/ZK1569)
- [Loïc ZHU](https://github.com/LoicZHU)