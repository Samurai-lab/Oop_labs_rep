#include "FileIO.h"

template<typename T>
FileIO<T>::FileIO(std::string filename) : fileName(std::move(filename)) {}

template<typename T>
int FileIO<T>::load(LinkedList<T> &linkedList) {
    std::fstream stream(fileName, std::ios::out);
    if (!stream) return -1;
    auto it = linkedList.first();
    auto count = 0;
    for (; it != linkedList.last(); it++) {
        stream << *it << "\n";
        count++;
    }
    stream.close();
    return count;
}

template<typename T>
int FileIO<T>::unload() {
    std::fstream stream(fileName, std::ios::in);
    if (!stream) return -1;
    auto count = 0;
    T k;
    stream >> k;
    while (!stream.eof()) {
        count++;
        list.push(k);
        stream >> k;
    }
    stream.close();
    return count;
}

template<typename T>
LinkedList<T> FileIO<T>::give_list() {
    LinkedList<T> temp = list;
    auto sizel = list.give_size();
    for (int i = 0; i < sizel; i++) {
        list.pop();
    }
    return temp;
}

template<typename T>
void FileIO<T>::del_less_than(T obj) {
    std::fstream in(fileName, std::ios::in);
    std::fstream out(buffName, std::ios::out);
    T k;
    in >> k;
    while (!in.eof()) {
        if (obj <= k) {
            out << k << "\n";
        }
        in >> k;
    }
    in.close();
    out.close();
    remove(fileName.c_str());
    rename(buffName.c_str(), fileName.c_str());
}

template<typename T>
void FileIO<T>::add_records(int number, int k) {
    std::fstream in(fileName, std::ios::in);
    std::fstream out(buffName, std::ios::out);

    T obj;
    in >> obj;
    int count = 1;
    while (!in.eof()) {
        out << obj << "\n";
        in >> obj;
        if (count == number) {
            std::cout << "Write " << k << " elements: " << std::endl;
            T res;
            for (int i = 1; i <= k; i++) {
                std::cin >> res;
                out << res << "\n";
            }
        }
        count++;
    }
    in.close();
    out.close();
    remove(fileName.c_str());
    rename(buffName.c_str(), fileName.c_str());
}

template<typename T>
void FileIO<T>::decrease_records(T L) {
    std::fstream in(fileName, std::ios::in);
    std::fstream out(buffName, std::ios::out);
    T k;
    in >> k;

    while (!in.eof()) {
        out << k - L << "\n";
        in >> k;
    }
    in.close();
    out.close();
    remove(fileName.c_str());
    rename(buffName.c_str(), fileName.c_str());
}
