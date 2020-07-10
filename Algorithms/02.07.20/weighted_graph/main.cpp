#include<iostream>
#include "graph.hpp"

int main() {
    Graph city;

    /* Adding city if not exist, first argument is name of city,
     * second argument is destination,
     * third argument is distance(km) */
    city.add_city("Vanadzor", "Gyumri", 68);
    city.add_city("Vanadzor", "Aparan", 63);
    city.add_city("Vanadzor", "Dilijan", 36);
    city.add_city("Erevan", "Aparan", 56);
    city.add_city("Erevan", "Sevan", 61);
    city.add_city("Dilijan", "Sevan", 35);

    std::cout << "My Graph" << std::endl << std::endl;

    /* print all edges and weights */
    city.print("Vanadzor");
    city.print("Erevan");
    city.print("Sevan");

    return 0;
}

/*                              GRAPH                                 *
 *                                                                    *
 *        _________            _________            _________         *
 *       |Vanadzor |____63____| Aparan  |____56____| Erevan  |        *
 *       |__ID_0___|          |__ID_2___|          |__ID_1___|        *
 *            |     \                                   |             *
 *          68|      \36                                |61           *
 *            |       \                                 |             *
 *        ____|____    \ ________                   ____|____         *
 *       | Gyumri  |    |Dilijan |_______35________|  Sevan  |        *
 *       |__ID_3___|    |__ID_4__|                 |__ID_5___|        *
 *                                                                    *
 *                                                                    *
 *                                                                    *
 */