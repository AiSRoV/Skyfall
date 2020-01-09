#include <iostream> // cout, cin
#include <time.h>   // time
#include <stdlib.h> // srand

using namespace std;

enum Element { FIRE, AIR, WATER, EARTH };
enum ItemType { SWORD, BOW, SPELL };

struct Sword {
	int damage;
};

struct Bow {
	int damage;
	int charge_time;
	double distance;
};

struct Spell {
	int damage;
	Element element;
	double distance;
};

struct Item {
	ItemType itemtype;
	union { // объединение, нужно для экономии памяти
		Sword sword;
		Bow bow;
		Spell spell;
	} item;
};

Item getRandomItem(); // Создаёт и возвращает предмет со случайными характеристиками
void printItem(Item loot); // Выводит на экран информацию о предмете

int main() {
	Item loot[5];
	int i;

	srand((unsigned)time(NULL));

	for (i = 0; i < 5; ++i) {
		loot[i] = getRandomItem();
		printItem(loot[i]);
	}

	return 0;
}

Item getRandomItem() {
	Item loot;
	int predmet = rand() % 3, // что за предмет (меч=0, лук=1, заклин=2)
		magiya = rand() % 4; // огонь=0, воздух=1, вода=2, земля=3

	switch (predmet) {
	case 0: loot.itemtype = SWORD;
		loot.item.sword.damage = rand() % 1000;
		break;
	case 1: loot.itemtype = BOW;
		loot.item.bow.damage = rand() % 1000;
		loot.item.bow.charge_time = rand() % 100;
		loot.item.bow.distance = rand() % 100;
		break;
	case 2: loot.itemtype = SPELL;
		loot.item.spell.damage = rand() % 1000;
		loot.item.spell.distance = rand() % 100;
		switch (magiya) {
		case 0: loot.item.spell.element = FIRE; break;
		case 1: loot.item.spell.element = AIR; break;
		case 2: loot.item.spell.element = WATER; break;
		case 3: loot.item.spell.element = EARTH; break;
		}
		break;
	}

	return loot;
}

void printItem(Item loot) {
	switch (loot.itemtype) {
	case SWORD: cout << "---SWORD---" << "\n";
		cout << "Damage: " << loot.item.sword.damage << "\n\n";
		break;
	case BOW:   cout << "---BOW---" << "\n";
		cout << "Damage: " << loot.item.bow.damage << "\n";
		cout << "Charge Time: " << loot.item.bow.charge_time << "\n";
		cout << "Distance: " << loot.item.bow.distance << "\n\n";
		break;
	case SPELL: cout << "---SPELL---" << "\n";
		cout << "Damage: " << loot.item.spell.damage << "\n";
		cout << "Element: ";
		switch (loot.item.spell.element) {
		case FIRE:  cout << "Fire" << "\n"; break;
		case AIR:   cout << "Air" << "\n";  break;
		case WATER: cout << "Water" << "\n"; break;
		case EARTH: cout << "Earth" << "\n"; break;
		}
		cout << "Distance: " << loot.item.spell.distance << "\n\n";
		break;

	}
}


