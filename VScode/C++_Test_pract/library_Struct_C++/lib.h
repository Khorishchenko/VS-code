#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include <cstring>
#include <string>
using namespace std;

LIB *addBook(LIB *lib, const int count_books);
void show_Boks(LIB *str, const int counBooks);
void find_Autor(LIB *str, const int countBooks);
void find_Name_Book(LIB *str, const int countBooks);
void sort_Book_Name(LIB *str, const int countBooks);
void sort_Aut_name(LIB *str, const int countBooks);
void BOOKS(LIB *str);
void Ops();

#define SIZE 3

struct LIB
{
    string name;
    string author;
    string publishing;
    string genre;
};

void BOOKS(LIB *str)
{
   
    str[0].name = "Trick the universe";
    str[0].author = "Max Maximov";
    str[0].publishing = "ISBN: 978-5-04-112116-7";
    str[0].genre = "Fantasy";
    
    str[1].name = "Bird's Nest";
    str[1].author = "Shirley Jackson";
    str[1].publishing = "ISBN: 978-5-17-123003-6";
    str[1].genre = "Fantasy";
    
    str[2].name = "Wandering earth";
    str[2].author = "Liu Qixin";
    str[2].publishing = "ISBN: 978-5-04-117996-0";
    str[2].genre = "Fantasy";     
    
    
}

void Book_abstract(string str)
{
    if (str == "Trick the universe"){
            cout << "\nАннотация на книгу «Обмануть вселенную»:" << endl;
            cout << "Двое врачей психиатрической больницы берутся за расследование дела пациента по имени Анс." << endl; 
            cout << "Его обвиняют в жестоком убийстве, но он упорно не говорит ни о себе, ни о преступлении. " << endl;
            cout << "Только размытые намеки, которые вызывают все больше вопросов." << endl;
            cout << "Что же случилось той роковой сентябрьской ночью? Анс из будущего, как и утверждает? " << endl;
            cout << "Кто он вообще такой? Убийца? Психопат? Просто сумасшедший или все-таки жертва? " << endl;
            cout << "А может, сама вселенная ведет свою, ведомую только ей, игру?" << endl;
    }
            
    else if (str == "Bird's Nest"){
            cout << "\nАннотация на книгу «Блуждающая Земля»:" << endl;
            cout << "Заглавная повесть «Блуждающая Земля» – литературная основа фильма-блокбастера, купленного" << endl;
            cout << "стриминговым сервисом Netflix." << endl;
            cout << "Десять историй, включая пять произведений-лауреатов китайской премии «Галактика», являются " << endl;
            cout << "ослепительно оригинальной одой планете Земля, ее прошлому и будущему. С меланхоличным, но острым " << endl;
            cout << "пониманием человеческой природы Лю показывает попытки человечества понять, найти себя и, прежде " << endl;
            cout << "всего, выжить в пустоте космоса. Лю Цысинь переносит читателя на край вселенной и в конец времен, " << endl;
            cout << "чтобы рассказать о людях с судьбой, которую мы никогда не смогли бы себе представить." << endl;
    }
    
    else if (str == "Wandering earth"){
            cout << "\nАннотация на книгу «Птичье гнездо»:" << endl;
            cout << "Двадцатитрехлетнюю Элизабет Ричмонд ожидала судьба скромной серой мышки: каждый день она отправлялась " << endl;
            cout << "на работу в канцелярию музея и проводила вечера в компании своей невротичной тети Морген." << endl;
            cout << "спокойствие ее жизни внезапно нарушают ужасные мигрени и боли в спине, а затем и странные приступы " << endl;
            cout << "амнезии. Элизабет начинает ходить к психиатру, и на одном из сеансов доктор Райт, решив применить для " << endl;
            cout << "лечения гипноз, понимает, что перед ним вовсе не одна девушка, а четыре отдельные саморазрушительные личности… " << endl;
          
    }
}

#endif