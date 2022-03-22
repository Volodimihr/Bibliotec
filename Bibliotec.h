// Bibliotec.h : Include file for standard system include files,
// or project specific include files.
#define _CRT_SECURE_NO_WARNINGS
#pragma once

#include <iostream>
#include <cstring>
#include "Struct.h"
#include "Books.h"
#include "Readers.h"

// TODO: Reference additional headers your program requires here.

void save(Book *&barr, Reader *&rarr, int &bsize, int &rsize, int &bid, int &rid);

void load(Book *&barr, Reader *&rarr, int &bsize, int &rsize, int &bid, int &rid);

void menu(Book *&barr, Reader *&rarr, int &bsize, int &rsize, int &bid, int &rid);
