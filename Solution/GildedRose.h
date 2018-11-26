#include <string>
#include <vector>

using namespace std;

class Item
{
public:
    string name;
    int sellIn;
    int quality;
    Item(string name, int sellIn, int quality) : name(name), sellIn(sellIn), quality(quality) 
    {}
};

class GildedRose
{
public:
    vector<Item> & items;
    GildedRose(vector<Item> & items);
    
    void updateQuality();

private:
    inline void decreaseSellin(Item &item) const;

    inline void updateConcertQuality(Item &item) const;

    inline void clampMaxQuality(Item &item) const;

    inline void updateBrieQuality(Item &item) const;

    inline void updateNormalItemsQuality(Item &item) const;

    inline void updateConjuredItems(Item &item) const;

    inline void clampMinQuality( Item &item) const;
};