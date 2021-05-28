#include"GunInterface.h"
#include"WaterGun.h"

#pragma once
class WaterGunWrapper : public GunInterface
{
protected:
    WaterGun* waterGun;
public:
    void fire()
    {
        waterGun->lanzaAgua();
    }
};