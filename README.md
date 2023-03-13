# Exercice demande de valeurs

## Objectifs
Les buts de ce laboratoire sont :
- Interface utilisateur.
- Lecture écriture de fichiers texte.

## Cahier des charges
Développer un programme respectant les contraintes suivantes :

- Un menu permet de choisir entre ces 3 options :
  1. Commencer une nouvelle saisie.
  2. Afficher le contenu du fichier de saisie.
  3. Ajouter une valeur dans le fichier.
  4. Afficher la moyenne des valeurs du fichier.
  5. Quitter le programme.

**Option 1 :**
Efface le contenu du fichier et affiche un message de confirmation.

**Option 2 :**
Affiche le contenu du fichier texte.

**Option 3 :**
Demande une valeur à l'utilisateur et l'ajoute à la fin du fichier texte.
La mesure doit être enregistrée avec la date courante.

**Option 4 :**
Affiche la moyenne des valeurs du fichier texte.

**Option 5 :**
Quitte le programme.

## Format du fichier texte
Le fichier texte contient une valeur par ligne.

Le format de la ligne est ainsi :
```
date,valeur
```

Exemple de fichier :
```
2018-01-01,10
2021-08-02,4.56
2023-01-03,-12.5
```


# Partie 2, les fichiers binaires
- Créer une structure pour stocker une saisie.
- Il faut un champ pour stocker le numéro de la mesure.
- Le numéro de la mesure et la valeur sont des entiers de 16 bits.
- Les structures doivent être sauvées dans un fichier binaire.
- Les mesures sont stockées à la suite et il y a toujours un incrément de `1` entre chaque mesure.
- Créer une fonction pour afficher une structure de mesure.
- Créer une fonction pour lire une mesure à une position donnée en paramètre.
  - La fonction affiche la mesure trouvée.
  - `readMeasure(FILE *file, int position)`
- Créer une fonction pour rechercher une mesure en fonction de sa valeur (la première valeur trouvée).
  - La fonction affiche la mesure trouvée.
  - `findMeasure(FILE *file, int value)`
- Créer une fonction qui affiche la taille du fichier en `bytes`.

- Une fois fonctionnel, ajouter une chaîne de caractère pour ajouter un nom à la mesure.
  - Pas besoin de le demander à l'utilisateur, utiliser un nom fixe.
  - Modifier la fonction d'affichage pour afficher le nom de la mesure.

## Hexdump
- Installer l'extension hexdump pour VSCode (ms-vscode.hexeditor).
- Sauvegarder une seule structure dans un fichier binaire et contrôler le contenu du fichier avec l'extension hexdump.

## Questions
- Que se passe-t-il si une mesure est sauvée avec une mauvaise taille ?
- Comment garantir que la structure lue est correcte ?
- Comment est sauvée la chaîne de caractère dans le fichier binaire ?