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
      if (l->next!=NULL){
      printf(",");
    }
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

  void filterEven(list *l){
  if (*l== NULL){             //leere Liste-Case
  printf("\nleere Liste bekommen \n");
  return;
  }

  list vor = *l;                  //Vorgänger
  list dummy = (*l)->next;        //Kontrollierendes ELement
  //erstes Element löschen wenn es ungerade ist
  //wird wiederholt bis ein gerades Element kommt oder die Liste zuenede list
  while (vor==*l && vor->value%2==1||-(vor->value)%2==1 ){
    //print_list(*l);
    vz;
    if(vor->next != NULL){
      delete_head(l);
      vor = dummy;
      dummy = dummy->next;

    }
    else{
      if(vor->value%2==1){
        vor = NULL;
        *l= NULL;
      }
      break;
    }
  }
  // Nach dem ersten geraden Element müssen die Elemente verknüpft werden
  //also kann nichtmehr nur der HEad gelöscht werden
  while(vor!= NULL){
  //  print_list(*l);
    vz;
    int tmp= 0;        // Kontrollvariable ob gelöscht wurde
    if(dummy->value%2==1 ||-(dummy->value)%2==1 ){
      if(dummy->next == NULL){
        vor->next= NULL;
        break;
        }
      else{
        vor->next =dummy->next;
        tmp=1;
        }
      free(dummy);
      }
    dummy = vor->next;

    if(dummy->next != NULL ||-(dummy->value)%2==1 && tmp == 0){
      dummy = dummy->next;
      vor = vor->next;
    }
  if(dummy->next == NULL){
  if(dummy->value %2==1 || -(dummy->value)%2==1) vor->next= NULL;
  break;
  }
  }
}


void swap(int *a, int *b)     // Funktion für InsertionSort in sort()
{
  // printf("%i\n",*a);
  // printf("%i\n",*b);
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  //printf("%i\n",*a);
  //printf("%i\n",*b);
}
void sort(int m,list *l){    //InsertionSort-Methode
if (m>=0) {                         // für aufsteigendes sortieren
  if (*l== NULL && check==1){             //leere Liste-Case
    printf("\nleere Liste bekommen \n");
    return;
  }
  list dumb = *l;         //die komplette Liste
  list dumb2 = NULL;

while(*l!=NULL&& (*l)->next !=NULL){
  if((*l)->next->value ==(*l)->value){                    // für gleiche Zahlen
    *l=(*l)->next;





  }
  else if((*l)->next->value >(*l)->value){                // falls Bedingung ok list
    *l=(*l)->next;

}
  else{                                                   //falls getauscht werden muss
    // vz;
    // print_list(*l);
    // vz;
    swap(&(*l)->value,&(*l)->next->value);
    *l = dumb;



}
}
*l=dumb;
}
else if(m<0){                     // für absteigendes sortieren
  if (*l== NULL && check==1){             //leere Liste-Case
    printf("\nleere Liste bekommen \n");
    return;
  }
  list dumb = *l;
  while(*l!=NULL&& (*l)->next !=NULL){
    if((*l)->next->value ==(*l)->value){
      *l=(*l)->next;





    }
    else if((*l)->next->value <(*l)->value){
      *l=(*l)->next;

  }
    else{
      // vz;
      // print_list(*l);
      // vz;
      swap(&(*l)->next->value,&(*l)->value);
      *l = dumb;



  }
  }
  *l=dumb;
}
}
int main(){
list L=NULL;
insert(24,&L);
insert(7,&L);
insert(6,&L);
insert(7,&L);
insert(4,&L);
insert(-14,&L);
insert(18,&L);
insert(-93,&L);
insert(43,&L);
insert(1,&L);
insert(15,&L);
printf("%i",positionOf(43,L));
vz;
filterEven(&L);
print_list(L);


//printf("%i",L->next->next->value);


}
