#include "QueryBuilder.hpp"

#include <iostream>

int main()
{
    QueryBuilder l_Builder(QueryTypes::Update, "item_template");

    l_Builder.AddColumn(0, DataType::Key, "entry", "1337");
    l_Builder.AddColumn(0, DataType::Key, "class", "2");
    l_Builder.AddColumn(0, DataType::None, "subclass", "7");
    l_Builder.AddColumn(0, DataType::None, "name", "Lost sword of the four gods");
    l_Builder.AddColumn(0, DataType::None, "inventorytype", "13");
    l_Builder.AddColumn(0, DataType::None, "description", "Idk a god damn description");
    l_Builder.AddColumn(0, DataType::None, "stat_type1", "3");
    l_Builder.AddColumn(0, DataType::None, "stat_value1", "3333");

    l_Builder.AddColumn(1, DataType::Key, "entry", "1337420");
    l_Builder.AddColumn(1, DataType::None, "class", "2");
    l_Builder.AddColumn(1, DataType::None, "subclass", "7");
    l_Builder.AddColumn(1, DataType::None, "name", "Lost sword of the fifth gods");
    l_Builder.AddColumn(1, DataType::None, "inventorytype", "17");
    l_Builder.AddColumn(1, DataType::None, "description", "Idk a god damn description LoL");
    l_Builder.AddColumn(1, DataType::None, "stat_type1", "4");
    l_Builder.AddColumn(1, DataType::None, "stat_value1", "5555");

    printf("%s\n", l_Builder.Generate().c_str());

    l_Builder.Reset(QueryTypes::Replace, "item_template");

    l_Builder.AddColumn(0, DataType::Key, "entry", "1337");
    l_Builder.AddColumn(0, DataType::None, "class", "2");
    l_Builder.AddColumn(0, DataType::None, "subclass", "7");
    l_Builder.AddColumn(0, DataType::None, "name", "Lost sword of the four gods");
    l_Builder.AddColumn(0, DataType::None, "inventorytype", "13");
    l_Builder.AddColumn(0, DataType::None, "description", "Idk a god damn description");
    l_Builder.AddColumn(0, DataType::None, "stat_type1", "3");
    l_Builder.AddColumn(0, DataType::None, "stat_value1", "3333");

    l_Builder.AddColumn(1, DataType::Key, "entry", "1337420");
    l_Builder.AddColumn(1, DataType::None, "class", "2");
    l_Builder.AddColumn(1, DataType::None, "subclass", "7");
    l_Builder.AddColumn(1, DataType::None, "name", "Lost sword of the fifth gods");
    l_Builder.AddColumn(1, DataType::None, "inventorytype", "17");
    l_Builder.AddColumn(1, DataType::None, "description", "Idk a god damn description LoL");
    l_Builder.AddColumn(1, DataType::None, "stat_type1", "4");
    l_Builder.AddColumn(1, DataType::None, "stat_value1", "5555");

    printf("%s\n", l_Builder.Generate().c_str());

    l_Builder.Reset(QueryTypes::Insert, "item_template");

    l_Builder.AddColumn(0, DataType::Key, "entry", "1337");
    l_Builder.AddColumn(0, DataType::None, "class", "2");
    l_Builder.AddColumn(0, DataType::None, "subclass", "7");
    l_Builder.AddColumn(0, DataType::None, "name", "Lost sword of the four gods");
    l_Builder.AddColumn(0, DataType::None, "inventorytype", "13");
    l_Builder.AddColumn(0, DataType::None, "description", "Idk a god damn description");
    l_Builder.AddColumn(0, DataType::None, "stat_type1", "3");
    l_Builder.AddColumn(0, DataType::None, "stat_value1", "3333");

    l_Builder.AddColumn(1, DataType::Key, "entry", "1337420");
    l_Builder.AddColumn(1, DataType::None, "class", "2");
    l_Builder.AddColumn(1, DataType::None, "subclass", "7");
    l_Builder.AddColumn(1, DataType::None, "name", "Lost sword of the fifth gods");
    l_Builder.AddColumn(1, DataType::None, "inventorytype", "17");
    l_Builder.AddColumn(1, DataType::None, "description", "Idk a god damn description LoL");
    l_Builder.AddColumn(1, DataType::None, "stat_type1", "4");
    l_Builder.AddColumn(1, DataType::None, "stat_value1", "5555");

    printf("%s\n", l_Builder.Generate().c_str());

    system("pause:");

    return 1;
}