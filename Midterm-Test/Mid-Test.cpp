#include <stdio.h>

struct MidtestNode {
    int score;
    struct MidtestNode *next;
};

struct MidtestNode *AddNode( struct MidtestNode **walk, int s );    // prototype
void ShowAll( struct MidtestNode *walk );                       // prototype
void UpdateNode( struct MidtestNode *walk, int A, int B);       // prototype
void SwapNode( struct MidtestNode **walk, int A, int B );       // prototype
void ShowBack(struct MidtestNode **walk);                       // prototype

int main(){
    struct MidtestNode *start;
    start = NULL;
    AddNode( &start ,33 );
    AddNode( &start ,44 );
    AddNode( &start ,55 );
    AddNode( &start ,66 );ShowAll( start );
    UpdateNode(start , 33, 99);ShowAll( start );
    SwapNode( &start, 99, 66);ShowAll( start );
    ShowBack(&start);
    return 0;
}

struct MidtestNode *AddNode( struct MidtestNode **walk, int s){

    while ( *walk != NULL ){
        walk = &(*walk)->next;
    } // end while

    *walk = new struct MidtestNode;
    (*walk)->score = s;
    (*walk)->next = NULL;
    return *walk;

} // end function

void ShowAll( struct MidtestNode *walk ){
    
    while (walk != NULL){
        printf(" %d", walk->score);
        walk = walk->next;
    } // end while
    printf( "\n-------------\n" );
    
} // end function

void UpdateNode ( struct MidtestNode *walk, int A, int B){

    while (walk && walk->score != A ){
        walk = walk->next;
    } // end while
    walk->score = B;
} // end function

void SwapNode( struct MidtestNode **walk, int A, int B ){
          
    struct MidtestNode *prevA = NULL, *currentA = *walk;
    while ( currentA && currentA->score != A ) {
        prevA = currentA;
        currentA = currentA->next;
    }

    struct MidtestNode *prevB = NULL, *currentB = *walk;
    while ( currentB && currentB->score != B) {
        prevB = currentB;
        currentB = currentB->next;
    }
    
    if (prevA != NULL)
        prevA->next = currentB;
    else
        *walk = currentB;
    
    if (prevB != NULL)
        prevB->next = currentA;
    else
        *walk = currentA;
    
    struct MidtestNode *temp = currentB->next;
    currentB->next = currentA->next;
    currentA->next = temp;

} // end function

void ShowBack(struct MidtestNode **walk){
    
    struct MidtestNode *current = *walk;
    struct MidtestNode *prev = NULL, *next = NULL;
    
    while (current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *walk = prev;
    
    while ( ( *walk ) != NULL ){
        printf( " %d" ,( *walk )->score );
        *walk = ( *walk )->next;
    } // end while
    printf( "\n-------------\n" );
}