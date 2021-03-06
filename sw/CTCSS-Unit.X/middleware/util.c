/*
\author         Oliver Blaser
\date           21.04.2021
\copyright      GNU GPLv3 - Copyright (c) 2021 Oliver Blaser
*/

#include "util.h"


#define _UTIL_ITOA_BUFFERSIZE (12)


const char hexLookUp[] = "0123456789ABCDEF";


/**
 * @brief Returns the length of a string
 * @param str Pointer to a null terminated string
 * @param size The size of the string buffer pointed to
 * @return Number of characters (not including the null terminator)
 */
size_t UTIL_strnlen(const char* str, size_t size)
{
    size_t len = 0;
    if(str) while((*(str + len) != 0) && (len < size)) ++len;
    return len;
}

/**
 * @brief Converts an integer to a string
 * @param value 
 * @param str Pointer to the destination string
 * @param strSize Size of the destination string
 * @return UTIL_STRERR_INVPTR or UTIL_STRERR_BUFSIZE or the length of the new string (not including the null terminator)
 */
int UTIL_itoa(int32_t value, char* str, size_t strSize)
{
    char revBuf[_UTIL_ITOA_BUFFERSIZE];
    int revBufIndex = 0;
    uint32_t val = *(&value);
    char* p = str;
    
    if(!str) return UTIL_STRERR_INVPTR;
    if(strSize < _UTIL_ITOA_BUFFERSIZE) return UTIL_STRERR_BUFSIZE;
    
    if(value == 0)
    {
        *str = '0';
        *(str + 1) = 0;
        return 1;
    }
    
    if(value < 0)
    {
        *p = '-';
        ++p;
        
        val = ~val;
        ++val;
    }
    
    while(val != 0)
    {
        revBuf[revBufIndex] = (val % 10) + 0x30;
        ++revBufIndex;
        val /= 10;
    }
    
    --revBufIndex;
    
    while(revBufIndex > (-1))
    {
        *p = revBuf[revBufIndex];
        ++p;
        --revBufIndex;
    }
    
    *p = 0;
    
    return (p - str);
}

#if(UTIL_CONFIG_USE_ITOA_BUFFER)
static char itoa_buffer[_UTIL_ITOA_BUFFERSIZE];
const char* UTIL_itoap(int32_t value)
{
    if(UTIL_itoa(value, itoa_buffer, (sizeof(itoa_buffer)/sizeof(itoa_buffer[0]))) < 0) return 0;
    return itoa_buffer;
}
#endif

/**
 * @brief Converts a byte to a hex string
 * @param byte The byte to convert
 * @param str Pointer to the destination string
 * @param strSize Size of the destination string
 * @return The length of the new string (not including the null terminator) or 0 on error
 */
size_t UTIL_byteToHexStr(uint8_t byte, char* str, size_t strSize)
{
    size_t size = 3;
    
    if(str && (strSize >= size))
    {
        str[0] = hexLookUp[(byte >> 4) & 0x0F];
        str[1] = hexLookUp[byte & 0x0F];
        str[2] = 0;
    }
    else return 0;
    
    return size - 1;
}

/**
 * @brief Converts a byte buffer to a hex string
 * @param buffer Pointer to the byte buffer
 * @param count Number of bytes to convert
 * @param str Pointer to the destination string
 * @param strSize Size of the destination string
 * @return The length of the new string (not including the null terminator) or 0 on error
 */
size_t UTIL_bufToHexStr(const uint8_t* buffer, size_t count, char* str, size_t strSize)
{
    size_t size = count * 3;
    
    if(buffer && (count > 0) && str && (strSize >= size))
    {
        char* p = str;
        
        for(size_t i = 0; i < count; ++i)
        {
            if(i > 0) *p++ = ' ';
            p += UTIL_byteToHexStr(buffer[i], p, 3);
        }
        
        *p = 0;
    }
    else return 0;
    
    return size - 1;
}
