#include<iostream>
#include<stack>
using namespace std;

void insert(stack<int>&st, int x){
    if(st.empty()|| st.top()<x){
        st.push(x);
        return ;

    }
    int temp = st.top();
    st.pop();
    insert(st,x);
    st.push(temp);
}

void sortstack(stack<int>&st){
    if(st.empty()) return ;
    int top = st.top();
    st.pop();
    sortstack(st);
    insert(st, top);
}
int main(){
    int n;
    cin>>n;
    stack<int>st;
    for(int i =0;i<n;i++){
        int x;
        cin>>x;
        st.push(x);
    }
    sortstack(st);

    while(!st.empty()){
        cout<<st.top();
        st.pop();
        if (!st.empty()) cout << ", ";
    }
    return 0;
}

