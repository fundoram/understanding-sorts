#pragma once

const int MAX_SIZE = 20000;

typedef int ItemType;

void bubbleSort(ItemType[], int);

void swap(ItemType&, ItemType&);

void mergeSort(ItemType[], int, int);

void merge(ItemType[], int, int, int);

void radix(ItemType[], int);

int getMax(ItemType[], int);

void count(ItemType[], int, int);

int getBubbleCount(void);

int getMergeCount(void);

int getRadixCount(void);
