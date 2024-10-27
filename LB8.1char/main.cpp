#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

bool findStr(char* str) {
    int pos = 0;
    while (str[pos] != '\0') {
        if ((str[pos] == 'a' && str[pos + 1] == 'a') ||
            (str[pos] == 'b' && str[pos + 1] == 'b') ||
            (str[pos] == 'c' && str[pos + 1] == 'c')) {
            return true;
        }
        pos++;
    }
    return false;
}

char* Change(char* s) {
    size_t newSize = strlen(s) * 3 + 1;
    char* t = new char[newSize];
    int pos1 = 0;
    *t = 0;

    while (true) {
        char* p1 = strstr(s + pos1, "aa");
        char* p2 = strstr(s + pos1, "bb");
        char* p3 = strstr(s + pos1, "cc");

        char* p = nullptr;
        if (p1 && (!p || p1 < p)) p = p1;
        if (p2 && (!p || p2 < p)) p = p2;
        if (p3 && (!p || p3 < p)) p = p3;

        if (!p) break;

        int pos2 = p - s;
        strncat_s(t, newSize, s + pos1, static_cast<rsize_t>(pos2 - pos1));
        strcat_s(t, newSize, "***");
        pos1 = pos2 + 2;
    }

    strcat_s(t, newSize, s + pos1);

    return t;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    if (findStr(str)) {
        char* dest = Change(str);
        cout << "'aa or bb or cc' found and will be changed" << endl;
        cout << "Modified string (param) : " << str << endl;
        cout << "Modified string (result): " << dest << endl;
        delete[] dest;
    }
    else {
        cout << "'***' not found" << endl;
    }

    return 0;
}
