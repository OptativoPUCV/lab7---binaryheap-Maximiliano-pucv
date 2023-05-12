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
    pq->heapArray = (heapElem*)realloc(pq->heapArray,pq->capac*(sizeof(heapElem)*2)+1);
    pq->capac = (pq->capac*2)+1;
  }
  pq->size++;
  pq->heapArray[pq->size-1].data = data;
  pq->heapArray[pq->size-1].priority = priority;
  heapElem aux = pq->heapArray[pq->size-1];
  int i = pq->size-1;
  while(i != 0 && pq->heapArray[i].priority > pq->heapArray[(i-1)/2].priority)
    {
      aux = pq->heapArray[i];
      pq->heapArray[i] = pq->heapArray[(i-1)/2];
      pq->heapArray[(i-1)/2] = aux;
      i = (i-1)/2;
    }

}


void heap_pop(Heap* pq){
  heapElem aux = pq->heapArray[pq->size-1];
  pq->heapArray[pq->size-1] = pq->heapArray[0];
  pq->heapArray[0] = aux;
  int i = 0;
  pq->size--;
  
  while(i != pq->size-1)
    {
      //caso 1
      if(pq->heapArray[(i*2)+1].data == NULL && pq->heapArray[(i*2)+2].data == NULL)
      {
        break;
      }

      //caso 2
      if(pq->heapArray[(i*2)+1].data != NULL && pq->heapArray[(i*2)+2].data == NULL)
      {
        if(pq->heapArray[i].priority < pq->heapArray[(i*2)+1].priority)
        {
          aux = pq->heapArray[i];
          pq->heapArray[i] = pq->heapArray[(i*2)+1];
          pq->heapArray[(i*2)+1] = aux;
          i = (i*2)+1;
        }
      }
      else if(pq->heapArray[(i*2)+1].data == NULL && pq->heapArray[(i*2)+2].data != NULL)
      {
        if(pq->heapArray[i].priority < pq->heapArray[(i*2)+2].priority)
        {
          aux = pq->heapArray[i];
          pq->heapArray[i] = pq->heapArray[(i*2)+2];
          pq->heapArray[(i*2)+2] = aux;
          i = (i*2)+2;
        }
      }

      //caso 3
      if(pq->heapArray[(i*2)+1].data != NULL && pq->heapArray[(i*2)+2].data != NULL)
      {
        if(pq->heapArray[i].priority > pq->heapArray[(i*2)+1].priority && pq->heapArray[i].priority > pq->heapArray[(i*2)+2].priority)
        {
          break;
        }
        else if(pq->heapArray[i].priority < pq->heapArray[(i*2)+1].priority && pq->heapArray[i].priority > pq->heapArray[(i*2)+2].priority)
        {
          aux = pq->heapArray[i];
          pq->heapArray[i] = pq->heapArray[(i*2)+1];
          pq->heapArray[(i*2)+1] = aux;
          i = (i*2)+1;
        }
        else if(pq->heapArray[i].priority > pq->heapArray[(i*2)+1].priority && pq->heapArray[i].priority < pq->heapArray[(i*2)+2].priority)
        {
          aux = pq->heapArray[i];
          pq->heapArray[i] = pq->heapArray[(i*2)+2];
          pq->heapArray[(i*2)+2] = aux;
          i = (i*2)+2;
        }
        else if (pq->heapArray[i].priority < pq->heapArray[(i*2)+1].priority && pq->heapArray[i].priority < pq->heapArray[(i*2)+2].priority)
        {
            aux = pq->heapArray[i];
            pq->heapArray[i] = pq->heapArray[(i*2)+2];
            pq->heapArray[(i*2)+2] = aux;
            i = (i*2)+2;
        }
      }
    }
  
}

Heap* createHeap(){
  Heap *heap = (Heap*)malloc(sizeof(Heap));
  heap->heapArray = (heapElem*)malloc(sizeof(heapElem)*3);
  heap->capac = 3;
  heap->size = 0;
  return heap;
}
