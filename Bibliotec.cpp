// Bibliotec.cpp : Defines the entry point for the application.
//
#define _CRT_SECURE_NO_WARNINGS
#include "Bibliotec.h"
#include <iostream>

using namespace std;

int main()
{
    int bId = 1;
    int rId = 1;
    int bSize = 0;
    int rSize = 0;

    Book *books = nullptr;
    Reader *readers = nullptr;

    menu(books, readers, bSize, rSize, bId, rId);

    for (int i = 0; i < bSize; i++)
    {
        delete [] books[i].autor;
        delete [] books[i].title;
        delete [] books[i].genre;
        delete [] books[i].pubDate;
    }

    for (int i = 0; i < rSize; i++)
    {
        delete [] readers[i].name;
        delete [] readers[i].family;
        delete [] readers[i].father;
        delete [] readers[i].birthDate;
        delete [] readers[i].pass;
        delete [] readers[i].booksWith;
    }

    if (bSize)
    {
        delete[] books;
    }
    if (rSize)
    {
        delete[] readers;
    }

    return 0;
}

void save(Book *&barr, Reader *&rarr, int &bsize, int &rsize, int &bid, int &rid)
{
    FILE *f = fopen("data.bds", "wb");  // побитовое сохранение библиотеки и читателей в файл
    int tri = 3;
    if(f){
        fwrite(&bsize, sizeof(int), 1, f);
        fwrite(&bid, sizeof(int), 1, f);
        for(int i = 0; i < bsize; i++){
            fwrite(&barr[i].id, sizeof(int), 1, f);

            int len = (int)strlen(barr[i].title)+1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(barr[i].title, sizeof(char), len, f);

            len = (int)strlen(barr[i].autor)+1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(barr[i].autor, sizeof(char), len, f);

            len = (int)strlen(barr[i].genre)+1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(barr[i].genre, sizeof(char), len, f);

            len = (int)strlen(barr[i].pubDate)+1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(barr[i].pubDate, sizeof(char), len, f);

            fwrite(&barr[i].rating, sizeof(double), 1, f);

            fwrite(&barr[i].price, sizeof(double), 1, f);

            fwrite(&barr[i].gived, sizeof(int), 1, f);

            fwrite(&barr[i].it, sizeof(time_t), 1, f);
        }

        fwrite(&rsize, sizeof(int), 1, f);
        fwrite(&rid, sizeof(int), 1, f);
        for(int i = 0; i < rsize; i++){
            fwrite(&rarr[i].id, sizeof(int), 1, f);

            int len = (int)strlen(rarr[i].family)+1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(rarr[i].family, sizeof(char), len, f);

            len = (int)strlen(rarr[i].name)+1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(rarr[i].name, sizeof(char), len, f);

            len = (int)strlen(rarr[i].father)+1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(rarr[i].father, sizeof(char), len, f);

            len = (int)strlen(rarr[i].pass)+1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(rarr[i].pass, sizeof(char), len, f);

            len = (int)strlen(rarr[i].birthDate)+1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(rarr[i].birthDate, sizeof(char), len, f);

            fwrite(&rarr[i].readBooks, sizeof(int), 1, f);

            fwrite(rarr[i].booksWith, sizeof(int), tri, f);
        }

        fclose(f);

        cout << "\n Library saved!" << endl;
    }
}

void load(Book *&barr, Reader *&rarr, int &bsize, int &rsize, int &bid, int &rid)
{
    for (int i = 0; i < bsize; i++)
    {
        delete [] barr[i].autor;
        delete [] barr[i].title;
        delete [] barr[i].genre;
        delete [] barr[i].pubDate;
    }

    for (int i = 0; i < rsize; i++)
    {
        delete [] rarr[i].name;
        delete [] rarr[i].family;
        delete [] rarr[i].father;
        delete [] rarr[i].birthDate;
        delete [] rarr[i].pass;
        delete [] rarr[i].booksWith;
    }

    if (bsize)
    {
        delete[] barr;
    }
    if (rsize)
    {
        delete[] rarr;
    }

    FILE *f = fopen("data.bds", "rb");  // побитовая загрузка библиотеки и читателей из файла
    int tri = 3;
    if(f){
        fread(&bsize, sizeof(int), 1, f);
        fread(&bid, sizeof(int), 1, f);
        barr = new Book[bsize];
        for(int i = 0; i < bsize; i++){
            fread(&barr[i].id, sizeof(int), 1, f);

            int len = 0;
            fread(&len, sizeof(int), 1, f);
            barr[i].title = new char[len];
            fread(barr[i].title, sizeof(char), len, f);

            fread(&len, sizeof(int), 1, f);
            barr[i].autor = new char[len];
            fread(barr[i].autor, sizeof(char), len, f);

            fread(&len, sizeof(int), 1, f);
            barr[i].genre = new char[len];
            fread(barr[i].genre, sizeof(char), len, f);

            fread(&len, sizeof(int), 1, f);
            barr[i].pubDate = new char[len];
            fread(barr[i].pubDate, sizeof(char), len, f);

            fread(&barr[i].rating, sizeof(double), 1, f);

            fread(&barr[i].price, sizeof(double), 1, f);

            fread(&barr[i].gived, sizeof(int), 1, f);

            fread(&barr[i].it, sizeof(time_t), 1, f);
        }

        fread(&rsize, sizeof(int), 1, f);
        fread(&rid, sizeof(int), 1, f);
        rarr = new Reader[rsize];
        for(int i = 0; i < rsize; i++){
            fread(&rarr[i].id, sizeof(int), 1, f);

            int len = 0;
            fread(&len, sizeof(int), 1, f);
            rarr[i].family = new char[len];
            fread(rarr[i].family, sizeof(char), len, f);

            fread(&len, sizeof(int), 1, f);
            rarr[i].name = new char[len];
            fread(rarr[i].name, sizeof(char), len, f);

            fread(&len, sizeof(int), 1, f);
            rarr[i].father = new char[len];
            fread(rarr[i].father, sizeof(char), len, f);

            fread(&len, sizeof(int), 1, f);
            rarr[i].pass = new char[len];
            fread(rarr[i].pass, sizeof(char), len, f);

            fread(&len, sizeof(int), 1, f);
            rarr[i].birthDate = new char[len];
            fread(rarr[i].birthDate, sizeof(char), len, f);

            fread(&rarr[i].readBooks, sizeof(int), 1, f);

            rarr[i].booksWith = new int[tri];
            fread(rarr[i].booksWith, sizeof(int), tri, f);
        }

        fclose(f);

        cout << "\n Library loaded!" << endl;
    }
}

void menu(Book *&barr, Reader *&rarr, int &bsize, int &rsize, int &bid, int &rid)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);    // главное меню
    SetConsoleTextAttribute(console, 57);
    system("cls");
    char *req = new char[15]{};
    do{
        cout <<
        "\n\t\t---------------"
        "\n\t\t| Библиотека  |"
        "\n\t\t| база данных |"
        "\n\t\t---------------" << endl;
        cout << "\n Выберите базу данных: " << endl;
        cout << "\n books - \"Книгохранилище\"" << endl;
        cout << " readers - \"Круг читателей\"" << endl;
        cout << "\n save - сохранить данные" << endl;
        cout << " load - загрузить данные" << endl;
        cout << "\n  Выход из программы - exit" << endl;
        cout << " > ";
        cin.getline(req, 15);

        if(strcmp(req, "books")==0)
        {
            system("cls");
            books_menu(barr, rarr, bsize, rsize, bid);
        }
        else if(strcmp(req, "readers")==0)
        {
            system("cls");
            readers_menu(rarr, barr, rsize, rid);
        }
        else if(strcmp(req, "save")==0)
        {
            system("cls");
            save(barr, rarr, bsize, rsize, bid, rid);
        }
        else if(strcmp(req, "load")==0)
        {
            system("cls");
            load(barr, rarr, bsize, rsize, bid, rid);
        }
        else if(strcmp(req,"exit")!=0)
        {
            cout<<" Wrong command. Try again."<<endl;
        }
    }while(strcmp(req, "exit") != 0);

    delete [] req;
}
