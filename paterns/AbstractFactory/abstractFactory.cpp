#include "abstractFactory.h"

int main()
{

    Furniture furniture;
    ArtDecoFurnitureFactory adf_factory;
    VictorianFurnitureFactory vf_factory;
    ModernFurnitureFactory mf_factory;

    AllFurniture *adf = furniture.createFurniture(adf_factory);
    AllFurniture *vf = furniture.createFurniture(vf_factory);
    AllFurniture *mf = furniture.createFurniture(mf_factory);

    std::cout << "=========================================\n";
    std::cout << "ArtDeco Furniture Factory:" << std::endl;
    adf->info();
    std::cout << "=========================================\n";
    std::cout << "VictorianFurnitureFactory:" << std::endl;
    vf->info();
    std::cout << "=========================================\n";
    std::cout << "ModernFurnitureFactory:" << std::endl;
    mf->info();

    return 0;
}