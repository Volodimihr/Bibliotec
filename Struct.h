#pragma once
#include <cstring>
#include <ctime>
#include <Windows.h>

struct Book
{
    int id;
    char *title;
    char *autor;
    char *genre;
    char *pubDate;
    double rating;
    double price;
    int gived;
    time_t it;
};

struct Reader
{
    int id;
    char *family;
    char *name;
    char *father;
    char *pass;
    char *birthDate;
    int readBooks;
    int *booksWith;
};
