#include <iostream>
#include <string>
#include <set>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <map>
#include <queue>
#include <unordered_set>

using namespace std;

//1.Să se determine ultimul (din punct de vedere alfabetic) cuvânt care poate apărea într-un text care conține mai multe
// cuvinte separate prin ” ” (spațiu). De ex. ultimul (dpdv alfabetic) cuvânt din ”Ana are mere rosii si galbene” este cuvântul "si"
/**
 * determina ultimul cuvant alfabetic din text
 * @param s - textul de intrare, string
 * @return string, ultimul cuvant
 */
string ultimulCuv(const string& s){
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
//2.Să se determine distanța Euclideană între două locații identificate prin perechi de numere. De ex. distanța între (1,5) și (4,1) este 5.0
/**
 * determina distanta euclidiana intre doua locatii
 * @param l1 punctul 1 pair<int,int>
 * @param l2 punctul 2 pair<int,int>
 * @return double, distanta euclidiana intre l1 si l2
 */
double dEuclidiana(pair<int, int> l1, pair<int, int> l2){
    return sqrt(pow(l1.first - l2.first, 2) + pow(l1.second-l2.second, 2));
}

//3.Să se determine produsul scalar a doi vectori rari care conțin numere reale. Un vector este rar atunci când conține multe elemente nule.
// Vectorii pot avea oricâte dimensiuni. De ex. produsul scalar a 2 vectori unisimensionali [1,0,2,0,3] și [1,2,0,3,1] este 4.
/**
 * Determina produsul scalar a doi vectori
 * @param v1 primul vector de numere reale
 * @param v2 al doilea vector de numere reale
 * @return float, produsul scalar a v1 si v2
 */
float prodScalar(vector<float> v1, vector<float> v2){
    float p=0;
    for(int i =0; i<v1.size(); i++){
        p+=(v1[i]*v2[i]);
    }
    return p;
}

//4.Să se determine cuvintele unui text care apar exact o singură dată în acel text. De ex. cuvintele care apar o singură dată în
// ”ana are ana are mere rosii ana" sunt: 'mere' și 'rosii'.
/**
 * Determina cuvintele care apar o singura data si le afiseaza
 * @param s - string, textul in care se cauta cuvintele
 */
void cuvUnice(const string& s){
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

//5.Pentru un șir cu n elemente care conține valori din mulțimea {1, 2, ..., n - 1} astfel încât o singură valoare se repetă
// de două ori, să se identifice acea valoare care se repetă. De ex. în șirul [1,2,3,4,2] valoarea 2 apare de două ori.
/**
 * Determina valoarea care apare de doua ori in v
 * @param v - vector<int>, {1, 2, ..., n - 1} cu o valoare care se repeta
 * @return int, valoarea care se repeta
 */
int valoareDubla(vector<int> v){
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

//7.Să se determine al k-lea cel mai mare element al unui șir de numere cu n elemente (k < n).
// De ex. al 2-lea cel mai mare element din șirul [7,4,6,3,9,1] este 7.
/**
 * Determina al k-lea cel mai mare element dintr-un sir
 * @param v sirul de int
 * @param k int
 * @return al k-lea cel mai mare element din v
 */
int kthLargest(vector<int>v, int k){
    //O(logn + k)
    priority_queue<int> pq(v.begin(), v.end());
    while(k>1){
        pq.pop();
        k--;
    }
    return pq.top();
}

//8.Să se genereze toate numerele (în reprezentare binară) cuprinse între 1 și n. De ex. dacă n = 4, numerele sunt: 1, 10, 11, 100.
/**
 * Afiseaza toate numerele binare mai mici decat n
 * @param n int, numarul zecimal pana la care se genereaza
 */
void nrBinare(int n){
    int crtBin=1;
    vector<int> nr;
    for(int zec=1; zec<=n; n++){

        if(crtBin % 10==1){
            crtBin*=10;
        }else{
            crtBin++;
        }

    }
}
/*
 * bin=111
 * p=3
 * zec=3
 * n=4
 */

//10.Considerându-se o matrice cu n x m elemente binare (0 sau 1) sortate crescător pe linii, să se identifice
// indexul liniei care conține cele mai multe elemente de 1.
/**
 * Determina indexul liniei cu cele mai multe el de 1
 * @param matr - matrice cu elemente binare sortate crescator pe linii
 * @return indexul liniei cautate (indexat de la 1)
 */
int max1(vector<vector<int>> matr){
    pair<int, int> min=pair<int,int>(INT_MAX,0);//numarul minim de 0
    for(int i=0; i<matr.size();i++){
        int j=0;
        while(j<matr[0].size() && matr[i][j]==0){
            j++;
        }
        if(j-1<min.first){
            min=pair<int,int>(j-1,i+1);
        }
    }

    return min.second;
}

//11.Considerându-se o matrice cu n x m elemente binare (0 sau 1), să se înlocuiască cu 1 toate aparițiile elementelor egale cu 0
// care sunt complet înconjurate de 1.
/**
 * Parcurge valorile de 0 din matrice si le marcheaza ca vizitate
 * @param board - matricea binara
 * @param vizited - multimea coordonatelor vizitate
 * @param start - punctul de start
 */
void dfs(vector<vector<int>>&board, set<pair<int, int>>& vizited, pair<int, int> start){
    if(board[start.first][start.second]==0 && vizited.find(start)==vizited.end()){
        vizited.insert(start);

        if(start.first>0)
            dfs(board, vizited, pair<int, int>(start.first-1, start.second));
        if(start.second>0)
            dfs(board, vizited, pair<int, int>(start.first, start.second-1));
        if(start.first<board.size()-1)
            dfs(board, vizited, pair<int, int>(start.first+1, start.second));
        if(start.second<board[0].size()-1)
            dfs(board, vizited, pair<int, int>(start.first, start.second+1));
    }


}

void zoneInconjurate(vector<vector<int>>& board) {
    set<pair<int, int>> vizited;
    //col stanga si dreapta
    for(int i=0; i<board.size();i++){
        dfs(board, vizited, pair<int, int>(i,0));
        dfs(board, vizited, pair<int, int>(i,board[0].size()-1));
    }

    //liniile sus si jos
    for(int i=1; i<board[0].size()-1;i++){
        dfs(board, vizited, pair<int, int>(0,i));
        dfs(board, vizited, pair<int, int>(board.size()-1, i));
    }

    for(int i=0; i<board.size(); i++){
        for(int j=0; j<board[0].size(); j++){
            if(board[i][j]==0 && vizited.find(pair<int, int>(i,j))==vizited.end()){
                board[i][j]=1;
            }
        }
    }
}



int main() {
    //1
    std::cout << ultimulCuv("Ana are mere rosii si galbene")<<'\n';
    //2
    std::cout << dEuclidiana(pair<int, int> (1,5), pair<int, int> (4,1))<<'\n';
    //3
    std::cout << prodScalar({1,0,2,0,3}, {1,2,0,3,1})<<'\n';
    //4
    cuvUnice("ana are ana are mere rosii ana");
    //5
    std::cout << valoareDubla({1,2,3,4,2})<<'\n';
//    std::cout << p6({2,8,7,2,2,5,2,3,1,2,2})<<'\n';
    //7
    std::cout << kthLargest({7,4,6,3,9,1}, 2)<<'\n';
    //10
    std::cout << max1({{0,0,0,1,1},
                       {0,1,1,1,1},
                       {0,0,1,1,1}})<<'\n';

    //11
    vector<vector<int>> matrZone={{1,0,0,1,1,0,1,1,1,1},
                                  {1,0,0,1,1,1,1,1,1,1},
                                  {1,1,1,1,0,0,1,1,0,1},
                                  {1,0,0,1,1,0,1,1,0,0},
                                  {1,1,0,1,1,0,0,1,0,1},
                                  {1,1,1,0,1,0,1,0,0,1},
                                  {1,1,1,0,1,1,1,1,1,1}};
    zoneInconjurate(matrZone);
    for(const auto& l : matrZone){
        for(const auto& el : l){
            cout<<el<<' ';
        }
        cout<<'\n';
    }
}
