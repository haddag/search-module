#haddagsearch-module

##Fonctionnalité faite:

###Correction automatique des fautes d'orthographe faite dans le moteur de recherche:(Réalisé à 100%)
    
1. Tache1 (Réalisé à 100%) : Création d'un module haddagsearch avec comme fichier haddagsearch.info et haddagsearch.module.
2. Tache2 (Réalisé à 100%) : Création d'un formulaire accessible par les administrateurs uniquement pour la gestion des mots inutiles à la recherche.
3. Tache3 (Réalisé à 100%) : Création d'une fonction qui supprime les caractères pouvant se placer entre chaque mot et retourne la liste des mots dans un tableau.
4. Tache4 (Réalisé à 100%) : Création d'une fonction qui supprime les mots de la recherche et qui sont dans la liste des mots inutiles.
5. Tache5 (Réalisé à 100%) : Récupération du module sonnex.inc et suppression des fonctions inutile sau module haddagsearch.
6. Tache6 (Réalisé à 100%) : Création d'une fonction qui transforme la liste des mots de la recherche pour qu'il soit codé via le module sonnex. 
7. Tache7 (Réalisé à 100%) : Optimisation du module haddagsearch via des modification du module sonnex.inc en supprimant la fonction mb_startswith, et en rendant le                               chargement plus rapide et les tests plus précis.
8. Tache8 (Réalisé à 100%) : Test de fonctionnement.
  
###Ajout de suggestions sur le moteur de recherche à partir de 3 caractères: (Réalisé à 80%)
  
1. Tache1 (Réalisé à 100%) : Création d'un formulaire accessible par les administrateurs uniquement pour la gestion des suggestions.
2. Tache2 (Réalisé à 100%) : Création d'une fonction qui récupère la liste des suggestions et qui la trie par mots simple/mots technique.
3. Tache3 (Réalisé à 100%) : Création d'une fonction qui teste si la recherche est composée d'un mot simple et s'il possède un mot technique.
4. Tache4 (Réalisé à 100%) : Récupération du fichier autocomplete.js et modification pour que le fichier .js récupère les infos du moteur de recherche et les envoie au serveur.
5. Tache5 (Réalisé à 0%) : altération du formulaire du moteur de recherche pour charger le fichier js.
6. Tache6 (Réalisé à 0%) : Renvoie des infos au formulaire depuis le serveur.

##Fonctionnalité à faire
  
###Mettre les pages les plus importantes en première (Réalisé à 0%)
    
##Gestion de code/Versioning
  
Pour la première fonctionnalité je me suis contenté de faire des commit à chaque nouvel ajout de fonctionnalités en précisant les modifications effectuées.
J'ai créé une branche secondaire nommée optim1 pour y mettre la dernière optimisation faite qui se nomme: improved end early optimisation.
Je l'ai ensuite fusionné avec la branche principale à la fin de l'optimisation quand elle fut fonctionnelle.
  
Pour la deuxième fonctionnalité je n'ai pas commit à chaque ajout de fonctionnalité il y a donc les deux derniers commit qui sont pour la deuxième fonctionnalité.
J'ai aussi créer une nouvelle branche nommée dev_suggestion qui n'a pas été fusionnée.

##Fichier/Installation

Les fichiers nécessaires à l'installation du module haddagsearch.module, haddagsearch.info, sonnex.inc et haddagsearch-autocomplete.js
Ces fichiers seront à rajouter au dossier du site rouen.fr qui se situe dans le serveur web installer sur votre poste.
Dans les dossiers du serveur les placer dans htdocs/test/sites/all/modules/.
  
##Tests effectués

Pour la correction orthographique j'ai effectué du profilage car le chargement des pages était très lent(6 secondes), cela était du à des fonctions de sonnex qui           n'était pas optimisé (trop de fois charger ou les tests était trop lent). J'ai donc utilisé un fichier qui contenait la liste des mots du Scrabble et j'ai appliqué sonnex.inc à ce fichier pour générer un fichier texte avec les mots modifiés par sonnex.
  
1. Sans optimisation le test a duré 265 minutes et 20 secondes
2. Le deuxième test a été fait après l'optimisation sur les tests à chaque lettre rentrer par l'utilisateur. Ce test a duré 27 minutes et 23 secondes.
3. Le troisième test a été fait après le rangement des lettres par fréquence d'apparition. Ce test a duré 27 minutes et 6 secondes.
4. Le quatrième test a été fait après la fusion de la fonction mb_startwith et sonnex_sonnex. Ce test a duré 7 minutes 47 secondes.
5. Le cinquième test a été fait après l'amélioration de la fonction sonnex_sonnex. Ce test a duré 6 minutes et 10 secondes.
6. Le dernier test a été fait après la désactivation de xdebug. Ce test a duré 45 secondes.
