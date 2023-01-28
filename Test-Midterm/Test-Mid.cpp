#include <stdio.h>
#include <string.h>

struct Salvonode{
    char name[20];
    int score;
    struct Salvonode *next;
};

struct Salvonode *AddNode( struct Salvonode **walk, char n[], int s );              // prototype
void ShowAll( struct Salvonode *walk );                                             // prototype
void UpdateNode( struct Salvonode **walk, char Oldname[], char Newname[], int s );  // prototype
void SwapNode( struct Salvonode **walk, char A[], char B[] );                       // prototype
void Showback( struct Salvonode **Walk );                                           // prototype

int main() {
    struct Salvonode *start;
    start = NULL; 
    AddNode( &start, "Haaland", 25 );
    AddNode( &start, "Kane",    16 );
    AddNode( &start, "Neymar",  11 );
    AddNode( &start, "Messi",   8  ); ShowAll( start );
    UpdateNode( &start, "Messi", "Mbappe", 13 ); ShowAll( start );
    SwapNode( &start, "Neymar", "Mbappe" ); ShowAll( start );
    Showback( &start ); 
    return 0;
}

struct Salvonode *AddNode( struct Salvonode **walk, char name[], int score ) {
    
    while ( *walk != NULL ) {
        walk = &( *walk )->next;
    } // end while

    *walk = new struct Salvonode;
    strcpy( ( *walk )->name, name );
    ( *walk )->score = score;
    ( *walk )->next  = NULL;
    return *walk;

} // end function

void ShowAll( struct Salvonode *walk ) {
    while ( walk != NULL ) {
        printf( " %s(%d)" , walk->name , walk->score );
        walk = walk->next;
    } // end while
    
    printf( "\n-------------------------------------------\n" );

} // end function

void UpdateNode( struct Salvonode **walk, char Oldname[], char Newname[], int score ) {
    while (strcmp( ( *walk )->name, Oldname ) != 0 ){
        walk = &( *walk )->next;
    } // end while
    
    strcpy( ( *walk )->name, Newname );
    ( *walk )->score = score;

} // end function

void SwapNode( struct Salvonode **walk, char A[], char B[] ) {
    
    struct Salvonode *PickA = NULL, *current1 = *walk;
    struct Salvonode *PickB = NULL, *current2 = *walk;
    while ( strcmp( current1->name, A ) != 0 ) {
        PickA = current1;
        current1 = current1->next;
    } // end while
    
    while ( strcmp( current2->name, B ) != 0 ) {
        PickB = current2;
        current2 = current2->next;
    } // end while
    
    if (PickA != NULL ) {
        PickA->next = current2;
    } // end if
        
    if (PickB != NULL ) {
        PickB->next = current1;
    } // end if
    
    struct Salvonode *temp = current2->next;
    current2->next = current1->next;
    current1->next = temp;
}

void Showback( struct Salvonode **walk ) {
    struct Salvonode *current = *walk;
    struct Salvonode *prev = NULL, *next = NULL;
    
    while ( current != NULL ) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } // end while
    
    *walk = prev;

    while ( ( *walk ) != NULL ){
        printf( " %s(%d)" , ( *walk )->name , ( *walk )->score );
        *walk = ( *walk )->next;
    } // end while

} // end function