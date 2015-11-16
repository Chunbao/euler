//
//  main.cpp
//  test
//
//  Created by JI CHUNBAO on 15-11-15.
//  Copyright (c) 2015年 ___SEU___. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

//class CMyString
//{
//    friend std::ostream& operator<<( std::ostream& os, const CMyString& str);
//private:
//    char* m_pData; //  私有变量保存字符串
//public:
//    CMyString( const char* str = NULL ); // 构造函数
//    CMyString( const CMyString& str ); // 拷贝构造函数
//    ~CMyString( void ); // 析构函数
//    CMyString& operator=( const CMyString& str ); // 赋值运算符
//    CMyString operator+( const CMyString& str ); // 字符串连接
//    bool operator==( const CMyString& str ); // 判断相等
//    char operator[]( int idx ); // 数组索引
//    int getLength(); // 返回长度
//};

class CMyString {
public:
    CMyString();
    CMyString(const char* str = nullptr);
    CMyString(const CMyString&);
    CMyString& operator=(const CMyString&);
    ~CMyString();
    
    CMyString operator+(const CMyString& str);
    bool operator==(const CMyString&);
    int getLength();
    
    friend std::ostream& operator<<(std::ostream& os, const CMyString& str);
private:
    char* p_data;
};

CMyString::CMyString() {}
CMyString::CMyString(const char* str) {
    if (!str) {
        str = nullptr;
    }
    else {
        p_data = new char[strlen(str) + 1];
        strcpy(p_data, str);
    }
}
CMyString::CMyString(const CMyString& str) {
    //IMPORTANT
    //Similar with above function
}
CMyString& CMyString::operator=(const CMyString& rhs) {
    return *this;
}

CMyString::~CMyString(){
    if (p_data) {
        delete[] p_data;
        p_data = nullptr;
    }
}

CMyString CMyString::operator+(const CMyString& str) {
    //????
    return str;
}

bool CMyString::operator==(const CMyString& str) {
    return strcmp(p_data, str.p_data) ? false : true;
}

int CMyString::getLength() {
    return strlen(p_data);
}

std::ostream& operator<<(std::ostream& os, const CMyString& str) {
    os << str.p_data;
    return os;
}

char* strcpy(char* dest, const char* src) {
    if (!dest || !src || dest == src) {
        throw "Error";
    }
    char* tempDest = dest;
    while((*dest++=*src++)!='\0');
    return tempDest;
}

/*
 * return negtive if lhs < rhs
 *        positive if lhs > rhs
 *        0        if lhs = rhs
 */
int strcmp(const char* lhs, const char* rhs) {
    int val;
    while (!(val = *lhs - *rhs) && *lhs) {
        ++lhs;
        ++rhs;
    }
    return val;
}

//strncmp

int main(int argc, const char * argv[])
{

    // insert code here...
    char* str1 = "There h";
    char* str2 = (char*) malloc(strlen(str1));
    char str3[] = "Sdasdasd";
    strcpy(str2, str3);
    std::cout << strcmp(str3,str2) << std::endl;
    
    CMyString str5(str1);
    cout << (str5 == str3);
    return 0;
}

