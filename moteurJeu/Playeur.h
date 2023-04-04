#ifndef PLAYEUR_H
#define PLAYEUR_H

#include <gl-matrix.h>

class Playeur
{
private:
    vec2 position;

public:
    /** constructeur, crée les objets 3D à dessiner */
    Playeur();

    /** destructeur, libère les ressources */
    ~Playeur();

    /**
     * retourne la position du joueur dans le labyrinthe
     * @return vec2 position
     */
    vec2 &getPosition();

    /**
     * affecte la position du joueur dans le labyrinthe
     * @param vec2 pos position
     */
    void setPosition(vec2 pos);

    /**
     * affecte la position % scène du cube
     * @param vec3 pos position
     */
    void setPosition(vec3 pos);
};

#endif
