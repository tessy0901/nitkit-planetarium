#include<deque>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#include<set>
#include<cmath>
#include<tuple>
#include<string>
#include<chrono>
#include<functional>
#include<iterator>
#include<random>
#include<unordered_set>
#include<array>
#include<map>
#include<iomanip>
#include<assert.h>
#include<list>
#include<bitset>
#include<stack>
#include<memory>
#include<numeric>
#include <fstream>   // ifstream, ofstream
using namespace std;
using namespace std::chrono;
typedef long long int llint;
typedef long double lldo;
#define mp make_pair
#define mt make_tuple
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define fir first
#define sec second
#define res resize
#define ins insert
#define era erase
/*cout<<fixed<<setprecision(20);cin.tie(0);ios::sync_with_stdio(false);*/
const llint mod=1000000007 ;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-10;
const long double epsA=1e-4;
template <class T,class U>bool mineq(T& a,U b){if(a>b){a=b;return true;}return false;}
template <class T,class U>bool maxeq(T& a,U b){if(a<b){a=b;return true;}return false;}
llint gcd(llint a,llint b){if(a%b==0){return b;}else return gcd(b,a%b);}
llint lcm(llint a,llint b){if(a==0){return b;}return a/gcd(a,b)*b;}
template<class T> void SO(T& ve){sort(ve.begin(),ve.end());}
template<class T> void REV(T& ve){reverse(ve.begin(),ve.end());}
template<class T>llint LBI(const vector<T>&ar,T in){return lower_bound(ar.begin(),ar.end(),in)-ar.begin();}
template<class T>llint UBI(const vector<T>&ar,T in){return upper_bound(ar.begin(),ar.end(),in)-ar.begin();}
int main(void){
	//starout.txtのあるディレクトリに入れてください
	//starout01.txt ~ starout12.txt までを生成します
	
	std::ifstream fin("starout.txt");
	std::ofstream fout[13];
	fout[1].open("starout01.txt");
	fout[2].open("starout02.txt");
	fout[3].open("starout03.txt");
	fout[4].open("starout04.txt");
	fout[5].open("starout05.txt");
	fout[6].open("starout06.txt");
	fout[7].open("starout07.txt");
	fout[8].open("starout08.txt");
	fout[9].open("starout09.txt");
	fout[10].open("starout10.txt");
	fout[11].open("starout11.txt");
	fout[12].open("starout12.txt");
	int a;double b,c,d;
	while(fin>>a){
		fin>>b>>c>>d;
		if(d<5.0){(fout[a])<<b*74.8572<<" "<<c*74.8572<<" "<<d<<endl;}
	}
	return 0;
}