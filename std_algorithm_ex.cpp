#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <list>
#include <numeric>


using namespace std;

// simple predicate
bool foo(int a) {
    return a > 0;
}
class Student {
public:
    Student(string name, double rating)
    :name(name), rating(rating) {

    }
    friend ostream& operator<<(ostream& os, const Student& student);
    bool operator==(const Student& other) const;


    string name;
    double rating;
};

ostream & operator<<(ostream& os, const Student& student){
        os << student.name << " " << student.rating << ". " << endl;
        return os;
}

bool Student::operator==(const Student &other) const {
    {
        if (this->name == other.name && this->rating == other.rating) return true;
        return false;
    }
}

int main(int argc, char * argv[]) {








    std::vector<int> v = {-10, 2, 4, 0, -3, 10, 13};
    auto result = std::count_if(v.begin(), v.end(), foo); // pass predicate
    cout << "The number of elements that greater than 0 is: " << result << endl; // 4

    cout << "t std::equal ==================\t==================\t=================="<<endl;




    std::vector<int> vv = {1, 2, 3};
    std::vector<int> vvv = {1, 2, 3, 4};
    cout << boolalpha << std::equal(vv.begin(), vv.end(), vvv.begin(), vvv.end() - 1) << endl;
    // compare two ranges (1. 2, 3 and 1, 2, 3 without 4)

    cout << "\t std::find()  ==================\t==================\t=================="<<endl;




    std::vector<int> v2 = {1, 3, 5, 6, 7};
    auto res = std::find(v2.cbegin(), v2.cend(), 3);
    cout << *res << endl; // return iterator pointing to 3
    cout << *(++res) << endl;// next element after 3 is a 5;



    cout << "std::find() \t==================\t==================\t=================="<<endl;



    Student s("Russo", 4.4);
    Student s2("Elena", 4.4);
    Student s3("Dasha", 4.4);
    Student s33("Petya", 4.4);
    std::vector<Student> vector = {s, s2, s3};
    auto resultat =  std::find(vector.begin(), vector.end(), s33);
    if (resultat != vector.end()) cout << "+" << endl;
    else cout << "-" << endl;


    resultat = std::find_if(vector.begin(), vector.end(), [](Student& student) {
        return student.name == "Masha";
    });
    if (resultat != vector.end()) cout << "Elena found" << endl;
    else cout << "NOT FOUND" << endl;





    cout << "\t std::find_if ==================\t==================\t=================="<<endl;

    std::vector<int> vec = {100, 200, 300, 400, 500};
    auto r = std::find_if(vec.begin(), vec.end(), [](int a) {
        return a > 100 && a < 400; // return true if find value between 100 and 400
    });
    std::cout << *r << endl;




    cout << "\t std::find_if ==================\t==================\t=================="<<endl;
    // Student s7("Russo", 4.4);
    // Student s8("Elena", 4.4);
    // Student s9("Dasha", 4.4);
    // Student s10("Petya", 4.4);
    // std::vector<Student*> vector22 = {&s, &s2, &s3, &s10};
    // auto re = std::find_if(vector22.begin(), vector22.end(), [](Student* student) {
    //     return student->name=="Russo";
    // });
    // cout << (re == vector22.end() ? "false" : "true") << endl;
    cout << "\tstd::copy ==================\t==================\t=================="<<endl;
    Student s7("Russo", 4.4);
    Student s8("Elena", 4.4);
    Student s9("Dasha", 4.4);
    Student s10("Petya", 4.4);
    std::vector<Student*> vector22 = {&s, &s2, &s3, &s10};
    std::vector<Student*> new_students;

    std::copy(vector22.begin(), vector22.end(), back_inserter(new_students));
    std::for_each(new_students.begin(), new_students.end(), [](Student* s) {
        cout << *s << endl;
    });

    cout << "\t std::copy_if ==================\t==================\t=================="<<endl;
    Student s11("Russo", 4.4);
    Student s12("Elena", 4.0);
    Student s13("Dasha", 3.4);
    Student s14("Petya", 3.9);
    Student s15("Petya", 4.7);
    std::vector<Student*> vector33 = {&s11, &s12, &s13, &s14, &s15};
    std::vector<Student*> new_students1;


    // copy student if only rating > 4
    std::copy_if(vector33.begin(), vector33.end(), std::back_inserter(new_students1), [](Student * student) {
        return student->rating >= 4.0;
    });
    for (int i = 0; i < new_students1.size(); ++i) printf("Student name: %s. rating: %f \n", new_students1[i]->name.c_str(), new_students1[i]->rating);



    cout << "\t copy_if ==================\t==================\t=================="<<endl;

    std::vector<int> vector_int = {10, 15, -5, 13, -2, -5, 0};
    std::vector<int> new_vector_int;
    std::copy_if(vector_int.begin(), vector_int.end(), std::back_inserter(new_vector_int), [](int num) {
        return num > 0;
    });
    std::for_each(std::begin(new_vector_int), std::end(new_vector_int), [](int n){cout<<n<<endl;});



    cout << "\t custom sort  algorithm ==================\t==================\t=================="<<endl;
    int arr [] = {10, 7, 12, 9, 5, 15, 3, 11};

    for (int i = 1; i < std::size(arr); ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }



    std::for_each(std::begin(arr), std::end(arr), [](int n)->void{cout<<n<<endl;});


    cout << "\t sort ==================\t==================\t=================="<<endl;

    std::list<int> l = {10, 7, 5, 12, 11, 8, 3, 13, 17};

    std::for_each(l.begin(), l.end(), [](int n){cout << n << endl;});

    cout << "\n\n\t sort() for simple array ==================\t==================\t=================="<<endl;
    int arrayy [] = {200, 202, 198, 204, 196, 207};
    std::sort(std::begin(arrayy), std::end(arrayy));
    for (int & elem : arrayy) cout << elem << endl;


    cout << "\t sort ==================\t==================\t=================="<<endl;

    Student s111("Russo", 4.4);
    Student s122("Elena", 4.0);
    Student s133("Dasha", 3.4);
    Student s144("Petya", 3.9);
    Student s155("Petya", 4.7);
    std::vector<Student*> vector333 = {&s111, &s122, &s133, &s144, &s155};
    std::sort(std::begin(vector333), std::end(vector333), [](Student * st, Student * st2) {
        return st->rating < st2->rating;
    });
    for (auto & el : vector333)cout << *el << endl;



    cout << "\t remove() -> iterator -> erase() ==================\t==================\t=================="<<endl;

    std::list<int> lst = {10, 7, 5, 12, 11, 8, 3, 13, 17};
    // lst.remove(10);
    auto it = std::remove(lst.begin(), lst.end(), 10);
    if (it != lst.end()) lst.erase(it);
    std::for_each(lst.begin(), lst.end(), [](int n){cout << n << endl;});

    cout << "\t remove_if()-> iterator -> erase() ==================\t==================\t=================="<<endl;
    std::vector<int> myv = {10, 7, 5, 12, 11, 8, 3, 13, 17};
    auto iter = std::remove_if(std::begin(myv), std::end(myv), [](int num) {
        return num >= 10;
    });
    myv.erase(iter, myv.end());
    for (int & el : myv) cout << el << endl;

    cout << "\t std::max_element() ==================\t==================\t=================="<<endl;
    std::vector<int> myv1 = {10, 7, 5, 12, 11, 8, 3, 13, 17};
    auto max_el = std::max_element(myv1.begin(), myv1.end());
    cout << *max_el << endl;


    cout << "\t std::min_element() ==================\t==================\t=================="<<endl;
    std::vector<int> myv2 = {10, 7, 5, 12, 11, 8, 3, 13, 17};
    auto min_el = std::min_element(myv1.begin(), myv1.end());
    cout << *min_el << endl;

    cout << "\t std::min_max_element() ==================\t==================\t=================="<<endl;
    std::vector<int> myv3 = {10, 7, 5, 12, 11, 8, 3, 13, 17};
    auto el = std::minmax_element(myv1.begin(), myv1.end()); // return pair<iter_min, iter_max>
    cout << "Min: " << *el.first << endl; // 3
    cout << "Max: " << *el.second << endl; // 17

    cout << "\t std::accumulate() ==================\t==================\t=================="<<endl;
    std::vector<int> myv4 = {10, 7, 5 };
    int accumulate = std::accumulate(myv4.begin(), myv4.end(), 0); // 10 + 7 + 5 + (0 - init value) = 22
    cout << "Sum of all elements: " << accumulate << endl;
    cout << "\t std::accumulate() overloading default behavour ==================\t==================\t=================="<<endl;
    std::vector<int> myv5 = {10, 7, 5 };
    int accumulate1 = std::accumulate(myv5.begin(), myv5.end(), 1, [](int num1, int num2) {
        // 1 replace 0, because if we pass 0, so 0 * 10 * 7 * 5 = 0;
        return num1 * num2;
    }); 
    cout << "Multiple of all elements: " << accumulate1 << endl;

    cout << "\t std::equal() ==================\t==================\t=================="<<endl;
    int a [] = {100, 200, 300};
    int b [] = {100, 200, 300};
    bool o = std::equal(begin(a), end(a), begin(b), end(b));
    cout << o << endl; // true


    cout << "\t std::equal() ==================\t==================\t=================="<<endl;
    std::vector<int> vector_1 = {10, 8, 12, 14};
    std::vector<int> vector_2 = {14, 8, 12, 10};
    // false
    cout << "Before sorting: " << std::equal(vector_1.begin(), vector_1.end(), vector_2.begin(), vector_2.end()) << endl;;
    // we need to sort both collections and compare after that
    std::sort(vector_1.begin(), vector_1.end());
    std::sort(vector_2.begin(), vector_2.end());
    // true
    cout << "After sorting: " << std::equal(vector_1.begin(), vector_1.end(), vector_2.begin(), vector_2.end()) << endl;;


    cout << "\t std::mismatch() ==================\t==================\t=================="<<endl;
    std::vector<int> vector_3 = {10, 8, 12, 14};
    std::vector<int> vector_4 = {14, 8, 12, 10};


    // return iterator pointing first mismatch (in our case are 10 and 14)
    auto iterator = std::mismatch(vector_3.begin(), vector_3.end(), vector_4.begin(), vector_4.end());
    cout << "First mismatch: " << *iterator.first << endl; // 10
    cout << "Second mismatch: " << *iterator.second << endl; // 14

    if (iterator.first == vector_3.end() && iterator.second == vector_4.end()) {
        cout << "Both collections is equals" << endl;
    } else {
        cout << "We have some mismatch" << endl;
    }
    cout << "\t std::equal() with predicate ==================\t==================\t=================="<<endl;

    std::vector<Student> vector_students = {
        Student ("Misha", 4.4),
        Student ("Sasha", 4.9),
        Student ("Vasya", 4.0),
        Student ("Petr", 4.6)
    };
    std::vector<Student> vector_students_2 = {
        Student ("Misha", 4.4),
        Student ("Sasha", 4.9),
        Student ("Vasya", 4.0),
        Student ("Petr", 4.6)
    };
    auto res11 = std::equal(
        vector_students.begin(),
     vector_students.end(),
      vector_students_2.begin(),
       vector_students_2.end(),

        [](Student & student1, Student & student2) {
        return student1.name == student2.name;
    });
    cout << res11 << endl;





    cout << "\t std::unique(); ==================\t==================\t=================="<<endl;

    // remove duplicate element only if it in sequence
    // std::vector<int> v = {100, 200,200,200, 300,300, 400, 100,100, 100, 100, 500, 600, 700, 800, 900, 1000, 1000};
    // auto it = std::unique(v.begin(), v.end());
    // v.resize(std::distance(v.begin(), it));
    // for (it = v.begin(); it != v.end(); ++it) cout << *it << endl;


    // sort vector and remove all duplicates after that
    std::vector<int> v66 = {10, 12, 14, 16, 10, 20, 15, 12, 22, 14, 16, 20};
    std::sort(v66.begin(), v66.end());
    auto iterat = std::unique(v66.begin(), v66.end());
    v66.resize(std::distance(v66.begin(), iterat));
    for (auto & ell : v) cout << ell << endl;


    cout << "\t ==================\t==================\t=================="<<endl;
    std::vector<int> myvv = {1, 2, 3, 4, 5};
    std::vector<int> myvv_copy;
    std::copy(myvv.begin(), myvv.end(), std::back_inserter(myvv_copy));

    for (auto & elementik : myvv_copy) cout << elementik << std::endl;
    return 0;

}
