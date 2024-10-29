#include <iostream>

#include "toml.hpp"

#include "utility.hpp"
#include "overhead.hpp"
#include "die.hpp"
#include "engagement.hpp"
#include "entity.hpp"

#include "boost/bimap/bimap.hpp"

int main(int argc, char* argv[]){
    
    //accept exactly one argument
    if(argc != 2){
        std::cout << "Pass exactly 1 argument: Path to roll config file in rolls/" << std::endl;
        return 1;
    }

    //try to parse toml file    
    toml::table tbl;
    try{
        tbl = toml::parse_file(argv[1]);
        std::cout << "Parsed input successfully." << std::endl;
    }
    catch(const toml::parse_error& err){
        std::cerr << "Parsing failed" << std::endl
                  << err << std::endl;
        return 1;
    }

    //iterate over entities in the config file
    std::vector<Entity*> entities;
    for (auto&& entity : *tbl["entity"].as_array()){
        const toml::table& subTbl = *entity.as_table();
        if(subTbl.contains("name")){
            std::string name = subTbl["name"].as_string()->get();
            std::cout << "Load Entity: " << name << std::endl;
            Entity* newEntity = new Entity(*entity.as_table());
            entities.push_back(newEntity);
        } else {
            std::cout << "Nameless entity encountered!" << std::endl;
        }
    }

    //build the rules
    Overhead* overhead = new Overhead();

    Engagement ohai(entities[0],entities[1]);

    Die d(100);
    d.Roll();
    std::cout << "Roll the die: " << d << std::endl;

    return 0;
}