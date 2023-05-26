# labyrintheAveugle

## générateur de labyrinthe

**algorithme sidewinder**

* N=1
* S=4
* E=2
* W=8

```
g++ sidewinder.cpp -o sidewinder
```
```
./sidewinder
```

# Procédure de compilation, de lancement et de test

Ce fichier README décrit la procédure complète pour compiler, lancer et tester les programmes OpenGL du livre D-BookeR.

## Installation des dépendances

Avant de compiler les programmes, vous devez vous assurer d'avoir installé les dépendances suivantes :

- libglfw3-dev
- libglew-dev
- libsdl2-dev
- libsdl2-image-dev
- libopenal-dev
- libalut-dev

Vous pouvez les installer en utilisant la commande suivante :
sudo apt-get install libglfw3-dev libglew-dev libsdl2-dev libsdl2-image-dev libopenal-dev libalut-dev

## Compilation

Pour compiler les programmes, exécutez la commande suivante :
make

Cela va générer les exécutables dans le répertoire courant.

## Lancement

Pour lancer un programme, exécutez la commande suivante :
make run

Cela exécutera le programme principal.