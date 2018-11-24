//
// Created by argha on 24/11/18.
//
#include "ext/catch.hpp"
#include "GildedRose.h"

TEST_CASE("Sellin and Quality lowers every day"){
    vector<Item> items;
    items.push_back(Item("abc", 10, 20));

    GildedRose app(items);
    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.sellIn<10);
    REQUIRE(item.quality<20);
}

TEST_CASE("Quality lowers twice once sell by date passes "){
    vector<Item> items;
    items.push_back(Item("abc", 1, 20));

    GildedRose app(items);
    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.sellIn==0);
    REQUIRE(item.quality==19);

    app.updateQuality();

    REQUIRE(item.sellIn==-1);
    REQUIRE(item.quality==17);
}

TEST_CASE("Quality is never less than zero"){
    vector<Item> items;
    items.push_back(Item("abc", 20, 0));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.quality==0);
}

TEST_CASE("Aged Brie improves in quality as it ages"){
    vector<Item> items;
    items.push_back(Item("Aged Brie", 20, 10));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.quality==11);

    app.updateQuality();

    REQUIRE(item.quality==12);
}


