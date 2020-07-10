#include<iostream>
#include "graph.hpp"

void print_graph();

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

    std::cout << "From [source]: to [destination]\n\n";

    /* print all edges and weights */
    city.print("Vanadzor");
    city.print("Erevan");
    city.print("Sevan");
    city.print("Dilijan");
    city.print("Aparan");
    city.print("Gyumri");

    std::cout << "\nCall Dijkstras_path(src, dst) function.\n";
    std::cout << "_________________________________\n";

    city.dijkstras_path("Vanadzor", "Sevan");
    city.dijkstras_path("Vanadzor", "Erevan");
    city.dijkstras_path("Gyumri", "Sevan");
    city.dijkstras_path("Gyumri", "Erevan");

    std::cout << std::endl;
    print_graph();

    return 0;
}

/* Only for example :-) */
void print_graph() {
    std::cout << " _________            _________            _________         \n";
    std::cout << "|Vanadzor |____63____| Aparan  |____56____| Erevan  |        \n";
    std::cout << "|_________|          |_________|          |_________|        \n";
    std::cout << "     |     \\                                   |             \n";
    std::cout << "   68|      \\36                                |61           \n";
    std::cout << "     |       \\                                 |             \n";
    std::cout << " ____|____    \\ ________                   ____|____         \n";
    std::cout << "| Gyumri  |    |Dilijan |_______35________|  Sevan  |        \n";
    std::cout << "|_________|    |________|                 |_________|        \n\n";
}