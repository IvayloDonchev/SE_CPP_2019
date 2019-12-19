#include <algorithm>
#include <chrono>
#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include <vector>

using namespace std;

template <typename T>
void filter(const vector<T>& v, vector<T>& lesser, const int pivot) {
    for (const auto el : v) {
        if (el < pivot) lesser.push_back(el);
    }
}

template <typename T>
void quick_sort(vector<T>& v) {
    if (v.size() <= 1) return;
    auto start_it = v.begin();
    auto end_it = v.end();

    const T pivot = *start_it;
    vector<T> lesser;
    auto fut1 = std::async([&]() {
        filter<T>(std::ref(v), std::ref(lesser), pivot);
        quick_sort<T>(std::ref(lesser));
        });


    vector<T> greater;
    copy_if(start_it + 1, end_it, std::back_inserter(greater),
        [&](const T& el) { return el >= pivot; });

    quick_sort(greater);

    fut1.wait();

    std::copy(lesser.begin(), lesser.end(), v.begin());
    v[lesser.size()] = pivot;
    std::copy(greater.begin(), greater.end(),
        v.begin() + lesser.size() + 1);
}


int main() {
    vector<int> v;

    int n;
    cin >> n;
    v.reserve(n);
    while (n--) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    auto start = std::chrono::high_resolution_clock::now();

    quick_sort<int>(v);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Elapsed time " << elapsed.count() << " ms\n";


    for (unsigned i = 0; i < v.size() - 1; i++) {

        if (v[i] != i + 1) {
            cerr << "Huston we have a problem" << endl;
            cerr << v[i] << " " << v[i + 1] << endl;
            return 0;
        }
    }

    return 0;
}

/*
double T1(){
    std::cout << "T1 : start" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "T1 : end" << std::endl;
    return 5.2;
}

int T2(){
    std::cout << "T2 : start" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "T2 : end" << std::endl;
    return 444;
}

void T3(double arg1, int arg2){
    std::cout << "T3 : start" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "T3 : end" << std::endl;
}

int main(){

    auto start = std::chrono::high_resolution_clock::now();

    std::cout << "I'm the main thread: start" << std::endl;
    {
        auto future_t1 = std::async(std::launch::deferred,T1);
                const int res_t2 = T2();
        const double res_t1 = future_t1.get();
        T3(res_t1, res_t2);
    }
    std::cout << "I am the main thread: completed" << std::endl;

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end-start;
    std::cout << "Elapsed time " << elapsed.count() << " ms\n";
    return 0;
}*/