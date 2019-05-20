#include <string>
#include <cstdarg>

//missing string printf
//this is safe and convenient but not exactly efficient
inline std::string format(const char* fmt, ...) {
    int size = 1024;
    char* buffer = 0;
    buffer = new char[size];
    va_list vl;
    va_start(vl, fmt);
    int nsize = vsnprintf(buffer, size, fmt, vl);
    if (size <= nsize) { //fail delete buffer and try again
        delete[] buffer;
        buffer = 0;
        buffer = new char[nsize + 1]; //+1 for /0
        nsize = vsnprintf(buffer, size, fmt, vl);
    }
    std::string ret(buffer);
    va_end(vl);
    delete[] buffer;
    return ret;
}
static bool
str_to_uint16(const char *str, uint16_t *res)
{
  char *end;
  errno = 0;
  intmax_t val = strtoimax(str, &end, 10);
  if (errno == ERANGE || val < 0 || val > UINT16_MAX || end == str || *end != '\0')
    return false;
  *res = (uint16_t) val;
  return true;
}
