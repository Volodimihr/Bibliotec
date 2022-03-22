#define _CRT_SECURE_NO_WARNINGS
#include "Books.h"
#include "Readers.h"

using namespace std;

void print_books(Book *&barr, Reader *&rarr, int &bsize, bool dir)   //вывод списка книг в последовательном и обратном порядке
{
    for(int i = dir?0:(bsize-1); dir?(i<bsize):(i>=0); dir?i++:i--){
        cout << "\n ID: " << barr[i].id << endl;
        cout << " Book title: " << barr[i].title << endl;
        cout << " Book autor: " << barr[i].autor << endl;
        cout << " Book Genre: " << barr[i].genre << endl;
        cout << " Date of publicing: " << barr[i].pubDate << endl;
        cout << " Book rating: " << barr[i].rating << endl;
        cout << " Rent price: " << barr[i].price << endl;
        int giv = barr[i].gived;
        if(giv == -1)
            cout << " Book in the library." << endl;
        else {
            cout << " Book gived to " << rarr[giv].family << " " << rarr[giv].name << " ID: " << rarr[giv].id << endl;
        }
    }
}

void add_book(Book *&barr, int &bsize, int &bid)  // добавление книги в библиотеку
{
    if(bsize == 0){
        barr = new Book[1];
    }
    else
    {
        Book *tmp = new Book[bsize+1];
        for(int i = 0; i < bsize; i++){
            tmp[i] = barr[i];
        }
        delete [] barr;
        barr = tmp;
    }

    Book &obj = barr[bsize];
    char *buf  = new char[255]{};
    cout << "\n Enter the title of book: ";
    cin.getline(buf, 255);
    obj.title = new char[strlen(buf)+1];
    strcpy(obj.title, buf);
    cout << " Enter name of autor: ";
    cin.getline(buf, 255);
    obj.autor = new char[strlen(buf)+1];
    strcpy(obj.autor, buf);
    cout << " Enter genre of book: ";
    cin.getline(buf, 255);
    obj.genre = new char[strlen(buf)+1];
    strcpy(obj.genre, buf);
    cout << " Enter date of publicing: ";
    cin.getline(buf, 255);
    obj.pubDate = new char[strlen(buf)+1];
    strcpy(obj.pubDate, buf);
    cout << " Enter the rating of book -> ";
    cin >> obj.rating;
    if(cin.fail())
        cin.clear();
    cout << " Enter the book rent price -> ";
    cin >> obj.price;
    if(cin.fail())
        cin.clear();
    cin.ignore();
    obj.gived = -1;
    obj.it = -1;

    obj.id = bid++;
    bsize++;

    delete [] buf;
    system("cls");
}

void del_book(Book *&barr, Reader *&rarr, int &bsize)   // удаление книги из библиотеки
{
    if(bsize < 1){
        cout << " Bibliotec is empty!";
        return;
    }
    else
        print_books(barr, rarr, bsize, true);

    int delBookId = 0;
    cout << " Enter book ID for delete: ";
    cin >> delBookId;
    cin.ignore();
    bool foundBook = false;
    for(int i = 0; i < bsize; i++){
        if(barr[i].id == delBookId)
            foundBook = true;
    }
    if(foundBook){
        Book *tmp = new Book[--bsize];
        for (int i = 0; i < bsize; i++) {
            if(barr[i].id < delBookId)
                tmp[i] = barr[i];
            else
                tmp[i] = barr[i+1];
        }
        delete [] barr;
        barr = tmp;
    }
    else
        cout << " The book with this ID was not found!";
    system("cls");
}

void edit_part_book(Book &obj)  // частичное редактирование данных книги
{
    int act = -1;
    do{
        cout << "\n 1 - title change" << endl;
        cout << " 2 - autor change" << endl;
        cout << " 3 - genre change" << endl;
        cout << " 4 - publication date" << endl;
        cout << " 5 - rating change" << endl;
        cout << " 6 - price change" << endl;
        cout << " 0 - to the previous menu" << endl;
        cout << " Enter number of point to change: ";
        cin >> act;
        cin.ignore();
        char *buf = new char[255]{};

        switch (act) {
        case 0:
            system("cls");
            break;
        case 1:
        {
            cout << "\n Enter the new title of book -> ";
            cin.getline(buf, 255);
            obj.title = new char[strlen(buf)+1];
            char *ttmp = new char[strlen(buf) + 1];
            strcpy(ttmp, buf);
            delete [] obj.title;
            obj.title = ttmp;
            break;
        }
        case 2:
        {
            cout << " Enter the new name of autor -> ";
            cin.getline(buf, 255);
            char *atmp = new char[strlen(buf) + 1];
            strcpy(atmp, buf);
            delete [] obj.autor;
            obj.autor = atmp;
            break;
        }
        case 3:
        {
            cout << " Enter the genre of book -> ";
            cin.getline(buf, 255);
            char *gtmp = new char[strlen(buf) + 1];
            strcpy(gtmp, buf);
            delete [] obj.genre;
            obj.genre = gtmp;
            break;
        }
        case 4:
        {
            cout << " Enter the new publication date of book -> ";
            cin.getline(buf, 255);
            char *ptmp = new char[strlen(buf) + 1];
            strcpy(ptmp, buf);
            delete [] obj.pubDate;
            obj.pubDate = ptmp;
            break;
        }
        case 5:
        {
            cout << " Enter the new rating of book -> ";
            cin >> obj.rating;
            cin.ignore();
            break;
        }
        case 6:
        {
            cout << " Enter the new book price -> ";
            cin >> obj.price;
            cin.ignore();
            break;
        }
        default:
            break;
        }
        delete [] buf;
    }while(act != 0);
    system("cls");
}

void edit_book(Book *&barr, Reader *&rarr, int &bsize)  // полное редактирование данных книги
{
    if(bsize < 1){
        cout << " Bibliotec is empty!";
        return;
    }
    else
        print_books(barr, rarr, bsize, true);

    int fB = -1;
    int idb = -1;
    cout << "\n Enter ID of editing book: ";
    cin >> idb;
    cin.ignore();
    for (int i = 0; i < bsize; i++) {
        if(barr[i].id == idb)
            fB = i;
    }
    if(fB != -1){
        char *buf = new char[255]{};
        do{
            cout << " Enter: " << endl;
            cout << "\t part - partial editing" << endl;
            cout << "\t full - full editing" << endl;
            cout << "\t back - to main menu" << endl;
            cout << "\t -> ";
            cin.getline(buf, 255);
            if(strcmp(buf, "part") == 0){
                edit_part_book(barr[fB]);
            }
            else if(strcmp(buf, "back") == 0){
                system("cls");
                return;
            }
            else if(strcmp(buf, "full") != 0){
                cout<<" Wrong command. Try again."<<endl;
            }
        } while(strcmp(buf, "full") != 0);

        cout << "\n Enter the title of book -> ";
        cin.getline(buf, 255);
        char *ttmp = new char[strlen(buf) + 1];
        strcpy(ttmp, buf);
        delete [] barr[fB].title;
        barr[fB].title = ttmp;
        cout << " Enter the name of autor -> ";
        cin.getline(buf, 255);
        char *atmp = new char[strlen(buf) + 1];
        strcpy(atmp, buf);
        delete [] barr[fB].autor;
        barr[fB].autor = atmp;
        cout << " Enter the genre of book -> ";
        cin.getline(buf, 255);
        char *gtmp = new char[strlen(buf) + 1];
        strcpy(gtmp, buf);
        delete [] barr[fB].genre;
        barr[fB].genre = gtmp;
        cout << " Enter the publication date of book -> ";
        cin.getline(buf, 255);
        char *ptmp = new char[strlen(buf) + 1];
        strcpy(ptmp, buf);
        delete [] barr[fB].pubDate;
        barr[fB].pubDate = ptmp;
        cout << " Enter the rating of book(0 - 10) -> ";
        cin >> barr[fB].rating;
        if(barr[fB].rating < 0)
            barr[fB].rating = 0;
        if(barr[fB].rating > 10)
            barr[fB].rating = 10;
        if(cin.fail())
            cin.clear();
        cout << " Enter the book price -> ";
        cin >> barr[fB].price;
        if(cin.fail())
            cin.clear();
        cin.ignore();
        delete [] buf;
    }
    else {
        cout << " The book with this ID was not found!";
    }
    system("cls");
}

void search_by(Book *&barr, Reader *&rarr, int &bsize, int by) // поиск книги по строковым параметрам
{
    char *buf = new char[255]{};
    switch (by) {
    case 1:
        cout << " Enter searching title: ";
        break;
    case 2:
        cout << " Enter searching autor: ";
        break;
    case 3:
        cout << " Enter searching genre: ";
        break;
    }
    cin.getline(buf, 255);

    char *bpt = nullptr;
    for (int i = 0; i < bsize; i++) {
        bpt = (by==1)?barr[i].title:
                      (by==2)?barr[i].autor:
                              (by==3)?barr[i].genre:nullptr;
        if(strstr(bpt, buf) != 0){
            cout << "\n ID: " << barr[i].id << endl;
            cout << " Book title: " << barr[i].title << endl;
            cout << " Book autor: " << barr[i].autor << endl;
            cout << " Book genre: " << barr[i].genre << endl;
            cout << " Date of publicing: " << barr[i].pubDate << endl;
            cout << " Book rating: " << barr[i].rating << endl;
            cout << " Rent price: " << barr[i].price << endl;
            int giv = barr[i].gived;
            if(giv == -1)
                cout << " Book in the library." << endl;
            else {
                cout << " Book gived to " << rarr[giv].family << " " << rarr[giv].name << " ID: " << rarr[giv].id << endl;
            }
        }
    }

    delete [] buf;
}

void search_by_popularity(Book *&barr, Reader *&rarr, int &bsize)   // поиск книги по популярности
{
    double pop;
    cout << " Enter searching population: ";
    cin >> pop;
    if(cin.fail())
        cin.clear();
    cin.ignore();

    if(pop<1)
        pop=1;
    if(pop>9)
        pop=9;

    for(int i = 0; i < bsize; i++)
    {
        if(barr[i].rating<pop+1 && barr[i].rating>pop-1){
            cout << "\n ID: " << barr[i].id << endl;
            cout << " Book title: " << barr[i].title << endl;
            cout << " Book autor: " << barr[i].autor << endl;
            cout << " Book genre: " << barr[i].genre << endl;
            cout << " Date of publicing: " << barr[i].pubDate << endl;
            cout << " Book rating: " << barr[i].rating << endl;
            cout << " Rent price: " << barr[i].price << endl;
            int giv = barr[i].gived;
            if(giv == -1)
                cout << " Book in the library." << endl;
            else {
                cout << " Book gived to " << rarr[giv].family << " " << rarr[giv].name << " ID: " << rarr[giv].id << endl;
            }
        }
    }
}

void search_book(Book *&barr, Reader *&rarr, int &bsize)    // меню поиска книги
{
    int act;
    do {
        cout << "\n\t Book search: " << endl;
        cout << " 1 - by title" << endl;
        cout << " 2 - by autor" << endl;
        cout << " 3 - by ganre" << endl;
        cout << " 4 - by popularity" << endl;
        cout << " 0 - to the previous menu" << endl;
        cout << " Choose action -> ";
        cin >> act;
        if(cin.fail())
            cin.clear();
        cin.ignore();

        switch (act) {
        case 0:
            system("cls");
            break;
        case 1:
        {
            search_by(barr, rarr, bsize, 1);
            break;
        }
        case 2:
        {
            search_by(barr, rarr, bsize, 2);
            break;
        }
        case 3:
        {
            search_by(barr, rarr, bsize, 3);
            break;
        }
        case 4:
        {
            search_by_popularity(barr, rarr, bsize);
            break;
        }
        default:
            break;
        }
    }while(act != 0);
}

void sort_by(Book *&barr, Reader *&rarr, int &bsize, int by)    // сортировка книг по разным параметрам
{
    Book *tmp = new Book[bsize];
    for(int i = 0; i < bsize; ++i){
        tmp[i] = barr[i];
    }
    if(by == 1){
        Book ch;
        int i, j;
        for(i = 0; i < bsize; i++){
            ch = tmp[i];
            for(j=i-1; j >= 0 && strcmp(tmp[j].title, ch.title) > 0; j--){
                tmp[j+1]=tmp[j];
            }
            tmp[j+1] = ch;
        }
    }
    else if(by == 2){
        Book ch;
        int i, j;
        for(i = 0; i < bsize; i++){
            ch = tmp[i];
            for(j=i-1; j >= 0 && strcmp(tmp[j].autor, ch.autor) > 0; j--){
                tmp[j+1]=tmp[j];
            }
            tmp[j+1] = ch;
        }
    }
    else if(by == 3){
        Book ch;
        int i, j;
        for(i = 0; i < bsize; i++){
            ch = tmp[i];
            for(j=i-1; j >= 0 && strcmp(tmp[j].genre, ch.genre) > 0; j--){
                tmp[j+1]=tmp[j];
            }
            tmp[j+1] = ch;
        }
    }
    else if(by == 4){
        Book ch;
        int i, j;
        for(i = 0; i < bsize; i++){
            ch = tmp[i];
            for(j=i-1; j >= 0 && tmp[j].rating > ch.rating; j--){
                tmp[j+1]=tmp[j];
            }
            tmp[j+1] = ch;
        }
    }

    int act = -1;  // ???
    do{
        cout << "\n 1 - in increasing order" << endl;
        cout << " 2 - in revers order" << endl;
        cout << " 0 - to the previous menu" << endl;
        cout << " > ";
        cin >> act;
        if(cin.fail())
            cin.clear();
        cin.ignore();

        switch(act){
        case 0:
            system("cls");
            break;
        case 1:
            print_books(tmp, rarr, bsize, true);
            break;
        case 2:
            print_books(tmp, rarr, bsize, false);
            break;
        }
    }while(act != 0);
    delete [] tmp;
}

void sort_books(Book *&barr, Reader *&rarr, int &bsize)  // меню сортировки книг
{
    int act = -1;
    do {
        cout << "\n\t Books sort: " << endl;
        cout << " 1 - by title" << endl;
        cout << " 2 - by autor" << endl;
        cout << " 3 - by genre" << endl;
        cout << " 4 - by popularity" << endl;
        cout << " 0 - to the previous menu" << endl;
        cout << " Choose action -> ";
        cin >> act;
        if(cin.fail())
            cin.clear();
        cin.ignore();

        switch (act) {
        case 0:
            system("cls");
            break;
        case 1:
        {
            sort_by(barr, rarr, bsize, 1);
            break;
        }
        case 2:
        {
            sort_by(barr, rarr, bsize, 2);
            break;
        }
        case 3:
        {
            sort_by(barr, rarr, bsize, 3);
            break;
        }
        case 4:
        {
            sort_by(barr, rarr, bsize, 4);
            break;
        }
        default:
            break;
        }
    }while(act != 0);
}

void gived_books(Book *&barr, Reader *&rarr, int &bsize)    // список книг уже выданных читателям
{
    for(int i = 0; i < bsize; i++)
    {
        if(barr[i].gived != -1){
            cout << "\n ID: " << barr[i].id << endl;
            cout << " Book title: " << barr[i].title << endl;
            cout << " Book autor: " << barr[i].autor << endl;
            cout << " Book genre: " << barr[i].genre << endl;
            cout << " Date of publicing: " << barr[i].pubDate << endl;
            cout << " Book rating: " << barr[i].rating << endl;
            cout << " Rent price: " << barr[i].price << endl;
            int giv = barr[i].gived;
            if(giv == -1)
                cout << " Book in the library." << endl;
            else {
                cout << " Book gived to " << rarr[giv].family << " " << rarr[giv].name << " ID: " << rarr[giv].id << endl;
            }
        }
    }
}

void issue_book(Book *&barr, Reader *&rarr, int &bsize, int &rsize)     // функция выдачи книги
{
    int idb, idr, ib, ir;
    print_books(barr, rarr, bsize, true);
    cout << "\n Enter book ID to be issued: ";
    cin >> idb;
    if(cin.fail())
        cin.clear();
    cin.ignore();
    print_readers(rarr, barr, rsize, true);
    for(int i = 0; i < bsize; i++){
        if(barr[i].id == idb)
            ib = i;
    }
    cout << "\n ID: " << barr[ib].id << " \"" << barr[ib].title << "\"" << endl;
    cout << " Enter ID reader for who to be issued book: ";
    cin >> idr;
    if(cin.fail())
        cin.clear();
    cin.ignore();
    for(int i = 0; i < rsize; i++){
        if(rarr[i].id == idr)
            ir = i;
    }
    cout << " Issue book" << " \"" << barr[ib].title << "\" to " << rarr[ir].name << " " << rarr[ir].family << "\?" << endl;
    cout << "yes/no, y/n: ";
    char *buf = new char[4]{};
    cin.getline(buf, 4);
    if(strcmp(buf, "yes") == 0 || strcmp(buf, "y") == 0)
    {
        bool rb = false;
        int rr = 3;
        if(barr[ib].gived == -1){
            rb = true;
        }
        else
        {
            cout << "\n This book already issued!" << endl;
        }

        for(int i = 2; i >= 0; i--){
            if(rarr[ir].booksWith[i] == -1){
                rr = i;
            }
        }

        if(rr == 3)
            cout << "\n Book limit exceeded!" << endl;

        if(rb && rr != 3)
        {
            barr[ib].it = time(0);
            barr[ib].gived = ir;
            rarr[ir].booksWith[rr] = ib;
            cout << "\n Book issue completed." << endl;
        }
    }
    else
    {
        return;
    }
    delete [] buf;
}

void return_book(Book *&barr, Reader *&rarr, int &bsize)    // функция возврата книги
{
    for(int i = 0; i < bsize; i++){
        if(barr[i].gived != -1){
            cout << "\n ID: " << barr[i].id << endl;
            cout << " Book title: " << barr[i].title << endl;
            cout << " Book autor: " << barr[i].autor << endl;
            cout << " Book Genre: " << barr[i].genre << endl;
            cout << " Date of publicing: " << barr[i].pubDate << endl;
            cout << " Book rating: " << barr[i].rating << endl;
            cout << " Rent price: " << barr[i].price << endl;
            int giv = barr[i].gived;
            if(giv == -1)
                cout << " Book in the library." << endl;
            else {
                cout << " Book gived to " << rarr[giv].family << " " << rarr[giv].name << " ID: " << rarr[giv].id << endl;
            }
        }
    }
    cout << "\n Enter ID of returning book: ";
    int idb, rb;
    cin >> idb;
    if(cin.fail())
        cin.clear();
    cin.ignore();
    for(int i = 0; i < bsize; i++){
        if(barr[i].id == idb)
            rb = i;
    }
    double rt = difftime(barr[rb].it, time(0));
    double owes = (rt * barr[rb].price)/3600;
    cout << " The reader owes " << owes << " grn." << endl;
    cout << "\n Do you want to pay and return the book to the library?" << endl;
    cout << "yes/no, y/n: ";
    char *buf = new char[4]{};
    cin.getline(buf, 4);
    if(strcmp(buf, "yes") == 0 || strcmp(buf, "y") == 0){
        for(int i = 3; i >= 0; i--){
            if(rarr[barr[rb].gived].booksWith[i] == rb)
                rarr[barr[rb].gived].booksWith[i] = -1;
        }
        barr[rb].gived = -1;

        cout << "\n Book paid and returned." << endl;
    }
    delete [] buf;
}

void books_menu(Book *&barr, Reader *&rarr, int &bsize, int &rsize, int &bid)   // основное меню по работе с книгами
{
    char *req = new char[15]{};

    do{
        cout << "\n\t Books Menu" << endl;
        cout << " add - to add new book"<<endl;
        cout << " del - to remove book"<<endl;
        cout << " print - to show all books"<<endl;
        cout << " edit - edit book" << endl;
        cout << " search - search book" << endl;
        cout << " sort - sort books" << endl;
        cout << " gived - gived books" << endl;
        cout << " issue - issue book" << endl;
        cout << " return - return book" << endl;
        cout << " exit - to quit" << endl;
        cout << " back - to main menu" << endl;
        cout << " > ";
        cin.getline(req, 15);
        if(strcmp(req, "exit") == 0)
        {
            exit(0); // !!!!!!!!!!!!!!!!
        }
        else if(strcmp(req, "print") == 0)
        {
            system("cls");
            print_books(barr, rarr, bsize, true);
        }
        else if(strcmp(req, "add") == 0)
        {
            system("cls");
            add_book(barr, bsize, bid);
        }
        else if(strcmp(req, "del") == 0)
        {
            system("cls");
            del_book(barr, rarr, bsize);
        }
        else if(strcmp(req, "edit") == 0)
        {
            system("cls");
            edit_book(barr, rarr, bsize);
        }
        else if (strcmp(req, "search") == 0)
        {
            system("cls");
            search_book(barr, rarr, bsize);
        }
        else if (strcmp(req, "sort") == 0)
        {
            system("cls");
            sort_books(barr, rarr, bsize);
        }
        else if (strcmp(req, "gived") == 0)
        {
            system("cls");
            gived_books(barr, rarr, bsize);
        }
        else if (strcmp(req, "issue") == 0)
        {
            system("cls");
            issue_book(barr, rarr, bsize, rsize);
        }
        else if (strcmp(req, "return") == 0)
        {
            system("cls");
            return_book(barr, rarr, bsize);
        }
        else if(strcmp(req, "back") != 0)
        {
            cout << " Wrong command. Try again." << endl;
        }
    }while(strcmp(req, "back") != 0);
    system("cls");

    delete [] req;
}
