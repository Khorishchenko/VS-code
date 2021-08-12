#include <iostream> 
#include <ctime> // для time()
#include <cstdlib> // для rand() и srand()
#include <array>
#include <chrono>

// Давайте создадим генератор случайных монстров.
// a) Сначала создайте перечисление MonsterType со следующими типами монстров: Dragon, Goblin, Ogre, Orc, Skeleton, 
// Troll, Vampire и Zombie + добавьте MAX_MONSTER_TYPES,
//  чтобы иметь возможность подсчитать общее количество всех перечислителей.

// b) Теперь создайте класс Monster со следующими тремя атрибутами 
// (переменными-членами): тип (MonsterType), имя (std::string) и количество здоровья (int).


// e) Теперь нам нужно вывести информацию про нашего монстра. Для этого нужно конвертировать MonsterType в std::string. Добавьте функцию getTypeString(),
//  которая будет выполнять конвертацию, и функцию вывода print().


// f) Теперь мы уже можем создать сам генератор монстров. Для этого создайте статический класс MonsterGenerator и статический метод с именем generateMonster(), 
// который будет возвращать случайного монстра. 
// Пока что возвратом метода пускай будет анонимный объект: (Monster::Orc, "Jack", 90).

// g) Теперь MonsterGenerator должен генерировать некоторые случайные атрибуты. Для этого нам понадобится генератор случайного числа. 
// Воспользуйтесь следующей функцией:

// b

// //  Измерение времени выполнения (тайминг) кода
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

    // a
        enum MonsterType{
            Dragon,
            Godlib,
            Orge,
            Orc,
            Skeleton,
            Ytroll,
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
        // e
        std::string getTypeString(MonsterType type)
        {
            switch (m_type)
            {
                case Dragon: return "dragon";
                case Godlib: return "goblin";
                case Orge: return "ogre";
                case Orc: return "orc";
                case Skeleton: return "skeleton";
                case Ytroll: return "troll";
                case Vampire: return "vampire";
                case Zombie: return "zombie";
            }
        
		    return "Error!";
        }
        // e
        void print(){
            std::cout << m_name << " is the " << getTypeString(m_type) << " that has " << m_health << " health points." << '\n';
        }

};
// f
class MonsterGenerator{
    public:

        // g
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
            static std::string s_names[6]{ "John", "Brad", "Alex", "Thor", "Hulk", "Asnee" };
            return Monster(Monster::MonsterType((0, Monster::MAX_MONSTER_TYPES -1)), s_names[getRandomNumber(0, 6)], getRandomNumber(1, 100));
        }
};

int main()
{
    // a, b, e;
	// Monster jack(Monster::Orc, "Jack", 90);
    // jack.print();

    // f
    // Monster m = MonsterGenerator::generateMonster();
	// m.print();

    Timer t;

    // g
    srand(static_cast<unsigned int>(time(0))); // используем системные часы в качестве стартового значения
	//rand(); // пользователям Visual Studio: делаем сброс первого случайного числа
 
	Monster m = MonsterGenerator::generateMonster();
	m.print();

	std::cout << "Time taken: " << t.elapsed() << '\n';

    return 0;
}
