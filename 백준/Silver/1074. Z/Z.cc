#include <bits/stdc++.h>

using namespace std;

int N, r, c, cnt=0;
void part(int w, int h, int size) {
    if (size==2) {
        if (r==w && c==h) {
            cout << cnt;
        }
        else if (r==w+1 && c==h) {
            cout << cnt+1;
        }
        else if (r==w && c==h+1) {
            cout << cnt+2;
        }
        else if (r==w+1 && c==h+1) {
            cout << cnt+3;
        }
    }
    if (size>=4) {
        size/=2;
        int neww=w+size, newh=h+size;
        if (r<neww && c<newh) part(w,h,size);
        else if (r<neww+size && c<newh) {
            cnt+=size*size;
            part(neww,h,size);
        }
        else if (r<neww && c<newh+size) {
            cnt+=size*size*2;
            part(w,newh,size);
        }
        else {
            cnt+=size*size*3;
            part(neww,newh,size);
        }
    }

}

int main(void) {
    cin >> N >> c >> r;
    part(0,0,pow(2,N));
}