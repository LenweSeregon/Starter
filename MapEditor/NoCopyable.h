#ifndef __MapEditor__NoCopyable__
#define __MapEditor__NoCopyable__

class NoCopyable
{
private:
    
public:
    
    NoCopyable() = default;
    NoCopyable(const NoCopyable&) = delete;
    NoCopyable& operator=(const NoCopyable&) = delete;
};

class NoCopyableButMovable
 {
 private:
 
 public:
     
     NoCopyableButMovable() = default;
     NoCopyableButMovable(const NoCopyableButMovable&) = delete;
     NoCopyableButMovable& operator=(const NoCopyableButMovable&) = delete;
     NoCopyableButMovable(NoCopyableButMovable&&) = default;
 };

class NoCopyableAndMovable
{
private:
    
public:
    
    NoCopyableAndMovable() = default;
    NoCopyableAndMovable(const NoCopyableAndMovable&) = delete;
    NoCopyableAndMovable& operator=(const NoCopyableAndMovable&) = delete;
    NoCopyableAndMovable(NoCopyableAndMovable&&) = delete;
};

class CopyableAndMovable
{

};


#endif /* defined(__MapEditor__NoCopyable__) */
