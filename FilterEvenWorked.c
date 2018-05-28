#include <stdio.h>
#include <stdlib.h>
#define vz printf("\n")


struct le{
  int value;
  struct le * next;
};

typedef struct le listenelement;
typedef listenelement * list; // Vielleicht überflüss

int check=1;

void insert(int v, list *l){
  listenelement *new;
  new = malloc(sizeof(listenelement));
  new -> value =v;
  new -> next = *l;
  *l = new;
}


int delete_head(list * l){
  if (*l == NULL) return -1;
  list old = *l;
  *l = old ->next;
  free(old);
  return 0;
}

void delete_all(list * l){
  list next;
  while(*l != NULL){
    next=(*l)->next;
    free(*l);
    *l = next;
  }
}

int length(list l){
  int count = 0;
  while(l!= NULL){
    count++;
    l=l->next;

  }
  return count;
}

void print_list(list l){
  if(l== NULL) printf("leer");
  else
    while(l!= NULL){
      printf("%d",l-> value);
      l= l->next;
    }
}

int positionOf(int v,list l){
int i=0;
    while(l!=NULL){
      if(l->value == v){
      return i;
    }

      else {
        i++;
        l = l->next;
      }
    }
    if (l==NULL){
      return -1;
    }

  }

void filterEven(list l){
        while(l!=NULL){
          if(l->value %2 == 1){       //für den ersten Wert der Liste
            list old = l->next;
            l->next = l->next->next;
            l->value = old->value;
            free(old);
            l=l->next;

          }
        // else if(l->next->value %2 == 1){ //für ungerade Zahlen in der Liste
        //   list old = l->next;
        //   l->next = l->next->next;
        //   free(old);
        //   l = l->next;
        //   }

        else if(l->next->value %2 == 0) { //für gerade Zahlen in der Liste
          l = l->next;
        }
        else{
          l=l->next;
        }
      }
}

void swap(int *a, int *b)     // Funktion für Insertion sort in sort()
{
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}
void sort(int m,list l){    //InsertionSort-Methode
if (m>=0) {
  /* code */
while(l!=NULL && l->next !=NULL){
  if(l->next->value >l->value){
    l=l->next;
}
  else{
    swap(&l->value,&l->next->value);
    sort(m,l->next);

}
}

}
else if(m<0){
while(l!=NULL && l->next !=NULL){
  if(l->next->value <l->value){
    l=l->next;
}
  else{
    swap(&l->next->value,&l->value);
    sort(m,l->next);

}
}
}
}
int main(){
list L=NULL;
insert(6,&L);
insert(5,&L);
insert(6,&L);
insert(7,&L);
insert(4,&L);
insert(9,&L);
//printf("%i",L->next->next->value);
filterEven(L);
print_list(L);

}
