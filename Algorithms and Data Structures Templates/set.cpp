#include <set>
using namespace std;
set <int> st;
set <int>::iterator it;

void testSet(){
    st.insert(3);
    st.count(3); //1 means element is present, 0 means not present
    st.insert(4);
    it = st.find(4);
    st.erase(4);

    //display elements in map
    for (it=st.begin(); it!=st.end(); it++){
        int e = *it;
        printf("%d\n", e);
    }
}