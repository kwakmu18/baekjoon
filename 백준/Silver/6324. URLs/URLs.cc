//< protocol > "://" < host > [ ":" < port > ] [ "/" < path > ]
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n; string url;
    cin >> n;

    for(int i=1;i<=n;i++) {
        cin >> url;
        string protocol="", host="", port="<default>", path="<default>";
        bool port_exist=false, path_exist=false;
        int now=0, urllen=url.length(), colon_idx=0, slash_idx=0;

        while (url[now]!=':') {
            protocol+=url[now]; now++;
        } now+=3;

        for(int j=now;j<urllen;j++) {
            if (url[j]==':') {
                colon_idx=j; break;
            }
        }
        for(int j=now;j<urllen;j++) {
            if (url[j]=='/') {
                slash_idx=j; break;
            }
        }
        if (colon_idx==0 && slash_idx!=0) path_exist=true;
        else if (colon_idx!=0 && slash_idx==0) port_exist=true;
        else if (colon_idx>slash_idx) path_exist=true;
        else if (colon_idx!=0 && slash_idx!=0) {
            port_exist=true; path_exist=true;
        }

        if (port_exist) {
            port="";
            if (path_exist) {
                path="";
                while (url[now]!=':') {
                    host+=url[now]; now++;
                } now++;
                while (url[now]!='/') {
                    port+=url[now]; now++;
                } now++;
                while (now<urllen) {
                    path+=url[now]; now++;
                }
            }
            else {
                while (url[now]!=':') {
                    host+=url[now]; now++;
                } now++;
                while (now<urllen) {
                    port+=url[now]; now++;
                }
            }
        }
        else {
            if (path_exist) {
                path="";
                while (url[now]!='/') {
                    host+=url[now]; now++;
                } now++;
                while (now<urllen) {
                    path+=url[now]; now++;
                }
            }
            else {
                while (now<urllen) {
                    host+=url[now]; now++;
                }
            }
        }

        cout << "URL #" << i << "\n";
        cout << "Protocol = " << protocol << "\n";
        cout << "Host     = " << host << "\n";
        cout << "Port     = " << port << "\n";
        cout << "Path     = " << path << "\n\n";
    }
}