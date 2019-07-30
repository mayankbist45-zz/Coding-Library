#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define int long long
#define endl '\n'
#define MOD 1000000007

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

struct item {
    int key{}, prior{}, cnt{};
    item *l = NULL, *r = NULL;

    item(int key, int prior) : key(key), prior(prior), l(NULL), r(NULL) {}
};

typedef item *pitem;

int cnt(pitem t) {
    return t ? t->cnt : 0;
}

void upd_cnt(pitem t) {
    if (t)
        t->cnt = 1 + cnt(t->l) + cnt(t->r);
}

void split(pitem t, int key, pitem &l, pitem &r) {
    if (!t)
        l = r = NULL;
    else if (key < t->key)
        split(t->r, key, l, t->l), r = t;
    else
        split(t->l, key, t->r, r), r = t;
    upd_cnt(t);
}

void merge(pitem &t, pitem l, pitem r) {
    if (!l || !r)
        t = l ? l : r;
    else if (l->prior > r->prior)
        merge(l->r, l->r, r), t = l;
    else
        merge(r->l, l, r->l), t = r;
    upd_cnt(t);
}

void erase(pitem &t, int key) {
    if (t->key == key)
        merge(t, t->l, t->r);
    else
        erase(key < t->key ? t->l : t->r, key);
    upd_cnt(t);
}

void insert(pitem &t, pitem it) {
    if (!t)
        t = it;
    else if (it->prior > t->prior)
        split(t, it->key, it->l, it->r), t = it;
    else
        insert(it->key < t->key ? t->l : t->r, it);
    upd_cnt(t);
}

pitem unite(pitem l, pitem r) {
    if (!l || !r)
        return l ? l : r;
    if (l->prior < r->prior)
        swap(l, r);
    pitem lt, rt;
    split(r, l->key, lt, rt);
    l->l = unite(l->l, lt);
    l->r = unite(l->r, rt);
    return l;
}

void heapify(pitem t) {
    if (!t)
        return;
    pitem max = t;
    if (t->l != NULL and t->l->prior > max->prior)
        max = t->l;
    if (t->r != NULL and t->r->prior > max->prior)
        max = t->r;
    if (max != t) {
        swap(t->prior, max->prior);
        heapify(max);
    }
}

pitem build(int *a, int n) {
    //Construct a treap
    if (n == 0)
        return NULL;
    int mid = n / 2;
    pitem t = new item(a[mid], rand());
    t->l = build(a, mid);
    t->r = build(a + mid + 1, n - mid - 1);
    heapify(t);
    return t;
}

void dfs(pitem &t) {
    if (!t)
        return;
    dfs(t->l);
    cout << t->key << " ";
    dfs(t->r);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    map<char, int> get;
    get['I'] = 1;
    get['D'] = 2;
    get['K'] = 3;
    get['C'] = 4;

    item *Treap;
    for (int i = 0; i < q; i++) {
        char c;
        int x;
        cin >> c >> x;

        if (get[c] == 1){

            insert(Treap , )
        }
        else if (get[c] == 2)
            st.erase(x);
        else if (get[c] == 3) {
            int sz = st.size();
            if (sz >= x)
                cout << *st.find_by_order(x - 1) << endl;
            else
                cout << "invalid" << endl;
        } else
            cout << st.order_of_key(x) << endl;
    }
    dfs(Treap);

    return 0;
}

