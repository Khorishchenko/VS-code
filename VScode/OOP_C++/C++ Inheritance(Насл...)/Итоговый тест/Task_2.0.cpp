#include <iostream>
#include <cstdlib> // для rand() и srand()
#include <ctime> // для time()

// // Задание №3
// Самое любимое! Будем создавать простую игру, в которой вы будете сражаться с монстрами. Цель игры — собрать максимум золота, 
// прежде чем вы умрете или достигнете 20 уровня.

// Игра состоит из трех классов: Creature, Player и Monster. Player и Monster наследуют класс Creature.
// a) Сначала создайте класс Creature со следующими членами:
//    имя (std::string);
//    символ (char);
//    количество здоровья (int);
//    количество урона, которое он наносит врагу во время атаки (int);
//    количество золота, которое он имеет (int).
// Создайте полный набор геттеров (по одному на каждую переменную-член класса). Добавьте еще три метода:
//    void reduceHealth(int) — уменьшает здоровье Creature на указанное целочисленное значение;
//    bool isDead() — возвращает true, если здоровье Creature равно 0 или меньше;
//    void addGold(int) — добавляет золото Creature-у.


class Creature
{
    protected:
        std::string name;
        char  m_char;
        int   hp;
        int   damage;
        int   gold;
    public:

        Creature(std::string m_name, char ch, int Hp, int Damage, int Gold) :
            name(m_name), m_char(ch), hp(Hp), damage(Damage), gold(Gold)
            {
            }

        std::string& getName() {return name;}
        char getSymbol() {return m_char;}
        int  getHealth() {return hp;}
        int  getDamage() {return damage;}
        int  getGold() {return gold;}

        void reduceHealth(int minus_hp){
             hp -= minus_hp;
        }

        bool isDead(){
             return hp <= 0;
        }

        void addGold(int add_gold){
             gold += add_gold;
        }
};

class Player : public Creature
{
    private:
        int level = 1;
    public:
        Player(std::string name) :
            Creature(name, '@', 10, 1, 0)
            {
            }

        void levelUp(){
            level++;
            damage++;
        }

        int getLevel() {return level;}

        bool hasWon() {return level >= 20;}
};

class Monster : public Creature
{
    public:
        enum Type{
            DRAGON,
            ORC,
            SLIME,
            MAX_TYPES
        };

        struct MonsterData
        {
            std::string name;
            char symbol;
            int health;
            int damage;
            int gold;      
        };

        Monster(Type type) : 
            Creature(monsterData[type].name, monsterData[type].symbol, monsterData[type].health, monsterData[type].damage, monsterData[type].gold){}

        static MonsterData monsterData[MAX_TYPES];

        static Monster getRandomMonster(){
            return static_cast<Type>(getRandomNumber(0, MAX_TYPES - 1));
        }

        static int getRandomNumber(int min, int max)
        {
            static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
            // Равномерно распределяем генерацию значения из диапазона
            return static_cast<int>(rand() * fraction * (max - min + 1) + min);
        }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES]
{
	{ "dragon", 'D', 20, 4, 100 },
	{ "orc", 'o', 4, 2, 25 },
	{ "slime", 's', 1, 1, 10 }
};

int main()
{
	// Creature o("orc", 'o', 4, 2, 10);
	// o.addGold(5);
	// o.reduceHealth(1);
	// std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold." << std::endl;

    std::string name;
    std::cout << "Enter your name: " << std::endl, std::cin >> name;

    Player pl(name);

    std::cout << "Welcome, " << pl.getName() << ".\n" << "You have " << pl.getHealth() << " health and are carrying " << pl.getGold() << "gold." << std::endl;
 
    // Monster m(Monster::ORC);
	// std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";


    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат
 
	for (int i = 0; i < 10; ++i)
	{
		Monster m = Monster::getRandomMonster();
		std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	}

	return 0;
}