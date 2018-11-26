//
// Created by argha on 24/11/18.
//

#include <vector>
#include <iostream>
#include <chrono>
#include "GildedRose.h"

int main() {
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    // this Conjured item doesn't yet work properly
    items.push_back(Item("Conjured Mana Cake", 3, 6));

    GildedRose app(items);

    std::cout << "OMGHAI!" << std::endl;

    for (const auto &item: app.items) {
        std::cout << item.name << " " << item.sellIn<<" " << item.quality << std::endl;
    }
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < 30; ++i) {
//        std::cout<<"day "<<i+1<<std::endl;
        app.updateQuality();
//        for (const auto &item: app.items) {
//            std::cout << item.name << " " << item.sellIn <<" " <<item.quality << std::endl;
//        }
    }
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    cout << duration.count() << endl;
    return 0;
}