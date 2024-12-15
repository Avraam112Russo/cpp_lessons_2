#include<iostream>
#include<unordered_map>
using namespace std;





int main() {

    //at();
    /*
    std::unordered_map<int, double> mapa = {
    {100, 4.4}, {200, 3.4}, {300, 9.4}, {400, 1.4}};

    std::unordered_map<int, double>::iterator it = mapa.begin();
    for (; it != mapa.end(); ++it) cout << it->first << " : " << it->second << endl;
    */




    // bucket(); Returns the bucket number where the element with key k is located.
    /*
    std::unordered_map<string, string> my_map= {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };
    for (auto & el : my_map) {
        cout << "Name: " << el.first << ". Last name: " << el.second << endl;
        cout << my_map.bucket(el.first) << endl;
    }
    */


    // begin(n); n - index of bucket
    // end(n);
    /*
    std::unordered_map<string, string> my_map= {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };

    for (int i = 0; i < my_map.bucket_count(); ++i) {
        cout << "Bucket #: " << i << endl;
        for (std::unordered_map<string, string>::local_iterator loc_it = my_map.begin(i); loc_it != my_map.end(i); ++loc_it) {
            cout << loc_it->first << " : " <<loc_it->second << endl;
        }
        cout << "================" << endl;
    }
    */



    // bucket_size(n); return count elements in bucket
    // my_map.size(); // buckets count
    // my_map.reserve(); -> set capacity -> set count bucket
    /*
    std::unordered_map<string, string> my_map= {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };

    for (int i = 0; i < my_map.bucket_count(); ++i) {
        cout << "Bucket #: " << i << " have a size: " <<my_map.bucket_size(i) << endl;;
    }
    cout << "Size of map" << my_map.size() << endl;; // 6
    cout << "Bucket_count of map" << my_map.bucket_count() << endl;; // 13 // 6 - with pairs and 7 is empty
    cout << "=============================" << endl;
    my_map.reserve(400); // set capacity // now we have 400 buckets
    */


    // count(); return 1 if map contains key and return 0 if not
    /*
    std::unordered_map<string, string> my_map= {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };

    cout << my_map.count("Russo")<< endl; // output 1
    cout << my_map.count("Russoansajsna")<< endl; // output 0
    */


    // find(); Searches the container for an element with k as key and returns an iterator to it if found,
    // otherwise it returns an iterator to unordered_map::end (the element past the end of the container).
    /*
    std::unordered_map<string, string> my_map= {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };
    std::unordered_map<string, string>::iterator it = my_map.find("Vika"); // return iterator pointing to element with key vika
    if (it != my_map.end()) {
        cout << it->first << " : " << it->second << endl;
    }
    */


    // my_map.hash_function(); return hash function what unordered map used
    /*
    typedef std::unordered_map<string, string> my_map_def;
    my_map_def my_map= {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };

    my_map_def::hasher hash_function = my_map.hash_function();
    cout << hash_function("hola!") << endl; // return hash this string -> 11141719691418113381
    cout << hash_function("how are you??!") << endl; // -> 18276317629616540815
    */


    // key_eq(); Returns the key equivalence comparison predicate used by the unordered_map container.
    /*
    std::unordered_map<string,string> my_map= {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };
    std::unordered_map<string, string>::key_equal key_eq = my_map.key_eq();
    cout << std::boolalpha << key_eq("test", "test") << endl; // return true
    cout << std::boolalpha << key_eq("test", "testndsd") << endl; // return false
    */


    // load_factor();
    /*
    std::unordered_map<string,string> my_map= {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };

    std::cout << my_map.size() << endl; // count elements  6
    std::cout << my_map.bucket_count() << endl; // capacity   13
    std::cout << my_map.load_factor() << endl; // output: 0.461538 -> 6 / 13 = 0.461538
    */


    // max_bucket_count(); show max capacity for my machine
    /*
    std::unordered_map<string, string> map;
    cout << map.max_bucket_count() << endl; // output: 115292150460684697
    */


    // max_load_factor();
    /*
    std::unordered_map<string,string> my_map;
    my_map.max_load_factor(0.1); // set this value and for 6 element we have more than 60 bucket, while by default max_load_factor we have 13 bucket
    my_map = {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };

    cout << my_map.size() << endl; // count inserted elements // 6
    cout << my_map.bucket_count()<< endl; // capacity // 61
    cout << my_map.load_factor() << endl; // 0.0983607 // less than my_map.max_load_factor(0.1);
    cout << my_map.max_load_factor() << endl; // 0.1
    */


    //rehash(n); same and reserve();// increase capacity
    typedef std::unordered_map<string, string> map_str;
    map_str my_map = {
        {"Russo", "Zaripov"},
        {"Elena", "Sokolova"},
        {"Vika", "Malysheva"},
        {"Dasha", "Rogova"},
        {"DashaS", "RogovaD"},
        {"DashaD", "RogovaA"},
    };
    map_str::hasher hash = my_map.hash_function();
    auto it = my_map.begin();
    for (; it != my_map.end(); ++it) {
        cout << hash.operator()(it->first) << endl;
    }


    cout << "==============================" << endl;
    my_map.rehash(100);
    cout << my_map.bucket_count() << endl;;
    auto iter = my_map.begin();
    for (; iter != my_map.end(); ++iter) {
        cout << hash.operator()(iter->first) << endl;
    }


    return 0;
}