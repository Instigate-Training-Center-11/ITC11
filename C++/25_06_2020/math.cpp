#include <iostream>
#include <stack>
using namespace std;

int math(string ss) {
	stack<string>* stck = new stack<string>[2];
        string s = "";
        int length = sizeof(ss);
        int j = 0;
        for(int i = 0; i < length; ++i) {
                if(ss[i] >= '0' && ss[i] <= '9') {
                        s += ss[i];
                } else {
		 		if(ss[i] == '(' ) {
					string d = ""; 
					d += ss[i];
					stck[1].push(d);
					s = "";
					continue;
				} else {
				if(ss[i] == '=') {
					if(s != "") {
						stck[0].push(s); // 5 3 2
					}
                                        break;
                                }
				stck[0].push(s); // 5 3 2

				cout << s << endl;
                 
				if((ss[i] == '+' || ss[i] == '-') && stck[0].size() >= 2  && (stck[1].top()[0] == '*' || stck[1].top()[0] == '/')) {
					int m = stoi(stck[0].top());
					stck[0].pop();
					int n = stoi(stck[0].top());
                        	        stck[0].pop();
					char ch = stck[1].top()[0];
					stck[1].pop();
					if(ch == '*') {
						stck[0].push(to_string(n * m));
					} else if(ch == '/') {
						stck[0].push(to_string(n / m));
					}
				}

				if(ss[i] == ')') {
					while(stck[1].top()[0] != '(') {
                				int m = stoi(stck[0].top());
                				stck[0].pop();
                				int n = stoi(stck[0].top());
                				stck[0].pop();

                				char ch = stck[1].top()[0];
                				stck[1].pop();

              					if(ch == '*') {
                        				stck[0].push(to_string(n * m));
                				}  if(ch == '/') {
                        				stck[0].push(to_string(n / m));
                				}  if(ch == '-') {
                        				stck[0].push(to_string(n - m));
                				}  if(ch == '+') {
                        				stck[0].push(to_string(n+m));
                				}
        				}
					stck[1].pop();
					s = "";
					continue;
				}
				s = ss[i];
				stck[1].push(s);  // + - 
				cout << stck[1].top() << endl;
                        	s =  "";
			}
                }
	}
	cout << "stck[0] :" << stck[0].size() << endl;
	string sss;

	while(!stck[1].empty()) {
		int m = stoi(stck[0].top());
                stck[0].pop();
                int n = stoi(stck[0].top());
                stck[0].pop();

                char ch = stck[1].top()[0];
                stck[1].pop();
		
		int sum = 0;

		if(ch == '*') {
			stck[0].push(to_string(n * m));
                }  if(ch == '/') {
                        stck[0].push(to_string(n / m));
		}  if(ch == '-') {
                        stck[0].push(to_string(n - m));
                }  if(ch == '+') {
                        stck[0].push(to_string(n+m));
                }	 
	}
        return stoi(stck[0].top());
}

int main() {
	// cin 5+(7-2+8/4)= or 5*8+9/3+1=
        string s;
        cin >> s;
        int sum = math(s);

	cout << "sum :" << sum << endl;

        return 0;
}

