#include <bits/stdc++.h>

using namespace std;

string FizzBuzz(int num) {
    bool cond3 = num%3==0, cond5 = num%5==0;
    if (cond3 && cond5) return "FizzBuzz";
    if (cond3 && !cond5) return "Fizz";
    if (!cond3 && cond5) return "Buzz";
    return to_string(num);
}



int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);

    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;

    int start;

    if (s1!="FizzBuzz" && s1!="Fizz" && s1!="Buzz") start = stoi(s1);
    if (s2!="FizzBuzz" && s2!="Fizz" && s2!="Buzz") start = stoi(s2);
    if (s3!="FizzBuzz" && s3!="Fizz" && s3!="Buzz") start = stoi(s3);

    for(int i=start-10;i<100000000;i++) {
        
        int a = i, b = i+1, c = i+2, d = i+3;

        if (FizzBuzz(a) == s1 && FizzBuzz(b) == s2 && FizzBuzz(c) == s3) {
            cout << FizzBuzz(d);
            break;
        }
    }


}