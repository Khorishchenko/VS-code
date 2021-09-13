#include <iostream>
#include <set>
using namespace std;
 
int main() {
    set <int> st;
 
    for (int i = 0; i < 5; i++) {
        st.insert(i + 1);
    }
 
    set <int> :: iterator it = st.begin();
 
    cout << *it; // 1
    it++;
    cout << *it; // 2
    return 0;
}
