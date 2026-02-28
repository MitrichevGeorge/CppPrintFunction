#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

template<typename T> struct is_container { static constexpr bool value = false; };
template<typename T, typename Alloc> struct is_container<vector<T, Alloc>> { static constexpr bool value = true; };
template<typename T, typename Alloc> struct is_container<list<T, Alloc>> { static constexpr bool value = true; };
template<typename T, typename Alloc> struct is_container<deque<T, Alloc>> { static constexpr bool value = true; };
template<typename T, typename Alloc> struct is_container<set<T, Alloc>> { static constexpr bool value = true; };
template<typename T, typename Alloc> struct is_container<multiset<T, Alloc>> { static constexpr bool value = true; };
template<typename T, typename Alloc> struct is_container<unordered_set<T, Alloc>> { static constexpr bool value = true; };
template<typename Key, typename T, typename Compare, typename Alloc> struct is_container<map<Key, T, Compare, Alloc>> { static constexpr bool value = true; };
template<typename Key, typename T, typename Compare, typename Alloc> struct is_container<multimap<Key, T, Compare, Alloc>> { static constexpr bool value = true; };
template<typename Key, typename T, typename Hash, typename KeyEqual, typename Alloc> struct is_container<unordered_map<Key, T, Hash, KeyEqual, Alloc>> { static constexpr bool value = true; };
template<typename T, typename Alloc> struct is_container<queue<T, Alloc>> { static constexpr bool value = true; };
template<typename T, typename Alloc> struct is_container<stack<T, Alloc>> { static constexpr bool value = true; };
template<typename T1, typename T2> struct is_container<pair<T1, T2>> { static constexpr bool value = false; };

template<typename T>
void print_element(ostream& os, const T& value, bool is_last = true);

template<typename T1, typename T2>
void print_element(ostream& os, const pair<T1, T2>& p, bool is_last = true) {
    os << "(";
    print_element(os, p.first, false);
    print_element(os, p.second, true);
    os << ")";
    if (!is_last) os << " ";
}

template<>
void print_element(ostream& os, const string& value, bool is_last) {
    os << "\"" << value << "\"";
    if (!is_last) os << " ";
}

template<>
void print_element(ostream& os, const char* const& value, bool is_last) {
    os << "\"" << value << "\"";
    if (!is_last) os << " ";
}

template<typename T>
void print_element(ostream& os, const T& value, bool is_last) {
    if constexpr (is_container<T>::value) {
        os << "[";
        size_t idx = 0;
        for (const auto& elem : value) {
            print_element(os, elem, idx == value.size() - 1);
            if (idx++ != value.size() - 1) os << ", ";
        }
        os << "]";
    } 
    else if constexpr (is_same_v<T, bool>) {
        os << (value ? "true" : "false");
    }
    else {
        os << value;
    }
    if (!is_last) os << " ";
}

template<typename T, typename Container>
void print_element(ostream& os, const stack<T, Container>& s, bool is_last = true) {
    stack<T, Container> temp = s;
    vector<T> elements;
    while (!temp.empty()) {
        elements.push_back(temp.top());
        temp.pop();
    }
    reverse(elements.begin(), elements.end());
    print_element(os, elements, is_last);
}

template<typename T, typename Container>
void print_element(ostream& os, const queue<T, Container>& q, bool is_last = true) {
    queue<T, Container> temp = q;
    vector<T> elements;
    while (!temp.empty()) {
        elements.push_back(temp.front());
        temp.pop();
    }
    print_element(os, elements, is_last);
}

void print() { cout << endl; }

template<typename T, typename... Args>
void print(const T& first, const Args&... args) {
    print_element(cout, first, sizeof...(args) == 0);
    if constexpr (sizeof...(args) > 0) {
        print(args...);
    } else {
        cout << endl;
    }
}

int main() {
    print(1, 2, 3, 4, 5);
    print("Hello", "World");
    print(3.14, "pi", true);
    
    vector<int> v = {1, 2, 3};
    print(v);
    
    map<string, int> m = {{"one", 1}, {"two", 2}};
    print(m);
    
    queue<int> q; q.push(1); q.push(2); q.push(3);
    print(q);
    
    stack<double> s; s.push(1.1); s.push(2.2);
    print(s);
    
    deque<int> d = {1, 2, 3, 4};
    print(d);
    
    vector<vector<int>> vv = {{1, 2}, {3, 4}};
    print(vv);

    vector<vector<vector<int>>> b = {{{1, 2, 3}, {4, 5, 6}}, {{1, 2, 3}, {4, 5, 6}}};
    print(b);

    print();
    
    print("wefg", vv, m);
    
    return 0;
}
