# Fractol

## Language : C

Ce projet à été réalisé dans le cadre du cursus à l'école **42 Paris**.

Fractol est un programme permettant d'afficher et d'éxplorer différentes fractales intéractives à l'aide de la bibliothèqe graphique MinilibX. Il met en oeuvre des calculs mathématiques afin de tracer en temps réel des ensembles fractals.

---

## Instalation et Compilation

### Prérequis

- Une machine sous **Linux** ou **MacOS**
- La bibliothèque **MinilibX** installée
- Un compilateur **cc**

### MinilibX

Avant de compiler le projet, il est nécessaire d'installer la **[MinilibX](https://github.com/42paris/minilibx-linux.git)**.

Il faut :

Cloner la MinilibX dans le dossier du proejt puis y rentrer :

```sh
git clone https://github.com/42paris/minilibx-linux.git minilibx && cd minilibx
``` 

Compiler la MinilibX puis sortir :

```sh
make && cd ..
```

### Compilation

La commande suivante génère un exécutable 'fractol':

```sh
make
```

Pour nettoyer les fichiers objets :

```sh
make clean
```

Pour supprimer les fichiers objets et l'exécutable :

```sh
make fclean
```

Pour recompiler depuis zéro :

```sh
make re
```

---

## Utilisation

Le programme prends en argument le type de fractale à afficher :

```sh
./fractol [type]
```

Avec '[type]' pouvant être :

- 'mandelbrot'
- 'julia' <x> <y>

Exemple :

```sh
./fractol julia -1.47 0.0
```

---

## Contrôles

- **Zoom** : 'Molette' (centré au milieu de l'écran)
- **Modifier les coordonnées de Julia** : '8, 2, 4, 6' (pavé numérique)
- **Changer de fractale** : 'Espace'
- **Changer de mode de calcul (interpolation ou non)** : 'F1'
- **Quitter** : 'ESC'
- **[+] [-]** : Changer la qualité du fractal.

Dans cette première partie **il n'est pas possible de se déplacer, de changer de couleurs ou de zoomer sur le curseur**.

L'interface utilisateur est disponible et affiche les contrôles ainsi que des informations.

---

### Fonctionnement de l'algorithme

L'algorithme repose sur plusieurs étapes :

1. **Initialisation des données**

  - Définition des paramètres d'affichage et des constantes fractales en fonction de l'entrée.

2. **Calcul des ensempbles fractals**

  - Chaque pixel est évalué en fonction de son appartenance à l'ensemble fractal choisi.
  - Utilisation d'une **Interpolation par plus proche voisin** permettant un calcul plus rapide au détriment de la qualité.
  - Possibilité de **modifier le nombre d'itérations avant divergence** pour ajuster la précision de l'affichage.

3. **Rendu graphique**

  - Transformation des valeurs calculées en couleurs et gradient.
  - Affichage via la MinilibX.

4. **Gestion des interactions Utilisateur**

  - Réactivité aux entrées clavier et souris.
