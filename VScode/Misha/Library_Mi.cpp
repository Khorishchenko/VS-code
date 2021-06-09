#include <iostream>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define BOOK_COUNT 5
#define c cout <<

struct Book
{
    string author;
    string name;
    string annotation;
    string publisher;
};
Book getBook(int number)
{
    Book book;
    switch (number)
    {
    case 1:
        book.author = "Max Maximov";
        book.name = "Trick the universe";
        book.annotation = "Two doctors at a psychiatric hospital take on the investigation of a patient named Anse. He is accused of a brutal murder, but he stubbornly does not talk about himself or about the crime. Only vague hints that raise more and more questions. What happened on that fatal September night? Ans from the future, as he claims? Who is he anyway? Assassin? Psychopath? Just crazy or a victim? Or maybe the universe itself is playing its own game, led only by it?";
        book.publisher = "978-5-04-112116-7";
        break;
    case 2:
        book.author = "Liu Qixin";
        book.name = "Wandering earth";
        book.annotation = "The title story, The Wandering Earth, is the literary basis for a blockbuster movie bought by the streaming service Netflix. Ten stories, including five winners of the China Galaxy Prize, are a dazzlingly original ode to planet Earth, its past and future. With a melancholic but keen understanding of human nature, Liu shows humanity's attempts to understand, find itself and, above all, survive in the void of space. Liu Qixin takes the reader to the edge of the universe and to the end of time to talk about people with destinies that we could never have imagined.";
        book.publisher = "978-5-04-117996-0";
        break;
    case 3:
        book.author = "Shirley Jackson";
        book.name = "Bird's Nest";
        book.annotation = "Twenty-three-year-old Elizabeth Richmond was destined for the fate of a modest gray mouse: every day she went to work in the museum office and spent evenings in the company of her neurotic aunt Morgen. But the routine calmness of her life is suddenly disturbed by terrible migraines and back pains, and then by strange attacks of amnesia. Elizabeth begins to visit a psychiatrist, and at one of the sessions Dr. Wright, deciding to use hypnosis for treatment, realizes that he is not at all one girl, but four separate self-destructive personalities ... \"The Bird's Nest\" is a masterpiece of a psychological novel about the nature of darkness within us, in which Jackson was one of the first to address the topic of multiple personality disorder, which became especially popular after the publication of \"The Mysterious Story of Billy Milligan\" by Daniel Keyes.";
        book.publisher = "978-5-17-123003-6";
        break;
    case 4:
        book.author = "Garth Nix";
        book.name = "Sir Thursday";
        book.annotation = "Earlier, Arthur Penhaligon always managed to take a break from exploits in his familiar earthly world. But after he took possession of the Third Key, he was unable to return to his family. New adventures overtook the boy before he had time to leave the palaces of the mysterious House ... By an absurd accident, Arthur picked up a seemingly harmless coin - and immediately turned out to be a recruited soldier of the invincible army of Sir Thursday! Well, unlike Mister Monday and Dark Tuesday, Drowned Wednesday didn’t wish Arthur anything bad ... Maybe this time it will be okay? The books of Garth Nyx have long been appreciated by young lovers of mysterious stories. However, adults also read them with pleasure. And it is not surprising, because the fantasy worlds of Nyx are always unique, and the adventures that fall to the lot of the heroes are always unexpected. Sir Thursday is the fourth book in the Keys to the Kingdom series.";
        book.publisher = "978-5-389-19718-3";
        break;
    case 5:
        book.author = "Hannah Matthewson";
        book.name = "Inverted city";
        book.annotation = "Welcome to Witherward, a replica of London like no other. Big Ben? He's not needed here! But what about Buckingham Palace? Also unnecessary! Here people turn into animals and magic floods the streets. Ilsa spent the first seventeen years of her life in ordinary Victorian London, where magic is considered fiction. An orphan, she earned her living first by stealing, and then became the assistant to a magician, creating illusions. When the girl gets to Witherward, she learns that an eternal war is going on in this world between six factions and their representatives, who have different powers. Werewolves. Thought Readers. Magicians. Ghosts. Underground inhabitants. And also oracles who can see the future. They are the ones who want to kill Ilsa. The faction is confident that Witherward has a dire future if the girl remains. But she is ready to fight for the right to live in this world.";
        book.publisher = "978-5-04-112647-6";
        break;
    default:
        break;
    }
    return book;
}


void coutBook(Book book)
{
    c book.author << " - " << book.name << "\n\n";
    c "Book abstract «" << book.name << "»:" << endl;
    c book.annotation << "\n\n";
    c "ISBN: " << book.publisher << "\n\n\n";
}
void coutAllBooks(Book *allBooks)
{
    for (int i = 0; i < BOOK_COUNT; i++)
        coutBook(allBooks[i]);
}
string toLowerCase(string text)
{
    string newText = text;
    transform(newText.begin(), newText.end(), newText.begin(), ::tolower);
    return newText;
}
int main()
{
    Book *allBooks = new Book[BOOK_COUNT];
    for (int i = 0; i < BOOK_COUNT; i++)
        allBooks[i] = getBook(i + 1);
    int answer = 0;
    while (answer != 8)
    {
        cout << "Choose one of the actions: \n1. List all books \n2. Find a book by author \n3. Find a book by title \n4. Sort all books by title \n5. Sort all books by author \nOr any other number exit the program \n> ";
        cin >> answer;
        cin.ignore();
        switch (answer)
        {
        case 1:
            coutAllBooks(allBooks);
            break;
        case 2:
        {
            string author;
            cout << "Author: ";
            getline(cin, author);
            author = toLowerCase(author);
            int books = 0;
            for (int i = 0; i < BOOK_COUNT; i++)
                if (toLowerCase(allBooks[i].author).find(author) != -1)
                {
                    coutBook(allBooks[i]);
                    books++;
                }
            if (books == 0)
                cout << "There are no such books\n";
            break;
        }
        case 3:
        {
            string name;
            cout << "Name of the book: ";
            getline(cin, name);
            name = toLowerCase(name);
            int books = 0;
            for (int i = 0; i < BOOK_COUNT; i++)
                if (toLowerCase(allBooks[i].name).find(name) != -1)
                {
                    coutBook(allBooks[i]);
                    books++;
                }
            if (books == 0)
                cout << "There are no such books\n";
            break;
        }
        case 4:
        {
            for (int i = 0; i < BOOK_COUNT; i++)
                for (int j = 0; j < BOOK_COUNT - 1; j++)
                    if (allBooks[j].name.compare(allBooks[j + 1].name) > 0)
                        swap(allBooks[j], allBooks[j + 1]);
            cout << "All books sorted by title\n";
            break;
        }
        case 5:
        {
            for (int i = 0; i < BOOK_COUNT; i++)
                for (int j = 0; j < BOOK_COUNT - 1; j++)
                    if (allBooks[j].author.compare(allBooks[j + 1].author) > 0)
                        swap(allBooks[j], allBooks[j + 1]);
            cout << "All books sorted by author\n";
            break;
        }
        case 6:
        {
            for (int i = 0; i < BOOK_COUNT; i++)
                for (int j = 0; j < BOOK_COUNT - 1; j++)
                    if (allBooks[j].publisher.compare(allBooks[j + 1].publisher) > 0)
                        swap(allBooks[j], allBooks[j + 1]);
            cout << "All books sorted by publisher\n";
            break;
        }
        default:
            answer = 8;
            break;
        }
    }
    system("pause");
}