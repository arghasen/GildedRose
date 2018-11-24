#include "GildedRose.h"
#include <iostream>

GildedRose::GildedRose(vector<Item> & items) : items(items)
{}
    
void GildedRose::updateQuality() 
{
    for (int i = 0; i < items.size(); i++)
    {
        if (items[i].name != "Aged Brie" && items[i].name != "Backstage passes to a TAFKAL80ETC concert")
        {
            if (items[i].quality > 0)
            {
                if (items[i].name != "Sulfuras, Hand of Ragnaros")
                {
                    items[i].quality = items[i].quality - 1;
                }
            }
        }
        else
        {
            if (items[i].quality < 50)
            {
                items[i].quality = items[i].quality + 1;

                if (items[i].name == "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (items[i].sellIn < 11)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }

                    if (items[i].sellIn < 6)
                    {
                        if (items[i].quality < 50)
                        {
                            items[i].quality = items[i].quality + 1;
                        }
                    }
                }
            }
        }

        if (items[i].name != "Sulfuras, Hand of Ragnaros")
        {
            items[i].sellIn = items[i].sellIn - 1;
        }

        if (items[i].sellIn < 0)
        {
            if (items[i].name != "Aged Brie")
            {
                if (items[i].name != "Backstage passes to a TAFKAL80ETC concert")
                {
                    if (items[i].quality > 0)
                    {
                        if (items[i].name != "Sulfuras, Hand of Ragnaros")
                        {
                            items[i].quality = items[i].quality - 1;
                        }
                    }
                }
                else
                {
                    items[i].quality = items[i].quality - items[i].quality;
                }
            }
            else
            {
                if (items[i].quality < 50)
                {
                    items[i].quality = items[i].quality + 1;
                }
            }
        }
    }
}

int main()
{
    vector<Item> items;
    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
        items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
            // this Conjured item doesn't yet work properly
        items.push_back(Item("Conjured Mana Cake", 3, 6));
    GildedRose app(items);
    cout << "OMGHAI!" << endl;
    app.updateQuality();
}
