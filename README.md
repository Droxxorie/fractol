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

### [MinilibX](https://github.com/42paris/minilibx-linux.git)



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

