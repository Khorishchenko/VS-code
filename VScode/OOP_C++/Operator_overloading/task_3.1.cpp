#include <iostream>
#include <vector>

// Задание №2
// Класс GradeMap и программа, которую мы написали, неэффективна по нескольким причинам. Опишите один способ улучшения класса GradeMap.

// std::vector не является изначально отсортированным. Это означает, что каждый раз, при вызове operator[](), мы будем перебирать весь std::vector для поиска элемента. 
// С несколькими элементами это не является проблемой, но, по мере того как их количество будет увеличиваться, процесс поиска элемента 
// будет становиться все медленнее и медленнее. Мы могли бы это оптимизировать, сделав m_map отсортированным и используя бинарный поиск. 
// Таким образом, количество элементов, которые будут использоваться при просмотре во время поиска одного элемента, уменьшится в разы.

// Задание №3
// Почему следующая программа не работает должным образом?


// int main()
// {
// 	GradeMap grades;
 
// 	char& gradeJohn = grades["John"]; // выполняется push_back
// 	gradeJohn = 'A';
 
// 	char& gradeMartin = grades["Martin"]; // выполняется push_back
// 	gradeMartin = 'B';
 
// 	std::cout << "John has a grade of " << gradeJohn << '\n';
// 	std::cout << "Martin has a grade of " << gradeMartin << '\n';
 
// 	return 0;
// }




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
 
	// // Помещаем его в конец вектора
	// m_map.push_back(temp);
 
	// // И возвращаем ссылку на его оценку
	// return m_map.back().grade;

    // or 

    m_map.push_back(StudentGrade{name});
}


int main()
{
	GradeMap grades;
 
	char& gradeJohn = grades["John"]; // выполняется push_back
	gradeJohn = 'A';
 
	char& gradeMartin = grades["Martin"]; // выполняется push_back
	gradeMartin = 'B';
 
	std::cout << "John has a grade of " << gradeJohn << '\n';
	std::cout << "Martin has a grade of " << gradeMartin << '\n';
 
	return 0;
}


// Ответ №3

// При добавлении Martin, std::vector должен увеличить свой размер. А для этого потребуется динамическое выделение нового блока памяти, копирование элементов массива 
// в этот новый блок и удаление старого блока. Когда это произойдет, то любые ссылки на существующие элементы в std::vector пропадут!
//  Другими словами, после того, как выполнится push_back("Martin"), gradeJohn останется ссылкой на удаленную память. Это и приведет к неопределенным результатам.


