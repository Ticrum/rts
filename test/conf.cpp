#include "resourceManager.hh"
#include <iostream>
int main(void)
{
    ef::ConfWeapon wep;
    ef::ConfBuilding build;
    ef::ConfUnit unit;
    bool gate = true;
    int buffer = -1;
    std::string name("resours/weapon/conf/miniGun.dabsic");
    for(int i= 0; i < 10 && gate; i++)
    {
        switch(wep.load(name))
        {
        case 1:
            std::cout<< "the file is not here or can't load \n";
            break;
        case 2:
            std::cout<<"fails weapon\n";
            break;
        case 3:
            std::cout<<"fail dmg\n";
            break;
        case 4:
            std::cout<<"fail nbrAtt\n";
            break;
        case 5:
            std::cout<<"fail cdr\n";
            break;
        case 6:
            std::cout<<"fail range\n";
            break;
        case 7:
            std::cout<<"target\n";
            break;
        default :
            std::cout << "gg " << wep.conf << "\n";
            gate = false;
        }
    }
    gate = true;
    name = "resours/building/conf/LATHOURES.dabsic";
    for(int i= 0; i < 10 && gate; i++)
        switch(buffer = build.load(name))
        {
        case 1:
            std::cout << "the file is not here or can't load\n";
            break;
        case 2:
            std::cout << "fail objName\n";
            break;
        case 3:
            std::cout << "fail objName too big\n";
            break;
        case 4:
            std::cout << "fail objImgId\n";
            break;
        case 5:
            std::cout << "fail objSizeX\n";
            break;
        case 6:
            std::cout << "fail objSizeY\n";
            break;
        case 7:
            std::cout << "fail objMaxhp\n";
            break;
        case 8:
            std::cout << "fail objArmor\n";
            break;
        case 9:
            std::cout << "fail objRangeOfVision\n";
            break;
        case 10:
            std::cout << "fail buildCost\n";
            break;
        case 11:
            std::cout << "fail buildTTP\n";
            break;
        case 12:
            std::cout << "fail buildType\n";
            break;
        case 13:
            std::cout << "fail buildCanBetarguet\n";
            break;
        case 14:
            std::cout << "fail buildEnerCost\n";
            break;
        case 15:
            std::cout << "fail buildEnerProd\n";
            break;
        case 16:
            std::cout << "fail buildMoneProd\n";
            break;
        case 17:
            std::cout << "fail buildweapConfSize\n";
            break;
        case 18:
            std::cout << "fail build wrong type\n";
            break;
        case 19:
            std::cout << "fail buildCBT wrong argu\n";
            break;
        default:
            if(buffer > 0)
                std::cout << "fail build n°"<< buffer << "\n";
            else
            {
                std::cout << "gg " << build.conf << "\n";
                gate = false;
            }
        }
    gate = true;
    name = "resours/unit/conf/missingno.dabsic";
    for(int i= 0; i < 10 && gate; i++)
        switch(buffer = unit.load(name))
        {
        case 1:
            std::cout << "the file is not here or can't load\n";
            break;
        case 2:
            std::cout << "fail objName\n";
            break;
        case 3:
            std::cout << "fail objName too big\n";
            break;
        case 4:
            std::cout << "fail objImgId\n";
            break;
        case 5:
            std::cout << "fail objSizeX\n";
            break;
        case 6:
            std::cout << "fail objSizeY\n";
            break;
        case 7:
            std::cout << "fail objMaxhp\n";
            break;
        case 8:
            std::cout << "fail objArmor\n";
            break;
        case 9:
            std::cout << "fail objRangeOfVision\n";
            break;
        case 10:
            std::cout << "fail UnitCost\n";
            break;
        case 11:
            std::cout << "fail Unitspeeeeeeeeed\n";
            break;
        case 12:
            std::cout << "fail Unit2FAST4U\n";
            break;
        case 13:
            std::cout << "fail UnitmoveType\n";
            break;
        case 14:
            std::cout << "fail UnitFly\n";
            break;
        case 15:
            std::cout << "fail UnitTimeToProduce\n";
            break;
        case 16:
            std::cout << "fail UnitweaponConfSize\n";
            break;
        case 17:
            std::cout << "fail Unit Wrong Move type\n";
            break;
        case 18:
            std::cout << "fail Unit Wrong is Fly\n";
            break;
        default:
            if(buffer > 0)
                std::cout << "fail unit weapon n°"<< buffer << "\n";
            else
            {
                std::cout << "gg " << unit.conf << "\n";
                gate = false;
            }

        }
    std::cout << "___--" << wep.conf << "--___\ndmg : "<< wep.dmg<< "\nnbrAtt : "<< wep.nbrAtt<< "\ncbrMax : "<< wep.cdrMax << "\nrange : " << wep.range << "\ntarget : " << wep.manualTarget<< "\n";
    std::cout << "___--" << build.conf << "("<< build.conformConf<< ")--___\nimgId : "<< build.imgId << "\nobjSize : "<< build.objSize.x<< "; " << build.objSize.y<< "\nmaxhp : " << build.maxhp<< "\narmor : " << build.armor << "\nrangeOfVision : " << build.rangeOfVision << "\n------------\n"<<
        "cost : " << build.cost<< "\ntimeToProduce" << build.timeToProduce << "\ntype : " <<build.type << "\ncanBeTarget : " << build.canBeTarget << "\nenergyCost : " << build.energyCost << "\nenergyProduction : " << build.energyProduction << "\nmoneyProduction : " << build.moneyProduction << "\nweaponConf : (" << build.weaponConf.size() << ") | ";
    for(unsigned int i = 0; i < build.weaponConf.size(); i++)
        {
            std::cout << build.weaponConf[i]<< ",";
        }
    std::cout<< "\n";
    std::cout << "___--" << unit.conf << "("<< unit.conformConf<< ")--___\nimgId : "<< unit.imgId << "\nobjSize : "<< unit.objSize.x<< "; " << unit.objSize.y<< "\nmaxhp : " << unit.maxhp<< "\narmor : " << unit.armor << "\nrangeOfVision : " << unit.rangeOfVision << "\n------------\n"<<
        "cost : " << unit.cost << "\nspeed : " << unit.speed << "\nrunningSpeed : " << unit.runningSpeed << "\nmoveType : " << unit.moveType << "\nIsFlying : " << unit.isFlying<< "\ntimeToProduce : " << unit.timeToProduce << "\nweaponConf : (" << unit.weaponConf.size() << ") | ";
    for(unsigned int i = 0; i < unit.weaponConf.size(); i++)
        {
            std::cout << unit.weaponConf[i]<< ",";
        }
    std::cout<< "\n";
}