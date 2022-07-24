#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;

struct Movie {
    int shop, movie, price;
    bool rented;
    Movie() {}
    Movie(int shop, int movie, int price, bool rented){
        this->shop = shop;
        this->movie = movie;
        this->price = price;
        this->rented = rented;
    }
};

struct cmp1 {
    bool operator() (const Movie &a, const Movie &b) const{
        if (a.rented != b.rented) {
            if (!a.rented) return true;
            else return false;
        }
        if (a.price != b.price) return a.price < b.price;
        if (a.shop != b.shop) return a.shop < b.shop;
        return false;
    }
};

struct cmp2 {
    bool operator() (const Movie &a, const Movie &b) const{
        if (a.rented != b.rented) {
            if (a.rented) return true;
            else return false;
        }
        if (a.price != b.price) return a.price < b.price;
        if (a.shop != b.shop) return a.shop < b.shop;
        return a.movie < b.movie;
    }
};

class MovieRentingSystem {
public:
    int n;
    set <Movie, cmp1> movies[10005];
    set <Movie, cmp2> shops;
    map <pii, int> price;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        this -> n = n;
        for (vector <int> entry: entries){
            movies[entry[1]].insert(Movie(entry[0], entry[1], entry[2], false));
            shops.insert(Movie(entry[0], entry[1], entry[2], false));
            price[{entry[0], entry[1]}] = entry[2];
        }
        // cout << "ok" << endl;
        // for (auto it: shops){
        //     cout << it.shop << " " << it.movie << " " << it.price << endl;
        // }
        // shops.erase(Movie(1,2,3,false));
        // cout << "ok" << endl;
        // for (auto it: shops){
        //     cout << it.shop << " " << it.movie << " " << it.price << endl;
        // }
    }
    
    vector<int> search(int movie) {
        vector <int> res;
        int i = 0;
        for (auto it = movies[movie].begin(); it != movies[movie].end() && i < 5 && !it->rented; it++, i++) {
            res.push_back(it->shop);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int p = price[{shop, movie}];
        movies[movie].erase(Movie(shop, movie, p, false));
        movies[movie].insert(Movie(shop, movie, p, true));
        shops.erase(Movie(shop, movie, p, false));
        shops.insert(Movie(shop, movie, p, true));
    }
    
    void drop(int shop, int movie) {
        int p = price[{shop, movie}];
        movies[movie].erase(Movie(shop, movie, p, true));
        movies[movie].insert(Movie(shop, movie, p, false));
        shops.erase(Movie(shop, movie, p, true));
        shops.insert(Movie(shop, movie, p, false));
    }
    
    vector<vector<int>> report() {
        vector <vector<int>> res;
        int i=0;
        for (auto it = shops.begin(); it != shops.end() && i < 5 && it->rented; it++, i++) {
            res.push_back(vector <int> {it->shop, it->movie});
        }
        return res;
    }
};

int main(){
    int s, n;
    cin >> s >> n;
    vector<vector<int>> entries(n, vector<int> (3,0));
    for (int i=0; i<n; i++){
        for (int j=0; j<3; j++){
            cin >> entries[i][j];
        }
    }
    MovieRentingSystem sys = MovieRentingSystem(s, entries);
    sys.rent(0, 1);
    sys.rent(1, 2);
    vector<vector<int>> a = sys.report();
    for (vector <int> aa: a){
        cout << aa[0] << " " << aa[1] << endl;
    }
    sys.drop(1, 2);
    vector <int> b = sys.search(2);
    for (auto i: b){
        cout << i << " ";
    } cout << endl;
    return 0;
}