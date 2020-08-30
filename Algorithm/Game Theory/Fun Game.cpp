#include <bits/stdc++.h>

using namespace std;

struct p2 {
    int i , poss ;
    bool operator < ( p2& other ){
        return i < other.i ;
    }
};

int main()
{
    int Testcases ;
    scanf("%d",&Testcases);
    for( int t = 0 ; t < Testcases ; t++ ){
        int Number = 0 ;
        scanf("%d",&Number);
        int A[Number+1] , B[Number+1] ;
        for( int r = 0 ; r < Number ; r++ ) scanf( "%d" ,&A[ r ] );
        for( int r = 0 ; r < Number ; r++ ) scanf( "%d" ,&B[ r ] );
        p2 Converted[Number+1] = { 0 } ;
        int P1 , P2 ;
        P1 = P2 = 0 ;
        for( int c = 0 ; c < Number ; c++ ) {
            Converted[ c ].i = A[ c ] + B[ c ] ;
            Converted[ c ].poss = c ;
        }
        
        sort( Converted , Converted+Number );
        
        bool playing = true ;
        
        for( int p = Number - 1 ; p >= 0 ; p-- ){
            if( playing ){
                P1 += A[ Converted[ p ].poss ] ;
            }else{
                P2 += B[ Converted[ p ].poss ] ;
            }
            playing = !playing ;
        }
        if( P1 > P2 )printf("First\n");
        else if( P1 < P2 )printf("Second\n");
        else printf("Tie\n");
    }
    return 0;
}
