# CppPrintFunction
Функция print из python теперь в c++

### Примеры использования:
```cpp
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
```
