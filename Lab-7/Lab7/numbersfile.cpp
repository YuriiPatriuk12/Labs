#include "numbersfile.h"

bool NumbersFile::insertRange(size_t begin, size_t end, size_t power)
{
    ofstream o_file(this->file, ios_base::binary);
    try{
        int counter = 0;
        for (size_t var = begin; var != end+1; ++var) {
            counter++;
            if(counter == this->size+1)
                throw OverflowException();
            size_t temp = var * power;
            o_file.write((char*)&temp, sizeof(size_t));
        }
    }
    catch(OverflowException e){
        o_file.close();
        MessageBoxA(NULL, e.what(), (char*)"Error", MB_ICONWARNING);
        return false;
    }
    o_file.close();
    return true;
}
