#include <iostream>


#include <unordered_set>
#include <chrono>
#include "Cat.h"

//#include "hash.h"
//#include "Cat.h"


#include "generate_collisions.h"




int main(int argc, char ** argv)
{

    std::unordered_set < Cat , Cat_Hash , Cat_Equal > cats;

    cats.insert(Cat("Baris",2,"Black"));
    cats.insert(Cat("Barsik",3,"White"));
    cats.insert(Cat("Cat",4,"Red"));
    cats.insert(Cat("Barsik",1,"White"));


	for (const auto & cat : cats)
	{
		std::cout << cat << std::endl;
	}





	return 0;
}
