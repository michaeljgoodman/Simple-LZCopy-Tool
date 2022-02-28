#include <windows.h>
#include <lzexpand.h>
#include <iostream>

using namespace std;

static DWORD decompress_file_lz(LPCWSTR source, LPCWSTR target)
{
    DWORD ret;
    LONG error;
    INT src, dst;
    OFSTRUCT src_ofstruct, dst_ofstruct;

    if ((src = LZOpenFileW((LPWSTR)source, &src_ofstruct, OF_READ)) < 0)
    {
        
        return ERROR_FILE_NOT_FOUND;
    }
    if ((dst = LZOpenFileW((LPWSTR)target, &dst_ofstruct, OF_CREATE)) < 0)
    {
        
        LZClose(src);
        return ERROR_FILE_NOT_FOUND;
    }
    if ((error = LZCopy(src, dst)) >= 0) ret = ERROR_SUCCESS;
    else
    {
        
        ret = ERROR_INVALID_DATA;
    }

    LZClose(src);
    LZClose(dst);
    return ret;
}

    int wmain(int argc, wchar_t* argv[], wchar_t* envp[]) {

        cout << "Decompressing file...";

    if (argc == 2) {
        WCHAR output_file[] = L".\\out.bin";
        DWORD result = decompress_file_lz(argv[1], output_file);
    }
    if (argc == 3) {
        DWORD result = decompress_file_lz(argv[1], argv[2]);
    }

    return 0;

};