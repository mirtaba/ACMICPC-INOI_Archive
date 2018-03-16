#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '('){
            st.push('(');
           }
           else if(s[i] == ')'){
            if(st.size() > 0){
                st.pop();
            }
            else {
                cout << "Impossible" <<endl;
                return 0;
            }
           }
           else {
            if(st.size() > 0){
                st.pop();
                s[i] = ')';
            }
            else{
                st.push('(');
                s[i] = '(';
            }
           }
    }
    if(st.size() == 0){
        cout << s << endl;
    }
    else{
        cout << "Impossible" <<endl;
    }
    return 0;
}
