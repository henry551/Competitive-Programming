#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;
typedef pair <string,int> pii;
map <string,int> mp;
map <string,int>::iterator it;
unordered_map <int,int> num;

// lookup for map is O(logN)
// lookup for unordered_map is O(1)

void testMap(){
    mp.insert({"hi",3});
    mp.count("hi"); //1 means key is present, 0 means not present

    it = mp.find("hi");
    pii a = *it;

    it = mp.lower_bound("hi"); //lowest element with key greater than or equal to "hi"
    pii b = *it;

    it = mp.upper_bound("hi"); //lowest element with key greater than "hi"
    pii c = *it;

    it = mp.lower_bound("hi");
    it--;
    pii d = *it; //highest element with key less than "hi"

    num[3]+=2; //another way to add an element
    num.erase(3); //remove element with key 3

    //display elements in map
    for (it=mp.begin(); it!=mp.end(); it++){
        pii e = *it;
        printf("%d %d\n", e.first, e.second);
    }

    //display elements in unordered_map
    for (auto it: num){
        printf("%d %d\n", it.first, it.second);
    }
}