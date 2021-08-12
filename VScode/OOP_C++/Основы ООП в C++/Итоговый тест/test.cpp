#include <iostream> 
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()
#include <string>
#include <chrono>
 
class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
 
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now())
	{
	}
 
	void reset()
	{
		m_beg = clock_t::now();
	}
 
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};


class Monster
{
public:
	enum MonsterType
	{
		Dragon,
		Goblin,
		Ogre,
		Orc,
		Skeleton,
		Troll,
		Vampire,
		Zombie,
		MAX_MONSTER_TYPES
	};
 
private:
 
	MonsterType m_type;
	std::string m_name;
	int m_health;
 
public:
	Monster(MonsterType type, std::string name, int health)
		: m_type(type), m_name(name), m_health(health)
	{
 
	}
 
	std::string getTypeString() const
	{
		switch (m_type)
		{
		case Dragon: return "dragon";
		case Goblin: return "goblin";
		case Ogre: return "ogre";
		case Orc: return "orc";
		case Skeleton: return "skeleton";
		case Troll: return "troll";
		case Vampire: return "vampire";
		case Zombie: return "zombie";
		}
	
		return "Error!";
	}
 
	void print() const
	{
		std::cout << m_name << " is the " << getTypeString() << " that has " << m_health << " health points." << '\n';
	}
};
 
class MonsterGenerator
{
public:
	// Генерируем случайное число между min и max (включительно).
	// Предполагается, что srand() уже был вызван
	static int getRandomNumber(int min, int max)
	{
		static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); // используем static, так как это значение нужно вычислить единожды
		// Равномерно распределяем вычисление значения из нашего диапазона
		return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}
 
	static Monster generateMonster()
	{
		Monster::MonsterType type = static_cast<Monster::MonsterType>(getRandomNumber(0, Monster::MAX_MONSTER_TYPES - 1));
		int health = getRandomNumber(1, 100);
 
		static std::string s_names[6]{ "John", "Brad", "Alex", "Thor", "Hulk", "Asnee" }; 
		return Monster(type, s_names[getRandomNumber(0, 5)], health);
	}
};
 
int main()
{
    Timer t;
	srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	rand(); // пользователям Visual Studio: делаем сброс первого случайного числа
 
	Monster m = MonsterGenerator::generateMonster();
	m.print();
 

	std::cout << "Time taken: " << t.elapsed() << '\n';
    
    return 0;
}