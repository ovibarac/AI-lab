#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>

using namespace std;

//1.Să se determine ultimul (din punct de vedere alfabetic) cuvânt care poate apărea într-un text care conține mai multe
// cuvinte separate prin ” ” (spațiu). De ex. ultimul (dpdv alfabetic) cuvânt din ”Ana are mere rosii si galbene” este cuvântul "si"
string p1(const string& s){
    //O(n*log(k)), k-nr cuvinte, n-nr caractere
    set<string> set;
    string crt;
    for(char ch : s){
        if(ch==' '){
            set.insert(crt);
            crt="";
        }else{
            crt.push_back(ch);
        }
    }
    set.insert(crt);
    return *set.rbegin();
}
//Să se determine distanța Euclideană între două locații identificate prin perechi de numere. De ex. distanța între (1,5) și (4,1) este 5.0
double p2(pair<int, int> l1, pair<int, int> l2){
    return sqrt(pow(l1.first - l2.first, 2) + pow(l1.second-l2.second, 2));
}

//Să se determine produsul scalar a doi vectori rari care conțin numere reale. Un vector este rar atunci când conține multe elemente nule.
// Vectorii pot avea oricâte dimensiuni. De ex. produsul scalar a 2 vectori unisimensionali [1,0,2,0,3] și [1,2,0,3,1] este 4.
float p3(vector<float> v1, vector<float> v2){
    float p=0;
    for(int i =0; i<v1.size(); i++){
        p+=(v1[i]*v2[i]);
    }
    return p;
}

//Să se determine cuvintele unui text care apar exact o singură dată în acel text. De ex. cuvintele care apar o singură dată în
// ”ana are ana are mere rosii ana" sunt: 'mere' și 'rosii'.
void p4(const string& s){
    unordered_map<string, int> map;
    string crt;
    for(char ch : s){
        if(ch==' '){
            map[crt]++;
            crt="";
        }else{
            crt.push_back(ch);
        }
    }
    map[crt]++;
    for(const auto& cuv:map){
        if(cuv.second==1){
            cout<<cuv.first<<' ';
        }
    }
    cout<<'\n';
}

//Pentru un șir cu n elemente care conține valori din mulțimea {1, 2, ..., n - 1} astfel încât o singură valoare se repetă
// de două ori, să se identifice acea valoare care se repetă. De ex. în șirul [1,2,3,4,2] valoarea 2 apare de două ori.
int p5(vector<int> v){
    int sum=0;
    for(const auto&nr:v)
        sum+=nr;
    return sum - v.size()*(v.size()-1)/2;
}

//Pentru un șir cu n numere întregi care conține și duplicate, să se determine elementul majoritar (care apare de mai mult de n / 2 ori).
// De ex. 2 este elementul majoritar în șirul [2,8,7,2,2,5,2,3,1,2,2].
//int p6(vector<int> v){
//    auto comp=[](pair<int, int> p1, pair<int, int>p2){return p1.second>p2.second;};
//    map<int, int, decltype(comp)> map(comp);
//    for(const auto& nr:v){
//        map[nr]++;
//    }
//
//    return map.begin()->first;
//}

//Să se determine al k-lea cel mai mare element al unui șir de numere cu n elemente (k < n).
// De ex. al 2-lea cel mai mare element din șirul [7,4,6,3,9,1] este 7.
int p7(vector<int>v, int k){
    priority_queue<int> pq(v.begin(), v.end());
    while(k>1){
        pq.pop();
        k--;
    }
    return pq.top();
}

//Să se genereze toate numerele (în reprezentare binară) cuprinse între 1 și n. De ex. dacă n = 4, numerele sunt: 1, 10, 11, 100.


int main() {
    std::cout << p1("Ana are mere rosii si galbene")<<'\n';
    std::cout << p2(pair<int, int> (1,5), pair<int, int> (4,1))<<'\n';
    std::cout << p3({1,0,2,0,3}, {1,2,0,3,1})<<'\n';
    p4("ana are ana are mere rosii ana");
    std::cout << p5({1,2,3,4,2})<<'\n';
//    std::cout << p6({2,8,7,2,2,5,2,3,1,2,2})<<'\n';
    std::cout << p7({7,4,6,3,9,1}, 2)<<'\n';
}
