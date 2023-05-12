#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq){
  if(pq->size == 0) return NULL;
  return pq->heapArray[0].data;
    return NULL;
}



void heap_push(Heap* pq, void* data, int priority){
  if(pq->size == pq->capac)
  {
    pq->heapArray = (heapElem*)realloc(pq->heapArray,pq->capac*(2)*sizeof(heapElem));
  }

}


void heap_pop(Heap* pq){

}

Heap* createHeap(){
  Heap *heap = (Heap*)malloc(sizeof(Heap));
  heap->heapArray = (heapElem*)malloc(sizeof(heapElem)*3);
  heap->capac = 3;
  heap->size = 0;
  return heap;
}
