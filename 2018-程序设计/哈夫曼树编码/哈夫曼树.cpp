#define _LOCAL_TEST_
#define	min3(x,y,z)	(min(min(x,y),z))
#define	max3(x,y,z)	(max(max(x,y),z))
#define	min4(x,y,u,v)	(min(min(x,y),min(u,v)))
#define	max4(x,y,u,v)	(max(max(x,y),max(u,v)))
#define	ALL(x)  (x.begin()), (x.end())
#define	INS(x)  inserter(x, x.begin())
#define	INF	0x3f3f3f3f
#define	MOD	1000000007
#define	PI	3.1415927
#define	EPS	1e-10


// #include "bits/stdc++.h"

#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;


typedef struct node{
    char txt;   //待编码的字符
    int feq;    //字符出现频率
    int self;   //本身之于数组当中的索引
    int lt, rt, pt; //右节点、右节点、双亲结点
    string code;    //对应的编码
}node;


//运算符定义在外面,写在里面应该只要一个变量
bool operator < (const node &a, const node &b){
    return a.feq < b.feq;
}

bool operator > (const node &a, const node &b){
    return a.feq > b.feq;
}

int root;
size_t maxCodeLen;
map<char, string> encoder;  //编码查询表
map<string, char> decoder;  //解码查询表
vector<node> charCodeTab;

void init(int sz){
    int nodeLenght = 2 * sz - 1;
    charCodeTab.resize(nodeLenght);
    for (int i = 0; i < nodeLenght; i++){
        charCodeTab[i].lt = -1;
        charCodeTab[i].rt = -1;
        charCodeTab[i].pt = -1;
        charCodeTab[i].self = i;
    }

    int f;
    unsigned char c;
    for (int i = 0; i < sz; i++){
        cin >> c >> f;
        charCodeTab[i].txt = c;
        charCodeTab[i].feq = f;
    }
   
    encoder.clear(); //清空编码词典
    maxCodeLen = -1; //初始化最长编码长度
    
}

void merge(int sz,int & root){
    priority_queue<node, vector<node>, greater<node>> que;
    for (int i = 0; i < sz; i++){
        que.push(charCodeTab[i]);
    }
    int idx = sz;
    while(que.size() > 1){
        auto t1 = que.top();que.pop();
        auto t2 = que.top();que.pop();
        charCodeTab[idx].feq = t1.feq + t2.feq;
        charCodeTab[idx].lt = t1.self;
        charCodeTab[idx].rt = t2.self;
        charCodeTab[idx].self = idx;
        // t1.pt = idx;
        // t2.pt = idx;
        // 上述修改只对副本进行了操作,而非修改本尊
        charCodeTab[t1.self].pt = idx;
        charCodeTab[t2.self].pt = idx;
        que.push(charCodeTab[idx++]);
    }
    root =  que.top().self;//返回根节点
}


void HuffmanCode(int root,char digit){
    if (root != -1){
        node &curr = charCodeTab[root];
        // cout << "root =  " << root 
        // << " lt = " << curr.lt << " rt = " << curr.rt 
        // << " pt = " << curr.pt << endl;
        if (curr.pt != -1){
            curr.code = charCodeTab[curr.pt].code;
            curr.code.push_back(digit);
        }
        HuffmanCode(charCodeTab[root].lt, '0');
        HuffmanCode(charCodeTab[root].rt, '1');
    }
}



void traverse(int root){
    if (root != -1){
        node &curr = charCodeTab[root];
        if (curr.lt == -1 && curr.rt == -1){
            encoder[curr.txt] = curr.code;
            decoder[curr.code] = curr.txt;
            maxCodeLen = max(maxCodeLen, curr.code.size());
            cout << curr.txt << " : " << curr.code << endl;
        }
        traverse(charCodeTab[root].lt);
        traverse(charCodeTab[root].rt);
    }
}


void txtDecode(int lines){
    char c;
    string code;
    cin.get(c);
    while(lines--){
        // 哈夫曼编码的前缀总是不相同的!
        // 因此我们可以不断添加前缀直至找到对应的字符为止
        while (cin.get(c)){
            if (c == '\n'){
                cout << endl;
                break;
            }
            code += c;
            if(decoder.count(code)){
                // 每次找到字符都要清空一下字符串
                cout << decoder[code];
                code.clear();
            }
        }
    }
}


int main(){ 
    #ifdef _LOCAL_TEST_
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    
    #ifndef _LOCAL_TEST_
    std::ios::sync_with_stdio(false);
    //ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);//
    #endif

    int x,c;
    while (cin >> x){
        init(x);                    // 初始化
        merge(x, root);             // 合并结点建树
        HuffmanCode(root, '0');     // 为树编码
        traverse(root);             // 遍历一遍把所有编码存入哈希表
        cin >> x;
        txtDecode(x);
    }
    return 0;
}