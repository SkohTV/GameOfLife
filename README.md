### Description :

<br>

Créer un programme en C avec une arborescence et documentation propre et détaillée<br>
Le rendu final est un gif des X premières étapes du jeu de la vie.<br>
La taille de la grille et de la forme initiale doit être customizable<br>
Différentes grilles initiales ppm sont chargeables

__Règles du Jeu de la Vie__<br>
On commence avec une grille 2D et une forme de départ<br>
On réalise X tours avec les règles suivantes :<br>
\- Si une case possède deux ou trois cellules voisines, elle devient une cellule<br>
\- Sinon elle meurt de surpopulation / isolement<br>

<br>

---

<br>

### Etape de conception

<br>

<details><summary>Initialisation</summary><ul>
    <details><summary>Création de l'arborescence</summary><ul>
        Makefile<br>
        README.md<br>
        main.c<br>
        game.c (dans /code)<br>
        game.h (dans /code)<br>
        image.c (dans /code)<br>
        image.h (dans /code)<br>
        render.gif<br>
        /initial (Contient les grilles initiales)<br>
        /images (Contient les images 1 à X)<br>
    </ul></details>
    <details><summary>Formating des fichiers</summary><ul>
        Création de la doc<br>
        Bases des fichiers<br>
        Création des /initials<br>
        Choix de valeurs de départ dans le main.c (custom plus tard)<br>
    </ul></details>
</ul></details>
<details><summary>Programmation</summary><ul>
    <details><summary>Début</summary><ul>
        Affiche grille<br>
        Convertir grille en ppm et exporter dans /images<br>
        Charge fichier local et exporte en grille initiale<br>
        Export grille en image .ppm<br>
    </ul></details>
    <details><summary>Règles</summary><ul>
        Coder règles du jeu<br>
        Faire évoluer la grille<br>
        Exporter multiples images<br>
    </ul></details>
    Convert multiple ppm to gif (imageMagick)<br>
    <details><summary>Customisation</summary><ul>
        Créer custom<br>
        Limites de custom<br>
    </ul></details>
</ul></details>

<br>

__Conventions__<br>
0 = vide | 1 = plein<br>