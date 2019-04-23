#include <iostream>
#include <memory>                // Library for using smarts pointers
#include <vector>
using namespace std;

class Test {
private:
    int data;
public:
    // Overloaded constructors
    Test()
    :data{0} {
        cout << "\tTest constructor {" << data << "}" << endl;
    }
    Test(int data)
    : data{data} {
        cout << "\tTest constructor {" << data << "}" << endl;
    }    
    int get_data() const {
        return data;
    }
    ~Test() {
        cout << "\tTest destructor {" << data << "}" << endl;
    }
};

auto make() {
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();   // () calls the constructor  
}

void fill(vector<shared_ptr<Test>> &vec, int num) {
    for (int i=0;i<num;i++) {
        int temp;
        cout << "Enter data point [" << i+1 << "]: ";       
        cin >> temp;
        std::shared_ptr<Test> ptr = std::make_shared<Test>(temp);
        vec.push_back(ptr);
    }
}

void display(const vector<shared_ptr<Test>> &vec) {
    cout << "Displaying vector data\n--------------------------------------" << endl;
    for (auto &c: vec) {
        cout << c->get_data() << endl;
    }
    cout << "--------------------------------------" << endl;
};

int main() {
    unique_ptr<vector<shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    cout << "How many data points do you want to enter: ";
    int num;
    cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}

