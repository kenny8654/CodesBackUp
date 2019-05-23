/************************************/
/* Date		: 2019-05-11 16:31:05	*/
/* Author	: MiohitoKiri5474		*/
/* Email	: lltzpp@gmail.com		*/
/************************************/

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
template < class T > using stack = stack < T, vec < T > >;
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

mt19937 ran ( 0xabc123 );

inline vi merge ( vi l, vi r, int &num ){
}

struct node{
	node *l, *r;
	int value, pri, sz, num;
	vi data;

	node ( int _val ){
		l = r = nullptr;
		pri = ran();
		value = _val;
		data.pb ( _val );
		sz = 1;
		num = 0;
	}

	inline void up ( void ){
		sz = 1;
		CLR ( data );
		data.pb ( _val );
		if ( l ){
			sz += l -> sz;
			data = merge ( l -> data, data, num );
		}
		if ( r )
			sz += r -> sz;
	}
} *root = nullptr;

inline int Sz ( node *o ){
	return o ? o -> sz : 0;
}

inline void reverse ( node *&o ){
	o -> rev ^= 1;
	swap ( o -> l, o -> r );
}

inline void down ( node *&o ){
	if ( o -> rev ){
		if ( o -> l )
			reverse ( o -> l );
		if ( o -> r )
			reverse ( o -> r );
	}
}

node *merge ( node *a, node *b ){
	if ( !a || !b )
		return a ? a : b;
	if ( a -> pri < b -> pri ){
		down ( a );
		a -> r = merge ( a -> r, b );
		a -> up();
		return a;
	}
	down ( b );
	b -> l = merge ( a, b -> l );
	b -> up();
	return b;
}

void split ( node *o, node *&a, node *&b, k ){
	if ( !o )
		a = b = nullptr;
	else{
		down ( o );
		if ( Sz ( o -> l ) < k ){
			a = o;
			split ( a -> r, a -> r, b, k - Sz ( a -> r ) - 1 );
			up ( a );
		}
		else{
			b = 0;
			split ( b -> l, a, b -> l, Sz ( o ) );
			up ( b );
		}
		up ( o );
	}
}

int bit[maxN];

inline void add ( int a ){
	while ( a <= n ){
		bit[a]++;
		a += a & -a;
	}
}

inline int sum ( int a ){
	int res = 0;
	while ( a ){
		res += bit[a];
		a -= a & -a;
	}

	return res;
}

int main(){
	ios::sync_with_stdio ( false );
	cin.tie ( 0 );
	cout.tie ( 0 );

	int n;
}

inline void dfs ( int n ){
	if ( visited[n] )
		return;
	visited[n] = true;
	REPALL ( i, edges[n] ){
		dfs ( n );
	}
}

int dis[maxN];

inline void init ( void ){
	MEM ( seg, 0 );
	MEM ( lib, 0 );
	REPP ( i, 0, maxN ){
		dis[i] = i;
	}
}

inline void find ( int n ){
	return dis[n] == n ? n : dis[n] = find ( dis[n] );
}

inline void Union ( int a, int b ){
	dis[find ( a )] = find ( b );
}

inline bool same ( int a, int b ){
	return find ( a ) == find ( b );
}

inline int gcd ( int a, int b ){
	while ( a % b && b % a )
		a > b ? a %= b : b %= a;

	return min ( a, b );
}