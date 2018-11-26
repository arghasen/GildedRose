#include "GildedRose.h"

GildedRose::GildedRose(vector<Item> &items) : items(items) {}

void GildedRose::updateQuality() {
    for (auto &item:items) {
        if (item.name == "Sulfuras, Hand of Ragnaros")
            continue;

        decreaseSellin(item);
        if (item.name == "Backstage passes to a TAFKAL80ETC concert") {
            updateConcertQuality(item);
        } else if (item.name == "Aged Brie") {
            updateBrieQuality(item);
        } else if (item.name == "Conjured Mana Cake") {
            updateConjuredItems(item);
        } else {
            updateNormalItemsQuality(item);
        }
        clampMaxQuality(item);
        clampMinQuality(item);
    }
}

void GildedRose::updateConjuredItems(Item &item) const {
    item.quality = item.quality - 2;
    if (item.sellIn < 0)
        item.quality = item.quality - 2;
}

void GildedRose::updateNormalItemsQuality(Item &item) const {
    item.quality = item.quality - 1;
    if (item.sellIn < 0)
        item.quality = item.quality - 1;
}

void GildedRose::clampMinQuality(Item &item) const {
    item.quality = max(item.quality, 0);
}

void GildedRose::updateBrieQuality(Item &item) const {
    item.quality = item.quality + 1;
    if (item.sellIn < 0)
        item.quality = item.quality + 1;
}

void GildedRose::updateConcertQuality(Item &item) const {
    if (item.sellIn < 0) {
        item.quality = 0;
    } else if (item.sellIn < 6) {
        item.quality = item.quality + 3;
    } else if (item.sellIn < 11) {
        item.quality = item.quality + 2;
    } else {
        item.quality = item.quality + 1;
    }
}

void GildedRose::clampMaxQuality(Item &item) const {
    item.quality = min(item.quality, 50);
}

void GildedRose::decreaseSellin(Item &item) const {
    item.sellIn = item.sellIn - 1;
}


