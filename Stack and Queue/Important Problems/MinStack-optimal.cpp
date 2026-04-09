#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;


class MinStack{
    private : 
    //stack<pair<int,int>>st;
    stack<int>st;
    int currMin;

    public:
    MinStack(){};

    void push(int value){
        if(st.empty()){
            
            currMin = value;
            st.push(value);
         

        }
        else 
            if(value>=currMin){
                st.push(value);
            }

            else {
                st.push(2*value - currMin);
                currMin = value;
            }
        
    }

    void pop(){
        if(st.empty()){
            return;
        }
else{
    int x = st.top();
    st.pop();

    if(x<currMin){
        currMin = 2* currMin -x;
    }
}



    }

    int top(){
        if(st.empty()) return -1;

        int x = st.top();
        if(currMin<x) return x;
        return currMin;
    }

    int getMin (){
        return currMin;
    }
};

int main(){
    MinStack s;
    int choice , value;

   cout << "MinStack Operations Menu:\n";
    cout << "1. Push\n2. Pop\n3. Top\n4. GetMin\n5. Exit\n";

while(true){
    cout<<"Enter Choices:";
    cin>>choice;

    switch(choice){
        case 1 :
        cout<<"Enter value:";
        cin>>value;
        s.push(value);
        break;

        case 2:
        s.pop();
        break;
        case 3:
       cout<< s.top();
       break;
case 4:
                cout << "Minimum element: " << s.getMin() << endl;
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice, try again." << endl;
        }
    }
}