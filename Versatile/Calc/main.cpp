#include <iostream>
using namespace std;

#define ll long long

typedef struct {
    ll value;
    string binary;
    bool isPal;
}Number;

bool isPal (string number) {
    int Sz = number.size();
    int halfSz = Sz/2;
    for(int i = 0 ; i < halfSz; i++) {
        if(number[i] != number[Sz-i-1]) return false;
    }
    return true;
}


string intToBin(ll number) {
    int sz = 0;
    ll numCpy = number;
    int binCnt;
    for(binCnt = 0 ; numCpy!=0 ; binCnt++ ) numCpy >>= 1;
    if(binCnt == 0)binCnt = 1;
    string binNum(binCnt , ' ');

    for(int j = 0 ; j < binCnt;j++) {
        binNum[binCnt - j - 1] = (char)((number&1)+'0');
        number>>=1;
    }
    return binNum;
}

Number calc(ll n1 , ll n2, char opChar) {
    Number num;
    switch (opChar) {
        case '+':
            num.value = n1+n2;
        break;
        case '-':
            num.value = n1-n2;
        break;
        case '*':
            num.value = n1*n2;
        break;
        case '/':
            num.value = n1/n2;
        break;
        case '|':
            num.value = n1|n2;
        break;
        case '&':
            num.value = n1 & n2;
        break;
        default:
            num.binary = "";
            return num;
    }
    string out = intToBin(num.value);
    num.binary+=out;
    num.isPal = isPal(num.binary);
    return num;
}

void testCalc() {
    typedef struct {
        ll n1;
        ll n2;
        char opChar;
        string binOutput;
        bool isPalOut;

    }Test;
    Test tests[] = {
        {12 , 24 , '+' , intToBin(12+24) , isPal(intToBin(12+24))} ,
        {24 , 12 , '-' , intToBin(24-12) , isPal(intToBin(24-12))} ,
        {2 , 8 , '*' , intToBin(2*8) , isPal(intToBin(2*8))} ,
        {10 , 2 , '/' , intToBin(10/2) , isPal(intToBin(10/2))} ,
    };

    for(int i = 0 ; i < sizeof(tests)/sizeof(Test);i++) {
        Number out = calc(tests[i].n1 , tests[i].n2 , tests[i].opChar);
        if(out.binary!=tests[i].binOutput || out.isPal != tests[i].isPalOut) cout << "Error test "<<i+1;
    }
}

void testIsPal() {
    typedef struct {
        string testInput;
        bool testOutput;
    }Test;
    Test tests[] = {
        {"010" , true} ,
        {"1100" , false} ,
        {"1001" , true} ,
        {"10101", true}
    };

    for(int i = 0 ; i < sizeof(tests)/sizeof(Test);i++) {
        if(isPal(tests[i].testInput)!=tests[i].testOutput) cout << "Error test "<<i+1;
    }
}

void testIntToBin() {
    typedef struct {
        ll testInput;
        string testOutput;
    }Test;
    Test tests[] = {
        {0 , "0"} ,
        {10 , "1010"} ,
        {12 , "1100"} ,
        {3, "11"}
    };

    for(int i = 0 ; i < sizeof(tests)/sizeof(Test);i++) {
        if(intToBin(tests[i].testInput)!=tests[i].testOutput) cout << "Error test "<<i+1;
    }
}


int main() {
    testIsPal();
    testIntToBin();
    testCalc();
    ll n1 , n2 ;
    char optchar;
    cout << "enter number 1 , number2 , operation character (+ , - , * , / , & , |)\n";
    cout << "n1 : ";
    cin >> n1;
    cout << "n2 : ";
    cin >> n2;
    cout << "operation character : ";
    cin >> optchar;
    Number num = calc(n1, n2 , optchar);
    if(num.binary == "") {
        cout << "Wrong operation character";
        return -1;
    }
    cout << "----------------------\n";
    cout << "number in decimal : " << num.value << '\n';
    cout << "number in binary : " << num.binary << '\n';
    cout << "is number palindrome : " << (num.isPal?"true" : "false") << '\n';
}
