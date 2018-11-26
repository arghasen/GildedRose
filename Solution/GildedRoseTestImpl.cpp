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

TEST_CASE("Aged Brie improves in quality 2 times after sell by date"){
    vector<Item> items;
    items.push_back(Item("Aged Brie", -1, 10));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.quality==12);
}

TEST_CASE("Quality Of an Item is never more than 50"){
    vector<Item> items;
    items.push_back(Item("Aged Brie", 20, 50));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.quality==50);

}

TEST_CASE("Sulfuras are never sold nor decrease in quality"){
    vector<Item> items;
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 20, 50));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.sellIn==20);
    REQUIRE(item.quality==50);

}

TEST_CASE("Backstage Passes increase in Quality"){
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 20, 10));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.sellIn==19);
    REQUIRE(item.quality==11);
}

TEST_CASE("Backstage Passes increase in Quality by 2 when 10 days or less"){
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 10));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.sellIn==9);
    REQUIRE(item.quality==12);
}


TEST_CASE("Backstage Passes increase in Quality by 3 when 5 days or less"){
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 10));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.sellIn==4);
    REQUIRE(item.quality==13);
}

TEST_CASE("Backstage Passes drop to 0 after concert"){
    vector<Item> items;
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 0, 10));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.sellIn==-1);
    REQUIRE(item.quality==0);
}

TEST_CASE("Conjured Items drop twice as fast in quality"){
     vector<Item> items;
    items.push_back(Item("Conjured Mana Cake", 20, 10));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.sellIn==19);
    REQUIRE(item.quality==8);
}

TEST_CASE("Conjured Items drop by 4 after sellby date"){
    vector<Item> items;
    items.push_back(Item("Conjured Mana Cake", 0, 10));

    GildedRose app(items);

    app.updateQuality();

    const auto& item = app.items.front();

    REQUIRE(item.sellIn==-1);
    REQUIRE(item.quality==6);
}