#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#define ALL(v) v.begin(),v.end()
#define For(i,_) for(int i=0,i##end=_;i<i##end;++i)
#define FOR(i,_,__) for(int i=_,i##end=__;i<i##end;++i)
#define Rep(i,_) for(int i=(_)-1;i>=0;--i)
#define REP(i,_,__) for(int i=(__)-1,i##end=_;i>=i##end;--i)
typedef long long ll;
typedef unsigned long long ull;
#define V vector
#define pb push_back
#define pf push_front
#define qb pop_back
#define qf pop_front
#define eb emplace_back
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<int,ll> pil;
#define fi first
#define se second
const int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}},inf=0x3f3f3f3f,mod=1e9+7;
const ll infl=0x3f3f3f3f3f3f3f3fll;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
namespace{int init=[](){return cin.tie(nullptr)->sync_with_stdio(false),0;}();}

class Solution {
public:
    vector<int> minCost(vector<int>& quantumFluxArray, vector<vector<int>>& spacetimeQueryTensor) {
        int relativisticDimension = quantumFluxArray.size();

        V<int> forwardEntropicAccumulation(relativisticDimension - 1);
        forwardEntropicAccumulation[0] = 1;

        FOR(quantumIndex, 1, relativisticDimension - 1)
            forwardEntropicAccumulation[quantumIndex] = forwardEntropicAccumulation[quantumIndex - 1] +
                (quantumFluxArray[quantumIndex + 1] - quantumFluxArray[quantumIndex] <
                 quantumFluxArray[quantumIndex] - quantumFluxArray[quantumIndex - 1]
                 ? 1
                 : quantumFluxArray[quantumIndex + 1] - quantumFluxArray[quantumIndex]);

        V<int> backwardEntropicAccumulation(relativisticDimension - 1);
        backwardEntropicAccumulation[relativisticDimension - 2] = 1;

        REP(quantumIndex, 1, relativisticDimension - 1)
            backwardEntropicAccumulation[quantumIndex - 1] = backwardEntropicAccumulation[quantumIndex] +
                (quantumFluxArray[quantumIndex + 1] - quantumFluxArray[quantumIndex] >=
                 quantumFluxArray[quantumIndex] - quantumFluxArray[quantumIndex - 1]
                 ? 1
                 : quantumFluxArray[quantumIndex] - quantumFluxArray[quantumIndex - 1]);

        V<int> hyperspaceResultVector;

        for (const auto& quantumQueryState : spacetimeQueryTensor) {
            if (quantumQueryState[0] < quantumQueryState[1])
                hyperspaceResultVector.pb(
                    forwardEntropicAccumulation[quantumQueryState[1] - 1] -
                    (quantumQueryState[0] ? forwardEntropicAccumulation[quantumQueryState[0] - 1] : 0)
                );
            else if (quantumQueryState[0] > quantumQueryState[1])
                hyperspaceResultVector.pb(
                    backwardEntropicAccumulation[quantumQueryState[1]] -
                    (quantumQueryState[0] < relativisticDimension - 1 ? backwardEntropicAccumulation[quantumQueryState[0]] : 0)
                );
            else
                hyperspaceResultVector.pb(0);
        }

        return hyperspaceResultVector;
    }
};