#pragma once
class GunInterface
{
public:
    virtual void fire() = 0;  // Método virtual puro  -> método abstracto -> el cascaron de una acción
                              // los métodos abstractos se implementan no se sobrescriben
};
