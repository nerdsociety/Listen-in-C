/*
Praxis der Programmierung
Hausaufgabe 1
Abgabedatum: 10.6.2018

Gruppe: 1,2,3
Gruppenmitglieder:
Rida Ahmed       793251
Gabor Juche      793094
Stephan Scholz   791220
*/

#include <stdio.h>
#include <stdlib.h>
#define vz printf("\n")

int delete_head();
int check=1; // globale Hilfsvariable

//----anlegen der Struktur le mit variable "listenelement" vom selbigen Typ-----
typedef struct le{
  int value;                  // beliebiger Wert
  struct le * next;           // Pointer auf das nächste Listenelement
}listenelement;

typedef listenelement * list; // Pointer list auf listenelement
//------------------------------------------------------------------------------

//-------------------------- Beginn Prozeduren ---------------------------------
//---------------Prozedur zum Einfügen eines neuen Listenelements---------------
void insert(int v, list *l){
  listenelement *new;
  new = malloc(sizeof(listenelement));
  new -> value =v;
  new -> next = *l;
  *l = new;
}
//------------------------------------------------------------------------------

//-------------------Prozedur zum löschen aller Listenelemente------------------
void delete_all(list * l){
  list next;
  while(*l != NULL){              //prüfen, ob Liste Elemente enthält ist
    next=(*l)->next;
    free(*l);
    *l = next;
  }
}
//------------------------------------------------------------------------------

//-----------------------Prozedur zum ausgeben der Liste------------------------
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
//------------------------------------------------------------------------------

//-------------Prozedur zum filtern aller geraden Werte aus der Liste-----------
void filterEven(list *l){
  if (*l== NULL){                 //  leere Liste-Case
  printf("\nleere Liste bekommen \n");
  return;
  }

  list vor = *l;                  //  Vorgänger
  list dummy = (*l)->next;        //  Kontrollierendes ELement
  //  erstes Element löschen wenn es ungerade ist
  //  wird wiederholt bis ein gerades Element kommt oder die Liste zuenede list
  while (vor==*l && vor->value%2==1||-(vor->value)%2==1 ){
    //  print_list(*l);
    vz;
    if(vor->next != NULL){
      delete_head(l);
      vor = dummy;
      dummy = dummy->next;        // akuelles Listenelement auf next
    }
    else{
      if(vor->value%2==1){
        vor = NULL;
        *l= NULL;
      }
      break;
    }
  }
  //  Nach dem ersten geraden Element müssen die Elemente verknüpft werden
  //  also kann nichtmehr nur der Head gelöscht werden
  while(vor!= NULL){
  //  print_list(*l);
    vz;
    int tmp= 0;        // Kontrollvariable ob gelöscht wurde
    if(dummy->value%2==1 ||-(dummy->value)%2==1 ){  // prüfen, ob next Listenelemnt ungerade ist
      if(dummy->next == NULL){  //prüfen, ob es das letzte Listenelement List
        vor->next= NULL;
        break;
        }
      else{
        vor->next =dummy->next; //next vom aktuellen Element wird auf das übernächste Element gesetzt
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
//------------------------------------------------------------------------------

//------------------Prozedur für InsertionSort in sort()------------------------
void swap(int *a, int *b)
{
  // printf("%i\n",*a);
  // printf("%i\n",*b);
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
  //  printf("%i\n",*a);
  //  printf("%i\n",*b);
}
void sort(int m,list *l){                   // InsertionSort-Methode
if (m>=0) {                                 // für aufsteigendes sortieren
  if (*l== NULL && check==1){               // leere Liste-Case
    printf("\nleere Liste bekommen \n");
    return;
  }
  list dumb = *l;                           // die komplette Liste
  list dumb2 = NULL;

while(*l!=NULL&& (*l)->next !=NULL){        // prüfen ob aktuelles und nächstes Element ungleich NULL
  if((*l)->next->value ==(*l)->value){      // für gleiche Zahlen
    *l=(*l)->next;                          // Liste wird weiter durchgegangen
  }
  else if((*l)->next->value >(*l)->value){  // falls Bedingung ok list
    *l=(*l)->next;
}
  else{                                     // falls getauscht werden muss
    swap(&(*l)->value,&(*l)->next->value);
    *l = dumb;
}
}
*l=dumb;
}
else if(m<0){                               // für absteigendes sortieren
  if (*l== NULL && check==1){               // leere Liste-Case
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
//------------------------------------------------------------------------------
//-------------------------- Ende Prozeduren ---------------------------------

//-------------------------- Beginn Funktionen ---------------------------------
//---------------Funktion zum Einfügen eines neuen Listenelements---------------
int delete_head(list * l){
  if (*l == NULL) return -1;    //leere Liste-Case
  list old = *l;
  *l = old ->next;              //Pointer auf das erste Element wird auf next gesetzt
  free(old);                    //Speicherplatz des ersten Listenelementes wird freigegeben
  return 0;
}
//------------------------------------------------------------------------------

//------------------Funktion zum ermitteln der Länger der Liste-----------------
int length(list l){
  int count = 0;
  while(l!= NULL){              // Listenelemente werden gezählt
    count++;
    l=l->next;
  }
  return count;
}
//------------------------------------------------------------------------------

//------------------Funktion zum ermitteln der Länger der Liste-----------------
int positionOf(int v,list l){
int i=0;
    while(l!=NULL){
      if(l->value == v){      //prüfen, ob value der geuchte Wert ist
      return i;
    }

      else {
        i++;
        l = l->next;          // Liste wird durchgegangen
      }
    }
    if (l==NULL){
      return -1;
    }

  }
//------------------------------------------------------------------------------

//----------------------------main()-Funktion-----------------------------------
int main(){
int auswahl = 1, s = 0, k = 0, f = 0, zaehler = 1;
list L=NULL;    // neue leere Liste

printf("\n---- Initialisieren der Liste ----\n\n---- Size der Liste bestimmen ----\n\nAnzahl der Liste eingeben: ");
scanf("%i",&f);

printf("\n---- Liste befuellen ----\n\nZahlen eingeben und jeweils mit Enter bestaetigen: \n");

while(zaehler<=f){
    printf("%i Zahl eingeben: ", zaehler);
    zaehler++;
    scanf("%i",&k);
    insert(k,&L);
}

printf("\nEs wurde eine List mit folgenden Elementen erzeugt: ");
print_list(L); // Ausgebe der Liste

while(auswahl>0){
  printf("\n\n---- Sie befinden sich im Hauptmenue ----");
  printf("\n \n {1} Loeschen des ersten Elementes\n");
  printf(" {2} Loeschen aller Elemente\n");
  printf(" {3} Laenge der Liste\n");
  printf(" {4} Liste sortieren\n");
  printf(" {5} Liste auf grade Zahlen sortieren (ungerade werden gelöscht!)\n");
  printf(" {6} Position eines Wertes\n");
  printf("\n {0} Programm beenden\n\n");
  scanf("%i",&auswahl);

  switch(auswahl) {
     case 0:
        break;
	   case 1:
        delete_head(&L);
        print_list(L); break;
	   case 2:
        delete_all(&L);
//      print_list(L);
        printf("\nDie Liste ist jetzt leer!\n"); break;
	   case 3:
        printf("Laenge der Liste: %i\n", length(L)); break;
     case 4:
        sort(1,&L);   // sortieren aller Werte der Liste
        printf("\nListe sortiert: \n");
        print_list(L); break;
     case 5:
        filterEven(&L); // Alle ungeraden Werte aus der Liste entfernen
        printf("\nListe aller geraden Zahlen (ungerade gelöscht): \n");
        print_list(L); break;
     case 6:
        printf("\nBitte Zahl eingeben: ");
        scanf("%i",&s);
        printf("Die Postion lautet: %i \n",positionOf(s,L)); break; // Position eines Elementes der Liste bestimmen
	   default:
        printf("Bitte eine gueltige Eingabe von 0 - 6\n"); break;
    }

}
}
//--------------------------  Ende Funktionen ----------------------------------
