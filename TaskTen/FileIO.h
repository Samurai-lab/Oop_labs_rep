
#ifndef TASKTEN_FILEIO_H
#define TASKTEN_FILEIO_H

#include "LinkedList.h"


template<typename T>
class FileIO {
    LinkedList<T> list;
    std::string fileName;
    std::string buffName = "temp.txt";
public:
    FileIO(std::string filename);

    int load(LinkedList<T> &linkedList);

    int unload();

    LinkedList<T> give_list();

    void del_less_than(T obj);

    void decrease_records(T L);

    void add_records(int number, int k);};

#endif
