#include"GunInterface.h"
#include"FireGun.h"

#pragma once
class FireGunWrapper : public GunInterface
{
protected:
    FireGun* fireGun;
public:
    void fire()
    {
        fireGun->lanzaLlamas();
    }
};