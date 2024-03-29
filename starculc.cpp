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
const llint mod=1000000007;
const llint big=2.19e15+1;
const long double pai=3.141592653589793238462643383279502884197;
const long double eps=1e-12;
template <class T,class U>bool mineq(T& a,U b) {
	if(a>b) {
		a=b;return true;
		}
		return false;
	}
template <class T,class U>bool maxeq(T& a,U b) {
	if(a<b) {
		a=b;return true;
		}
		return false;
	}
llint gcd(llint a,llint b) {
	if(a%b==0) {
		return b;
		}else return gcd(b,a%b);
	}
llint lcm(llint a,llint b) {
	if(a==0) {
			return b;
		}
		return a/gcd(a,b)*b;
	}
template<class T> void SO(T& ve) {
	sort(ve.begin(),ve.end());
}
template<class T> void REV(T& ve) {
	reverse(ve.begin(),ve.end());
}
template<class T>llint LBI(const vector<T>&ar,T in) {
	return lower_bound(ar.begin(),ar.end(),in)-ar.begin();
}
template<class T>llint UBI(const vector<T>&ar,T in) {
	return upper_bound(ar.begin(),ar.end(),in)-ar.begin();
}
//csvファイルを受け取って、星の画像を返す。
//やっぱり 空白区切りにしました
double culchole(double r,double Srank) {
	return Srank;
}
double dist(tuple<double,double,double> a,tuple<double,double,double> b) {
	return (get<0>(a)-get<0>(b))*(get<0>(a)-get<0>(b))+(get<1>(a)-get<1>(b))*(get<1>(a)-get<1>(b))+(get<2>(a)-get<2>(b))*(get<2>(a)-get<2>(b));
}
int main(void) {
	int starnum=3215,i,h,j;
	vector<tuple<int,double,double,double>>stars(starnum);
	//正十二面体 の面の中心に対して、一番近いものの面に来る
	tuple<double,double,double>men[12];
	men[0]=mt(1.0,0.0,0.0);men[11]=mt(-1.0,0.0,0.0);
	double xten=1/sqrt(5);
	for(i=1;i<=5;i++) {
		men[i]=mt(xten,xten*2*cos((i+i-1)*pai/5),xten*2*sin((i+i-1)*pai/5));
	}
	for(i=6;i<=10;i++) {
		men[i]=mt(-xten,xten*2*cos((i+i-12)*pai/5),xten*2*sin((i+i-12)*pai/5));
	}
	for(i=0;i<starnum;i++) {
		int HIP;
		double Skei=0,Si=0;//赤経、赤緯 ラジアンで表す
		cin>>HIP;
		int zi,hun;
		double byo;
		cin>>zi>>hun>>byo;
		Skei=(zi/24.0+hun/(24.0*60)+byo/(24.0*3600))*pai*2;
		int fu;cin>>fu;
		cin>>zi>>hun>>byo;
		Si=(zi/90.0+hun/(90.0*60)+byo/(90.0*3600))*pai/2;
		if(fu==0){
			Si*=-1;
		}
		double Srank;cin>>Srank;//等級
		//どの紙に印刷されるかを考える
		pair<double,int>dre=mp(999.0,0);
		tuple<double,double,double> za=mt(sin(Si),cos(Si)*cos(Skei),cos(Si)*sin(Skei));
		for(j=0;j<12;j++) {
			mineq(dre,mp(dist(men[j],za),j));
		}
		int Pban=dre.sec;//この番号の紙に印刷する
		//紙は,内接円を1とした座標系で表す
		
		if(Pban==0) {
			double holesize=culchole(1/get<0>(za),Srank);
			stars[i]=mt(0,get<1>(za)/get<0>(za),get<2>(za)/get<0>(za),holesize);
		}
		if(1<=Pban&&Pban<=5) {
			//回転させて得る
			Skei-=(Pban-3)*pai*0.4;//一度3番の面に移す 中心点のy が0なのでやりやすい
			//それを0番に動かすように回転させている 1~5番は正五角形が0番と反対なので注意
			za=mt(sin(Si)*xten-cos(Si)*cos(Skei)*xten*2,cos(Si)*cos(Skei)*xten+sin(Si)*xten*2,cos(Si)*sin(Skei));
			if(get<0>(za)<0) {
				cerr<<"bag"<<endl;
			}
			double holesize=culchole(1/get<0>(za),Srank);
			stars[i]=mt(Pban,get<1>(za)/get<0>(za),get<2>(za)/get<0>(za),holesize);
		}
		if(6<=Pban&&Pban<=10) {
			//回転させて得る
			Skei-=(Pban-6)*pai*0.4;//一度6番の面に移す 中心点のy が0なのでやりやすい
			//それを0番に動かすように回転させている 1~5番は正五角形が0番と反対なので注意
			za=mt(-sin(Si)*xten+cos(Si)*cos(Skei)*xten*2,-cos(Si)*cos(Skei)*xten-sin(Si)*xten*2,cos(Si)*sin(Skei));
			if(get<0>(za)<0) {
				cerr<<"bag"<<endl;
			}
			double holesize=culchole(1/get<0>(za),Srank);
			stars[i]=mt(Pban,get<1>(za)/get<0>(za),get<2>(za)/get<0>(za),holesize);
		}
		if(Pban==11) {
			get<0>(za)*=-1;
			get<1>(za)*=-1;
			double holesize=culchole(1/get<0>(za),Srank);
			stars[i]=mt(Pban,get<1>(za)/get<0>(za),get<2>(za)/get<0>(za),holesize);
		}
		cout<<get<0>(stars[i])<<" "<<get<1>(stars[i])<<" "<<get<2>(stars[i])<<" "<<get<3>(stars[i])<<endl;
	}
}