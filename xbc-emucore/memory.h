

#ifndef MEMORY_H_
#define MEMORY_H_

class Memory
{
private:
    unsigned char* data;
    int size;
public:
    Memory(int _Size) : size(_Size) { data = new unsigned char[_Size]; }

    ~Memory() { delete data; }

    void WriteData(int _Address, unsigned char _Data) { data[_Address] = _Data; }
    unsigned char ReadData(int _Address) { return data[_Address]; }
};

#endif