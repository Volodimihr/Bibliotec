#pragma once
#include "Struct.h"
#include <iostream>
#include <cstring>

void print_books(Book *&barr, Reader *&rarr, int &bsize, bool dir);

void add_book(Book *&barr, int &bsize, int &bid);

void del_book(Book *&barr, Reader *&rarr, int &bsize);

void edit_part_book(Book &obj);

void edit_book(Book *&barr, Reader *&rarr, int &bsize);

void search_by(Book *&barr, Reader *&rarr, int &bsize, int by);

void search_by_popularity(Book *&barr, Reader *&rarr, int &bsize);

void search_book(Book *&barr, Reader *&rarr, int &bsize);

void sort_by(Book *&barr, Reader *&rarr, int &bsize, int by);

void sort_books(Book *&barr, Reader *&rarr, int &bsize);

void gived_books(Book *&barr, Reader *&rarr, int &bsize);

void issue_book(Book *&barr, Reader *&rarr, int &bsize, int &rsize);

void return_book(Book *&barr, Reader *&rarr, int &bsize);

void fix_book(Book *&barr, Reader *&rarr, int &bsize);

void books_menu(Book *&barr, Reader *&rarr, int &bsize, int &rsize, int &bid);
