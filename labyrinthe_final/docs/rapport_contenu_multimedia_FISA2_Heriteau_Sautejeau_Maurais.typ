#import "enssat.typ":*
#show: doc => conf(
  titre: [ Projet "Labyrinthe aveugle" ],
  auteurs: (
    (nom: "Pierre Alain", email:"alain@enssat.fr"),
    (nom: "Romain Heriteau", email:"rheritea@enssat.fr"),
    (nom: "Florian Sautejeau", email:"fsauteje@enssat.fr"),
    (nom: "Antoine Maurais", email:"amauraisb@enssat.fr"),
  ),
  annee: 2023,
  promotion: "Fisa Informatique 2",
  module: "Contenu Multimédia",
  doc,
)

= Introduction


== Présentation du projet "Labyrinthe aveugle"

Le projet "Labyrinthe aveugle" consiste à la création d'une application de jeu, en équipe. Le jeu est un labyrinthe dans lequel le joueur doit s'orienter grâce au son. En effet, le joueur ne verra pas le labyrinthe ainsi que sa position dans celui-ci. Ce projet dispose de 3 niveaux d'avancement qui sont les suivants :
- *Echo-location simple* : Le joueur doit appuyer sur des touches pour savoir s'il y a un mur à droite/gauche/devant (/en haut/en bas pour la version en 3dimensions).
- *Echo-location avancée* : Le joueur obtient automatiquement un retour en fonction de son envi-
ronnement.
- *Ajout d'un mode spectateur* : Pour des raisons de debug, vous pouvez avoir besoin d’afficher le
labyrinthe dans une fenêtre et la rendre visible aux spectateurs


== Présentation des membres du groupe

Ce projet est à réaliser en groupe, notre équipe, la FAR est composée de 3 membres. Florian Sautejeau, Antoine Maurais et Romain Heriteau composent la FAR. 


= Le travail en équipe

Afin de méner à bien ce projet en groupe nous avons fonctionné sous la forme de mini-scrum. Un cycle correspondait à une séance de 3h30. Celui-ci débutait par un point d'équipe où chacun décidait les tâches à réaliser au cours de la séance. Et il finissait par une présentation du travail réalisé. Cela nous a permis de nous faire des feedbacks et d'adapter notre trajectoire sur le long terme. Nous avons utilisé les outils suivant :
- *Trello* pour la gestion de l'état de nos tâches et de notre reste à faire.
- *git* pour le développement collaboratif avec l'aide de son système de branches.



= Mise en place technique

Le développement du jeu a été réalisé en C++. Le C++ est un langage de programmation orienté objet créé en 1983 par Bjarne Stroustrup. Aucun membre de notre équipe avait d'expérience sur ce langage de programmation nous avons du montée en compétence.

== Choix de la méthode de génération du labyrinthe

Nous avons décidé de réaliser un labyrinthe en 2 dimensions. La génération de celui-ci est assurée par une méthode

== Utilisation d'OpenAL pour la gestion du son

En ce qui concerne la gestion du son nous avons fait le choix d'OpenAL. OpenAL (Open Audio Library) est un bibliothèque pour la gestion de la lecture audio 3D, créée par Creative Labs en 2000. Cette bibliothèque était parfaite pour nous car elle permet de gérer le son en 3 dimensions, elle est open source et elle dispose d'une bonne documentation. 

== Mise en place de l'écho-location

= Architecture logicielle

= Tests
A la fin de chaque itération de notre mini-scrum nous mettions en commun notre code et le testions. Ces tests etaient orientées côté utilisateur avec des tests utilisateurs. Ainsi chaque membre de l'équioe testait sur sa machine le bon fonctionnement du jeu.

= Conclusion

Pour conclure 

Montée en compétence sur C++, travail d'équipe, difficulté environnement 




