/* Copyright [2019] <mituh> */
/* 1153-decode-registration-card-of-pAT-25.cpp */
/* 字符串处理, map, STL, 排序 */
/*
9 4
B123180908127 99
B102180908003 86
A112180318002 98
T107150310127 62
A107180908108 100
T123180908010 78
B112160918035 88
A107180908021 98
B107180908022 98
1 A
2 107
3 180908
2 999
Sample Output:

Case 1: 1 A
A107180908108 100
A107180908021 98
A112180318002 98
Case 2: 2 107
3 260
Case 3: 3 180908
107 2
123 2
102 1
Case 4: 2 999
NA
*/
#include <cstdio>
#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
#define MaxSize 10050
#define INF 99999
struct LNode {
  string ID; int score;
};
struct SNode {
  int num, tot_score;
  string date;
};
struct DNode {
  string site; int num;
};

unordered_map<string, vector<LNode> > mp_level;
unordered_map<string, SNode> mp_site;
unordered_map<string, vector<DNode> > mp_date;

string split(string s, int start, int end) {
  int i; string ans = "";
  for (i = start; i < end; i++) ans += s[i];
  return ans;
}

int IsExist(vector<DNode> v, string s) {
  int i, ans = -1;
  for (i = 0; i < v.size(); i++) {
    if (v[i].site == s) { ans = i; break; }
  }
  return ans;
}

bool cmp_level(LNode n1, LNode n2) {
  if (n1.score != n2.score) {
    return n1.score > n2.score;
  }
  return n1.ID < n2.ID;
}

bool cmp_date(DNode n1, DNode n2) {
  if (n1.num != n2.num) {
    return n1.num > n2.num;
  }
  return n1.site < n2.site;
}
int main() {
#ifdef LOCAL
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
#endif
  int n, m, i, j;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    string ID, level, site, date; int score;
    cin >> ID >> score;
    level = split(ID, 0, 1);
    site = split(ID, 1, 1+3);
    date = split(ID, 4, 4+6);
    // cout << level << " " << site << " " << date << endl;
    LNode l_node; l_node.ID = ID; l_node.score = score;
    mp_level[level].push_back(l_node);
    
    if (mp_site.count(site)) {
      mp_site[site].num++;
      mp_site[site].tot_score += score;
    } else {
      SNode s_node; s_node.num = 1; s_node.tot_score = score;
      mp_site[site] = s_node;
    }
    
    int site_i = IsExist(mp_date[date], site);
    if (site_i != -1) {
      mp_date[date][site_i].num++;
    } else {
      DNode d_node; d_node.num = 1; d_node.site = site;
      mp_date[date].push_back(d_node);
    }
  }
  int type, ok; string s;
  for (i = 0; i < m; i++) {
    cin >> type >> s;
    cout << "Case " << i+1 << ": " << type << " " << s << endl;
    ok = 0;
    if (type == 1) {
      if (s == "T" || s == "A" || s == "B") {
        ok = 1;
        sort(mp_level[s].begin(), mp_level[s].end(), cmp_level);
        for (j = 0; j < mp_level[s].size(); j++) {
          cout << mp_level[s][j].ID << " " << mp_level[s][j].score << endl;
        }
      }
    } else if (type == 2) {
      if (mp_site.count(s)) {
        ok = 1;
        cout << mp_site[s].num << " " << mp_site[s].tot_score << endl;
      }
    } else if (type == 3) {
      if (mp_date.count(s)) {
        ok = 1;
        sort(mp_date[s].begin(), mp_date[s].end(), cmp_date);
        for (j = 0; j < mp_date[s].size(); j++) {
          cout << mp_date[s][j].site << " " << mp_date[s][j].num << endl;
        }
      }
    }
    if (!ok) cout << "NA\n";
  }
  return 0;
}

