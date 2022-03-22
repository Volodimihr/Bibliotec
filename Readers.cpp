#define _CRT_SECURE_NO_WARNINGS
#include "Readers.h"

using namespace std;

void print_readers(Reader *&rarr, Book *&barr, int &rsize, bool dir)    // вывод списка читателей в последовательном и обратном порядке
{
    for(int i = dir?0:(rsize-1); dir?(i<rsize):(i>=0); dir?i++:i--)
    {
        cout << "\n Reader Id: " << rarr[i].id << endl;
        cout << " Reader surname: " << rarr[i].family << endl;
        cout << " Reader name: " << rarr[i].name << endl;
        cout << " Reader father name: " << rarr[i].father << endl;
        cout << " Reader passport: " << rarr[i].pass << endl;
        cout << " Reader Birthdate: " << rarr[i].birthDate << endl;
        cout << " Read books: " << rarr[i].readBooks << endl;
        cout << " Books with:" << endl;
        for (int j = 0; j < 3; j++) {
            int k = rarr[i].booksWith[j];
            if(k != -1){
                cout << "\t" << barr[k].title << endl;
            }
        }
    }
}

void add_reader(Reader *&rarr, int &rsize, int &rid)    // добавление читателя в библиотеку
{
    if(rsize == 0){
        rarr = new Reader[1];
    }
    else
    {
        Reader *tmp = new Reader[rsize+1];
        for(int i = 0; i < rsize; i++){
            tmp[i] = rarr[i];
        }
        delete [] rarr;
        rarr = tmp;
    }

    int tri = 3;
    Reader &obj = rarr[rsize];
    char *buf  = new char[255]{};
    cout << "\n Enter reader surname: ";
    cin.getline(buf, 255);
    obj.family = new char[strlen(buf)+1];
    strcpy(obj.family, buf);
    cout << " Enter reader name: ";
    cin.getline(buf, 255);
    obj.name = new char[strlen(buf)+1];
    strcpy(obj.name, buf);
    cout << " Enter reader father name: ";
    cin.getline(buf, 255);
    obj.father = new char[strlen(buf)+1];
    strcpy(obj.father, buf);
    cout << " Enter passport number: ";
    cin.getline(buf, 255);
    obj.pass = new char[strlen(buf)+1];
    strcpy(obj.pass, buf);
    cout << " Enter reader Birthdate: ";
    cin.getline(buf, 255);
    obj.birthDate = new char[strlen(buf)+1];
    strcpy(obj.birthDate, buf);
    obj.readBooks = 0;
    obj.booksWith = new int[tri];
    for (int i = 0; i < tri; i++) {
        obj.booksWith[i] = -1;
    }
    obj.id = rid++;
    rsize++;

    delete [] buf;
    system("cls");
}

void del_reader(Reader *&rarr, Book *&barr, int &rsize)     // удаление читателя из библиотеки
{
    if(rsize < 1){
        cout << " Bibliotec is empty!";
        return;
    }
    else
        print_readers(rarr, barr, rsize, true);

    int delReaderId = 0;
    cout << " Enter readers id for delete: ";
    cin >> delReaderId;
    if(cin.fail())
        cin.clear();
    cin.ignore();
    bool fr = false;
    for(int i = 0; i < rsize; i++){
        if(rarr[i].id == delReaderId)
            fr = true;
    }
    if(fr){
        Reader *tmp = new Reader[--rsize];
        for (int i = 0; i < rsize; i++) {
            if(rarr[i].id < delReaderId)
                tmp[i] = rarr[i];
            else
                tmp[i] = rarr[i+1];
        }
        delete [] rarr;
        rarr = tmp;
    }
    else
        cout << " The book with this ID was not found!";
    system("cls");
}

void edit_part_reader(Reader &obj)  // частичное редактирование данных читателя
{
    int act = -1;
    do{
        cout << "\n 1 - surname change" << endl;
        cout << " 2 - name change" << endl;
        cout << " 3 - father name change" << endl;
        cout << " 4 - passport number change" << endl;
        cout << " 5 - birthdate change" << endl;
        cout << " 0 - to the previous menu" << endl;
        cout << " Enter number of point to change: ";
        cin >> act;
        if(cin.fail())
            cin.clear();
        cin.ignore();
        char *buf = new char[255]{};

        switch (act) {
        case 0:
            system("cls");
            break;
        case 1:
        {
            cout << " Enter reader surname: ";
            cin.getline(buf, 255);
            char *ftmp = new char[strlen(buf) + 1];
            strcpy(ftmp, buf);
            delete [] obj.family;
            obj.family = ftmp;
            break;
        }
        case 2:
        {
            cout << " Enter reader name: ";
            cin.getline(buf, 255);
            char *ntmp = new char[strlen(buf) + 1];
            strcpy(ntmp, buf);
            delete [] obj.name;
            obj.name = ntmp;
            break;
        }
        case 3:
        {
            cout << " Enter reader father name: ";
            cin.getline(buf, 255);
            char *otmp = new char[strlen(buf) + 1];
            strcpy(otmp, buf);
            delete [] obj.father;
            obj.father = otmp;
            break;
        }
        case 4:
        {
            cout << " Enter passport number: ";
            cin.getline(buf, 255);
            char *ptmp = new char[strlen(buf) + 1];
            strcpy(ptmp, buf);
            delete [] obj.pass;
            obj.pass = ptmp;
            break;
        }
        case 5:
        {
            cout << " Enter reader Birthdate: ";
            cin.getline(buf, 255);
            char *btmp = new char[strlen(buf) + 1];
            strcpy(btmp, buf);
            delete [] obj.birthDate;
            obj.birthDate = btmp;
            break;
        }
        default:
            break;
        }
        delete [] buf;
    }while(act != 0);
    system("cls");
}

void edit_reader(Reader *&rarr, Book *&barr, int &rsize)    // полное редактирование данных читателя
{
    if(rsize < 1){
        cout << " Bibliotec is empty!";
        return;
    }
    else
        print_readers(rarr, barr, rsize, true);

    int idr = -1, fr = -1;
    cout << "\n Enter id of reader for edit: ";
    cin >> idr;
    cin.ignore();
    for (int i = 0; i < rsize; i++) {
        if(rarr[i].id == idr)
            fr = i;
    }
    if(fr != -1){
        char *buf = new char[255]{};
        do{
            cout << " Enter: " << endl;
            cout << "\t part - partial editing" << endl;
            cout << "\t full - full editing" << endl;
            cout << "\t back - to main menu" << endl;
            cout << "\t -> ";
            cin.getline(buf, 255);
            if(strcmp(buf, "part") == 0){
                edit_part_reader(rarr[fr]);
            }
            else if(strcmp(buf, "back") == 0){
                system("cls");
                return;
            }
            else if(strcmp(buf, "full") != 0){
                cout<<" Wrong command. Try again."<<endl;
            }
        } while(strcmp(buf, "full") != 0);

        cout << " Enter reader surname: ";
        cin.getline(buf, 255);
        char *ftmp = new char[strlen(buf) + 1];
        strcpy(ftmp, buf);
        delete [] rarr[fr].family;
        rarr[fr].family = ftmp;
        cout << " Enter reader name: ";
        cin.getline(buf, 255);
        char *ntmp = new char[strlen(buf) + 1];
        strcpy(ntmp, buf);
        delete [] rarr[fr].name;
        rarr[fr].name = ntmp;
        cout << " Enter reader father name: ";
        cin.getline(buf, 255);
        char *otmp = new char[strlen(buf) + 1];
        strcpy(otmp, buf);
        delete [] rarr[fr].father;
        rarr[fr].father = otmp;
        cout << " Enter passport number: ";
        cin.getline(buf, 255);
        char *ptmp = new char[strlen(buf) + 1];
        strcpy(ptmp, buf);
        delete [] rarr[fr].pass;
        rarr[fr].pass = ptmp;
        cout << " Enter reader Birthdate: ";
        cin.getline(buf, 255);
        char *btmp = new char[strlen(buf) + 1];
        strcpy(btmp, buf);
        delete [] rarr[fr].birthDate;
        rarr[fr].birthDate = btmp;

        delete [] buf;
    }
    else {
        cout << " Reader with this ID was not found!";
    }
}

void search_by(Reader *&rarr, Book *&barr, int &rsize, int by)  // поиск читателя по строковым параметрам
{
    char *buf = new char[255]{};
    switch (by)
    {
    case 1:
        cout << " Enter searching surname: ";
        break;
    case 2:
        cout << " Enter searching name: ";
        break;
    case 3:
        cout << " Enter searching fathername: ";
        break;
    case 4:
        cout << " Enter searching passport number: ";
        break;
    }
    cin.getline(buf, 255);

    char *bpt = nullptr;
    for (int i = 0; i < rsize; i++) {
        bpt = (by == 1)?rarr[i].family:
                        (by == 2)?rarr[i].name:
                                  (by == 3)?rarr[i].father:
                                            (by == 4)?rarr[i].pass:nullptr;
        if(strstr(bpt, buf) != 0){
            cout << "\n Reader Id: " << rarr[i].id << endl;
            cout << " Reader surname: " << rarr[i].family << endl;
            cout << " Reader name: " << rarr[i].name << endl;
            cout << " Reader father name: " << rarr[i].father << endl;
            cout << " Reader passport: " << rarr[i].pass << endl;
            cout << " Reader Birthdate: " << rarr[i].birthDate << endl;
            cout << " Read books: " << rarr[i].readBooks << endl;
            cout << " Books with:" << endl;
            for (int j = 0; j < 3; j++) {
                int k = rarr[i].booksWith[j];
                if(k != -1){
                    cout << "\t" << barr[k].title << endl;
                }
            }
        }
    }
    delete [] buf;
}

void search_by_id(Reader *&rarr, Book *&barr, int &rsize)  // поиск читателя по ID
{
    int id;
    cout << " Enter searching ID: ";
    cin >> id;
    if(cin.fail())
        cin.clear();
    cin.ignore();

    for(int i = 0; i < rsize; i++)
    {
        if(rarr[i].id == id){
            cout << "\n Reader Id: " << rarr[i].id << endl;
            cout << " Reader surname: " << rarr[i].family << endl;
            cout << " Reader name: " << rarr[i].name << endl;
            cout << " Reader father name: " << rarr[i].father << endl;
            cout << " Reader passport: " << rarr[i].pass << endl;
            cout << " Reader Birthdate: " << rarr[i].birthDate << endl;
            cout << " Read books: " << rarr[i].readBooks << endl;
            cout << " Books with:" << endl;
            for (int j = 0; j < 3; j++) {
                int k = rarr[i].booksWith[j];
                if(k != -1){
                    cout << "\t" << barr[k].title << endl;
                }
            }
        }
    }
}

void search_reader(Reader *&rarr, Book *&barr, int &rsize)     // меню поиска читателя
{
    int act = -1;
    do {
        cout << "\n\t Readers search: " << endl;
        cout << " 1 - by surname" << endl;
        cout << " 2 - by name" << endl;
        cout << " 3 - by fathername" << endl;
        cout << " 4 - by passport number" << endl;
        cout << " 5 - by ID" << endl;
        cout << " 0 - to the previous menu" << endl;
        cout << " Choose action -> ";
        cin >> act;
        cin.ignore();
        if(cin.fail())
            cin.clear();

        switch (act) {
        case 0:
            system("cls");
            break;
        case 1:
        {
            search_by(rarr, barr, rsize, 1);
            break;
        }
        case 2:
        {
            search_by(rarr, barr, rsize, 2);
            break;
        }
        case 3:
        {
            search_by(rarr, barr, rsize, 3);
            break;
        }
        case 4:
        {
            search_by(rarr, barr, rsize, 4);
            break;
        }
        case 5:
        {
            search_by_id(rarr, barr, rsize);
            break;
        }
        default:
            break;
        }
    }while(act != 0);
}

void sort_by(Reader *&rarr, Book *&barr, int &rsize, int by)     // сортировка читателей по разным параметрам
{
    Reader *tmp = new Reader[rsize];
    for(int i = 0; i < rsize; ++i){
        tmp[i] = rarr[i];
    }
    if(by == 1){
        Reader ch;
        int i, j;
        for(i = 0; i < rsize; i++){
            ch = tmp[i];
            for(j=i-1; j >= 0 && strcmp(tmp[j].family, ch.family) > 0; j--){
                tmp[j+1]=tmp[j];
            }
            tmp[j+1] = ch;
        }
    }
    else if(by == 2){
        Reader ch;
        int i, j;
        for(i = 0; i < rsize; i++){
            ch = tmp[i];
            for(j=i-1; j >= 0 && strcmp(tmp[j].name, ch.name) > 0; j--){
                tmp[j+1]=tmp[j];
            }
            tmp[j+1] = ch;
        }
    }
    else if(by == 3){
        Reader ch;
        int i, j;
        for(i = 0; i < rsize; i++){
            ch = tmp[i];
            for(j=i-1; j >= 0 && strcmp(tmp[j].father, ch.father) > 0; j--){
                tmp[j+1]=tmp[j];
            }
            tmp[j+1] = ch;
        }
    }
    else if(by == 4){
        Reader ch;
        int i, j;
        for(i = 0; i < rsize; i++){
            ch = tmp[i];
            for(j=i-1; j >= 0 && strcmp(tmp[j].pass, ch.pass) > 0; j--){
                tmp[j+1]=tmp[j];
            }
            tmp[j+1] = ch;
        }
    }
    else if(by == 5){
        Reader ch;
        int i, j;
        for(i = 0; i < rsize; i++){
            ch = tmp[i];
            for(j=i-1; j >= 0 && tmp[j].readBooks > ch.readBooks; j--){
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

        switch(act){
        case 0:
            system("cls");
            break;
        case 1:
            print_readers(tmp, barr, rsize, true);
            break;
        case 2:
            print_readers(tmp, barr, rsize, false);
            break;
        }
    }while(act != 0);
    delete [] tmp;
}

void sort_reader(Reader *&rarr, Book *&barr, int &rsize)   // меню сортировки читателей
{
    int act = -1;
    do {
        cout << "\n\t Readers sort: " << endl;
        cout << " 1 - by surname" << endl;
        cout << " 2 - by name" << endl;
        cout << " 3 - by fathername" << endl;
        cout << " 4 - by passport number" << endl;
        cout << " 5 - by number of readed books" << endl;
        cout << " 6 - by ID" << endl;
        cout << " 0 - to the previous menu" << endl;
        cout << " Choose action -> ";
        cin >> act;
        cin.ignore();
        if(cin.fail())
            cin.clear();

        switch (act) {
        case 0:
            system("cls");
            break;
        case 1:
        {
            sort_by(rarr, barr, rsize, 1);
            break;
        }
        case 2:
        {
            sort_by(rarr, barr, rsize, 2);
            break;
        }
        case 3:
        {
            sort_by(rarr, barr, rsize, 3);
            break;
        }
        case 4:
        {
            sort_by(rarr, barr, rsize, 4);
            break;
        }
        case 5:
        {
            sort_by(rarr, barr, rsize, 5);
            break;
        }
        case 6:
        {
            sort_by(rarr, barr, rsize, 6);
            break;
        }
        default:
            break;
        }
    }while(act != 0);
}

void readers_withbooks(Reader *&rarr, Book *&barr, int &rsize) //
{
    int have = false;
    for(int i = 0; i < rsize; i++) // список читателей с книгами на руках, время в часах и сумма оплаты за это время
    {
        have = false;
        for(int j = 0; j < 3; j++){
            if(rarr[i].booksWith[j] != -1)
                have = true;
        }
        if(have)
        {
            cout << "\n Reader ID: " << rarr[i].id << endl;
            cout << " Reader surname: " << rarr[i].family << endl;
            cout << " Reader name: " << rarr[i].name << endl;
            cout << " Reader father name: " << rarr[i].father << endl;
            cout << " Reader passport: " << rarr[i].pass << endl;
            cout << " Reader Birthdate: " << rarr[i].birthDate << endl;
            cout << " Read books: " << rarr[i].readBooks << endl;
            cout << " Books with:" << endl;
            for (int j = 0; j < 3; j++) {
                int k = rarr[i].booksWith[j];
                if(k != -1){
                    double t = difftime(barr[k].it, time(0))/3600;
                    cout << "\tID: " << barr[k].id << " \"" << barr[k].title << "\",";
                    cout << " on hands: " << t << " hours,";
                    cout << " to pay: " << barr[k].price*t << " grn." << endl;
                }
            }
        }
    }
}

void readers_menu(Reader *&rarr, Book *&barr, int &rsize, int &rid)   // основное меню по работе с читателями
{
    char *req = new char[15]{};
    do{
        cout << "\n\t Readers Menu" << endl;
        cout << " print - show list of readers" << endl;
        cout << " add - add new reader" << endl;
        cout << " del - remove reader" << endl;
        cout << " edit - edit reader" << endl;
        cout << " search - search reader" << endl;
        cout << " sort - sort readers" << endl;
        cout << " issued - readers with books" << endl;
        cout << " exit - to quit" << endl;
        cout << " back - to main menu" << endl;
        cout << " >";
        cin.getline(req, 15);
        if(strcmp(req, "exit") == 0)
        {
            exit(0); // !!!!!!!!!!!!!!!!
        }
        else if (strcmp(req, "print") == 0) {
            system("cls");
            print_readers(rarr, barr, rsize, true);
        }
        else if (strcmp(req, "add") == 0) {
            system("cls");
            add_reader(rarr, rsize, rid);
        }
        else if (strcmp(req, "del") == 0) {
            system("cls");
            del_reader(rarr, barr, rsize);
        }
        else if (strcmp(req, "edit") == 0) {
            system("cls");
            edit_reader(rarr, barr, rsize);
        }
        else if (strcmp(req, "search") == 0) {
            system("cls");
            search_reader(rarr, barr, rsize);
        }
        else if (strcmp(req, "sort") == 0) {
            system("cls");
            sort_reader(rarr, barr, rsize);
        }
        else if (strcmp(req, "issued") == 0) {
            system("cls");
            sort_reader(rarr, barr, rsize);
        }
        else if (strcmp(req, "back") != 0) {
            cout<<" Wrong command. Try again."<<endl;
        }
    }while(strcmp(req, "back") != 0);
    system("cls");

    delete [] req;
}
