// by. MiohitoKiri5474
#include<bits/stdc++.h>

#pragma GCC optimize ( "O3" )
#pragma loop_opt ( on )

using namespace std;

typedef long long LL;

// define tools
#define REPP(i,f,s) for ( int i = f ; i < s ; i++ )
#define REPM(i,f,s) for ( int i = f ; i >= s ; i-- )
#define REPALL(i,n) for ( auto &i: n )
#define debuger cout << "111\n"
#define MEM(n,i) memset ( n, i, sizeof n )

// define pair
typedef pair < LL, LL > pll;
typedef pair < int, int > pii;
#define F first
#define S second
#define mp make_pair

// define vector && some stl's api
template < class T > using vec = vector < T >;
typedef vec < int > vi;
typedef vec < LL > vl;
#define pb push_back
#define ep emplace_back
#define REV reverse
#define SZ(n) ( int ) n.size()
#define CLR(n) n.clear()
#define BEG(n) n.begin()
#define END(n) n.end()
#define EMP(n) n.empty()
#define RSZ(n,s) n.resize ( s )
#define ALL(n) BEG ( n ), END ( n )
#define PIO(n) REPALL ( i, n ) cout << i << ' '; cout << '\n'
#define GETDATA(data,n) RSZ ( data, n ); REPALL ( i, data ) cin >> i

// define set
typedef set < int > si;
typedef set < LL > sl;
#define FID(n,Index) ( n.find ( Index ) != n.end() )

// graph
#define GRE(T,edge) vec < T > edge[maxN]
#define UNI(u,v,edge) edge[u].pb ( v ), edge[v].pb ( u )
#define UNIw(u,v,w,edge) edge[u].pb ( mp ( v, w ) ), edge[v].pb ( mp ( u, w ) )

// IO
#define GL(n) getline ( cin, n )

// define stack, queue, pri-queue
template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define maxN 100005

// ready~ go!
// let's coding and have fun!
// I can solve this problem!

vi data[6];

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int t, in, ans;
	bool check;
	set < pii > used;
	cin >> t;
	while ( t-- ){
		ans = 0;
		REPP ( i, 0, 5 ){
			REPP ( j, 0, 6 ){
				cin >> in;
				data[j].pb ( in );
			}
		}

		REPP ( i, 0, 6 ){
			REV ( ALL ( data[i] ) );
		}

		do{
			// debuger; // del
			check = false;
			REPP ( i, 0, 6 ) RSZ ( data[i], 5 );
			REPP ( i, 0, 3 ){
				REPP ( j, 0, 5 ){
					if ( data[i][j] == data[i + 1][j] && data[i + 1][j] == data[i + 2][j] && data[i][j] ){
						check = true;
						if ( !( FID ( used, pii ( i, j ) ) || FID ( used, pii ( i + 1, j ) ) || FID ( used, pii ( i + 1, j ) ) ) )
							ans++;
						used.insert ( pii ( i, j ) );
						used.insert ( pii ( i + 1, j ) );
						used.insert ( pii ( i + 2, j ) );
					}
				}
			}

			REPP ( i, 0, 6 ){
				REPP ( j, 0, 2 ){
					if ( data[i][j] == data[i][j + 1] && data[i][j + 1] == data[i][j + 2] && data[i][j] ){
						check = true;
						if ( !( FID ( used, pii ( i, j ) ) || FID ( used, pii ( i, j + 1 ) ) || FID ( used, pii ( i, j + 2 ) ) ) )
							ans++;
						used.insert ( pii ( i, j ) );
						used.insert ( pii ( i, j + 1 ) );
						used.insert ( pii ( i, j + 2 ) );
					}
				}
			}

			for ( auto i = used.rbegin() ; i != used.rend() ; i++ ){
				// cout << i -> F << ' ' << i -> S << '\n'; // del
				data[i -> F].erase ( ( BEG ( data[i -> F] ) + i -> S ) );
			}
			CLR ( used );
		} while ( check );

		cout << ans << '\n';
	}
}