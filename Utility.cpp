#include <dir.h>
#include <windows.h>
#include <process.h>

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

// ==================== HASH ====================

array <int, 4> mod;

struct elem{
    int type; // 1 = number, 2 = string
    ll number1;
    string string2;

    void checkMod(){
        if (!mod[0]){
            mod[0] = 998244353; mod[1] = 999995993; mod[2] = 999996989; mod[3] = 999999067;
        }
    }

    elem(): type(0) {
        checkMod();
    }

    elem(ll number1): type(1), number1(number1) {
        checkMod();
    }

    elem(string string2): type(2), string2(string2) {
        checkMod();
    }

    array <int, 4> hashValue(){
        assert(type != 0);
        array <int, 4> ansHashValue;
        if (type == 1){
            For(i, 0, 4){
                ansHashValue[i] = number1 % mod[i];
                if (ansHashValue[i] < 0) ansHashValue[i] += mod[i];
            }
        }
        else if (type == 2){
            For(i, 0, 4){
                ansHashValue[i] = 0;
                For(j, 0, isz(string2)){
                    ansHashValue[i] = ((ll)ansHashValue[i] * 256 + string2[j]) % mod[i];
                }
            }
        }
        return ansHashValue;
    }
};

array <int, 4> hashValue(elem a){
    return a.hashValue();
}

array <int, 4> hashValue(vector <elem> a){
    array <int, 4> ansHashValue;
    vector <array <int, 4>> aHashValue (isz(a));
    For(j, 0, isz(a)){
        aHashValue[j] = hashValue(a[j]);
    }
    For(i, 0, 4){
        ansHashValue[i] = 0;
        For(j, 0, isz(a)){
            ansHashValue[i] ^= abs(aHashValue[j][i] * (j + 1) + (j + 1) * (j + 1));
        }
        ansHashValue[i] %= mod[i];
        if (ansHashValue[i] < 0) ansHashValue[i] += mod[i];
    }
    return ansHashValue;
}

// ==================== HASH ====================

string tos(int x) {
    string ans;
    ans += (char)('0' + x / 10);
    ans += (char)('0' + x % 10);
    return ans;
}

string contestName; // Name of .contest file
string problemName; // Name of problem in .contest file
int tests; // Number of tests

signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    //freopen(".inp", "r", stdin);
    //freopen(".out", "w", stdout);
cout << "contestName: "; cin >> contestName;
cout << "problemName: "; cin >> problemName;
cout << "tests: "; cin >> tests;
mkdir("input");
ofstream outHashValInpOut("arrHashValInpOut.txt");
outHashValInpOut << "const int tests = " << tests << ";" << endl << endl;
outHashValInpOut << "vector <array <int, 4>> arrHashValInp (tests);" << endl;
outHashValInpOut << "vector <array <int, 4>> arrHashValOut (tests);" << endl << endl;
outHashValInpOut << "void initArrHashValInpOut(){" << endl;
For(test, 0, tests){
    // Copy .inp files to input/ folder
    string path1inp = "..\\" + contestName + "\\" + "Tasks\\" + problemName + "\\" + "Test" + tos(test) + "\\" + problemName + ".inp";
    string path1out = "..\\" + contestName + "\\" + "Tasks\\" + problemName + "\\" + "Test" + tos(test) + "\\" + problemName + ".out";
    string path2 = "\"input\\" + problemName + tos(test) + ".txt\"";
    system(("copy /y \"" + path1inp + "\" \"" + path2 + "\"").c_str());
    
    // Find hash of input and output.
    // Hash array of input is put in vector <array <int, 4>> arrayHashValueInp, and output is arrayHashValueOut
    
    outHashValInpOut << "    ";
    {
        vector <elem> elems;
        ifstream in(path1inp.c_str());
        
        // Push all input from in into elems, and then find hash of them
        // EDITING START HERE
        // Sample: Input a, b; Output a + b

        int x, y; in >> x >> y; elems.emplace_back(x); elems.emplace_back(y);

        // End sample
        // EDITING END HERE

        in.close();
        array <int, 4> hashValueInp = hashValue(elems);
        For(i, 0, 4){
            outHashValInpOut << "arrHashValInp[" << test << "][" << i << "] = " << hashValueInp[i] << "; ";
        }
    }
    outHashValInpOut << endl;
    
    outHashValInpOut << "    ";
    {
        vector <elem> elems;
        ifstream in(path1out.c_str());
        
        // Push all input from in into elems, and then find hash of them
        // EDITING START HERE
        // Sample: Input a, b; Output a + b

        int x; in >> x; elems.emplace_back(x);

        // End sample
        // EDITING END HERE

        in.close();
        array <int, 4> hashValueOut = hashValue(elems);
        For(i, 0, 4){
            outHashValInpOut << "arrHashValOut[" << test << "][" << i << "] = " << hashValueOut[i] << "; ";
        }
    }
    outHashValInpOut << endl;
}
outHashValInpOut << "}";
// Zip input/ folder
system("7z a -tzip input.zip \".\\input\\*\"");
system("copy /y \"..\\..\\testlib.h\"");
system("echo > inf.txt");
system("echo > ouf.txt");
system("echo > ans.txt");
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/
