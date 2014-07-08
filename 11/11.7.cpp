#include <iostream>
#include <vector>

using namespace std;

struct Person {
    int weight, height;
    Person(int weight, int height): weight(weight), height(height) {}
    bool operator<(const Person &that) const {
        return weight < that.weight && height < that.height;
    }
};

istream & operator>> (istream &is, Person &person) {
    is >> person.weight >> person.height;
    return is;
}

ostream & operator<< (ostream &os, const Person &person) {
    os << "(" << person.weight << "," << person.height << ")";
    return os;
}

int DFS(const vector<Person> &person, vector<int> &len, vector<int> &pre, int x) {
    if (len[x]) return len[x];
    int maxdist = 0;
    for (int i = 0; i < person.size(); ++i) {
        if (person[x] < person[i]) {
            int dist = DFS(person, len, pre, i);
            if (dist > maxdist) {
                maxdist = dist;
                pre[x] = i;
            }
        }
    }
    return len[x] = maxdist + 1;
}

vector<int> solve(const vector<Person>& person) {
    vector<int> result;
    if (person.size() == 0) {
        return result;
    }
    vector<int> len(person.size(), 0), pre(person.size(), -1);
    int maxdist = 0, top;
    for (int i = 0; i < person.size(); ++i) {
        int dist = DFS(person, len, pre, i);
        if (dist > maxdist) {
            maxdist = dist;
            top = i;
        }
    }
    while (top != -1) {
        result.push_back(top);
        top = pre[top];
    }
    return result;
}

int main() {
    vector<Person> person = {{65, 100}, {70, 150}, {56, 90}, {75, 190}, {60, 95}, {68, 110}};
    vector<int> idx = solve(person);
    for (int i = 0; i < idx.size(); ++i) {
        cout << person[idx[i]] << " ";
    }
    cout << endl;
    return 0;
}

