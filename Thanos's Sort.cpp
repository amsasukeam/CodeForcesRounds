#include <iostream>
#include<fstream>

using namespace std;

int nModification(int &n){
    return n/2;

}

int bestSorting(int vec[100] , int &n ){
        int alegere;
        int nr = 0;
        int max1=-1;
        int i;
        int j;
        for(i = 1 ; i < nModification(n); i++){
            if(vec[i] <= vec[i+1])
                nr++;
        }

        if(nr > max1 ){
           max1 = nr;
           alegere = 0;
        }

        nr = 0;
        for(i = nModification(n) ; i < n ; i++ )
            if(vec[i] <= vec[i+1])
                nr++;

         if(nr > max1 ){
           max1 = nr;
           alegere = 1;
        }

        return alegere;
}

void execute(int vec[100] , int &n ){

    int ok = 0;
    int i;
    int j;
    while(ok == 0){
        ok = 1;
        if(bestSorting(vec,n) == 0){
          n = nModification(n);
          for(i = 1 ; i < n ; i++)
             if(vec[i] > vec[i+1])
                ok = 0;
        }else{
            i = 1;
            if(n % 2 == 1 )
              j = nModification(n);
            else
              j = nModification(n)+1;
            while(i <= nModification(n))
              while(j <= n){
                 vec[i] = vec[j];
                 i++;
                 j++;
              }

            n = nModification(n);

            for(i = 1 ; i < n ; i++){
             if(vec[i] > vec[i+1])
                ok = 0;
        }
        }
    }





}

int main()
{
    int n;
    int vec[100];
    int ok = 1;
    ifstream f("date.in");
    cin >> n;
    int i;
    for(i = 1 ; i <= n ; i++)
      cin >>vec[i];

    for(i = 1 ; i <= n ; i++)
      if(vec[i] > vec[i+1])
                ok = 0;

      if(ok == 1)
      {
          cout<<n;
          return 0;
      }

   execute(vec,n);
   cout<< n;
    return 0;
}
