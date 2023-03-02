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