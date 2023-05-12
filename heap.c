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
    pq->heapArray = (heapElem*)realloc(pq->heapArray,(2*sizeof(heapElem)));
    pq->capac *= 2;
  }
  pq->size++;
  pq->heapArray[pq->size-1].data = data;
  pq->heapArray[pq->size-1].priority = priority;
  for(int j = 0; j<pq->size; j++)
    {
      printf(" (%i) ",pq->heapArray[j].priority);
    }
  printf("\n");
  heapElem aux = pq->heapArray[pq->size-1];
  int i = pq->size-1;
  while(i != 0 && pq->heapArray[i].priority > pq->heapArray[(i-pq->capac)/2].priority)
    {
      aux = pq->heapArray[i];
      pq->heapArray[i] = pq->heapArray[(i-pq->capac)/2];
      pq->heapArray[(i-pq->capac)/2] = aux;
      i = (i-pq->capac)/2;
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
