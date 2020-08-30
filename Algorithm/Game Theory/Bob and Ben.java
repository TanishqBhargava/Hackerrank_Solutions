import java.util.Scanner;

class Solution{
    static void solve(){
    Scanner sc=new Scanner(System.in);
    int ngame=sc.nextInt();
    for(int i=0;i<ngame;++i){
        int ntree=sc.nextInt(), xor=0;
        for(int j=0;j<ntree;++j){
        int nnode=sc.nextInt();
        sc.nextInt();
        int nimber=0;
            if(nnode!=2) nimber=2-(nnode&1);
        xor=(j==0?nimber: xor^nimber);
        }
        System.out.println(xor==0?"BEN":"BOB");
    }
    sc.close();
    }
    public static void main(String[] args){
    solve();
    }
}
