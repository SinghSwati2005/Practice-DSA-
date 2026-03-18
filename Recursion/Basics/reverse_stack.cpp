#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int>&st, int val){
if(st.empty()){
    st.push(val);
    return;
}
int topval = st.top();
st.pop();
insertAtBottom(st,val);
st.push(topval);
}

void reverseStack(stack<int>&st){
    if(st.empty()) return;

    int topval = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st,topval);
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
    reverseStack(st);
     while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
     }
         cout << endl;
     return 0;
}

