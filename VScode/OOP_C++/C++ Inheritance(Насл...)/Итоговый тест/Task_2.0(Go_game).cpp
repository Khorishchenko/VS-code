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


// Генерируем рандомное число между min и max
int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

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
        void addHP(int HP){
            hp += HP;
        }
};

class Player : public Creature
{
    private:
        int level = 1;
        int heal = 0;
    public:
        Player(std::string name) :
            Creature(name, '@', 10, 1, 0)
            {
            }

        void levelUp(){
            level++;
            damage++;
        }

        void UpHeal(int up){
            heal += up;
        }

        void minusHeal(int min){
            heal -= min;
        }

        int getLevel() {return level;}
        int getHeal() {return heal; }

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

void attacaMonster(Player &play, Monster &monst){
    if(play.isDead())
        return;

    monst.reduceHealth(play.getDamage());

    if(monst.isDead()){
        std::cout << "You killed the " << monst.getName() << ".\n";
		play.levelUp();
		std::cout << "You are now level " << play.getLevel() << ".\n";
		std::cout << "You found " << monst.getGold() << " gold.\n\n";
		play.addGold(monst.getGold());
        play.UpHeal((monst.getDamage() / 2) + 1);
    }

}

void addHeal(Player &pl){
    std::cout << "\nYou have " << pl.getHeal() << " heals\n";
    std::cout << "What do you use Heals ?: ";
    int heal; std::cin >> heal;
    pl.addHP(heal);
    pl.minusHeal(heal);
}


void attacPlayer(Monster &m, Player &p){
    if(m.isDead())
        return;

    p.reduceHealth(m.getDamage());
    std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n"; 

}

void fightMonster(Player &pl) {

    Monster m = Monster::getRandomMonster();
	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";

    std::cout << "Now, " << pl.getName() << ".\n" << "You have " << pl.getHealth() << " health and are carrying " << pl.getGold() << "gold." << std::endl;


    while (!m.isDead() && !pl.isDead())
    {
        std::cout << "\n(R)un or (F)ight or (H)eal: ";
        char input;
        std::cin >> input;
        if (input == 'r' || input == 'R')
        {
            if(getRandomNumber(1, 2) == 1)
            {
                std::cout << "You successfully fled.\n\n";
                return;
            }
            else{
                std::cout << "You failed to flee.\n\n";
                attacPlayer(m, pl);
                continue;
            }
        }


        if (input == 'h' || input == 'H'){
            addHeal(pl);
        }

        if (input == 'f' || input == 'F'){
            attacaMonster(pl, m);
            attacPlayer(m, pl);
        }
    }
}

int main()
{
	// Creature o("orc", 'o', 4, 2, 10);
	// o.addGold(5);
	// o.reduceHealth(1);
	// std::cout << "The " << o.getName() << " has " << o.getHealth() << " health and is carrying " << o.getGold() << " gold." << std::endl;

    srand(static_cast<unsigned int>(time(0))); // устанавливаем значение системных часов в качестве стартового числа
	rand(); // сбрасываем первый результат

    std::string name;
    std::cout << "Enter your name: " << std::endl, std::cin >> name;

    Player pl(name);
    std::cout << "Welcome, " << pl.getName() << ".\n" << "You have " << pl.getHealth() << " health and are carrying " << pl.getGold() << "gold." << std::endl;
 
    // Monster m(Monster::ORC);
	// std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
 
    // Если игрок не мертв и еще не победил, то игра продолжается
	while (!pl.isDead() && !pl.hasWon())
		fightMonster(pl);
    

    // К этому моменту игрок либо мертв, либо победил
	if (pl.isDead())
	{
		std::cout << "You died at level " << pl.getLevel() << " and with " << pl.getGold() << " gold.\n";
		std::cout << "Too bad you can't take it with you!\n";
	}
	else
	{
		std::cout << "You won the game with " << pl.getGold() << " gold!\n";
	}

    
	// for (int i = 0; i < 10; ++i)
	// {
	// 	Monster m = Monster::getRandomMonster();
	// 	std::cout << "A " << m.getName() << " (" << m.getSymbol() << ") was created.\n";
	// }

	return 0;
}