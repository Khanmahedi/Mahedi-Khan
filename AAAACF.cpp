#include<bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
#define ll       long long
#define pb      push_back
#define TT ll time;        cin >> time; while(time--)
#define FastIo  ios_base::sync_with_stdio(false);cin.tie(NULL) ;
const ll int INF = 5e18 , nmax = 2501 , block = 350 , N = 2e6+20 , mod = 1e9+7;
// #ifndef ONLINE_JUDGE
// #include "algodebug.h"
// #define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
// #else
// #define debug(x...)
// #endif
struct DSU{
   vector < ll > Par, S ;
   DSU(ll n){
    Par.assign(n+10 , 0) ;
    S.assign(n+10 , 0) ;
    for( ll i = 0 ; i <= n ; i++) Par[i] = i, S[i] = 1;
   }
   ll find_par(ll x){
     if(x == Par[x]) return x ;
     return Par[x] = find_par(Par[x]) ;
   }
   void Marge(ll x , ll y){
    ll para = find_par(x) ;
    ll parb = find_par(y) ;
    if(para != parb){ 
        Par[parb] = para ;
        S[para]+=S[parb] ;
        S[parb] = 0 ;
    }
   }
};


int main(){
  TT{
     ll n ;
     cin >> n ;
     vector < ll > v(n+1) , vv(n+1, 0) ;
     for( ll i = 1 ; i <= n ; i++) cin >> v[i] , vv[i] = 1 ;
      map < ll , vector < ll > > mp ;
      ll q ;
      cin >> q ;
      DSU dsu(n) ;
      for( ll i = 0 ; i < q ;  i++){
        ll x ;
        cin >> x ;
        if(x == 1){
          ll y , z ;
          cin >> y >> z ;
          if(v[y] > v[z]) { 
            v[y]+=v[z] ;
            dsu.Marge(y , z) ;
          }
          else if(v[y] < v[z]){
            v[z]+=v[y] ;
           dsu.Marge(z , y) ;
          }

        }
        if(x == 2){
          ll y ;
          cin >> y ;
          cout << dsu.S[y] << endl ;
        }
        if(x == 3){
          ll y ;
          cin >> y ;
          cout << dsu.find_par(y) << endl ;
        }
      }
  }
}  