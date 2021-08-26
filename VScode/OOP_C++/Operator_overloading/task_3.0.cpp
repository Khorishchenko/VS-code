#include <iostream>
#include <vector>

// a) Сначала напишите структуру StudentGrade с двумя элементами: имя студента (std::string) и оценка (char).

struct StudentGrade
{
    std::string name;
	char grade;
};

class GradeMap
{
    private:
        std::vector <StudentGrade> m_map;

    public:
        GradeMap() {}


        char& operator [] (const std::string &name);

};

char& GradeMap::operator [](const std::string &name){
    for (auto &m_name : m_map){
        if (m_name.name == name)
            return m_name.grade;
    }
    // В противном случае, создаем новый StudentGrade для нового ученика
	StudentGrade temp { name, ' ' };
 
	// Помещаем его в конец вектора
	m_map.push_back(temp);
 
	// И возвращаем ссылку на его оценку
	return m_map.back().grade;
}


int main()
{
	GradeMap grades;
	grades["John"] = 'A';
	grades["Martin"] = 'B';
	std::cout << "John has a grade of " << grades["John"] << '\n';
	std::cout << "Martin has a grade of " << grades["Martin"] << '\n';
 
	return 0;
}