#include<string>
#include"GunInterface.h"
#include"WaterGunWrapper.h"
#include"FireGunWrapper.h"
#include"MissileGunWrapper.h"

class Tank
{
protected:
    GunInterface* gun;
public:
    Tank() : gun(0){}
    void fire();
    void setGun(GunInterface* gun);
};
void Tank::fire()
{
    if (gun == 0)
        cout << "the gun is not already set";
    else
        gun->fire();
}

void Tank::setGun(GunInterface* gun)
{
    this->gun = gun;
}

int main()
{
    Tank tank;
    WaterGunWrapper waterGun;
    MissileGunWrapper misilGun;
    FireGunWrapper fireGun;
    tank.setGun(&waterGun);
    tank.fire();
    tank.setGun(&misilGun);
    tank.fire();
    tank.setGun(&fireGun);
    tank.fire();
}


