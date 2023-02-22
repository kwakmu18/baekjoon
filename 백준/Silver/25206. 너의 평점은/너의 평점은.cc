#include <bits/stdc++.h>

using namespace std;

map<string, double> credit;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.precision(7);

    credit["A+"] = 4.5; credit["A0"] = 4.0; credit["B+"] = 3.5; credit["B0"] = 3.0;
    credit["C+"] = 2.5; credit["C0"] = 2.0; credit["D+"] = 1.5; credit["D0"] = 1.0;
    credit["F"] = 0;

    int N = 20;
    double totalCredit = 0, totalGrade = 0;
    
    while (N--) {
        string subject, grade;
        double c;

        cin >> subject >> c >> grade;
        if (grade=="P") continue;

        totalGrade += (credit[grade] * c);
        totalCredit += c;
    }

    cout << totalGrade / totalCredit;
}