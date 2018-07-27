//
// Created by 操海兵 on 04/06/2018.
//

#ifndef CH_13_DMA_H
#define CH_13_DMA_H

#include <iostream>

class baseDMA{
private:
    char* label;
    int rating;
public:
    baseDMA(const char* l = "null", int r = 0);
    baseDMA(const baseDMA& rs);
    virtual ~baseDMA();
    baseDMA& operator=(const baseDMA& rs);
    friend std::ostream& operator<<(std::ostream& out, const baseDMA& rs);
};

// derive class without DMA
class lacksDMA : public baseDMA{
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char* c = "blank", const char * l = "null",
      int r = 0);
    lacksDMA(const char* c, const baseDMA& rs);
    friend std::ostream& operator<< (std::ostream& out,
      const lacksDMA& rs);
};

// derived with DMA
class hasDMA : public baseDMA{
private:
    char * style;
public:
    hasDMA(const char* s = "none", char * l = "null",
      int r = 0);
    hasDMA(const char* s, const baseDMA& rs);
    hasDMA(const hasDMA& rs);
    ~hasDMA();
    hasDMA& operator=(const hasDMA& rs);
    friend std::ostream& operator<<(std::ostream& out, const hasDMA& rs);
};
#endif //CH_13_DMA_H
