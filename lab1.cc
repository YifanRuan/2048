#include <bits/stdc++.h>
using namespace std;

class Lab1 {
  private:
    int left;
    int side, size;
    vector<string> nums;
    vector<int> order;

    void check() {
        string s;
        getline(cin, s);
        while (s != "n") getline(cin, s);
    }
    void pick() {
        int swap_t = rand() % (left + 1);
        swap(order[swap_t], order[left]);
        nums[order[left]][3] = '2';
    }
    void output_divs() {
        for (int i = 1; i <= side; ++i) cout << "+-----";
        cout << "+" << endl;
    }
    void output_nums(int front) {
        for (int i = 0; i < side; ++i) cout << nums[i + front * side];
        cout << "|" << endl;
    }
    void output() {
        for (int i = 0; i < side; ++i) {
            output_divs();
            output_nums(i);
        }
        output_divs();
    }

  public:
    void init(int a) {
        srand(unsigned(time(NULL)));
        side = a, size = a * a, left = size;
        for (int i = 0; i < size; ++i) nums.push_back("|     "), order.push_back(i);
        output();
    }
    void run() {
        while (left--) {
            check();
            pick();
            output();
        }
        cout << "game over" << endl;
    }
};

int main() {
    Lab1 l;
    l.init(4);
    l.run();
    return 0;
}