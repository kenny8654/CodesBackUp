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
#define eb emplace_back
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
// template < class T > using stack = stack < T, vec < T > >;
template < class T > using MaxHeap = priority_queue < T, vec < T >, less < T > >;
template < class T > using MinHeap = priority_queue < T, vec < T >, greater < T > >;

// define stringstream
#define sstr stringstream

// number~ remember change maxN
#define INF 0x3f3f3f3f
#define NEG_INF 0x8f8f8f8f
#define maxN 100005

// あの日見渡した渚を　今も思い出すんだ
// 砂の上に刻んだ言葉　君の後ろ姿
// 寄り返す波が　足元をよぎり何かを攫う
// 夕凪の中　日暮れだけが通り過ぎて行く

// ready~ go!
// let's go coding and have fun!
// I can solve this problem!

GRE ( int, edges );
GRE ( int, scclib );
int D[maxN], L[maxN], scc[maxN];
stack < int, vi > st;
bool visited[maxN];

void dfs ( int n, int dep ){
	L[n] = D[n] = dep++;
	st.push ( n );
	REPALL ( i, edges[n] ){
		if ( D[i] )
			L[n] = min ( L[n], L[i] );
		else
			dfs ( i, n );
	}

	if ( D[n] == L[n] ){
		int swp = -1;
		while ( swp != n ){
			swp = st.top();
			st.pop();
			scc[swp] = n;
			scclib[n].pb ( swp );
		}
	}
}

void build ( int n ){
	visited[n] = true;
	REPALL ( i, edges[n] ){
		if ( visited[i] )
			continue;
		if ( scc[n] != scc[i] ){
			son[n]++;
			deg[i]++;
		}
		dfs ( i );
	}
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n, m, u, v, ma = -1, idx = -1;
	vi check, out;
	cin >> n >> m;
	while ( m-- ){
		cin >> u >> v;
		edges[u].pb ( v );
	}

	n++;
	REPP ( i, 0, n ){
		if ( !D[i] ){
			dfs ( i, 0 );
		}
	}

	REPP ( i, 0, n ){
		if ( SZ ( scclib[i] ) > 1 ){
			num++;
			ma = max ( ma, SZ ( scclib ) );
		}
	}

	REPP ( i, 0, n ){
		if ( !visited[i] )
			build ( i );
	}

	REPP ( i, 0, n ){
		if ( !dag[n] && son[n] ){
			check.pb ( n );
		}
	}

	REPALL ( j, check ){
		REPALL ( i, scclib[scc[j]] ){
			out.pb ( i );
		}
	}

	cout << num << '\n';
	if ( EMP ( out ) )
		cout << "No Leader\n";
	else{
		sort ( ALL ( out ) );
		PIO ( out );
	}

	MEM ( visited, 0 );
	CLR ( out );
	REPP ( i, 0, n ){
		if ( SZ ( scclib[i] ) == ma && !visited[scc[i]] ){
			REPALL ( j, scclib[i] ) out.pb ( j );
			visited[scc[i]] = true;
		}
	}

	if ( EMP ( out ) )
		cout << "None\n";
	else{
		sort ( ALL ( out ) ); 
		PIO ( out );
	}
}