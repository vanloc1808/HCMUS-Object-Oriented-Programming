//
//SID: 20120131
//Name: Nguyen Van Loc
//Create on December 20th, 2021
//

#include <iostream>
#include <vector>
#include "C20120131_Store.h"
#include "C20120131_Food.h"
#include "C20120131_Cosmetics.h"
#include "C20120131_HouseholdAppliances.h"
#include "C20120131_ComplexStore.h"
#include "C20120131_MBMarket.h"

int main() {
    C20120131_MBMarket market;

    //create 10 stores due to the exercise's requirement
    C20120131_Store* store1 = new C20120131_Food(1, "Food1", 100, 6000);
    C20120131_Store* store2 = new C20120131_Food(2, "Food2", 200, 7000);
    C20120131_Store* store3 = new C20120131_Cosmetics(3, "Cosmetics1", 300, 8000, 90);
    C20120131_Store* store4 = new C20120131_Cosmetics(4, "Cosmetics2", 400, 9000, 120);
    C20120131_Store* store5 = new C20120131_HouseholdAppliances(5, "HouseholdAppliances1", 500, 10000);
    C20120131_Store* store6 = new C20120131_HouseholdAppliances(6, "HouseholdAppliances2", 600, 11000);
    C20120131_Store* store7 = new C20120131_Food(7, "Food3", 700, 12000);
    C20120131_Store* store8 = new C20120131_Food(8, "Food4", 800, 13000);
    C20120131_ComplexStore* store9 = new C20120131_ComplexStore(9, "ComplexStore1");
    C20120131_ComplexStore* store10 = new C20120131_ComplexStore(10, "ComplexStore2");

    //the below stores are used to add to complex store
    C20120131_Store* store11 = new C20120131_Cosmetics(9, "Cosmetics3", 900, 14000, 150);
    C20120131_Store* store12 = new C20120131_Cosmetics(10, "Cosmetics4", 1000, 15000, 180);
    C20120131_Store* store13 = new C20120131_HouseholdAppliances(11, "HouseholdAppliances3", 1100, 16000);
    C20120131_Store* store14 = new C20120131_HouseholdAppliances(12, "HouseholdAppliances4", 1200, 17000);
    C20120131_Store* store15 = new C20120131_Food(13, "Food5", 1300, 18000);
    C20120131_Store* store16 = new C20120131_Food(14, "Food6", 1400, 19000);

    store9->addStore(store11);
    store9->addStore(store13);
    store9->addStore(store16);
    store10->addStore(store12);
    store10->addStore(store14);
    store10->addStore(store15);

    //add stores to market
    market.addStore(store1);
    market.addStore(store2);
    market.addStore(store3);
    market.addStore(store4);
    market.addStore(store5);
    market.addStore(store6);
    market.addStore(store7);
    market.addStore(store8);
    market.addComplexStore(store9);
    market.addComplexStore(store10);

    std::cout << "Total fee: " << market.totalCost() << "\n";

    //do not need to delete here because it will be deleted in the destructor

    return 0;
}