#pragma once
#include "Struct.h"
#include <iostream>
#include <cstring>

void print_readers(Reader *&rarr, Book *&barr, int &rsize, bool dir);

void add_reader(Reader *&rarr, int &rsize, int &rid);

void del_reader(Reader *&rarr, Book *&barr, int &rsize);

void edit_part_reader(Reader &obj);

void edit_reader(Reader *&rarr, Book *&barr, int &rsize);

void search_by(Reader *&rarr, Book *&barr, int &rsize, int by);

void search_by_id(Reader *&rarr, Book *&barr, int &rsize);

void search_reader(Reader *&rarr, Book *&barr, int &rsize);

void sort_by(Reader *&rarr, Book *&barr, int &rsize, int by);

void sort_reader(Reader *&rarr, Book *&barr, int &rsize);

void readers_withbooks(Reader *&rarr, Book *&barr, int &rsize);

void readers_menu(Reader *&rarr, Book *&barr, int &rsize, int &rid);

