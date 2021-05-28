#include"GunInterface.h"
#include"MissileGun.h"

#pragma once
class MissileGunWrapper : public GunInterface
{
protected:
    MissileGun* missileGun;
public:
    void fire()
    {
        missileGun->lanzaMisiles();
    }
};
